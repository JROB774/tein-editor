GLOBAL constexpr const char* STATUS_BAR_DEFAULT_MSG = "Hover over items and widgets for more information.";
GLOBAL constexpr float       STATUS_BAR_LABEL_WIDTH = 0.125f; // NDC!

GLOBAL std::string status_bar_pushed_message;

INLDEF void push_status_bar_message (const char* _fmt, ...)
{
    va_list args;

    va_start(args, _fmt);
    defer { va_end(args); };

    status_bar_pushed_message = format_string_v(_fmt, args);
}

FILDEF void do_status_bar ()
{
    // If there is a message that has been pushed we display that, if
    // not then we just display a default message for the status bar.
    const char* message = STATUS_BAR_DEFAULT_MSG;
    if (!status_bar_pushed_message.empty()) {
        message = status_bar_pushed_message.c_str();
    }

    Vec2 cursor = { STATUS_BAR_INNER_PAD, 0.0f };

    float x = get_toolbar_w() + 1.0f;
    float y = get_viewport().h - STATUS_BAR_HEIGHT;
    float w = get_viewport().w - get_toolbar_w() - (get_control_panel_w()) - 2.0f;
    float h = STATUS_BAR_HEIGHT;

    // To account for the control panel and toolbar disappearing.
    if (!current_tab_is_level()) {            w += 1.0f; }
    if (!are_there_any_tabs  ()) { x -= 1.0f, w += 1.0f; }

    float status_bar_width = w - (STATUS_BAR_INNER_PAD * 2.0f);
    float advance = STATUS_BAR_INNER_PAD;

    float l2_w = roundf(status_bar_width * STATUS_BAR_LABEL_WIDTH); // Mouse.
    float l3_w = roundf(status_bar_width * STATUS_BAR_LABEL_WIDTH); // Select.

    // Get the mouse position.
    int mx = 0, my = 0;
    if (is_window_focused("WINMAIN")) {
        if (current_tab_is_level()) {
            if (point_in_bounds_xywh(get_mouse_pos(), level_editor.viewport)) {
                mx = CAST(int, level_editor.mouse_tile.x);
                my = CAST(int, level_editor.mouse_tile.y);
            }
        } else if (current_tab_is_map()) {
            if (point_in_bounds_xywh(get_mouse_pos(), map_editor.viewport)) {
                mx = CAST(int, map_editor.mouse_tile.x);
                my = CAST(int, map_editor.mouse_tile.y);
            }
        }
    }

    // Get the select bounds.
    int sx = 0, sy = 0, sw = 0, sh = 0;
    if (current_tab_is_level() && are_any_select_boxes_visible()) {
        int l,t,r,b;
        get_total_select_boundary(&l,&t,&r,&b);
        sx = l, sy = b, sw = (r-l)+1, sh = (t-b)+1;
    } else if (current_tab_is_map() && map_select_box_present()) {
        int l,t,r,b;
        get_map_select_bounds(&l,&t,&r,&b);
        sx = l, sy = b, sw = (r-l)+1, sh = (t-b)+1;
    }

    std::string mouse_str = format_string("Position (%d,%d)", mx,my);
    std::string select_str = format_string("Selection (%d,%d,%d,%d)", sx,sy,sw,sh);

    // We ensure that the mouse and select labels are always big enough to
    // show their entire content and they take priority over the tool-tip.
    float l2_tw = get_text_width_scaled(get_editor_font(), mouse_str.c_str());
    if (l2_w < l2_tw) { l2_w = l2_tw; }
    float l3_tw = get_text_width_scaled(get_editor_font(), select_str.c_str());
    if (l3_w < l3_tw) { l3_w = l3_tw; }

    // Now we can calculate how much space is left for the tool-tip label.
    float l1_w = (status_bar_width - (l2_w + l3_w)) - (advance * 2.0f);

    set_ui_font(&get_editor_font());

    // Status bar is a horizontal list of editor status information.
    begin_panel(x, y, w, h, UI_NONE, ui_color_medium);

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_RIGHT);

    do_label(UI_ALIGN_LEFT,  UI_ALIGN_CENTER, l1_w, h, message);
    advance_panel_cursor(STATUS_BAR_INNER_PAD);
    do_label(UI_ALIGN_RIGHT, UI_ALIGN_CENTER, l2_w, h, mouse_str.c_str());
    advance_panel_cursor(STATUS_BAR_INNER_PAD);
    do_label(UI_ALIGN_RIGHT, UI_ALIGN_CENTER, l3_w, h, select_str.c_str());

    end_panel();

    // Reset the pushed status bar message for the next update.
    status_bar_pushed_message.clear();
}
