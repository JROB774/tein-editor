namespace internal
{
    GLOBAL std::map<std::string, Window> windows;

    GLOBAL unsigned int main_thread_id;
    GLOBAL bool        window_resizing;
    GLOBAL bool     from_manual_resize; // Hack used to solve a stupid flashing window bug with the New/Resize window.

    FILDEF bool is_subwindow_open ()
    {
        for (auto it: windows) {
            if (it.first != "WINMAIN") {
                if (!is_window_hidden(it.first)) {
                    return true;
                }
            }
        }
        return false;
    }

    STDDEF int resize_window (void* _userdata, SDL_Event* _event)
    {
        // We only care about window resizing events, ignore everything else!
        if (_event->type         != SDL_WINDOWEVENT)          { return 0; }
        if (_event->window.event != SDL_WINDOWEVENT_SIZE_CHANGED &&
            _event->window.event != SDL_WINDOWEVENT_RESIZED)  { return 0; }

        float old_width = 0.0f;
        float old_height = 0.0f;

        Window& window = get_window_from_id(_event->window.windowID);

        old_width     = window.width;
        old_height    = window.height;
        window.width  = CAST(float, _event->window.data1);
        window.height = CAST(float, _event->window.data2);

        // If not on main thread leave early as it would be unsafe otherwise.
        // See the top of the init_window() function for a clear explanation.
        unsigned int main_window_thread_id = *CAST(unsigned int*, _userdata);
        if (main_window_thread_id != get_thread_id()) { return 0; }

        // Force a redraw on resize, which looks nicer than the usual glitchy
        // looking screen content when a program's window is usually resized.
        window_resizing = true;
        if (!from_manual_resize) {
            if (window.resize_callback) {
                if (old_width  != CAST(float, _event->window.data1) ||
                    old_height != CAST(float, _event->window.data2)) {

                    window.resize_callback();
                }
            }
        } else {
            from_manual_resize = false;
        }
        window_resizing = false;

        return 0;
    }

    FILDEF void push_quit_event ()
    {
        SDL_Event e;
        SDL_zero(e);

        e.type           = SDL_QUIT;
        e.quit.type      = SDL_QUIT;
        e.quit.timestamp = SDL_GetTicks();

        SDL_PushEvent(&e);
    }
}

STDDEF bool create_window (std::string name_, std::string title_, int x_, int y_, int w_, int h_, int mw_, int mh_, u32 flags_)
{
    if (internal::windows.find(name_) != internal::windows.end()) {
        LOG_ERROR(ERR_MAX, "Window with name \"%s\" already exists!", name_.c_str());
        return false;
    }

    internal::windows.insert(std::pair<std::string, Window>(name_, Window()));
    Window& window = internal::windows.at(name_);

    flags_ |= (SDL_WINDOW_HIDDEN|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_OPENGL); // Required flags!
    window.window = SDL_CreateWindow(title_.c_str(), x_, y_, w_, h_, flags_);
    if (!window.window) {
        LOG_ERROR(ERR_MIN, "Failed to create window! (%s)", SDL_GetError());
        return false;
    }

    window.id = SDL_GetWindowID(window.window);
    if (!window.id) {
        LOG_ERROR(ERR_MIN, "Failed to get window ID! (%s)", SDL_GetError());
        return false;
    }

    // Only set a minimum size if both values are a valid size.
    if (mw_ && mh_) { set_window_min_size(name_, mw_, mh_); }

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

    LOG_DEBUG("Created Window %s", name_.c_str());
    return true;
}

FILDEF bool is_window_hidden (std::string name_)
{
    return (SDL_GetWindowFlags(internal::windows.at(name_).window) & SDL_WINDOW_HIDDEN);
}

FILDEF bool is_window_focused (std::string name_)
{
    return internal::windows.at(name_).focus;
}

FILDEF void show_window (std::string name_)
{
    SDL_ShowWindow(internal::windows.at(name_).window);
}

FILDEF void hide_window (std::string name_)
{
    SDL_HideWindow(internal::windows.at(name_).window);
}

FILDEF void raise_window (std::string name_)
{
    SDL_RaiseWindow(internal::windows.at(name_).window);
}

FILDEF void set_window_title (std::string name_, std::string title_)
{
    SDL_SetWindowTitle(internal::windows.at(name_).window, title_.c_str());
}

FILDEF void set_window_icon (std::string name_, std::string icon_)
{
    std::vector<u8> icon_data(load_binary_resource(icon_));
    if (!icon_data.size()) { return; } // Failed to load the resource!

    const stbi_uc* buffer = &icon_data[0];
    int size = CAST(int, icon_data.size());

    // We expect the passed file name to be a packed editor resource.
    int w, h, bpp;
    u8* raw_data = stbi_load_from_memory(buffer, size, &w, &h, &bpp, 0);
    if (!raw_data) {
        LOG_ERROR(ERR_MIN, "Failed to load window icon!");
        return;
    }
    defer { stbi_image_free(raw_data); };

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
      raw_data, w, h, bpp*8, w*bpp, SDL_PIXELFORMAT_RGBA32);
    if (!surface) {
        LOG_ERROR(ERR_MIN, "Failed to create window icon! (%s)", SDL_GetError());
        return;
    }

    SDL_SetWindowIcon(internal::windows.at(name_).window, surface);
    SDL_FreeSurface(surface);
}

