#if defined(PLATFORM_WINNT)
FILDEF HWND internal__get_window_handle (SDL_Window* _window)
{
    SDL_SysWMinfo win_info;
    SDL_zero(win_info);

    SDL_VERSION(&win_info.version);

    if (!SDL_GetWindowWMInfo(_window, &win_info)) { return NULL; }
    else { return win_info.info.win.window; }
}
#endif // PLATFORM_WINNT

FILDEF u32 internal__dialog_callback (u32 _interval, void* _user_data)
{
    push_editor_event(EDITOR_EVENT_COOLDOWN);
    return 0;
}

FILDEF void internal__set_cooldown_timer ()
{
    int cooldown_time_ms = 60;
    level_editor.cooldown_timer = SDL_AddTimer(cooldown_time_ms, internal__dialog_callback, NULL);
    if (!level_editor.cooldown_timer) {
        LOG_ERROR(ERR_MIN, "Failed to setup dialog cooldown timer! (%s)", SDL_GetError());
    }
}

template<typename T>
FORCEINLINE bool operator== (const Vec2_Base<T>& _a, const Vec2_Base<T>& _b)
{
    return ((_a.x == _b.x) && (_a.y == _b.y));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec2_Base<T>& _a, const Vec2_Base<T>& _b)
{
    return !(_a == _b);
}

template<typename T>
FORCEINLINE bool operator== (const Vec3_Base<T>& _a, const Vec3_Base<T>& _b)
{
    return ((_a.x == _b.x) && (_a.y == _b.y) && (_a.z == _b.z));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec3_Base<T>& _a, const Vec3_Base<T>& _b)
{
    return !(_a == _b);
}

template<typename T>
FORCEINLINE bool operator== (const Vec4_Base<T>& _a, const Vec4_Base<T>& _b)
{
    return ((_a.x == _b.x) && (_a.y == _b.y) && (_a.z == _b.z) && (_a.w == _b.w));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec4_Base<T>& _a, const Vec4_Base<T>& _b)
{
    return !(_a == _b);
}

template<typename T, size_t N>
FORCEINLINE void Stack<T, N>::push (const T& _val)
{
    ASSERT(count < N);
    data[count++] = _val;
}

template<typename T, size_t N>
FORCEINLINE T Stack<T, N>::pop ()
{
    ASSERT(count > 0);
    return data[--count];
}

template<typename T, size_t N>
FORCEINLINE T& Stack<T, N>::peek ()
{
    ASSERT(count > 0);
    return data[count-1];
}

template<typename T, size_t N>
FORCEINLINE const T& Stack<T, N>::peek () const
{
    ASSERT(count > 0);
    return data[count-1];
}

