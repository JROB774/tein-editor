STDDEF std::vector<u8> read_binary_file (std::string file_name)
{
    std::ifstream file(file_name, std::ios::binary);
    std::vector<u8> content;
    content.resize(get_size_of_file(file_name));
    file.read(CAST(char*, &content[0]), content.size()*sizeof(u8));
    return content;
}

STDDEF std::string read_entire_file (std::string file_name)
{
    std::ifstream file(file_name);
    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

FILDEF size_t get_size_of_file (std::string file_name)
{
    FILE* file = fopen(file_name.c_str(), "rb");
    if (!file) return 0;
    defer { fclose(file); };
    fseek(file, 0L, SEEK_END);
    return ftell(file);
}
FILDEF size_t get_size_of_file (FILE* file)
{
    if (!file) return 0;
    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    rewind(file); // Go back to avoid changing stream.
    return size;
}

FILDEF bool does_file_exist (std::string file_name)
{
    bool result = false;
    try { result = std::filesystem::exists(file_name) && std::filesystem::is_regular_file(file_name); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}
FILDEF bool does_path_exist (std::string path_name)
{
    bool result = false;
    try { result = std::filesystem::exists(path_name) && std::filesystem::is_directory(path_name); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}

STDDEF void list_path_content (std::string path_name, std::vector<std::string>& content, bool recursive)
{
    try
    {
        if (does_path_exist(path_name))
        {
            if (recursive)
            {
                for (auto& p: std::filesystem::recursive_directory_iterator(path_name))
                {
                    content.push_back(p.path().string());
                }
            }
            else
            {
                for (auto& p: std::filesystem::directory_iterator(path_name))
                {
                    content.push_back(p.path().string());
                }
            }
        }
    }
    catch (std::filesystem::filesystem_error& e)
    {
        LOG_ERROR(ERR_MIN, "File System Error: %s", e.what());
    }
}

STDDEF void list_path_files (std::string path_name, std::vector<std::string>& files, bool recursive)
{
    try
    {
        if (does_path_exist(path_name))
        {
            if (recursive)
            {
                for (auto& p: std::filesystem::recursive_directory_iterator(path_name))
                {
                    if (is_file(p.path().string())) files.push_back(p.path().string());
                }
            }
            else
            {
                for (auto& p: std::filesystem::directory_iterator(path_name))
                {
                    if (is_file(p.path().string())) files.push_back(p.path().string());
                }
            }
        }
    }
    catch (std::filesystem::filesystem_error& e)
    {
        LOG_ERROR(ERR_MIN, "File System Error: %s", e.what());
    }
}

FILDEF bool create_path (std::string path_name)
{
    try { std::filesystem::create_directories(path_name); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return does_path_exist(path_name);
}

FILDEF bool is_path_absolute (std::string path_name)
{
    bool result = false;
    try { result = std::filesystem::path(path_name).is_absolute(); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}

FILDEF bool is_file (std::string file_name)
{
    bool result = false;
    try { result = std::filesystem::is_regular_file(file_name); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}

FILDEF bool is_path (std::string path_name)
{
    bool result = false;
    try { result = std::filesystem::is_directory(path_name); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}

FILDEF u64 last_file_write_time (std::string file_name)
{
    u64 result = 0;
    try { result = std::chrono::time_point_cast<std::chrono::milliseconds>(std::filesystem::last_write_time(file_name)).time_since_epoch().count(); }
    catch (std::filesystem::filesystem_error& e) { LOG_ERROR(ERR_MIN, "File System Error: %s", e.what()); }
    return result;
}

FILDEF int compare_file_write_times (u64 a, u64 b)
{
    return (a == b) ? 0 : (a < b) ? -1 : 1;
}

FILDEF std::string make_path_absolute (std::string path_name)
{
    if (!is_path_absolute(path_name)) path_name.insert(0, get_executable_path());
    return path_name;
}

FILDEF std::string fix_path_slashes (std::string path_name)
{
    std::replace(path_name.begin(), path_name.end(), '\\', '/');
    return path_name;
}

FILDEF std::string strip_file_path (std::string file_name)
{
    file_name = fix_path_slashes(file_name);
    size_t last_slash = file_name.rfind('/');
    if (last_slash != std::string::npos)
    {
        if (last_slash == file_name.length()) file_name.clear();
        else file_name = file_name.substr(last_slash+1);
    }
    return file_name;
}

FILDEF std::string strip_file_ext (std::string file_name)
{
    file_name = fix_path_slashes(file_name);
    size_t last_dot = file_name.rfind('.');
    if (last_dot != std::string::npos)
    {
        if (last_dot == 0) file_name.clear();
        else file_name = file_name.substr(0, last_dot);
    }
    return file_name;
}

FILDEF std::string strip_file_name (std::string file_name)
{
    file_name = fix_path_slashes(file_name);
    size_t last_slash = file_name.rfind('/');
    if (last_slash != std::string::npos && last_slash != file_name.length())
    {
        file_name = file_name.substr(0, last_slash+1);
    }
    return file_name;
}

FILDEF std::string strip_file_path_and_ext (std::string file_name)
{
    return strip_file_ext(strip_file_path(file_name));
}

FILDEF void tokenize_string (const std::string& str, const char* delims,
                             std::vector<std::string>& tokens)
{
    size_t prev = 0;
    size_t pos;

    while ((pos = str.find_first_of(delims, prev)) != std::string::npos)
    {
        if (pos > prev) tokens.push_back(str.substr(prev, pos-prev));
        prev = pos+1;
    }
    if (prev < str.length())
    {
        tokens.push_back(str.substr(prev, std::string::npos));
    }
}

INLDEF std::string format_string (const char* format, ...)
{
    va_list args;
    va_start(args, format);
    std::string str = format_string_v(format, args);
    va_end(args);
    return str;
}

INLDEF std::string format_string_v (const char* format, va_list args)
{
    std::string str;
    int size = 2048; // vsnprintf(NULL, 0, format, args) + 1; // @Incomplete: Seems like you can't call this with NULL on OSX? Look more into it...
    char* buffer = cstd_malloc(char, size);
    if (buffer)
    {
        vsnprintf(buffer, size, format, args);
        str = buffer;
        cstd_free(buffer);
    }
    return str;
}

FILDEF vec2 get_mouse_pos ()
{
    int imx, imy;
    SDL_GetMouseState(&imx, &imy);
    return vec2(CAST(float, imx), CAST(float, imy));
}

INLDEF std::string format_time (const char* format)
{
    time_t     raw_time = time(NULL);
    struct tm* cur_time = localtime(&raw_time);

    size_t length = 256;
    size_t result = 0;

    // We go until our buffer is big enough.
    char* buffer = NULL;
    do
    {
        if (buffer) cstd_free(buffer);
        buffer = cstd_malloc(char, length);
        if (!buffer) return std::string();

        result = strftime(buffer, length, format, cur_time);
        length *= 2;
    }
    while (!result);

    defer { cstd_free(buffer); };
    return std::string(buffer);
}

FILDEF std::thread::id get_thread_id ()
{
    return std::this_thread::get_id();
}

FILDEF bool point_in_bounds_xyxy (vec2 p, quad q)
{
    return (p.x >= q.x1 && p.y >= q.y1 && p.x <= q.x2 && p.y <= q.y2);
}

FILDEF bool point_in_bounds_xywh (vec2 p, quad q)
{
    return (p.x >= q.x && p.y >= q.y && p.x < (q.x+q.w) && p.y < (q.y+q.h));
}

FILDEF bool insensitive_compare (const std::string& a, const std::string& b)
{
    if (a.length() != b.length()) return false;
    for (std::string::size_type i=0; i<a.length(); ++i)
    {
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}

FILDEF bool string_replace (std::string& str, const std::string& from, const std::string& to)
{
    std::string::size_type start_pos = str.find(from);
    if (start_pos == std::string::npos) return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
