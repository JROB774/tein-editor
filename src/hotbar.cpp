GLOBAL constexpr const char* HB_INFO_NEW           = "Create a new empty level.";
GLOBAL constexpr const char* HB_INFO_LOAD          = "Load an existing level.";
GLOBAL constexpr const char* HB_INFO_SAVE          = "Save the current level.";
GLOBAL constexpr const char* HB_INFO_SAVE_AS       = "Save the current level as a new file.";
GLOBAL constexpr const char* HB_INFO_UNDO          = "Undo the last recorded action.";
GLOBAL constexpr const char* HB_INFO_REDO          = "Redo the last recorded action.";
GLOBAL constexpr const char* HB_INFO_ZOOM_OUT      = "Zoom out the editor camera.";
GLOBAL constexpr const char* HB_INFO_ZOOM_IN       = "Zoom in the editor camera.";
GLOBAL constexpr const char* HB_INFO_PREFERENCES   = "Open the preferences menu to customize the editor.";
GLOBAL constexpr const char* HB_INFO_ABOUT         = "Open the about menu for application information.";
GLOBAL constexpr const char* HB_INFO_HELP          = "Information and help about modding The End is Nigh.";

FILDEF void do_hotbar ()
{
    Vec2 cursor = { 0.0f, 0.0f };

    // Height for the toolbar buttons.
    float bh = HOTBAR_HEIGHT - WINDOW_BORDER;

    set_ui_font(&get_editor_font());

    UI_Flag save_flags      = UI_NONE;
    UI_Flag save_as_flags   = UI_NONE;
    UI_Flag undo_flags      = UI_NONE;
    UI_Flag redo_flags      = UI_NONE;
    UI_Flag zoom_out_flags  = UI_NONE;
    UI_Flag zoom_in_flags   = UI_NONE;

    if (are_there_any_level_tabs()) {
        const Level_Tab& tab = get_current_level_tab();

        if (tab.history.state.empty()) {
            undo_flags = UI_LOCKED;
            redo_flags = UI_LOCKED;
        }

        if (tab.history.current_position <= -1)                                    { undo_flags = UI_LOCKED; }
        if (tab.history.current_position == CAST(int, tab.history.state.size())-1) { redo_flags = UI_LOCKED; }

        zoom_out_flags = (tab.camera.zoom == MIN_EDITOR_ZOOM) ? UI_LOCKED : UI_NONE;
        zoom_in_flags  = (tab.camera.zoom == MAX_EDITOR_ZOOM) ? UI_LOCKED : UI_NONE;
    } else {
        save_flags      = UI_LOCKED;
        save_as_flags   = UI_LOCKED;
        undo_flags      = UI_LOCKED;
        redo_flags      = UI_LOCKED;
        zoom_out_flags  = UI_LOCKED;
        zoom_in_flags   = UI_LOCKED;
    }

    // The hotbar is a horizontal list of available actions.
    begin_panel(0, 0, get_viewport().w, HOTBAR_HEIGHT, UI_NONE, ui_color_medium);

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_RIGHT);

    do_button_txt(hb_new_level,     bh, UI_NONE,         "New",         HB_INFO_NEW,           KB_LEVEL_NEW      );
    do_button_txt(hb_load_level,    bh, UI_NONE,         "Load",        HB_INFO_LOAD,          KB_LEVEL_OPEN     );
    do_button_txt(hb_save_level,    bh, save_flags,      "Save",        HB_INFO_SAVE,          KB_LEVEL_SAVE     );
    do_button_txt(hb_save_level_as, bh, save_as_flags,   "Save As",     HB_INFO_SAVE_AS,       KB_LEVEL_SAVE_AS  );
    do_button_txt(hb_undo_action,   bh, undo_flags,      "Undo",        HB_INFO_UNDO,          KB_UNDO           );
    do_button_txt(hb_redo_action,   bh, redo_flags,      "Redo",        HB_INFO_REDO,          KB_REDO           );
    do_button_txt(hb_zoom_out,      bh, zoom_out_flags,  "Zoom Out",    HB_INFO_ZOOM_OUT,      KB_CAMERA_ZOOM_OUT);
    do_button_txt(hb_zoom_in,       bh, zoom_in_flags,   "Zoom In",     HB_INFO_ZOOM_IN,       KB_CAMERA_ZOOM_IN );
    do_button_txt(hb_preferences,   bh, UI_NONE,         "Preferences", HB_INFO_PREFERENCES,   KB_PREFERENCES    );
    do_button_txt(hb_about,         bh, UI_NONE,         "About",       HB_INFO_ABOUT,         KB_ABOUT          );
    do_button_txt(hb_help,          bh, UI_NONE,         "Help",        HB_INFO_HELP,          KB_HELP           );

    end_panel();
}

FILDEF void hb_new_level ()
{
    le_new();
}

FILDEF void hb_load_level ()
{
    le_load();
}

FILDEF void hb_save_level ()
{
    if (!are_there_any_level_tabs()) { return; }
    le_save(get_current_level_tab());
}

FILDEF void hb_save_level_as ()
{
    if (!are_there_any_level_tabs()) { return; }
    le_save_as();
}

FILDEF void hb_undo_action ()
{
    if (!are_there_any_level_tabs()) { return; }
    undo();
}

FILDEF void hb_redo_action ()
{
    if (!are_there_any_level_tabs()) { return; }
    redo();
}

FILDEF void hb_history_begin ()
{
    if (!are_there_any_level_tabs()) { return; }
    history_begin();
}

FILDEF void hb_history_end ()
{
    if (!are_there_any_level_tabs()) { return; }
    history_end();
}

FILDEF void hb_zoom_out ()
{
    if (!are_there_any_level_tabs()) { return; }

    Level_Tab& tab = get_current_level_tab();
    if ((tab.camera.zoom /= 2.0f) < MIN_EDITOR_ZOOM) {
        tab.camera.zoom = MIN_EDITOR_ZOOM;
    }
}

FILDEF void hb_zoom_in ()
{
    if (!are_there_any_level_tabs()) { return; }

    Level_Tab& tab = get_current_level_tab();
    if ((tab.camera.zoom *= 2.0f) > MAX_EDITOR_ZOOM) {
        tab.camera.zoom = MAX_EDITOR_ZOOM;
    }
}

FILDEF void hb_preferences ()
{
    if (is_window_hidden("WINPREFERENCES")) {
        init_preferences_menu(); // Load current settings.
        show_window("WINPREFERENCES");
    } else {
        raise_window("WINPREFERENCES");
    }
}

FILDEF void hb_about ()
{
    if (is_window_hidden("WINABOUT")) { show_window("WINABOUT"); }
    else { raise_window("WINABOUT"); }
}

FILDEF void hb_help ()
{
    load_webpage("http://glaielgames.com/teinworkshop/moddermanual/");
}
