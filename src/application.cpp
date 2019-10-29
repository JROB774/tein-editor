#include "utility.cpp"
#include "debug.cpp"
#include "error.cpp"
#include "custom_events.cpp"
#include "window.cpp"
#include "cursor.cpp"
#include "key_bindings.cpp"
#include "settings.cpp"
#include "texture.cpp"
#include "texture_atlas.cpp"
#include "texture_pack.cpp"
#include "font.cpp"
#include "shader.cpp"
#include "renderer.cpp"
#include "resource_manager.cpp"
#include "user_interface.cpp"
#include "level.cpp"
#include "map.cpp"
#include "gpak.cpp"
#include "hotbar.cpp"
#include "toolbar.cpp"
#include "tooltip.cpp"
#include "tile_panel.cpp"
#include "layer_panel.cpp"
#include "control_panel.cpp"
#include "new_dialog.cpp"
#include "resize_dialog.cpp"
#include "path_dialog.cpp"
#include "tab_bar.cpp"
#include "palette.cpp"
#include "level_editor.cpp"
#include "map_editor.cpp"
#include "editor.cpp"
#include "status_bar.cpp"
#include "color_picker.cpp"
#include "preferences_menu.cpp"
#include "about.cpp"

GLOBAL constexpr const char* ERR_ERROR    = "Failed to setup the error system!";
GLOBAL constexpr const char* ERR_HOTLOAD  = "Failed to setup the hotloader!";
GLOBAL constexpr const char* ERR_RESMNGR  = "Failed to setup the resource manager!";
GLOBAL constexpr const char* ERR_UI       = "Failed to setup the UI system!";
GLOBAL constexpr const char* ERR_WINDOW   = "Failed to setup the window!";
GLOBAL constexpr const char* ERR_RENDERER = "Failed to setup the renderer!";
GLOBAL constexpr const char* ERR_TILES    = "Failed to setup the tile panel!";

GLOBAL constexpr const char* ERR_SETTINGS = "Failed to load editor settings!";
GLOBAL constexpr const char* ERR_KEYBINDS = "Failed to load editor key bindings!";
GLOBAL constexpr const char* ERR_RESOURCE = "Failed to load editor resources!";
GLOBAL constexpr const char* ERR_CURSORS  = "Failed to load editor cursors!";

