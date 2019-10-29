FILDEF Tab& internal__create_new_tab_and_focus (Tab_Type _type)
{
    size_t location;

    if (editor.current_tab == CAST(size_t, -1)) { location = 0; } // No tabs!
    else { location = editor.current_tab+1; }

    editor.tabs.insert(editor.tabs.begin()+location, Tab());
    Tab& tab = editor.tabs.at(location);

    tab.type            = _type;
    tab.camera.x        = 0.0f;
    tab.camera.y        = 0.0f;
    tab.camera.zoom     = 1.0f;
    tab.unsaved_changes = false;

    // Set this newly added tab to be the current tab for the editor.
    editor.current_tab = location;

    set_main_window_subtitle_for_tab(tab.name);

    maybe_scroll_tab_bar();

    return tab;
}

FILDEF u32 internal__backup_callback (u32 _interval, void* _user_data)
{
    push_editor_event(EDITOR_EVENT_BACKUP_TAB);

    // This tells SDL to setup the timer again to run with the new interval.
    // In this case we are just using the exact same interval as previously.
    return _interval;
}

FILDEF std::vector<std::string> internal__get_restore_files ()
{
    std::vector<std::string> files;
    list_path_files(get_executable_path().c_str(), files);

    // Remove any listed files that are not .restore files.
    std::vector<std::string> restores;
    for (auto& file: files) {
        std::string file_name(strip_file_path(file.c_str()));
        if (insensitive_compare(".restore", file_name.substr(4, strlen(".restore")))) { // NOTE: 4 because that is the length of ".csv" and ".lvl".
            restores.push_back(file);
        }
    }

    return restores;
}

FILDEF bool internal__restore_tab (std::string _file_name)
{
    std::string type(strip_file_path(_file_name.c_str()).substr(0, 4)); // NOTE: 4 because that is the length of ".csv" and ".lvl".
    if (type == ".lvl") {
        create_new_level_tab_and_focus();
        Tab& tab = get_current_tab();
        return load_restore_level(tab, _file_name.c_str());
    }
    if (type == ".csv") {
        create_new_map_tab_and_focus();
        Tab& tab = get_current_tab();
        return load_restore_map(tab, _file_name.c_str());
    }
    return false;
}

FILDEF void init_editor (int _argc, char** _argv)
{
    editor.tabs.clear();
    editor.current_tab = CAST(size_t, -1);

    editor.cooldown_timer = 0;

    editor.grid_visible =  true;
    editor.is_panning   = false;
    editor.dialog_box   = false;

    init_level_editor();
    init_map_editor();

    // Handle restoring levels/maps, command-line args, and default tab.
    std::vector<std::string> restore_files = internal__get_restore_files();
    bool denied_restore = false;
    if (!restore_files.empty()) {
        if (show_alert("Restore", "Would you like to attempt to restore tabs?", ALERT_TYPE_INFO, ALERT_BUTTON_YES_NO, "WINMAIN") == ALERT_RESULT_YES) {
            for (auto& file_name: restore_files) {
                if (!internal__restore_tab(file_name)) {
                    LOG_ERROR(ERR_MED, "Failed to restore '%s'!", file_name.c_str());
                    close_current_tab();
                } else {
                    remove(file_name.c_str()); // We can remove the restore file after it's loaded.
                }
            }
        } else {
            denied_restore = true;
        }
    }
    // Load the files that have been passed in as command line arguments.
    if (_argc > 1) {
        for (int i=1; i<_argc; ++i) {
            if (!does_file_exist(_argv[i])) {
                std::string msg(format_string("Could not find file '%s'!", _argv[i]));
                show_alert("Error", msg.c_str(), ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "WINMAIN");
            } else {
                std::string file(_argv[i]);
                std::string ext(file.substr(file.find_last_of(".")));
                Tab* tab = NULL;
                if      (ext == ".lvl") { level_drop_file(tab, file); }
                else if (ext == ".csv") { map_drop_file  (tab, file); }
            }
        }
    }
    // Otherwise just create an empty level tab and use that instead.
    if (_argc == 1 && (restore_files.empty() || denied_restore)) {
        create_new_level_tab_and_focus();
    }
}

FILDEF void quit_editor ()
{
    if (editor.cooldown_timer) { SDL_RemoveTimer(editor.cooldown_timer); }
    if (editor.backup_timer) { SDL_RemoveTimer(editor.backup_timer); }
}

