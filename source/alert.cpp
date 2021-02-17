#if defined(PLATFORM_WIN32)
STDDEF int show_alert (std::string title, std::string msg, int type,
                       int buttons, std::string window)
{
    // NOTE: We don't allow hidden windows because it causes program hang.
    HWND hwnd = NULL;
    if (!window.empty() && !is_window_hidden(window))
    {
        hwnd = internal__win32_get_window_handle(get_window(window).window);
    }
    return MessageBoxA(hwnd, msg.c_str(), title.c_str(), (type|buttons));
}
#else
#error show_alert not implemented on the current platform!
#endif
