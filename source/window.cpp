GLOBAL constexpr const char* WINDOW_STATE_FILE_NAME = "window.dat";

GLOBAL std::vector<std::string> restore_list;
GLOBAL std::map<std::string, Window> windows;

GLOBAL std::thread::id main_thread_id;
GLOBAL bool           window_resizing;
GLOBAL bool        from_manual_resize; // Hack used to solve a stupid flashing window bug with the New/Resize window.

FILDEF bool internal__are_any_subwindows_open ()
{
    for (auto it: windows)
    {
        if (it.first != "Main" && !is_window_hidden(it.first)) return true;
    }
    return false;
}

FILDEF void internal__push_quit_event ()
{
    SDL_Event e;
    SDL_zero(e);

    e.type           = SDL_QUIT;
    e.quit.type      = SDL_QUIT;
    e.quit.timestamp = SDL_GetTicks();

    SDL_PushEvent(&e);
}

STDDEF int internal__resize_window (void* main_window_thread_id, SDL_Event* event)
{
    // We only care about window resizing events, ignore everything else!
    if (event->type == SDL_WINDOWEVENT)
    {
        if (event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED ||
            event->window.event == SDL_WINDOWEVENT_RESIZED)
        {
            Window& window = get_window_from_id(event->window.windowID);

            float old_width  = window.width;
            float old_height = window.height;
            window.width     = CAST(float, event->window.data1);
            window.height    = CAST(float, event->window.data2);

            // If not on main thread leave early as it would be unsafe otherwise.
            // See the top of the init_window() function for a clear explanation.
            if (*CAST(std::thread::id*, main_window_thread_id) == get_thread_id())
            {
                // Force a redraw on resize, which looks nicer than the usual glitchy
                // looking screen content when a program's window is usually resized.
                window_resizing = true;
                if (!from_manual_resize)
                {
                    if (window.resize_callback)
                    {
                        if (old_width  != CAST(float, event->window.data1) ||
                            old_height != CAST(float, event->window.data2))
                        {
                            window.resize_callback();
                        }
                    }
                }
                else
                {
                    from_manual_resize = false;
                }
                window_resizing = false;
            }
        }
    }

    return 0;
}

FILDEF void internal__load_window_state ()
{
    LOG_DEBUG("Loading previous window state...");

    std::string window_state_file_name(get_appdata_path() + WINDOW_STATE_FILE_NAME);
    if (!does_file_exist(window_state_file_name))
    {
        LOG_DEBUG("No previous window state!");
        return;
    }

    GonObject gon = GonObject::Load(window_state_file_name);

    int x = MAIN_WINDOW_X;
    int y = MAIN_WINDOW_Y;
    int w = MAIN_WINDOW_BASE_W;
    int h = MAIN_WINDOW_BASE_H;

    if (gon.Contains("bounds"))
    {
        if (gon["bounds"].size() >= 1) x = gon["bounds"][0].Int(MAIN_WINDOW_X);
        if (gon["bounds"].size() >= 2) y = gon["bounds"][1].Int(MAIN_WINDOW_Y);
        if (gon["bounds"].size() >= 3) w = gon["bounds"][2].Int(MAIN_WINDOW_BASE_W);
        if (gon["bounds"].size() >= 4) h = gon["bounds"][3].Int(MAIN_WINDOW_BASE_H);
    }

    SDL_Window* win = windows.at("Main").window;
    SDL_Rect display_bounds;
    if (SDL_GetDisplayBounds(gon["display_index"].Int(0), &display_bounds) < 0)
    {
        LOG_DEBUG("Previous display not found, aborting window restore!");
        return;
    }

    // Make sure the window is not out of bounds at all.
    if (x != MAIN_WINDOW_X && x < display_bounds.x) x = display_bounds.x;
    if (x != MAIN_WINDOW_X && (x+w) >= display_bounds.w) x = display_bounds.w - w;
    if (y != MAIN_WINDOW_Y && y < display_bounds.y) y = display_bounds.y;
    if (y != MAIN_WINDOW_Y && (y+h) >= display_bounds.h) y = display_bounds.h - h;

    set_window_size("Main", w,h);
    set_window_pos("Main", x,y);

    bool maximized = gon["maximized"].Bool(false);
    if (maximized)
    {
        SDL_MaximizeWindow(win);
    }

    LOG_DEBUG("Restored window state: %dx%d %dx%d (%s)", x,y, w,h, (maximized) ? "Maximized" : "Default");
}
FILDEF void internal__save_window_state ()
{
    SDL_Window* win = windows.at("Main").window;

    int x = MAIN_WINDOW_X, y = MAIN_WINDOW_Y, w = MAIN_WINDOW_BASE_W, h = MAIN_WINDOW_BASE_H;
    int display_index = SDL_GetWindowDisplayIndex(win);
    int maximized = SDL_GetWindowFlags(win) & SDL_WINDOW_MAXIMIZED;

    // We do restore window so we ge the actual window pos and size.
    SDL_RestoreWindow(win);

    SDL_GetWindowPosition(win, &x,&y);
    SDL_GetWindowSize(win, &w,&h);

    std::string window_state_file_name(get_appdata_path() + WINDOW_STATE_FILE_NAME);
    std::ofstream file(window_state_file_name, std::ios::out|std::ios::trunc);
    if (file.is_open())
    {
        file << "bounds [ " << x << " " << y << " " << w << " " << h << " ]\n";
        file << "display_index " << display_index << "\n";
        file << "maximized " << ((maximized) ? "true" : "false") << "\n";
    }
}