FILDEF void do_editor ()
{
    if (!are_there_any_tabs()) {
        set_cursor(CURSOR_ARROW);
        return;
    }

    switch (get_current_tab().type) {
    case (TAB_TYPE_LEVEL): { do_level_editor(); } break;
    case (TAB_TYPE_MAP  ): { do_map_editor  (); } break;
    }
}

FILDEF void handle_editor_events ()
{
    Tab* tab = NULL;

    if (main_event.type == SDL_DROPFILE) {
        if (get_window_id("WINMAIN") == main_event.drop.windowID) {
            std::string file(main_event.drop.file);
            std::string ext(file.substr(file.find_last_of(".")));
            if      (ext == ".lvl") { level_drop_file(tab, file); }
            else if (ext == ".csv") { map_drop_file  (tab, file); }
        }
        SDL_free(main_event.drop.file); // Docs say to free it!
    }

    if (!are_there_any_tabs()) { return; }

    push_editor_camera_transform();
    defer { pop_editor_camera_transform(); };

    tab = &get_current_tab();

    switch (main_event.type) {
    case (SDL_USEREVENT): {
        switch (main_event.user.code) {
        case (EDITOR_EVENT_BACKUP_TAB): {
            // Go and backup every single tab that is currently open.
            for (auto& t: editor.tabs) {
                backup_tab(t);
            }
        } break;
        case (EDITOR_EVENT_COOLDOWN): {
            editor.dialog_box = false;
        } break;
        }
    } break;
    case (SDL_QUIT): {
        // Go through all tabs and make sure that they get saved if the user wants.
        for (auto& t: editor.tabs) {
            if (save_changes_prompt(t) == ALERT_RESULT_CANCEL) {
                main_running = true;
                break;
            }
        }
    } break;
    }

    switch (main_event.type) {
    case (SDL_MOUSEWHEEL): {
        // Handle camera zoom!
        if (!is_key_mod_state_active(KMOD_CTRL)) { return; }

        if      (main_event.wheel.y > 0) { tab->camera.zoom += (EDITOR_ZOOM_INCREMENT * tab->camera.zoom); } // Zoom in.
        else if (main_event.wheel.y < 0) { tab->camera.zoom -= (EDITOR_ZOOM_INCREMENT * tab->camera.zoom); } // Zoom out.

        // Make sure the editor camera zoom stays within reasonable boundaries.
        if (tab->type == TAB_TYPE_LEVEL) {
            tab->camera.zoom = std::clamp(tab->camera.zoom, MIN_LVL_EDITOR_ZOOM, MAX_LVL_EDITOR_ZOOM);
        } else {
            tab->camera.zoom = std::clamp(tab->camera.zoom, MIN_MAP_EDITOR_ZOOM, MAX_MAP_EDITOR_ZOOM);
        }
    } break;
    case (SDL_MOUSEMOTION): {
        // Handle the camera panning.
        if (editor.is_panning) {
            tab->camera.x += CAST(float, main_event.motion.xrel) / tab->camera.zoom;
            tab->camera.y += CAST(float, main_event.motion.yrel) / tab->camera.zoom;
        }
    } break;
    case (SDL_KEYDOWN):
    case (SDL_KEYUP): {
        editor.is_panning = is_key_code_active(SDLK_SPACE);
    } break;
    case (SDL_MOUSEBUTTONDOWN):
    case (SDL_MOUSEBUTTONUP): {
        // Do not handle these events whilst we are cooling down!
        if (editor.dialog_box) { return; }

        bool pressed = (main_event.button.state == SDL_PRESSED);
        if (pressed && is_there_a_hit_ui_element()) { return; }

        if (main_event.button.button == SDL_BUTTON_MIDDLE) {
            editor.is_panning = pressed;
        }
    } break;
    }

    switch (get_current_tab().type) {
    case (TAB_TYPE_LEVEL): { handle_level_editor_events(); } break;
    case (TAB_TYPE_MAP  ): { handle_map_editor_events  (); } break;
    }

    /*
    // We can crash the editor on command to test out the restore system.
    #if defined(DEBUG_BUILD)
    if (main_event.type == SDL_KEYDOWN) {
        if (main_event.key.keysym.sym == SDLK_F9) {
            LOG_ERROR(ERR_MAX, "Intentional Crash");
        }
    }
    #endif // DEBUG_BUILD
    */
}

