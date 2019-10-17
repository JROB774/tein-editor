GLOBAL constexpr float NEW_BOTTOM_BORDER = 26.0f;

GLOBAL constexpr float NEW_XPAD = 8.0f;
GLOBAL constexpr float NEW_YPAD = 8.0f;

GLOBAL constexpr float NEW_TEXT_BOX_H = 20.0f;

GLOBAL constexpr const char* NEW_WIDTH_LABEL = "Level Width:  ";
GLOBAL constexpr const char* NEW_HEIGHT_LABEL = "Level Height:  ";

GLOBAL int current_new_width  = CAST(int, DEFAULT_LEVEL_WIDTH);
GLOBAL int current_new_height = CAST(int, DEFAULT_LEVEL_HEIGHT);

FILDEF void internal__okay_new ()
{
    if (current_new_width < MINIMUM_LEVEL_WIDTH || current_new_height < MINIMUM_LEVEL_HEIGHT) {
        show_alert("Warning", format_string("Minimum level size is %dx%d!", MINIMUM_LEVEL_WIDTH, MINIMUM_LEVEL_HEIGHT).c_str(),
            ALERT_TYPE_WARNING, ALERT_BUTTON_OK, "WINNEW");
        return;
    }

    le_new_okay();
    hide_window("WINNEW");
}

FILDEF void open_new ()
{
    set_window_pos("WINNEW", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);

    current_new_width = CAST(int, DEFAULT_LEVEL_WIDTH);
    current_new_height = CAST(int, DEFAULT_LEVEL_HEIGHT);

    show_window("WINNEW");
}

FILDEF void do_new ()
{
    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    set_ui_font(&get_editor_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    ////////////////////////////////////////

    float bb = NEW_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2.0f);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the resize.
    Vec2 btn_cursor = { 0.0f, WINDOW_BORDER };
    begin_panel(0.0f, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Create")) { internal__okay_new(); }
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) { cancel_new();         }

    // Add a separator to the left for symmetry.
    btn_cursor.x = 1.0f;
    do_separator(bh);

    end_panel();

    ////////////////////////////////////////

    p2.x =                  1.0f;
    p2.y =                  1.0f;
    p2.w = vw             - 2.0f;
    p2.h = vh - p2.y - bb - 1.0f;

    begin_panel(p2, UI_NONE, ui_color_medium);

    Vec2 cursor = { NEW_XPAD, NEW_YPAD };

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    float label_w_w = get_text_width(get_editor_font(), NEW_WIDTH_LABEL) * get_font_draw_scale();
    float label_h_w = get_text_width(get_editor_font(), NEW_HEIGHT_LABEL) * get_font_draw_scale();

    float text_box_w = (vw-(NEW_XPAD*2.0f));
    float label_w = MAX(label_w_w, label_h_w);

    std::string w_str(std::to_string(current_new_width));
    std::string h_str(std::to_string(current_new_height));

    do_text_box_labeled(text_box_w, NEW_TEXT_BOX_H, UI_NUMERIC, w_str, label_w, NEW_WIDTH_LABEL, "0");
    advance_panel_cursor(NEW_YPAD);
    do_text_box_labeled(text_box_w, NEW_TEXT_BOX_H, UI_NUMERIC, h_str, label_w, NEW_HEIGHT_LABEL, "0");

    if (atoi(w_str.c_str()) > MAXIMUM_LEVEL_WIDTH) {
        w_str = std::to_string(MAXIMUM_LEVEL_WIDTH);
    }
    if (atoi(h_str.c_str()) > MAXIMUM_LEVEL_HEIGHT) {
        h_str = std::to_string(MAXIMUM_LEVEL_HEIGHT);
    }

    int old_new_width = current_new_width;
    int new_new_width = atoi(w_str.c_str());
    if (new_new_width != old_new_width) {
        current_new_width = new_new_width;
    }
    int old_new_height = current_new_height;
    int new_new_height = atoi(h_str.c_str());
    if (new_new_height != old_new_height) {
        current_new_height = new_new_height;
    }

    end_panel();
    end_panel();
}

FILDEF void cancel_new ()
{
    hide_window("WINNEW");
}

FILDEF void handle_new_events ()
{
    if (!is_window_focused("WINNEW")) { return; }

    if (!text_box_is_active()) {
        if (main_event.type == SDL_KEYDOWN) {
            switch (main_event.key.keysym.sym) {
            case (SDLK_RETURN): { internal__okay_new(); } break;
            case (SDLK_ESCAPE): { cancel_new();         } break;
            }
        }
    }
}

FILDEF int get_new_w ()
{
    return current_new_width;
}
FILDEF int get_new_h ()
{
    return current_new_height;
}
