FILDEF void internal__delete_old_crash_dumps ()
{
    // Crash dumps can be extremely large so if there are any dumps in the crash dump folder that are
    // older than 30 days then we delete them out of courtesy to free up space on the user's drive.

    LOG_DEBUG("Looking for old crash dumps to delete...");

    try
    {
        std::string crash_dump_path(get_appdata_path() + CRASH_DUMP_PATH);
        std::vector<std::string> to_remove;
        if (does_path_exist(crash_dump_path))
        {
            for (auto& p: std::filesystem::directory_iterator(crash_dump_path))
            {
                if (p.path().extension() == ".dmp")
                {
                    auto then = std::filesystem::last_write_time(p);
                    auto now = decltype(then)::clock::now();
                    int days = std::chrono::duration_cast<std::chrono::hours>(now-then).count()/24; // Days wasn't added until C++20 so we don't have it...
                    if (days >= 30) to_remove.push_back(p.path().string());
                }
            }
        }
        if (!to_remove.empty())
        {
            for (auto& file: to_remove)
            {
                LOG_DEBUG("Removing dump: %s", strip_file_path(file).c_str());
                std::filesystem::remove(file);
            }
        }
        else
        {
            LOG_DEBUG("No crash dumps to delete!");
        }
    }
    catch (std::filesystem::filesystem_error& e)
    {
        LOG_ERROR(ERR_MIN, "Failed to delete old crash dumps: %s", e.what());
    }
}

FILDEF void internal__dump_debug_application_info ()
{
    std::string drives = get_drive_names();
    LOG_DEBUG("Available Drives:");
    int drive_index = 0;
    for (auto& drive: drives)
    {
        LOG_DEBUG("%d: %c:\\", drive_index, drive);
        drive_index++;
    }

    int num_display_modes = SDL_GetNumVideoDisplays();
    if (num_display_modes > 0)
    {
        LOG_DEBUG("Available Displays:");
        for (int i=0; i<num_display_modes; ++i)
        {
            SDL_DisplayMode display_mode = {};
            if (SDL_GetCurrentDisplayMode(i, &display_mode) == 0)
            {
                const char* name = SDL_GetDisplayName(i);
                int w            = display_mode.w;
                int h            = display_mode.h;
                int hz           = display_mode.refresh_rate;
                LOG_DEBUG("%d: %s %dx%d@%dHz", i, name, w,h, hz);
            }
        }
    }

    int num_video_drivers = SDL_GetNumVideoDrivers();
    if (num_video_drivers > 0)
    {
        LOG_DEBUG("Available Drivers:");
        for (int i=0; i<num_video_drivers; ++i)
        {
            const char* name = SDL_GetVideoDriver(i);
            LOG_DEBUG("%d: %s", i, name);
        }
    }
}