FILDEF void update_backup_timer ()
{
    // Remove the old backup timer if there is one currently present.
    if (editor.backup_timer) { SDL_RemoveTimer(editor.backup_timer); }

    // We do not fail on this because the editor will still work without this
    // system. We just let the user know that the feature is not available.
    if (editor_settings.auto_backup) {
        if (editor_settings.backup_interval > 0) {
            // Avoid any issues with overflows.
            u32 backup_interval = CAST(u32, editor_settings.backup_interval)*1000;
            if (CAST(u64, editor_settings.backup_interval)*1000 > INT_MAX) {
                backup_interval = INT_MAX;
            }

            editor.backup_timer = SDL_AddTimer(backup_interval, internal__backup_callback, NULL);
            if (!editor.backup_timer) {
                LOG_ERROR(ERR_MED, "Failed to setup backup timer system! (%s)", SDL_GetError());
            }
        }
    }
}

FILDEF void set_current_tab (size_t _index)
{
    // If there are no tabs then there is nothing to set.
    if (editor.tabs.empty()) { return; }

    if (_index >= editor.tabs.size()) {
        _index = editor.tabs.size()-1;
    }

    editor.current_tab = _index;

    // Update the title of the actual window.
    set_main_window_subtitle_for_tab(get_current_tab().name);

    maybe_scroll_tab_bar();
}

FILDEF Tab& get_current_tab ()
{
    return editor.tabs.at(editor.current_tab);
}

FILDEF Tab& get_tab_at_index (size_t _index)
{
    if (_index >= editor.tabs.size()) { _index = editor.tabs.size()-1; }
    return editor.tabs.at(_index);
}

FILDEF bool are_there_any_tabs ()
{
    return !editor.tabs.empty();
}

FILDEF void increment_tab ()
{
    if (are_there_any_tabs()) {
        ++editor.current_tab;
        if (editor.current_tab >= editor.tabs.size()) {
            editor.current_tab = 0;
        }
        maybe_scroll_tab_bar();
    }
}
FILDEF void decrement_tab ()
{
    if (are_there_any_tabs()) {
        --editor.current_tab;
        if (editor.current_tab == CAST(size_t, -1)) {
            editor.current_tab = editor.tabs.size()-1;
        }
        maybe_scroll_tab_bar();
    }
}

FILDEF void set_main_window_subtitle_for_tab (const std::string& _subtitle)
{
    set_main_window_subtitle((_subtitle.empty()) ? "Untitled" : _subtitle.c_str());
}

FILDEF bool are_there_any_level_tabs ()
{
    for (auto tab: editor.tabs) {
        if (tab.type == TAB_TYPE_LEVEL) {
            return true;
        }
    }
    return false;
}
FILDEF bool are_there_any_map_tabs ()
{
    for (auto tab: editor.tabs) {
        if (tab.type == TAB_TYPE_MAP) {
            return true;
        }
    }
    return false;
}

FILDEF void create_new_level_tab_and_focus (int _w, int _h)
{
    Tab& tab = internal__create_new_tab_and_focus(TAB_TYPE_LEVEL);

    // Level-specific initialization stuff.
    for (auto& active: tab.tile_layer_active) { active = true; }
    tab.level_history.current_position = -1;
    tab.tool_info.select.cached_size   =  0;
    create_blank_level(tab.level, _w, _h);
}
FILDEF void create_new_map_tab_and_focus ()
{
    Tab& tab = internal__create_new_tab_and_focus(TAB_TYPE_MAP);

    // Map-specific initialization stuff.
    tab.map_history.current_position = -1;
    new_map_history_state(tab.map);
}

FILDEF bool current_tab_is_level ()
{
    if (!are_there_any_tabs()) { return false; }
    return (get_current_tab().type == TAB_TYPE_LEVEL);
}
FILDEF bool current_tab_is_map ()
{
    if (!are_there_any_tabs()) { return false; }
    return (get_current_tab().type == TAB_TYPE_MAP);
}