FILDEF void init_application (int _argc, char** _argv)
{
    begin_debug_timer("init_application");

    // We set this here at program start so any fatal calls to LOG_ERROR can
    // set this to false and we will never enter the main application loop.
    main_running = true;

    get_resource_location();

    begin_debug_section("Editor:");
    LOG_DEBUG("Version %d.%d.%d", EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH);
    #if defined(DEBUG_BUILD)
    LOG_DEBUG("Build: Debug");
    #else
    LOG_DEBUG("Build: Release");
    #endif
    end_debug_section();

    begin_debug_section("Initialization:");

    // We short-circuit on these because initialization of certain systems
    // may depend on previous systems to be correctly setup. So if one of
    // these fails it is safer to abort this function as soon as possible.
    //
    // For any non-essential systems (e.g. Hotloading) we just display an
    // error instead and carry on with the initialization of the program.
    if (!init_error_system()) { LOG_ERROR(ERR_MAX, ERR_ERROR); return; }

    u32 sdl_flags = SDL_INIT_VIDEO|SDL_INIT_TIMER;
    if (SDL_Init(sdl_flags) != 0) {
        LOG_ERROR(ERR_MAX, "Failed to initialize SDL! (%s)", SDL_GetError());
        return;
    }
    LOG_DEBUG("Initialized SDL2 Library");
    if (FT_Init_FreeType(&freetype) != 0) {
        LOG_ERROR(ERR_MAX, "Failed to initialize FreeType!");
        return;
    }
    LOG_DEBUG("Initialized FreeType2 Library");

    SDL_StartTextInput();

    // DUMP DEBUG INFO //////////////////////////////////////////////
    int num_display_modes = SDL_GetNumVideoDisplays();
    int num_video_drivers = SDL_GetNumVideoDrivers();

    LOG_DEBUG("Platform: %s", SDL_GetPlatform());
    if (num_display_modes > 0) {
        begin_debug_section("Displays:");
        for (int i=0; i<num_display_modes; ++i) {
            SDL_DisplayMode display_mode = {};
            if (SDL_GetCurrentDisplayMode(i, &display_mode) == 0) {
                const char* name = SDL_GetDisplayName(i);
                int w            = display_mode.w;
                int h            = display_mode.h;
                int hz           = display_mode.refresh_rate;
                LOG_DEBUG("(%d) %s %dx%d %dHz", i, name, w, h, hz);
            }
        }
        end_debug_section();
    }
    if (num_video_drivers > 0) {
        begin_debug_section("Drivers:");
        for (int i=0; i<num_video_drivers; ++i) {
            const char* name = SDL_GetVideoDriver(i);
            LOG_DEBUG("(%d) %s", i, name);
        }
        end_debug_section();
    }
    // DUMP DEBUG INFO //////////////////////////////////////////////

    if (!init_resource_manager()) { LOG_ERROR(ERR_MAX, ERR_RESMNGR ); return; }
    if (!init_ui_system       ()) { LOG_ERROR(ERR_MAX, ERR_UI      ); return; }
    if (!init_window          ()) { LOG_ERROR(ERR_MAX, ERR_WINDOW  ); return; }

    if (!create_window("WINPREFERENCES", "Preferences", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 570,480, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create preferences window!"); return;
    }
    if (!create_window("WINCOLOR", "Color Picker", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 250,302, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create color picker window!"); return;
    }
    if (!create_window("WINNEW", "New", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 230,126, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create new window!"); return;
    }
    if (!create_window("WINRESIZE", "Resize", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 230,200, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create resize window!"); return;
    }
    if (!create_window("WINABOUT", "About", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 440,96, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create about window!"); return;
    }
    if (!create_window("WINUNPACK", "Unpack", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 360, 80, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create GPAK unpack window!"); return;
    }
    if (!create_window("WINPACK", "Pack", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 360,80, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create GPAK unpack window!"); return;
    }
    if (!create_window("WINPATH", "Locate Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 440,100, 0,0, SDL_WINDOW_SKIP_TASKBAR)) {
        LOG_ERROR(ERR_MAX, "Failed to create path window!"); return;
    }

    get_window("WINPREFERENCES"). close_callback = []() { cancel_preferences   (); };
    get_window("WINCOLOR"      ). close_callback = []() { cancel_color_picker  (); };
    get_window("WINNEW"        ). close_callback = []() { cancel_new           (); };
    get_window("WINRESIZE"     ). close_callback = []() { cancel_resize        (); };
    get_window("WINABOUT"      ). close_callback = []() { hide_window("WINABOUT"); };
    get_window("WINUNPACK"     ). close_callback = []() { cancel_unpack        (); };
    get_window("WINPACK"       ). close_callback = []() { cancel_pack          (); };
    get_window("WINPATH"       ). close_callback = []() { cancel_path          (); };
    get_window("WINMAIN"       ).resize_callback = []() { do_application       (); };

    set_window_child("WINPREFERENCES");
    set_window_child("WINCOLOR");
    set_window_child("WINNEW");
    set_window_child("WINRESIZE");
    set_window_child("WINABOUT");
    set_window_child("WINUNPACK");
    set_window_child("WINPACK");
    set_window_child("WINPATH");

    if (!init_renderer           ()) { LOG_ERROR(ERR_MAX, ERR_RENDERER); return; }

    if (!load_editor_settings    ()) { LOG_ERROR(ERR_MED, ERR_SETTINGS);         }
    if (!load_editor_key_bindings()) { LOG_ERROR(ERR_MED, ERR_KEYBINDS);         }

    if (!load_editor_resources   ()) { LOG_ERROR(ERR_MAX, ERR_RESOURCE); return; }
    if (!init_tile_panel         ()) { LOG_ERROR(ERR_MAX, ERR_TILES   ); return; }

    init_layer_panel   ();
    init_color_picker  ();
    init_palette_lookup();

    init_editor(_argc, _argv);

    // Now that setup has been complete we can show the complete window.
    // See the 'window.hpp' file for why we initially hide the window.
    //
    // We don't bother showing if any of the setup functions resulted in
    // a fatal failure as it would look ugly to briefly flash the window.
    if (main_running) { show_window("WINMAIN"); }

    // We do this so we do an extra redraw on start-up making sure certain
    // things end up being initialized/setup. This fixes the scrollbars
    // appearing in the control panel sub-panels when they are not needed.
    should_push_ui_redraw_event = true;

    end_debug_section();

    end_debug_timer();
    dump_debug_timer_results();
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

    SDL_StopTextInput();

    FT_Done_FreeType(freetype);
    SDL_Quit();
}

FILDEF void do_application ()
{
    clear_debug_timer_results();
    defer { dump_debug_timer_results(); };

    ////////////////////////////////////////

    set_render_target(&get_window("WINMAIN"));
    set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());

    render_clear(ui_color_medium);

    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    do_hotbar();

    p2.x =                           1.0f;
    p2.y = HOTBAR_HEIGHT           + 1.0f;
    p2.w = get_viewport().w        - 2.0f;
    p2.h = get_viewport().h - p2.y - 1.0f;

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

    ////////////////////////////////////////

    if (!is_window_hidden("WINPREFERENCES")) {
        set_render_target(&get_window("WINPREFERENCES"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_preferences_menu();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINCOLOR")) {
        set_render_target(&get_window("WINCOLOR"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_color_picker();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINABOUT")) {
        set_render_target(&get_window("WINABOUT"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_about();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINNEW")) {
        set_render_target(&get_window("WINNEW"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_new();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINRESIZE")) {
        set_render_target(&get_window("WINRESIZE"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_resize();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINUNPACK")) {
        set_render_target(&get_window("WINUNPACK"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_unpack();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINPACK")) {
        set_render_target(&get_window("WINPACK"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_pack();
        render_present();
    }

    ////////////////////////////////////////

    if (!is_window_hidden("WINPATH")) {
        set_render_target(&get_window("WINPATH"));
        set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
        render_clear(ui_color_medium);
        do_path();
        render_present();
    }

    ////////////////////////////////////////


    // IMPORTANT: Otherwise the UI will not redraw very well!
    if (should_push_ui_redraw_event) {
        push_editor_event(EDITOR_EVENT_UI_REDRAW);
        should_push_ui_redraw_event = false;
    }

    ////////////////////////////////////////
}

FILDEF bool handle_application_events ()
{
    // We wait for events so we don't waste CPU and GPU power.
    if (!SDL_WaitEvent(&main_event)) {
        LOG_ERROR(ERR_MED, "Error waiting for events! (%s)", SDL_GetError());
        return false;
    }

    reset_ui_state();

    // We need to poll events afterwards so that we can process
    // multiple events that may have occurred on the same frame.
    do {
        if (main_event.type == SDL_QUIT) { main_running = false; }

        // Debug stuff (not shipped in release).
        generate_texture_atlases();
        pack_textures();

        handle_window_events();
        handle_key_binding_events();
        handle_ui_events();
        handle_tile_panel_events();
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
