GLOBAL constexpr float PATH_DIALOG_BOTTOM_BORDER = 26.0f;
GLOBAL std::string temp_game_path;

FILDEF void open_path ()
{
    temp_game_path = editor_settings.game_path;
    show_window("WINPATH");
}

FILDEF void do_path ()
{
    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    set_ui_font(&get_editor_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    ////////////////////////////////////////

    float bb = PATH_DIALOG_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2.0f);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the path dialog.
    Vec2 btn_cursor = { 0.0f, WINDOW_BORDER };
    begin_panel(0.0f, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Okay"  )) { okay_path  (); }
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) { cancel_path(); }

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

    constexpr float XPAD = 8.0f;
    constexpr float YPAD = 4.0f;

    Vec2 cursor = { XPAD, YPAD };

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    constexpr float BUTTON_W = 80.0f;
    constexpr float LABEL_H = 24.0f;

    cursor.x += 2.0f;
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, LABEL_H, format_string("Please locate '%s' path:", EXECUTABLE_NAME.c_str()).c_str());
    cursor.x -= 2.0f;

    set_panel_cursor_dir(UI_DIR_RIGHT);

    float tw = get_viewport().w - BUTTON_W - (XPAD*2.0f);
    float th = 24.0f;

    cursor.y += 2.0f;
    do_text_box(tw,th, UI_FILEPATH, temp_game_path, NULL, UI_ALIGN_LEFT);
    cursor.y += 1.0f;

    float btnh = th-2.0f;

    float x1 = cursor.x            - 1.0f;
    float y1 = cursor.y            - 1.0f;
    float x2 = cursor.x + BUTTON_W + 1.0f;
    float y2 = cursor.y + btnh     + 1.0f;

    // Create a nice border so the button's bounds are actually visible!
    set_draw_color(ui_color_ex_dark);
    fill_quad(x1, y1, x2, y2);

    if (do_button_txt(NULL, BUTTON_W,btnh, UI_SINGLE, "Search")) {
        auto result = path_dialog(false);
        if (!result.empty()) {
            temp_game_path = result.at(0);
        }
    }

    end_panel();
    end_panel();
}

FILDEF void okay_path ()
{
    temp_game_path = fix_path_slashes(temp_game_path.c_str());
    if (!temp_game_path.empty() && temp_game_path.back() != '/') {
        temp_game_path.push_back('/');
    }
    editor_settings.game_path = temp_game_path;

    save_preferences();
    hide_window("WINPATH");

    std::string executable(editor_settings.game_path + EXECUTABLE_NAME);
    run_executable(executable.c_str());
}

FILDEF void cancel_path ()
{
    temp_game_path.clear();
    hide_window("WINPATH");
}

FILDEF void handle_path_events ()
{
    if (!is_window_focused("WINPATH")) { return; }

    if (!text_box_is_active()) {
        if (main_event.type == SDL_KEYDOWN) {
            switch (main_event.key.keysym.sym) {
            case (SDLK_RETURN): { okay_path  (); } break;
            case (SDLK_ESCAPE): { cancel_path(); } break;
            }
        }
    }
}