FILDEF void close_tab (size_t _index)
{
    if (_index >= editor.tabs.size()) { return; } // Out of bounds!
    if (save_changes_prompt(editor.tabs.at(_index)) == ALERT_RESULT_CANCEL) { return; }

    editor.tabs.erase(editor.tabs.begin()+_index);

    // If this is the case then there are no more tabs left.
    if (editor.tabs.empty()) {
        editor.current_tab = CAST(size_t, -1);
        set_main_window_subtitle(NULL);
    } else {
        // Ensure that the current tab value stays within the bounds.
        if (editor.current_tab >= editor.tabs.size()) {
            editor.current_tab = editor.tabs.size()-1;
        }

        set_main_window_subtitle_for_tab(get_current_tab().name);
    }
}
FILDEF void close_current_tab ()
{
    if (!are_there_any_tabs()) { return; }
    else { close_tab(editor.current_tab); }
}
FILDEF void close_all_tabs ()
{
    if (!are_there_any_tabs()) { return; }
    while (!editor.tabs.empty()) { close_tab(0); }
}

FILDEF void push_editor_camera_transform ()
{
    const Tab& tab = get_current_tab();

    push_matrix(MATRIX_MODE_PROJECTION);
    push_matrix(MATRIX_MODE_MODELVIEW);

    float hw = get_viewport().w / 2.0f;
    float hh = get_viewport().h / 2.0f;

    float hsw = (get_viewport().w / tab.camera.zoom) / 2.0f;
    float hsh = (get_viewport().h / tab.camera.zoom) / 2.0f;

    float l = hw - hsw;
    float r = hw + hsw;
    float b = hh + hsh;
    float t = hh - hsh;

    set_orthographic(l, r, b, t);

    translate(tab.camera.x, tab.camera.y);
}
FILDEF void pop_editor_camera_transform ()
{
    pop_matrix(MATRIX_MODE_PROJECTION);
    pop_matrix(MATRIX_MODE_MODELVIEW);
}

FILDEF int save_changes_prompt (Tab& _tab)
{
    // Prompts user to save changes before permanently losing a level/map.
    // If there are no unsaved changes then the prompt is not presented.
    if (!_tab.unsaved_changes) { return ALERT_RESULT_NULL; }

    std::string tab_name((_tab.name.empty()) ? "Untitled" : strip_file_path(_tab.name.c_str()));
    std::string msg(format_string("'%s' has unsaved changes!\nWould you like to save?", tab_name.c_str()));
    int result = show_alert("Unsaved Changes", msg.c_str(), ALERT_TYPE_WARNING, ALERT_BUTTON_YES_NO_CANCEL, "WINMAIN");
    if (result == ALERT_RESULT_YES) {
        // The save was cancelled or there was an error so we cancel the action
        // the user was going to perform in order to maintain the level/map data.
        switch (_tab.type) {
        case (TAB_TYPE_LEVEL): { if (!le_save     (_tab)) { return ALERT_RESULT_CANCEL; } } break;
        case (TAB_TYPE_MAP  ): { if (!save_map_tab(_tab)) { return ALERT_RESULT_CANCEL; } } break;
        }
    }

    // Return the result in case caller wants to handle.
    return result;
}

FILDEF void backup_tab (Tab& _tab)
{
    switch (_tab.type) {
    case (TAB_TYPE_LEVEL): { backup_level_tab(_tab.level, _tab.name); } break;
    case (TAB_TYPE_MAP  ): { backup_map_tab  (_tab.map,   _tab.name); } break;
    }
}

FILDEF bool is_current_tab_empty ()
{
    if (are_there_any_tabs()) {
        const Tab& tab = get_current_tab();
        if (tab.type == TAB_TYPE_LEVEL) {
            return is_current_level_empty();
        } else {
            return is_current_map_empty();
        }
    }
    return false;
}

FILDEF void editor_select_all ()
{
    if (!are_there_any_tabs()) { return; }
    Tab& tab = get_current_tab();
    switch (tab.type) {
    case (TAB_TYPE_LEVEL): { le_select_all(); } break;
    case (TAB_TYPE_MAP  ): { me_select_all(); } break;
    }
}

FILDEF void editor_paste ()
{
    if (!are_there_any_tabs()) { return; }
    Tab& tab = get_current_tab();
    switch (tab.type) {
    case (TAB_TYPE_LEVEL): { le_paste(); } break;
    case (TAB_TYPE_MAP  ): { me_paste(); } break;
    }
}