#if defined(PLATFORM_WINNT)
STDDEF int show_alert (const char* _title, const char* _msg, int _type, int _buttons, std::string _window)
{
    // If the window is hidden then we do not bother passing it as the parent
    // of the alert box because on alert close the program proceeds to hang.
    HWND hwnd = NULL;
    if (!_window.empty() && !is_window_hidden(_window)) {
        hwnd = internal__get_window_handle(get_window(_window).window);
    }

    return MessageBoxA(hwnd, _msg, _title, (_type|_buttons));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::string get_executable_path ()
{
    constexpr size_t BUFFER_SIZE = MAX_PATH+1;
    char temp_buffer[BUFFER_SIZE] = {};

    GetModuleFileNameA(NULL, temp_buffer, BUFFER_SIZE);
    std::string path(fix_path_slashes(temp_buffer));

    // Get rid of the actual executable so it's just the path.
    size_t last_slash = path.find_last_of('/');
    if (last_slash != std::string::npos) { ++last_slash; }

    return path.substr(0, last_slash);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::vector<std::string> open_dialog (Dialog_Type _type, bool _multiselect)
{
    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    level_editor.dialog_box = true;

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (_type) {
    case (DIALOG_TYPE_LVL ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";    title = "Open";   ext = "lvl";  } break;
    case (DIALOG_TYPE_GPAK): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0"; title = "Unpack"; ext = "gpak"; } break;
    }

    constexpr size_t BUFFER_SIZE = UINT16_MAX+1;
    char file_buffer[BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = internal__get_window_handle(get_window("WINMAIN").window);
    open_file_name.lStructSize  = sizeof(OPENFILENAMEA);
    open_file_name.nFilterIndex = 2;
    open_file_name.lpstrFilter  = filter;
    open_file_name.lpstrFile    = file_buffer;
    open_file_name.nMaxFile     = BUFFER_SIZE;
    open_file_name.lpstrDefExt  = ext;
    open_file_name.lpstrTitle   = title;
    open_file_name.Flags        = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_NOCHANGEDIR;

    if (_multiselect) {
        open_file_name.Flags |= OFN_ALLOWMULTISELECT;
    }

    // Attempt to load the open dialog and handle any potential errors.
    std::vector<std::string> files;
    if (!GetOpenFileNameA(&open_file_name)) {
        DWORD error = CommDlgExtendedError();
        if (error) { // Zero means the user cancelled -- not an actual error!
            LOG_ERROR(ERR_MED, "Failed to open file! (Error: 0x%X)", error);
        }
    } else {
        const char* pos = file_buffer;
        if (*pos != '\0') {
            // Determines if there is just one file or multiple
            if (is_path(pos)) {
                // First part is always the path.
                std::string path(fix_path_slashes(pos));
                path.push_back('/');

                // Then it is followed by all the names.
                pos += open_file_name.nFileOffset;
                while (*pos) {
                    files.push_back(path + std::string(pos));
                    pos += strlen(pos)+1;
                }
            } else {
                files.push_back(fix_path_slashes(pos));
            }
        }
    }

    internal__set_cooldown_timer();
    return files;
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::string save_dialog (Dialog_Type _type)
{
    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    level_editor.dialog_box = true;

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (_type) {
    case (DIALOG_TYPE_LVL ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";    title = "Save As"; ext = "lvl";  } break;
    case (DIALOG_TYPE_GPAK): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0"; title = "Pack";    ext = "gpak"; } break;
    }

    constexpr size_t BUFFER_SIZE = MAX_PATH+1;
    char file_buffer[BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = internal__get_window_handle(get_window("WINMAIN").window);
    open_file_name.lStructSize  = sizeof(OPENFILENAMEA);
    open_file_name.nFilterIndex = 2;
    open_file_name.lpstrFilter  = filter;
    open_file_name.lpstrFile    = file_buffer;
    open_file_name.nMaxFile     = BUFFER_SIZE;
    open_file_name.lpstrDefExt  = ext;
    open_file_name.lpstrTitle   = title;
    open_file_name.Flags        = OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT|OFN_NOREADONLYRETURN|OFN_NOCHANGEDIR;

    // Attempt to load the save dialog and handle any potential errors.
    std::string file;
    if (!GetSaveFileNameA(&open_file_name)) {
        DWORD error = CommDlgExtendedError();
        if (error) { // Zero means the user cancelled -- not an actual error!
            LOG_ERROR(ERR_MED, "Failed to save file! (Error: 0x%X)", error);
        }
    } else {
        file = fix_path_slashes(file_buffer);
    }

    internal__set_cooldown_timer();
    return file;
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::vector<std::string> path_dialog (bool _multiselect)
{
    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    level_editor.dialog_box = true;

    std::vector<std::string> paths;

    IFileOpenDialog* file_dialog = NULL;
    if (!SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&file_dialog)))) {
        LOG_ERROR(ERR_MED, "Failed to create the folder dialog!");
        return paths;
    }
    defer { file_dialog->Release(); };

    DWORD options;
    if (!SUCCEEDED(file_dialog->GetOptions(&options))) {
        LOG_ERROR(ERR_MED, "Failed to get folder dialog options!");
        return paths;
    }

    options |= FOS_PICKFOLDERS;
    if (_multiselect) {
        options |= FOS_ALLOWMULTISELECT;
    }

    file_dialog->SetOptions(options);
    if (!SUCCEEDED(file_dialog->Show(NULL))) {
        // No error because the user may have just cancelled the operation...
        return paths;
    }

    IShellItemArray* shell_item_array = NULL;
    if (!SUCCEEDED(file_dialog->GetResults(&shell_item_array))) {
        LOG_ERROR(ERR_MED, "Failed to create shell item array!");
        return paths;
    }
    defer { shell_item_array->Release(); };

    IShellItem* shell_item = NULL;
    LPWSTR result = NULL;
    DWORD item_count = 0;

    shell_item_array->GetCount(&item_count);

    for (DWORD i=0; i<item_count; ++i) {
        shell_item_array->GetItemAt(i, &shell_item);
        if (shell_item) {
            shell_item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &result);
            if (result) {
                std::wstring wide_path(result);
                CoTaskMemFree(result);

                paths.push_back(std::string());
                std::string& path = paths.back();

                int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wide_path[0], CAST(int, wide_path.size()), NULL, 0, NULL, NULL);
                path.resize(size_needed, 0);
                WideCharToMultiByte(CP_UTF8, 0, &wide_path[0], CAST(int, wide_path.size()), &path[0], size_needed, NULL, NULL);
            }
        }
    }

    internal__set_cooldown_timer();
    return paths;
}
#endif // PLATFORM_WINNT

FILDEF size_t get_size_of_file (const char* _file_name)
{
    FILE* file = fopen(_file_name, "rb");
    if (!file) { return 0; }

    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);

    fclose(file);
    return size;
}

FILDEF size_t get_size_of_file (FILE* _file)
{
    if (!_file) { return 0; }

    fseek(_file, 0L, SEEK_END);
    size_t size = ftell(_file);
    rewind(_file); // Go back to avoid changing stream.

    return size;
}

#if defined(PLATFORM_WINNT)
FILDEF bool does_file_exist (const char* _file_name)
{
    DWORD attribs = GetFileAttributesA(_file_name);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && !(attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool does_path_exist (const char* _path)
{
    DWORD attribs = GetFileAttributesA(_path);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && (attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_content (const char* _path, std::vector<std::string>& _content)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(_path));
    while (path.back() == '/') { path.pop_back(); }

    // Check if the path even exists first.
    if (!is_path(path.c_str())) { return; }

    std::string find_path(path + "\\*");
    WIN32_FIND_DATAA find_data = {};

    HANDLE find_file = FindFirstFileA(find_path.c_str(), &find_data);
    defer { FindClose(find_file); }; // Clean-up on function return.

    if (find_file != INVALID_HANDLE_VALUE) {
        do {
            // We do not want to include the self and parent directories.
            std::string filename = find_data.cFileName;
            if (filename != "." && filename != "..") {
                _content.push_back(path + "/" + fix_path_slashes(filename.c_str()));
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_content_r (const char* _path, std::vector<std::string>& _content)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(_path));
    while (path.back() == '/') { path.pop_back(); }

    // We prefer to use forward slashes over backwards ones.
    std::replace(path.begin(), path.end(), '\\', '/');

    // Check if the path even exists first.
    if (!is_path(path.c_str())) { return; }

    std::string find_path(path + "\\*");
    WIN32_FIND_DATAA find_data = {};

    HANDLE find_file = FindFirstFileA(find_path.c_str(), &find_data);
    defer { FindClose(find_file); }; // Clean-up on function return.

    if (find_file != INVALID_HANDLE_VALUE) {
        do {
            std::string filename = find_data.cFileName;
            if (filename != "." && filename != "..") {
                // Make sure that we are using our preferred slashes.
                _content.push_back(path + "/" + fix_path_slashes(filename.c_str()));
                // Retrieve files from any sub-paths as well.
                if (is_path(_content.back().c_str())) {
                    list_path_content_r(_content.back().c_str(), _content);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_files (const char* _path, std::vector<std::string>& _files)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(_path));
    while (path.back() == '/') { path.pop_back(); }

    // Check if the path even exists first.
    if (!is_path(path.c_str())) { return; }

    std::string find_path(path + "\\*");
    WIN32_FIND_DATAA find_data = {};

    HANDLE find_file = FindFirstFileA(find_path.c_str(), &find_data);
    defer { FindClose(find_file); }; // Clean-up on function return.

    if (find_file != INVALID_HANDLE_VALUE) {
        do {
            // We do not want to include the self and parent directories.
            std::string filename = find_data.cFileName;
            if (filename != "." && filename != "..") {
                // Make sure that we are using our preferred slashes.
                std::string final(path + "/" + fix_path_slashes(filename.c_str()));
                if (is_file(final.c_str())) {
                    _files.push_back(final);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_files_r (const char* _path, std::vector<std::string>& _files)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(_path));
    while (path.back() == '/') { path.pop_back(); }

    // We prefer to use forward slashes over backwards ones.
    std::replace(path.begin(), path.end(), '\\', '/');

    // Check if the path even exists first.
    if (!is_path(path.c_str())) { return; }

    std::string find_path(path + "\\*");
    WIN32_FIND_DATAA find_data = {};

    HANDLE find_file = FindFirstFileA(find_path.c_str(), &find_data);
    defer { FindClose(find_file); }; // Clean-up on function return.

    if (find_file != INVALID_HANDLE_VALUE) {
        do {
            std::string filename = find_data.cFileName;
            if (filename != "." && filename != "..") {
                // Make sure that we are using our preferred slashes.
                std::string final(path + "/" + fix_path_slashes(filename.c_str()));
                if (is_file(final.c_str())) {
                    _files.push_back(final);
                } else {
                    list_path_files_r(final.c_str(), _files);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool create_path (const char* _path)
{
    // The Windows API function CreateDirectoryA only works if the path it is
    // creating is one-layer deep. We want our create_path function to create
    // all nested paths necessary so we do this by splitting up the provided
    // path and creating each sub-path until there are no more for us to add.

    std::vector<std::string> paths;
    tokenize_string(_path, "\\/", paths);

    if (!paths.empty()) {
        std::string path;
        for (auto& p: paths) {
            path += (p + "/");
            if (!does_path_exist(path.c_str())) {
                if (!CreateDirectoryA(path.c_str(), NULL)) {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool is_path_absolute (const char* _path)
{
    return !PathIsRelativeA(_path);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool is_file (const char* _file_name)
{
    return !is_path(_file_name);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool is_path (const char* _path)
{
    DWORD attribs = GetFileAttributesA(_path);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && (attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF u64 last_file_write_time (const char* _file_name)
{
    DWORD access = GENERIC_READ;
    DWORD share = FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE;

    HANDLE file = CreateFileA(_file_name, access, share, NULL,
      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) { return 0; }
    defer { CloseHandle(file); };

    FILETIME file_time = {};
    if (!GetFileTime(file, NULL, NULL, &file_time)) { return 0; }

    ULARGE_INTEGER time;
    time.LowPart  = file_time.dwLowDateTime;
    time.HighPart = file_time.dwHighDateTime;

    return CAST(u64, time.QuadPart);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF std::string make_path_absolute (const char* _path)
{
    // If path is not absolute then we prefix the absolute executable path.
    std::string path(_path);
    if (PathIsRelativeA(path.c_str())) {
        path.insert(0, get_executable_path());
    }
    return path;
}
#endif // PLATFORM_WINNT

FILDEF std::string fix_path_slashes (const char* _path)
{
    // We prefer the use of forward over backwards slashes.
    std::string path(_path);
    std::replace(path.begin(), path.end(), '\\', '/');

    return path;
}

STDDEF char* read_entire_file (const char* _file_name)
{
    FILE* file = fopen(_file_name, "rb");
    if (!file) { return NULL; } // Failed to open file.

    defer { fclose(file); };

    size_t size = get_size_of_file(file);

    // It is the caller's responsibility to free the allocated buffer.
    char* buffer = cstd_malloc(char, size+1);
    if (!buffer) { return NULL; } // Failed to allocate.

    // If the result is not equal to the specified size then we know that
    // fread was unsuccessful so free the buffer and return NULL instead.
    size_t result = fread(buffer, sizeof(char), size, file);
    if (result != size) { cstd_free(buffer); return NULL; }

    buffer[size] = '\0';
    return buffer;
}

STDDEF std::string read_entire_file_str (const char* _file_name)
{
    std::ifstream file(_file_name);

    std::stringstream stream;
    stream << file.rdbuf();

    return stream.str();
}

STDDEF std::vector<u8> read_binary_file (const char* _file_name)
{
    FILE* file = fopen(_file_name, "rb");
    if (!file) { return std::vector<u8>(); } // Failed to open file.

    defer { fclose(file); };

    size_t size = get_size_of_file(file);

    std::vector<u8> data;
    data.resize(size, 0);

    // If the result is not equal to the specified size then we know that
    // fread was unsuccessful so free the buffer and return NULL instead.
    size_t result = fread(&data[0], sizeof(u8), size, file);
    if (result != size) { return std::vector<u8>(); }

    return data;
}

#if defined(PLATFORM_WINNT)
FILDEF std::string strip_file_path (const char* _file_name)
{
    return std::string(PathFindFileNameA(_file_name));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF std::string strip_file_ext (const char* _file_name)
{
    char* file_name = cstd_malloc(char, strlen(_file_name)+1);
    if (!file_name) { return std::string(); }
    defer { cstd_free(file_name); };

    strcpy(file_name, _file_name);
    PathRemoveExtensionA(file_name);

    return std::string(file_name);
}
#endif // PLATFORM_WINNT

FILDEF std::string strip_file_path_and_ext (const char* _file_name)
{
    return strip_file_ext(strip_file_path(_file_name).c_str());
}

FILDEF std::string strip_file_name (const char* _file_name)
{
    std::string file_name(fix_path_slashes(_file_name));
    std::string::size_type last_slash = file_name.rfind('/');

    std::string path;
    if (last_slash != std::string::npos) {
        path = file_name.substr(0, last_slash+1);
    }
    return path;
}

FILDEF void tokenize_string (const std::string& _str, const char* _delims, std::vector<std::string>& _tokens)
{
    size_t prev = 0;
    size_t pos;

    while ((pos = _str.find_first_of(_delims, prev)) != std::string::npos) {
        if (pos > prev) { _tokens.push_back(_str.substr(prev, pos-prev)); }
        prev = pos+1;
    }
    if (prev < _str.length()) {
        _tokens.push_back(_str.substr(prev, std::string::npos));
    }
}

INLDEF std::string format_string (const char* _format, ...)
{
    std::string str;
    va_list args;

    va_start(args, _format);
    defer { va_end(args); };

    int size = vsnprintf(NULL, 0, _format, args) + 1;
    char* buffer = cstd_malloc(char, size);
    if (buffer) {
        vsnprintf(buffer, size, _format, args);
        str = buffer;
        cstd_free(buffer);
    }

    return str;
}

INLDEF std::string format_string_v (const char* _format, va_list _args)
{
    std::string str;

    int size = vsnprintf(NULL, 0, _format, _args) + 1;
    char* buffer = cstd_malloc(char, size);
    if (buffer) {
        vsnprintf(buffer, size, _format, _args);
        str = buffer;
        cstd_free(buffer);
    }

    return str;
}

FILDEF int get_line_count (const char* _str)
{
    int lines = 1; // Always have at least one line.
    for (const char* c=_str; *c; ++c) {
        if (*c == '\n') { ++lines; }
    }
    return lines;
}

FILDEF Vec2 get_mouse_pos ()
{
    // SDL gives the mouse as ints so we convert to floats.
    int imx, imy; SDL_GetMouseState(&imx, &imy);
    return Vec2 { CAST(float, imx), CAST(float, imy) };
}

INLDEF std::string format_time (const char* _format)
{
    time_t     raw_time = time(NULL);
    struct tm* cur_time = localtime(&raw_time);

    size_t length = 256;
    size_t result = 0;

    // We go until our buffer is big enough.
    char* buffer = NULL;
    do {
        if (buffer) { cstd_free(buffer); }
        buffer = cstd_malloc(char, length);
        if (!buffer) { return std::string(); }

        result = strftime(buffer, length, _format, cur_time);
        length *= 2;
    }
    while (!result);

    defer { cstd_free(buffer); };
    return std::string(buffer);
}

#if defined(PLATFORM_WINNT)
FILDEF unsigned int get_thread_id ()
{
    return CAST(unsigned int, GetCurrentThreadId());
}
#endif // PLATFORM_WINNT

FILDEF bool point_in_bounds_xyxy (Vec2 _p, float _x1, float _y1, float _x2, float _y2)
{
    return (_p.x >= _x1 && _p.y >= _y1 && _p.x <= _x2 && _p.y <= _y2);
}

FILDEF bool point_in_bounds_xyxy (Vec2 _p, Quad _q)
{
    return (_p.x >= _q.x1 && _p.y >= _q.y1 && _p.x <= _q.x2 && _p.y <= _q.y2);
}

FILDEF bool point_in_bounds_xywh (Vec2 _p, float _x, float _y, float _w, float _h)
{
    return (_p.x >= _x && _p.y >= _y && _p.x < (_x+_w) && _p.y < (_y+_h));
}

FILDEF bool point_in_bounds_xywh (Vec2 _p, Quad _q)
{
    return (_p.x >= _q.x && _p.y >= _q.y && _p.x < (_q.x+_q.w) && _p.y < (_q.y+_q.h));
}

FILDEF bool insensitive_compare (const std::string& _a, const std::string& _b)
{
    if (_a.length() != _b.length()) { return false; }
    for (std::string::size_type i=0; i<_a.length(); ++i) { // A and B are same length.
        if (tolower(_a[i]) != tolower(_b[i])) { return false; }
    }
    return true;
}

FILDEF bool string_replace (std::string& _str, const std::string& _from, const std::string& _to)
{
    std::string::size_type start_pos = _str.find(_from);
    if (start_pos == std::string::npos) { return false; }
    _str.replace(start_pos, _from.length(), _to);
    return true;
}

#if defined(PLATFORM_WINNT)
FILDEF void play_error_sound ()
{
    MessageBeep(MB_ICONERROR);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF void play_warning_sound ()
{
    MessageBeep(MB_ICONWARNING);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF void run_executable (const char* _exe)
{
    PROCESS_INFORMATION process_info = {};
    STARTUPINFOA startup_info = {};

    startup_info.cb = sizeof(STARTUPINFOA);

    if (!CreateProcessA(_exe, NULL,NULL,NULL, FALSE, 0, NULL, strip_file_name(_exe).c_str(), &startup_info, &process_info)) {
        LOG_ERROR(ERR_MED, "Failed to launch The End is Nigh executable!");
    }

    // Win32 API docs state these should be closed.
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF void load_webpage (const char* _url)
{
    ShellExecuteA(NULL, NULL, _url, NULL, NULL, SW_SHOW);
}
#endif // PLATFORM_WINNT
