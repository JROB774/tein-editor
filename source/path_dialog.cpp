GLOBAL constexpr float PATH_DIALOG_BOTTOM_BORDER = 26;
GLOBAL std::string temp_game_path;

FILDEF void open_path ()
{
    temp_game_path = editor_settings.game_path;
    show_window("LoadGame");
}

FILDEF void do_path ()
{
    quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2);

    set_ui_font(&get_editor_regular_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    float bb = PATH_DIALOG_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the path dialog.
    vec2 btn_cursor(0, WINDOW_BORDER);
    begin_panel(0, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Okay"  )) okay_path  ();
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) cancel_path();

    // Add a separator to the left for symmetry.
    btn_cursor.x = 1;
    do_separator(bh);

    end_panel();

    p2.x =                  1;
    p2.y =                  1;
    p2.w = vw             - 2;
    p2.h = vh - p2.y - bb - 1;

    begin_panel(p2, UI_NONE, ui_color_medium);

    constexpr float XPAD = 8;
    constexpr float YPAD = 4;

    vec2 cursor(XPAD, YPAD);

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    constexpr float BUTTON_W = 80;
    constexpr float LABEL_H = 24;

    cursor.x += 2;
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, LABEL_H, "Please locate 'The End is Nigh' executable:");
    cursor.x -= 2;

    set_panel_cursor_dir(UI_DIR_RIGHT);

    float tw = get_viewport().w - BUTTON_W - (XPAD*2);
    float th = 24;

    cursor.y += 2;
    do_text_box(tw,th, UI_FILEPATH, temp_game_path, "", UI_ALIGN_LEFT);
    cursor.y += 1;

    float btnh = th-2;

    float x1 = cursor.x            - 1;
    float y1 = cursor.y            - 1;
    float x2 = cursor.x + BUTTON_W + 1;
    float y2 = cursor.y + btnh     + 1;

    // Create a nice border so the button's bounds are actually visible!
    set_draw_color(ui_color_ex_dark);
    fill_quad(x1, y1, x2, y2);

    if (do_button_txt(NULL, BUTTON_W,btnh, UI_SINGLE, "Search"))
    {
        auto result = open_dialog(Dialog_Type::EXE, false);
        if (!result.empty())
        {
            temp_game_path = result.at(0);
        }
    }

    end_panel();
    end_panel();
}

FILDEF void okay_path ()
{
    temp_game_path = fix_path_slashes(temp_game_path);
    editor_settings.game_path = temp_game_path;

    save_preferences();
    hide_window("LoadGame");

    if (!run_executable(editor_settings.game_path))
    {
        LOG_ERROR(ERR_MED, "Failed to launch The End is Nigh executable!");
    }
}

FILDEF void cancel_path ()
{
    temp_game_path.clear();
    hide_window("LoadGame");
}

FILDEF void handle_path_events ()
{
    if (!is_window_focused("LoadGame")) return;

    if (!text_box_is_active())
    {
        if (main_event.type == SDL_KEYDOWN)
        {
            switch (main_event.key.keysym.sym)
            {
                case (SDLK_RETURN): okay_path  (); break;
                case (SDLK_ESCAPE): cancel_path(); break;
            }
        }
    }
}