FILDEF void set_window_min_size (std::string name_, int mw_, int mh_)
{
    SDL_SetWindowMinimumSize(internal::windows.at(name_).window, mw_, mh_);
}

FILDEF void set_window_max_size (std::string name_, int mw_, int mh_)
{
    SDL_SetWindowMaximumSize(internal::windows.at(name_).window, mw_, mh_);
}

FILDEF void set_window_pos (std::string name_, int x_, int y_)
{
    SDL_SetWindowPosition(internal::windows.at(name_).window, x_, y_);
}

FILDEF void set_window_size (std::string name_, int w_, int h_)
{
    SDL_SetWindowSize(internal::windows.at(name_).window, w_, h_);
}

FILDEF bool init_window ()
{
    // The SDL docs say that event watchers can potentially be called on a
    // separate thread this means that, if this is the case, the redraw on
    // resize is potentially unstable. As a result, we pass in the ID for
    // the main thread and then when in the resize handler check to see if
    // its thread ID is the same -- if it is then we can redraw safely.
    internal::main_thread_id = get_thread_id();

    // The SDL docs say that this should be done before creation of the window!
    int profile_mask =  SDL_GL_CONTEXT_PROFILE_CORE;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GL_CONTEXT_VERSION_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GL_CONTEXT_VERSION_MINOR);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE,                                 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,              profile_mask);

    #if defined(DEBUG_BUILD)
    std::string main_title(format_string("[DEBUG] %s (%d.%d.%d)", MAIN_WINDOW_TITLE, EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH));
    #else
    std::string main_title(format_string("%s (%d.%d.%d)", MAIN_WINDOW_TITLE, EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH));
    #endif

    if (!create_window("WINMAIN", main_title.c_str(), MAIN_WINDOW_X,MAIN_WINDOW_Y,MAIN_WINDOW_BASE_W,MAIN_WINDOW_BASE_H, MAIN_WINDOW_MIN_W,MAIN_WINDOW_MIN_H, MAIN_WINDOW_FLAGS)) {
        LOG_ERROR(ERR_MAX, "Failed to create the main application window!");
        return false;
    }

    get_window("WINMAIN").close_callback = []() {
        internal::push_quit_event();
    };

    // This is a useful feature of SDL's that will allow us to redraw our
    // screen whilst it is being resized, which is much more aesthetically
    // appealing when compared to the usual garbage visuals on a resize.
    SDL_AddEventWatch(internal::resize_window, &internal::main_thread_id);

    return true;
}

FILDEF void quit_window ()
{
    for (auto it: internal::windows) {
        SDL_DestroyWindow(it.second.window);
    }
    internal::windows.clear();
}

FILDEF void handle_window_events ()
{
    if (main_event.type != SDL_WINDOWEVENT) { return; }

    std::string window_name = get_window_name_from_id(main_event.window.windowID);
    Window& window = get_window_from_id(main_event.window.windowID);

    switch (main_event.window.event) {
    case (SDL_WINDOWEVENT_FOCUS_GAINED): {
        // Special case for the main window to ensure all sub-windows stay on top of it.
        if (window_name == "WINMAIN") {
            if (internal::is_subwindow_open()) {
                for (auto it: internal::windows) {
                    if (it.first != "WINMAIN") {
                        raise_window(it.first);
                    }
                }
            } else {
                window.focus = true;
            }
        } else {
            window.focus = true;
        }
    } break;
    case (SDL_WINDOWEVENT_FOCUS_LOST): { window.focus = false; } break;

    case (SDL_WINDOWEVENT_ENTER): { window.mouse = true; } break;
    case (SDL_WINDOWEVENT_LEAVE): { window.mouse = false; } break;

    case (SDL_WINDOWEVENT_CLOSE): {
        if (window.close_callback) {
            window.close_callback();
        }
    } break;
    }
}

INLDEF void set_main_window_subtitle (const char* _subtitle)
{
    #if defined(DEBUG_BUILD)
    std::string main_title(format_string("[DEBUG] %s (%d.%d.%d)", MAIN_WINDOW_TITLE, EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH));
    #else
    std::string main_title(format_string("%s (%d.%d.%d)", MAIN_WINDOW_TITLE, EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH));
    #endif

    // If NULL is passed we simply set back to the standard title.
    if (_subtitle) {
        main_title += " | ";
        main_title += _subtitle;
    }

    SDL_SetWindowTitle(internal::windows.at("WINMAIN").window, main_title.c_str());
}

FILDEF bool is_a_window_resizing ()
{
    return internal::window_resizing;
}

FILDEF Window& get_window (std::string name_)
{
    ASSERT(internal::windows.find(name_) != internal::windows.end());
    return internal::windows.at(name_);
}
FILDEF Window_ID get_window_id (std::string name_)
{
    return internal::windows.at(name_).id;
}
FILDEF Window& get_window_from_id (Window_ID id_)
{
    for (auto& it: internal::windows) {
        if (it.second.id == id_) {
            return it.second;
        }
    }
    ASSERT(false);
    return internal::windows.at("");
}
FILDEF std::string get_window_name_from_id (Window_ID id_)
{
    for (auto& it: internal::windows) {
        if (it.second.id == id_) {
            return it.first;
        }
    }
    ASSERT(false);
    return std::string();
}

FILDEF Window& get_focused_window ()
{
    for (auto& it: internal::windows) {
        if (it.second.focus) {
            return it.second;
        }
    }
    ASSERT(false);
    return internal::windows.at("WINMAIN");
}