STDDEF bool create_window (std::string name, std::string title, int x, int y, int w, int h, int min_w, int min_h, u32 flags)
{
    LOG_DEBUG("Creating window: %s", name.c_str());

    if (windows.find(name) != windows.end())
    {
        LOG_ERROR(ERR_MAX, "Window with name \"%s\" already exists!", name.c_str());
        return false;
    }

    windows.insert(std::pair<std::string, Window>(name, Window()));
    Window& window = windows.at(name);

    // These are the required flags for all of our application sub-windows.
    flags |= (SDL_WINDOW_HIDDEN|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_OPENGL);
    window.window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if (!window.window)
    {
        LOG_ERROR(ERR_MIN, "Failed to create window! (%s)", SDL_GetError());
        return false;
    }

    window.id = SDL_GetWindowID(window.window);
    if (!window.id)
    {
        LOG_ERROR(ERR_MIN, "Failed to get window ID! (%s)", SDL_GetError());
        return false;
    }

    // Only set a minimum size if both values are a valid size.
    if (min_w && min_h)
    {
        set_window_min_size(name, min_w, min_h);
    }

    // We use SDL_GetWindowSize to cache the final size of a window in case
    // any flags such as SDL_WINDOW_MAXIMIZED were used on window creation.
    int final_width;
    int final_height;

    SDL_GetWindowSize(window.window, &final_width, &final_height);

    window.width  = CAST(float, final_width);
    window.height = CAST(float, final_height);

    // Default to false and it will get handled by the window event system.
    window.focus = false;
    window.mouse = false;

    return true;
}

FILDEF bool is_window_hidden (std::string name)
{
    return (SDL_GetWindowFlags(windows.at(name).window) & SDL_WINDOW_HIDDEN);
}

FILDEF bool is_window_focused (std::string name)
{
    return windows.at(name).focus;
}

FILDEF void show_window (std::string name)
{
    set_window_pos(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(windows.at(name).window);
}

FILDEF void raise_window (std::string name)
{
    SDL_RaiseWindow(windows.at(name).window);
}

FILDEF void hide_window (std::string name)
{
    SDL_HideWindow(windows.at(name).window);
}

FILDEF void set_window_title (std::string name, std::string title)
{
    SDL_SetWindowTitle(windows.at(name).window, title.c_str());
}

FILDEF void set_window_min_size (std::string name, int w, int h)
{
    SDL_SetWindowMinimumSize(windows.at(name).window, w, h);
}

FILDEF void set_window_max_size (std::string name, int w, int h)
{
    SDL_SetWindowMaximumSize(windows.at(name).window, w, h);
}

FILDEF void set_window_pos (std::string name, int x, int y)
{
    SDL_SetWindowPosition(windows.at(name).window, x, y);
}

FILDEF void set_window_size (std::string name, int w, int h)
{
    SDL_SetWindowSize(windows.at(name).window, w, h);
}

FILDEF bool init_window ()
{
    // The SDL docs say that event watchers can potentially be called on a
    // separate thread this means that, if this is the case, the redraw on
    // resize is potentially unstable. As a result, we pass in the ID for
    // the main thread and then when in the resize handler check to see if
    // its thread ID is the same -- if it is then we can redraw safely.
    main_thread_id = get_thread_id();

    // We need different GL context flags and versions depending on the platform.
    #if defined(PLATFORM_WIN32)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    #elif defined(PLATFORM_OSX)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    #endif
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);

    #if defined(BUILD_DEBUG)
    std::string main_title(format_string("[DEBUG] %s (v%d.%d.%d)", MAIN_WINDOW_TITLE, APP_VER_MAJOR,APP_VER_MINOR,APP_VER_PATCH));
    #else
    std::string main_title(format_string("%s (v%d.%d.%d)", MAIN_WINDOW_TITLE, APP_VER_MAJOR,APP_VER_MINOR,APP_VER_PATCH));
    #endif // BUILD_DEBUG

    if (!create_window("Main", main_title, MAIN_WINDOW_X,MAIN_WINDOW_Y, MAIN_WINDOW_BASE_W,
        MAIN_WINDOW_BASE_H, MAIN_WINDOW_MIN_W,MAIN_WINDOW_MIN_H, MAIN_WINDOW_FLAGS))
    {
        LOG_ERROR(ERR_MAX, "Failed to create the main application window!");
        return false;
    }

    get_window("Main").close_callback = []()
    {
        internal__push_quit_event();
    };

    // This is a useful feature of SDL's that will allow us to redraw our
    // screen whilst it is being resized, which is much more aesthetically
    // appealing when compared to the usual garbage visuals on a resize.
    SDL_AddEventWatch(internal__resize_window, &main_thread_id);

    return true;
}