FILDEF void init_application (int argc, char** argv)
{
    {
        begin_debug_timer("Initialization");
        defer { end_debug_timer(); };

        // We set this here at program start so any fatal calls to LOG_ERROR can
        // set this to false and we will never enter the main application loop.
        main_running = true;

        LOG_DEBUG("[[Initialization]]");
        LOG_DEBUG("%s v%d.%d.%d (%s) - %s", APP_TITLE, APP_VER_MAJOR,APP_VER_MINOR,APP_VER_PATCH, APP_BUILD, APP_ARCH);

        u32 sdl_flags = SDL_INIT_VIDEO|SDL_INIT_TIMER;
        if (SDL_Init(sdl_flags) == 0)
            LOG_DEBUG("Initialized SDL v%d.%d.%d", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
        else
        {
            LOG_ERROR(ERR_MAX, "Failed to initialize SDL! (%s)", SDL_GetError());
            return;
        }

        if (FT_Init_FreeType(&freetype) == 0)
            LOG_DEBUG("Initialized FreeType v%d.%d.%d", FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
        else
        {
            LOG_ERROR(ERR_MAX, "Failed to initialize FreeType2!");
            return;
        }

        LOG_DEBUG("Executable Location: %s", get_executable_path().c_str());
        LOG_DEBUG("AppData Location: %s", get_appdata_path().c_str());

        get_resource_location();

        setup_crash_handler();

        internal__dump_debug_application_info();

        internal__delete_old_crash_dumps();

        if (!init_resource_manager()) { LOG_ERROR(ERR_MAX, "Failed to setup the resource manager!"); return; }
        if (!init_ui_system       ()) { LOG_ERROR(ERR_MAX, "Failed to setup the UI system!"       ); return; }
        if (!init_window          ()) { LOG_ERROR(ERR_MAX, "Failed to setup the window system!"   ); return; }

        if (!create_window("Preferences", "Preferences"     , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 570,480, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create preferences window!" ); return; }
        if (!create_window("ColorPicker", "Color Picker"    , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 250,302, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create color picker window!"); return; }
        if (!create_window("New"        , "New"             , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 230,126, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create new window!"         ); return; }
        if (!create_window("Resize"     , "Resize"          , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 230,200, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create resize window!"      ); return; }
        if (!create_window("About"      , "About"           , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 440, 96, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create about window!"       ); return; }
        if (!create_window("Unpack"     , "Unpack"          , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 360, 80, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create GPAK unpack window!" ); return; }
        if (!create_window("Pack"       , "Pack"            , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 360, 80, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create GPAK unpack window!" ); return; }
        if (!create_window("LoadGame"   , "Locate Game"     , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 440,100, 0,0, SDL_WINDOW_SKIP_TASKBAR)) { LOG_ERROR(ERR_MAX, "Failed to create path window!"        ); return; }

        get_window("Preferences"). close_callback = []() { cancel_preferences    (); };
        get_window("ColorPicker"). close_callback = []() { cancel_color_picker   (); };
        get_window("New"        ). close_callback = []() { cancel_new            (); };
        get_window("Resize"     ). close_callback = []() { cancel_resize         (); };
        get_window("About"      ). close_callback = []() { hide_window("About"    ); };
        get_window("Unpack"     ). close_callback = []() { cancel_unpack         (); };
        get_window("Pack"       ). close_callback = []() { cancel_pack           (); };
        get_window("LoadGame"   ). close_callback = []() { cancel_path           (); };
        get_window("Main"       ).resize_callback = []() { do_application        (); };

        make_window_a_child("Preferences");
        make_window_a_child("ColorPicker");
        make_window_a_child("New");
        make_window_a_child("Resize");
        make_window_a_child("About");
        make_window_a_child("Unpack");
        make_window_a_child("Pack");
        make_window_a_child("LoadGame");

        if (!init_renderer           ()) { LOG_ERROR(ERR_MAX, "Failed to setup the renderer!"      ); return; }
        if (!load_editor_settings    ()) { LOG_ERROR(ERR_MED, "Failed to load editor settings!"    );         }
        if (!load_editor_key_bindings()) { LOG_ERROR(ERR_MED, "Failed to load editor key bindings!");         }
        if (!load_editor_resources   ()) { LOG_ERROR(ERR_MAX, "Failed to load editor resources!"   ); return; }
        if (!init_tile_panel         ()) { LOG_ERROR(ERR_MAX, "Failed to setup the tile panel!"    ); return; }

        init_layer_panel   ();
        init_color_picker  ();
        init_palette_lookup();

        init_editor(argc, argv);

        // Now that setup has been complete we can show the complete window.
        // See the 'window.hpp' file for why we initially hide the window.
        //
        // We don't bother showing if any of the setup functions resulted in
        // a fatal failure as it would look ugly to briefly flash the window.
        if (main_running) show_main_window();

        // We do this so we do an extra redraw on start-up making sure certain
        // things end up being initialized/setup. This fixes the scrollbars
        // appearing in the control panel sub-panels when they are not needed.
        should_push_ui_redraw_event = true;
    }

    dump_editor_settings();
    dump_editor_key_bindings();

    LOG_DEBUG("");
    LOG_DEBUG("[[Session]]");
    LOG_DEBUG("Session Start Time: %s", format_time("%m/%d/%Y %H:%M:%S").c_str());
}

FILDEF void quit_application ()
{
    quit_editor();

    free_editor_cursors();
    free_editor_resources();

    quit_renderer();
    quit_window();

    quit_debug_system();
    quit_error_system();

    FT_Done_FreeType(freetype);
    SDL_Quit();
}

FILDEF void do_application ()
{
    set_render_target(&get_window("Main"));
    set_viewport(0, 0, get_render_target_w(), get_render_target_h());

    render_clear(ui_color_medium);

    quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2);

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    do_hotbar();

    p2.x =                           1;
    p2.y = HOTBAR_HEIGHT           + 1;
    p2.w = get_viewport().w        - 2;
    p2.h = get_viewport().h - p2.y - 1;

    begin_panel(p2, UI_NONE);

    do_control_panel();
    do_toolbar();
    do_tab_bar();
    do_editor();
    do_status_bar();

    end_panel();
    end_panel();

    do_tooltip();

    render_present();

    if (!is_window_hidden("Preferences"))
    {
        set_render_target(&get_window("Preferences"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_preferences_menu();
        render_present();
    }

    if (!is_window_hidden("ColorPicker"))
    {
        set_render_target(&get_window("ColorPicker"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_color_picker();
        render_present();
    }

    if (!is_window_hidden("About"))
    {
        set_render_target(&get_window("About"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_about();
        render_present();
    }

    if (!is_window_hidden("New"))
    {
        set_render_target(&get_window("New"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_new();
        render_present();
    }

    if (!is_window_hidden("Resize"))
    {
        set_render_target(&get_window("Resize"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_resize();
        render_present();
    }

    if (!is_window_hidden("Unpack"))
    {
        set_render_target(&get_window("Unpack"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_unpack();
        render_present();
    }

    if (!is_window_hidden("Pack"))
    {
        set_render_target(&get_window("Pack"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_pack();
        render_present();
    }

    if (!is_window_hidden("LoadGame"))
    {
        set_render_target(&get_window("LoadGame"));
        set_viewport(0, 0, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_path();
        render_present();
    }

    // IMPORTANT: Otherwise the UI will not redraw very well!
    if (should_push_ui_redraw_event)
    {
        push_editor_event(EDITOR_EVENT_UI_REDRAW, NULL, NULL);
        should_push_ui_redraw_event = false;
    }
}

FILDEF bool handle_application_events ()
{
    // We wait for events so we don't waste CPU and GPU power.
    if (!SDL_WaitEvent(&main_event))
    {
        LOG_ERROR(ERR_MED, "Error waiting for events! (%s)", SDL_GetError());
        return false;
    }

    reset_ui_state();

    // We need to poll events afterwards so that we can process
    // multiple events that may have occurred on the same frame.
    do
    {
        if (main_event.type == SDL_QUIT)
        {
            main_running = false;
        }

        #if defined(BUILD_DEBUG)
        generate_texture_atlases();
        pack_textures();
        #endif

        handle_window_events();
        handle_key_binding_events();
        handle_ui_events();
        handle_tile_panel_events();
        handle_tab_bar_events();
        handle_editor_events();
        handle_preferences_menu_events();
        handle_color_picker_events();
        handle_new_events();
        handle_resize_events();
        handle_tooltip_events();
        handle_about_events();
        handle_path_events();
    }
    while (SDL_PollEvent(&main_event));

    return true;
}
