GLOBAL constexpr float DEFAULT_LEVEL_TAB_WIDTH = 128.0f;
GLOBAL constexpr float SHIFT_TAB_BUTTON_WIDTH  =  13.0f;

GLOBAL size_t starting_tab_offset = 0;
GLOBAL size_t max_number_of_tabs  = 0;

FILDEF bool internal__do_level_tab (float _w, const Tab& _tab, size_t _index, bool _current)
{
    bool should_close = false;

    float xpad = 6.0f;

    float tw = _w;
    float th = get_panel_h();

    Vec2 cursor1 = { 0.0f, 0.0f };
    Vec2 cursor2 = { xpad, 0.0f };

    float bw = 24.0f;
    float pw = tw-(bw);
    float lw = pw-(xpad*2);

    std::string name((!_tab.name.empty()) ? strip_file_path(_tab.name.c_str()) : "Untitled");
    // We insert at the start so that it is always visible even if the
    // level's name gets cut off by the width of the final level tab.
    if (_tab.unsaved_changes) { name.insert(0, "* "); }

    UI_Flag flags = (_current) ? UI_HIGHLIGHT : UI_INACTIVE;
    begin_panel(get_panel_cursor().x, 0.0f, tw, th, flags, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor1);

    // We display the level tab's full file name in the status bar on hover.
    const Tab& tab = get_tab_at_index(_index);

    std::string info((tab.name.empty()) ? "Untitled" : tab.name);
    if (begin_click_panel_gradient(NULL, pw,th+1.0f, flags, info.c_str())) {
        set_current_tab(_index);
    }

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor2);

    do_label(UI_ALIGN_LEFT, UI_ALIGN_CENTER, lw,th, name.c_str());

    end_panel();

    cursor1.x += pw;
    cursor1.y  = 0.0f;

    if (do_button_img_gradient(NULL, bw,th+1.0f, flags, &CLIP_CROSS, info.c_str())) {
        should_close = true;
    }

    end_panel();

    advance_panel_cursor(tw+1.0f);
    return should_close;
}

FILDEF void do_tab_bar ()
{
    float x = get_toolbar_w() + 1.0f;
    float y = 0.0f;

    float bw = SHIFT_TAB_BUTTON_WIDTH;
    float bh = TAB_BAR_HEIGHT;

    set_ui_texture(&resource_icons);
    set_ui_font(&get_editor_regular_font());

    float pw = get_viewport().w - get_toolbar_w() - get_control_panel_w() - (bw*2) - 4.0f;
    float ph = TAB_BAR_HEIGHT;

    // To account for the control panel disappearing.
    if (!current_tab_is_level()) { pw += 1.0f; }

    // Figure out how many tabs we can fit on the bar before we need to start scrolling.
    max_number_of_tabs = CAST(int, ceilf(pw / (DEFAULT_LEVEL_TAB_WIDTH + 1.0f)));

    float tab_width = DEFAULT_LEVEL_TAB_WIDTH;
    float left_over = 0.0f;

    if (editor.tabs.size() >= max_number_of_tabs) {
        tab_width = floorf((pw-((max_number_of_tabs-1)*1.0f)) / CAST(float, max_number_of_tabs));
        left_over = (pw-((max_number_of_tabs-1)*1.0f)) - (tab_width * max_number_of_tabs);
    } else {
        starting_tab_offset = 0;
    }

    // THE LEFT ARROW BUTTON
    if (are_there_any_tabs()) {
        begin_panel(x, y, bw,bh, UI_NONE);
        Vec2 tmp = { 0.0f, 0.0f };
        set_panel_cursor(&tmp);
        bool l_arrow_active = (starting_tab_offset != 0);
        UI_Flag flags = (l_arrow_active) ? UI_NONE : UI_LOCKED;
        if (do_button_img(NULL, bw+1.0f,bh, flags, &CLIP_ARROW_LEFT)) {
            --starting_tab_offset;
        }
        end_panel();
    }

    // THE LIST OF TABS
    Vec2 cursor = { 0.0f, 0.0f };

    Vec4 color = (are_there_any_tabs()) ? ui_color_med_dark : ui_color_ex_dark;
    begin_panel(x+bw+1.0f, y, pw, ph, UI_NONE, color);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    size_t index_to_close = CAST(size_t, -1);
    size_t last = std::min(editor.tabs.size(), starting_tab_offset+max_number_of_tabs);
    for (size_t i=starting_tab_offset; i<last; ++i) {
        bool current = (i == editor.current_tab);
        float w = tab_width + ((i == last-1) ? left_over : 0.0f);
        if (internal__do_level_tab(w, editor.tabs.at(i), i, current)) {
            index_to_close = i;
        }
    }

    end_panel();

    // THE RIGHT ARROW BUTTON
    if (are_there_any_tabs()) {
        begin_panel(x+bw+2.0f+pw, 0.0f, bw,bh, UI_NONE);
        Vec2 tmp = { 0.0f, 0.0f };
        set_panel_cursor(&tmp);
        bool r_arrow_active = (starting_tab_offset+max_number_of_tabs < editor.tabs.size());
        UI_Flag flags = (r_arrow_active) ? UI_NONE : UI_LOCKED;
        if (do_button_img(NULL, bw+1.0f,bh, flags, &CLIP_ARROW_RIGHT)) {
            ++starting_tab_offset;
        }
        end_panel();
    }

    // If a level needs to be closed then we do it now.
    if (index_to_close != CAST(size_t, -1)) { close_tab(index_to_close); }
}

FILDEF void maybe_scroll_tab_bar ()
{
    if (editor.current_tab < starting_tab_offset) {
        starting_tab_offset = editor.current_tab;
    }
    while (editor.current_tab >= std::min(editor.tabs.size(), starting_tab_offset+max_number_of_tabs)) {
        ++starting_tab_offset;
    }
}

FILDEF void move_tab_left ()
{
    if (!are_there_any_tabs()) { return; }

    if (get_current_tab().type == TAB_TYPE_MAP) {
        if (map_editor.node_active) {
            return;
        }
    }

    if (editor.current_tab > 0) {
        auto begin = editor.tabs.begin();
        std::iter_swap(begin+editor.current_tab-1, begin+editor.current_tab);
        --editor.current_tab;
        maybe_scroll_tab_bar();
    }
}

FILDEF void move_tab_right ()
{
    if (!are_there_any_tabs()) { return; }

    if (get_current_tab().type == TAB_TYPE_MAP) {
        if (map_editor.node_active) {
            return;
        }
    }

    if (editor.current_tab < editor.tabs.size()-1) {
        auto begin = editor.tabs.begin();
        std::iter_swap(begin+editor.current_tab+1, begin+editor.current_tab);
        ++editor.current_tab;
        maybe_scroll_tab_bar();
    }
}
