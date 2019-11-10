namespace utility { ////////////////////////////////////////////////////////////

// Do not use this directly and instead use the defer macro!
template<typename T>
struct Defer
{
    T lambda;

             Defer   (T lambda_): lambda(lambda_) { /* Nothing! */ }
            ~Defer   ()                           {    lambda();   }

             Defer   (const Defer& defer_) = delete;
    Defer& operator= (const Defer& defer_) = delete;
};
struct Defer_Help
{
    template<typename T>
    Defer<T> operator+ (T type_) { return type_; }
};

#if defined(PLATFORM_WINNT)
FILDEF HWND get_window_handle (SDL_Window* window_)
{
    SDL_SysWMinfo win_info;
    SDL_zero(win_info);

    SDL_VERSION(&win_info.version);

    if (!SDL_GetWindowWMInfo(window_, &win_info)) { return NULL; }
    else { return win_info.info.win.window; }
}
#endif // PLATFORM_WINNT

FILDEF u32 dialog_callback (u32 interval_, void* user_data_)
{
    push_editor_event(EDITOR_EVENT_COOLDOWN);
    return 0;
}

FILDEF void set_cooldown_timer ()
{
    int cooldown_time_ms = 60;
    editor.cooldown_timer = SDL_AddTimer(cooldown_time_ms, utility::dialog_callback, NULL);
    if (!editor.cooldown_timer) {
        LOG_ERROR(ERR_MIN, "Failed to setup dialog cooldown timer! (%s)", SDL_GetError());
    }
}

} // utility ///////////////////////////////////////////////////////////////////

template<typename T>
FORCEINLINE bool operator== (const Vec2_Base<T>& a_, const Vec2_Base<T>& b_)
{
    return ((a_.x == b_.x) && (a_.y == b_.y));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec2_Base<T>& a_, const Vec2_Base<T>& b_)
{
    return !(a_ == b_);
}

template<typename T>
FORCEINLINE bool operator== (const Vec3_Base<T>& a_, const Vec3_Base<T>& b_)
{
    return ((a_.x == b_.x) && (a_.y == b_.y) && (a_.z == b_.z));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec3_Base<T>& a_, const Vec3_Base<T>& b_)
{
    return !(a_ == b_);
}

template<typename T>
FORCEINLINE bool operator== (const Vec4_Base<T>& a_, const Vec4_Base<T>& b_)
{
    return ((a_.x == b_.x) && (a_.y == b_.y) && (a_.z == b_.z) && (a_.w == b_.w));
}
template<typename T>
FORCEINLINE bool operator!= (const Vec4_Base<T>& a_, const Vec4_Base<T>& b_)
{
    return !(a_ == b_);
}