FILDEF void quit_window ()
{
    // Note: We remove this so when we SDL_RestoreWindow in internal__save_window_state
    // we don't end up invoking the resize handler function internal__resize_window.
    SDL_DelEventWatch(internal__resize_window, &main_thread_id);

    hide_window("Main");
    internal__save_window_state();

    for (auto it: windows) SDL_DestroyWindow(it.second.window);
    windows.clear();
}

FILDEF void handle_window_events ()
{
    if (main_event.type != SDL_WINDOWEVENT) return;

    std::string window_name = get_window_name_from_id(main_event.window.windowID);
    Window& window = get_window_from_id(main_event.window.windowID);

    switch (main_event.window.event)
    {
        case (SDL_WINDOWEVENT_FOCUS_GAINED):
        {
            // Special case for the main window to ensure all sub-windows stay on top of it.
            if (window_name == "Main" && internal__are_any_subwindows_open())
            {
                for (auto it: windows)
                {
                    if (it.first != "Main") raise_window(it.first);
                }
            }
            else
            {
                window.focus = true;
            }
        } break;
        case (SDL_WINDOWEVENT_FOCUS_LOST):
        {
            window.focus = false;
        } break;

        case (SDL_WINDOWEVENT_MINIMIZED):
        {
            if (window_name == "Main")
            {
                for (auto it: windows)
                {
                    if (it.first != "Main" && !is_window_hidden(it.first))
                    {
                        restore_list.push_back(it.first);
                        hide_window(it.first);
                    }
                }
            }
        } break;
        case (SDL_WINDOWEVENT_RESTORED):
        {
            if (window_name == "Main")
            {
                for (auto it: windows)
                {
                    if (it.first != "Main")
                    {
                        if (std::find(restore_list.begin(), restore_list.end(), it.first) != restore_list.end())
                        {
                            show_window(it.first);
                        }
                    }
                }
                restore_list.clear();
            }
        } break;

        case (SDL_WINDOWEVENT_CLOSE):
        {
            if (window.close_callback) window.close_callback();
        } break;

        case (SDL_WINDOWEVENT_ENTER):
        {
            window.mouse = true;
        } break;
        case (SDL_WINDOWEVENT_LEAVE):
        {
            window.mouse = false;
        } break;
    }
}

INLDEF void set_main_window_subtitle (std::string subtitle)
{
    #if defined(BUILD_DEBUG)
    std::string main_title(format_string("[DEBUG] %s (v%d.%d.%d)", MAIN_WINDOW_TITLE, APP_VER_MAJOR,APP_VER_MINOR,APP_VER_PATCH));
    #else
    std::string main_title(format_string("%s (v%d.%d.%d)", MAIN_WINDOW_TITLE, APP_VER_MAJOR,APP_VER_MINOR,APP_VER_PATCH));
    #endif

    if (!subtitle.empty())
    {
        main_title += " | ";
        main_title += subtitle;
    }

    SDL_SetWindowTitle(windows.at("Main").window, main_title.c_str());
}

FILDEF void show_main_window ()
{
    internal__load_window_state();
    SDL_ShowWindow(windows.at("Main").window);
}

FILDEF Window& get_focused_window ()
{
    for (auto& it: windows) if (it.second.focus) return it.second;
    return windows.at("Main");
}

FILDEF Window& get_window (std::string name)
{
    ASSERT(windows.find(name) != windows.end());
    return windows.at(name);
}

FILDEF Window& get_window_from_id (Window_ID id)
{
    for (auto& it: windows) if (it.second.id == id) return it.second;
    return windows.at("Main");
}

FILDEF Window_ID get_window_id (std::string name)
{
    return windows.at(name).id;
}

FILDEF std::string get_window_name_from_id (Window_ID id)
{
    for (auto& it: windows) if (it.second.id == id) return it.first;
    return std::string();
}

FILDEF bool is_a_window_resizing ()
{
    return window_resizing;
}