template<typename T, size_t N>
FORCEINLINE void Stack<T, N>::push (const T& val_)
{
    ASSERT(count < N);
    data[count++] = val_;
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
STDDEF int show_alert (const char* title_, const char* msg_, int type_, int buttons_, std::string window_)
{
    // If the window is hidden then we do not bother passing it as the parent
    // of the alert box because on alert close the program proceeds to hang.
    HWND hwnd = NULL;
    if (!window_.empty() && !is_window_hidden(window_)) {
        hwnd = utility::get_window_handle(get_window(window_).window);
    }
    return MessageBoxA(hwnd, msg_, title_, (type_|buttons_));
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
STDDEF std::vector<std::string> open_dialog (Dialog_Type type_, bool multiselect_)
{
    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    editor.dialog_box = true;

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (type_) {
    case (DIALOG_TYPE_LVL        ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";                                                                        title = "Open";   ext = "lvl";  } break;
    case (DIALOG_TYPE_CSV        ): { filter = "All Files (*.*)\0*.*\0CSV Files (*.csv)\0*.csv\0";                                                                        title = "Open";   ext = "csv";  } break;
    case (DIALOG_TYPE_LVL_AND_CSV): { filter = "All Files (*.*)\0*.*\0Supported Files (*.lvl; *.csv)\0*.lvl;*.csv\0CSV Files (*.csv)\0*.csv\0LVL Files (*.lvl)\0*.lvl\0"; title = "Open";   ext = NULL;   } break;
    case (DIALOG_TYPE_GPAK       ): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0";                                                                     title = "Unpack"; ext = "gpak"; } break;
    case (DIALOG_TYPE_EXE        ): { filter = "All Files (*.*)\0*.*\0EXE Files (*.exe)\0*.exe\0";                                                                        title = "Open";   ext = "exe";  } break;
    }

    constexpr size_t BUFFER_SIZE = UINT16_MAX+1;
    char file_buffer[BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = utility::get_window_handle(get_window("WINMAIN").window);
    open_file_name.lStructSize  = sizeof(OPENFILENAMEA);
    open_file_name.nFilterIndex = 2;
    open_file_name.lpstrFilter  = filter;
    open_file_name.lpstrFile    = file_buffer;
    open_file_name.nMaxFile     = BUFFER_SIZE;
    open_file_name.lpstrDefExt  = ext;
    open_file_name.lpstrTitle   = title;
    open_file_name.Flags        = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_NOCHANGEDIR;

    if (multiselect_) {
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

    utility::set_cooldown_timer();
    return files;
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::string save_dialog (Dialog_Type type_)
{
    ASSERT(type_ != DIALOG_TYPE_LVL_AND_CSV);

    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    editor.dialog_box = true;

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (type_) {
    case (DIALOG_TYPE_LVL ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";    title = "Save As"; ext = "lvl";  } break;
    case (DIALOG_TYPE_CSV ): { filter = "All Files (*.*)\0*.*\0CSV Files (*.csv)\0*.csv\0";    title = "Save As"; ext = "csv";  } break;
    case (DIALOG_TYPE_GPAK): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0"; title = "Pack";    ext = "gpak"; } break;
    case (DIALOG_TYPE_EXE ): { filter = "All Files (*.*)\0*.*\0EXE Files (*.exe)\0*.exe\0";    title = "Save As"; ext = "exe";  } break;
    }

    constexpr size_t BUFFER_SIZE = MAX_PATH+1;
    char file_buffer[BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = utility::get_window_handle(get_window("WINMAIN").window);
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

    utility::set_cooldown_timer();
    return file;
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF std::vector<std::string> path_dialog (bool multiselect_)
{
    // This is not really relevant to the internals of this particular system
    // but we do this here as a sort of hacky solution so that a click from
    // the dialog box doesn't carry over to the level editor and result in a
    // tile/spawn being placed, or whatever happening. This boolean gets set
    // to false after the dialog box cooldown timer is finished counting down.
    editor.dialog_box = true;

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
    if (multiselect_) {
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

    utility::set_cooldown_timer();
    return paths;
}
#endif // PLATFORM_WINNT

FILDEF size_t get_size_of_file (const char* file_name_)
{
    FILE* file = fopen(file_name_, "rb");
    if (!file) { return 0; }

    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);

    fclose(file);
    return size;
}

FILDEF size_t get_size_of_file (FILE* file_)
{
    if (!file_) { return 0; }

    fseek(file_, 0L, SEEK_END);
    size_t size = ftell(file_);
    rewind(file_); // Go back to avoid changing stream.

    return size;
}

#if defined(PLATFORM_WINNT)
FILDEF bool does_file_exist (const char* file_name_)
{
    DWORD attribs = GetFileAttributesA(file_name_);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && !(attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool does_path_exist (const char* path_)
{
    DWORD attribs = GetFileAttributesA(path_);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && (attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_content (const char* path_, std::vector<std::string>& content_)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(path_));
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
                content_.push_back(path + "/" + fix_path_slashes(filename.c_str()));
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_content_r (const char* path_, std::vector<std::string>& content_)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(path_));
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
                content_.push_back(path + "/" + fix_path_slashes(filename.c_str()));
                // Retrieve files from any sub-paths as well.
                if (is_path(content_.back().c_str())) {
                    list_path_content_r(content_.back().c_str(), content_);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_files (const char* path_, std::vector<std::string>& files_)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(path_));
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
                    files_.push_back(final);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
STDDEF void list_path_files_r (const char* path_, std::vector<std::string>& files_)
{
    // Clean the path in case there are trailing slashes.
    std::string path(fix_path_slashes(path_));
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
                    files_.push_back(final);
                } else {
                    list_path_files_r(final.c_str(), files_);
                }
            }
        }
        while (FindNextFile(find_file, &find_data));
    }
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool create_path (const char* path_)
{
    // The Windows API function CreateDirectoryA only works if the path it is
    // creating is one-layer deep. We want our create_path function to create
    // all nested paths necessary so we do this by splitting up the provided
    // path and creating each sub-path until there are no more for us to add.

    std::vector<std::string> paths;
    tokenize_string(path_, "\\/", paths);

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
FILDEF bool is_path_absolute (const char* path_)
{
    return !PathIsRelativeA(path_);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool is_file (const char* file_name_)
{
    return !is_path(file_name_);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF bool is_path (const char* path_)
{
    DWORD attribs = GetFileAttributesA(path_);
    return ((attribs != INVALID_FILE_ATTRIBUTES) && (attribs & FILE_ATTRIBUTE_DIRECTORY));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF u64 last_file_write_time (const char* file_name_)
{
    DWORD access = GENERIC_READ;
    DWORD share = FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE;

    HANDLE file = CreateFileA(file_name_, access, share, NULL,
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
FILDEF std::string make_path_absolute (const char* path_)
{
    // If path is not absolute then we prefix the absolute executable path.
    std::string path(path_);
    if (PathIsRelativeA(path.c_str())) {
        path.insert(0, get_executable_path());
    }
    return path;
}
#endif // PLATFORM_WINNT

FILDEF std::string fix_path_slashes (const char* path_)
{
    // We prefer the use of forward over backwards slashes.
    std::string path(path_);
    std::replace(path.begin(), path.end(), '\\', '/');

    return path;
}

STDDEF char* read_entire_file (const char* file_name_)
{
    FILE* file = fopen(file_name_, "rb");
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

STDDEF std::string read_entire_file_str (const char* file_name_)
{
    std::ifstream file(file_name_);

    std::stringstream stream;
    stream << file.rdbuf();

    return stream.str();
}

STDDEF std::vector<u8> read_binary_file (const char* file_name_)
{
    FILE* file = fopen(file_name_, "rb");
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
FILDEF std::string strip_file_path (const char* file_name_)
{
    return std::string(PathFindFileNameA(file_name_));
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF std::string strip_file_ext (const char* file_name_)
{
    char* file_name = cstd_malloc(char, strlen(file_name_)+1);
    if (!file_name) { return std::string(); }
    defer { cstd_free(file_name); };

    strcpy(file_name, file_name_);
    PathRemoveExtensionA(file_name);

    return std::string(file_name);
}
#endif // PLATFORM_WINNT

FILDEF std::string strip_file_path_and_ext (const char* file_name_)
{
    return strip_file_ext(strip_file_path(file_name_).c_str());
}

FILDEF std::string strip_file_name (const char* file_name_)
{
    std::string file_name(fix_path_slashes(file_name_));
    std::string::size_type last_slash = file_name.rfind('/');

    std::string path;
    if (last_slash != std::string::npos) {
        path = file_name.substr(0, last_slash+1);
    }
    return path;
}

FILDEF void tokenize_string (const std::string& str_, const char* delims_, std::vector<std::string>& tokens_)
{
    size_t prev = 0;
    size_t pos;

    while ((pos = str_.find_first_of(delims_, prev)) != std::string::npos) {
        if (pos > prev) { tokens_.push_back(str_.substr(prev, pos-prev)); }
        prev = pos+1;
    }
    if (prev < str_.length()) {
        tokens_.push_back(str_.substr(prev, std::string::npos));
    }
}

INLDEF std::string format_string (const char* format_, ...)
{
    std::string str;
    va_list args;

    va_start(args, format_);
    defer { va_end(args); };

    int size = vsnprintf(NULL, 0, format_, args) + 1;
    char* buffer = cstd_malloc(char, size);
    if (buffer) {
        vsnprintf(buffer, size, format_, args);
        str = buffer;
        cstd_free(buffer);
    }

    return str;
}

INLDEF std::string format_string_v (const char* format_, va_list args_)
{
    std::string str;

    int size = vsnprintf(NULL, 0, format_, args_) + 1;
    char* buffer = cstd_malloc(char, size);
    if (buffer) {
        vsnprintf(buffer, size, format_, args_);
        str = buffer;
        cstd_free(buffer);
    }

    return str;
}

FILDEF int get_line_count (const char* str_)
{
    int lines = 1; // Always have at least one line.
    for (const char* c=str_; *c; ++c) {
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

INLDEF std::string format_time (const char* format_)
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

        result = strftime(buffer, length, format_, cur_time);
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

FILDEF bool point_in_bounds_xyxy (Vec2 p_, float x1_, float y1_, float x2_, float y2_)
{
    return (p_.x >= x1_ && p_.y >= y1_ && p_.x <= x2_ && p_.y <= y2_);
}

FILDEF bool point_in_bounds_xyxy (Vec2 p_, Quad q_)
{
    return (p_.x >= q_.x1 && p_.y >= q_.y1 && p_.x <= q_.x2 && p_.y <= q_.y2);
}

FILDEF bool point_in_bounds_xywh (Vec2 p_, float x_, float y_, float w_, float h_)
{
    return (p_.x >= x_ && p_.y >= y_ && p_.x < (x_+w_) && p_.y < (y_+h_));
}

FILDEF bool point_in_bounds_xywh (Vec2 p_, Quad q_)
{
    return (p_.x >= q_.x && p_.y >= q_.y && p_.x < (q_.x+q_.w) && p_.y < (q_.y+q_.h));
}

FILDEF bool insensitive_compare (const std::string& a_, const std::string& b_)
{
    if (a_.length() != b_.length()) { return false; }
    for (std::string::size_type i=0; i<a_.length(); ++i) { // A and B are same length.
        if (tolower(a_[i]) != tolower(b_[i])) { return false; }
    }
    return true;
}

FILDEF bool string_replace (std::string& str_, const std::string& from_, const std::string& to_)
{
    std::string::size_type start_pos = str_.find(from_);
    if (start_pos == std::string::npos) { return false; }
    str_.replace(start_pos, from_.length(), to_);
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
FILDEF void run_executable (const char* exe_)
{
    PROCESS_INFORMATION process_info = {};
    STARTUPINFOA startup_info = {};

    startup_info.cb = sizeof(STARTUPINFOA);

    if (!CreateProcessA(exe_, NULL,NULL,NULL, FALSE, 0, NULL, strip_file_name(exe_).c_str(), &startup_info, &process_info)) {
        LOG_ERROR(ERR_MED, "Failed to launch The End is Nigh executable!");
    }

    // Win32 API docs state these should be closed.
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
}
#endif // PLATFORM_WINNT

#if defined(PLATFORM_WINNT)
FILDEF void load_webpage (const char* url_)
{
    ShellExecuteA(NULL, NULL, url_, NULL, NULL, SW_SHOW);
}
#endif // PLATFORM_WINNT
