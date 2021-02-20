#include <windows.h>
#include <commdlg.h>
#include <dbghelp.h>
#include <shlobj.h>
#include <shlobj_core.h>
#include <shlwapi.h>
#include <shellapi.h>

//
// Alert Prompt
//

FILDEF HWND internal__win32_get_window_handle (SDL_Window* window)
{
    SDL_SysWMinfo win_info = {};
    SDL_VERSION(&win_info.version);
    HWND hwnd = NULL;
    if (SDL_GetWindowWMInfo(window, &win_info))
    {
        hwnd = win_info.info.win.window;;
    }
    return hwnd;
}

STDDEF Alert_Result show_alert (std::string title, std::string msg, Alert_Type type, Alert_Button buttons, std::string window)
{
    int flags = 0;
    switch (type)
    {
        case (ALERT_TYPE_INFO):    flags |= MB_ICONINFORMATION; break;
        case (ALERT_TYPE_WARNING): flags |= MB_ICONWARNING;     break;
        case (ALERT_TYPE_ERROR):   flags |= MB_ICONERROR;       break;
    }
    switch (buttons)
    {
        case (ALERT_BUTTON_YES_NO_CANCEL): flags |= MB_YESNOCANCEL; break;
        case (ALERT_BUTTON_YES_NO):        flags |= MB_YESNO;       break;
        case (ALERT_BUTTON_OK):            flags |= MB_OK;          break;
        case (ALERT_BUTTON_OK_CANCEL):     flags |= MB_OKCANCEL;    break;
    }

    // NOTE: We don't allow hidden windows because it causes program hang.
    HWND hwnd = NULL;
    if (!window.empty() && !is_window_hidden(window))
    {
        hwnd = internal__win32_get_window_handle(get_window(window).window);
    }
    int ret = MessageBoxA(hwnd, msg.c_str(), title.c_str(), flags);

    Alert_Result result = ALERT_RESULT_INVALID;
    switch (ret)
    {
        case (IDCANCEL): result = ALERT_RESULT_CANCEL; break;
        case (IDOK):     result = ALERT_RESULT_OK;     break;
        case (IDNO):     result = ALERT_RESULT_NO;     break;
        case (IDYES):    result = ALERT_RESULT_YES;    break;
    }

    return result;
}

//
// File Dialog
//

GLOBAL constexpr size_t DIALOG_BUFFER_SIZE = UINT16_MAX+1;

FILDEF u32 internal__dialog_cooldown_callback (u32 interval, void* user_data)
{
    push_editor_event(EDITOR_EVENT_COOLDOWN, NULL, NULL);
    return 0;
}

FILDEF void internal__set_dialog_cooldown ()
{
    editor.cooldown_timer = SDL_AddTimer(60, internal__dialog_cooldown_callback, NULL);
    if (!editor.cooldown_timer)
    {
        LOG_ERROR(ERR_MIN, "Failed to setup dialog cooldown! (%s)", SDL_GetError());
    }
}

STDDEF std::vector<std::string> open_dialog (Dialog_Type type, bool multiselect)
{
    // NOTE: Used to prevent dialog box clicks from carrying into the editor.
    editor.dialog_box = true;

    defer { internal__set_dialog_cooldown(); };

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (type)
    {
    case (Dialog_Type::LVL    ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";                                                                        title = "Open";   ext = "lvl";  } break;
    case (Dialog_Type::CSV    ): { filter = "All Files (*.*)\0*.*\0CSV Files (*.csv)\0*.csv\0";                                                                        title = "Open";   ext = "csv";  } break;
    case (Dialog_Type::LVL_CSV): { filter = "All Files (*.*)\0*.*\0Supported Files (*.lvl; *.csv)\0*.lvl;*.csv\0CSV Files (*.csv)\0*.csv\0LVL Files (*.lvl)\0*.lvl\0"; title = "Open";   ext = "lvl";  } break;
    case (Dialog_Type::GPAK   ): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0";                                                                     title = "Unpack"; ext = "gpak"; } break;
    case (Dialog_Type::EXE    ): { filter = "All Files (*.*)\0*.*\0EXE Files (*.exe)\0*.exe\0";                                                                        title = "Open";   ext = "exe";  } break;
    }

    char file_buffer[DIALOG_BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = internal__win32_get_window_handle(get_window("WINMAIN").window);
    open_file_name.lStructSize  = sizeof(OPENFILENAMEA);
    open_file_name.nFilterIndex = 2;
    open_file_name.lpstrFilter  = filter;
    open_file_name.lpstrFile    = file_buffer;
    open_file_name.nMaxFile     = DIALOG_BUFFER_SIZE;
    open_file_name.lpstrDefExt  = ext;
    open_file_name.lpstrTitle   = title;
    open_file_name.Flags        = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_NOCHANGEDIR;

    if (multiselect)
    {
        open_file_name.Flags |= OFN_ALLOWMULTISELECT;
    }

    std::vector<std::string> files;
    if (!GetOpenFileNameA(&open_file_name))
    {
        DWORD error = CommDlgExtendedError();
        if (error) // Zero means the user cancelled -- not an actual error!
        {
            LOG_ERROR(ERR_MED, "Failed to open file! (Error: 0x%X)", error);
        }
    }
    else
    {
        const char* pos = file_buffer;
        if (*pos != '\0')
        {
            // Determines if there is just one file or multiple
            if (is_path(pos))
            {
                // First part is always the path.
                std::string path(fix_path_slashes(pos));
                path.push_back('/');
                // Then it is followed by all the names.
                pos += open_file_name.nFileOffset;
                while (*pos)
                {
                    files.push_back(path + std::string(pos));
                    pos += strlen(pos)+1;
                }
            }
            else
            {
                files.push_back(fix_path_slashes(pos));
            }
        }
    }

    return files;
}

STDDEF std::string save_dialog (Dialog_Type type)
{
    ASSERT(type != Dialog_Type::LVL_CSV);

    // NOTE: Used to prevent dialog box clicks from carrying into the editor.
    editor.dialog_box = true;

    defer { internal__set_dialog_cooldown(); };

    const char* filter = NULL;
    const char* title  = NULL;
    const char* ext    = NULL;

    switch (type)
    {
    case (Dialog_Type::LVL ): { filter = "All Files (*.*)\0*.*\0LVL Files (*.lvl)\0*.lvl\0";    title = "Save As"; ext = "lvl";  } break;
    case (Dialog_Type::CSV ): { filter = "All Files (*.*)\0*.*\0CSV Files (*.csv)\0*.csv\0";    title = "Save As"; ext = "csv";  } break;
    case (Dialog_Type::GPAK): { filter = "All Files (*.*)\0*.*\0GPAK Files (*.gpak)\0*.gpak\0"; title = "Pack";    ext = "gpak"; } break;
    case (Dialog_Type::EXE ): { filter = "All Files (*.*)\0*.*\0EXE Files (*.exe)\0*.exe\0";    title = "Save As"; ext = "exe";  } break;
    }

    char file_buffer[DIALOG_BUFFER_SIZE] = {};

    OPENFILENAMEA open_file_name = {};

    open_file_name.hwndOwner    = internal__win32_get_window_handle(get_window("WINMAIN").window);
    open_file_name.lStructSize  = sizeof(OPENFILENAMEA);
    open_file_name.nFilterIndex = 2;
    open_file_name.lpstrFilter  = filter;
    open_file_name.lpstrFile    = file_buffer;
    open_file_name.nMaxFile     = DIALOG_BUFFER_SIZE;
    open_file_name.lpstrDefExt  = ext;
    open_file_name.lpstrTitle   = title;
    open_file_name.Flags        = OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT|OFN_NOREADONLYRETURN|OFN_NOCHANGEDIR;

    std::string file;
    if (!GetSaveFileNameA(&open_file_name))
    {
        DWORD error = CommDlgExtendedError();
        if (error) // Zero means the user cancelled -- not an actual error!
        {
            LOG_ERROR(ERR_MED, "Failed to save file! (Error: 0x%X)", error);
        }
    }
    else
    {
        file = fix_path_slashes(file_buffer);
    }

    return file;
}

STDDEF std::vector<std::string> path_dialog (bool multiselect)
{
    // NOTE: Used to prevent dialog box clicks from carrying into the editor.
    editor.dialog_box = true;

    defer { internal__set_dialog_cooldown(); };

    std::vector<std::string> paths;

    IFileOpenDialog* file_dialog = NULL;
    if (!SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&file_dialog))))
    {
        LOG_ERROR(ERR_MED, "Failed to create the folder dialog!");
        return paths;
    }
    defer { file_dialog->Release(); };

    DWORD options;
    if (!SUCCEEDED(file_dialog->GetOptions(&options)))
    {
        LOG_ERROR(ERR_MED, "Failed to get folder dialog options!");
        return paths;
    }

    if (multiselect) options |= FOS_ALLOWMULTISELECT;
    options |= FOS_PICKFOLDERS;

    file_dialog->SetOptions(options);
    if (!SUCCEEDED(file_dialog->Show(NULL)))
    {
        // No error because the user may have only cancelled...
        return paths;
    }

    IShellItemArray* shell_item_array = NULL;
    if (!SUCCEEDED(file_dialog->GetResults(&shell_item_array)))
    {
        LOG_ERROR(ERR_MED, "Failed to create shell item array!");
        return paths;
    }
    defer { shell_item_array->Release(); };

    LPWSTR result     = NULL;
    DWORD  item_count = 0;

    IShellItem* shell_item = NULL;
    shell_item_array->GetCount(&item_count);

    for (DWORD i=0; i<item_count; ++i)
    {
        shell_item_array->GetItemAt(i, &shell_item);
        if (shell_item)
        {
            shell_item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &result);
            if (result)
            {
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

    return paths;
}

//
// Crash Handler
//

GLOBAL constexpr const char* CRASH_DUMP_PATH = "crashes/";

// Unhandled exception dump taken from here <https://stackoverflow.com/a/700108>
FILDEF LONG WINAPI internal__unhandled_exception_filter (struct _EXCEPTION_POINTERS* info)
{
    show_alert("Error", "Fatal exception occurred!\nCreating crash dump!",
        ALERT_TYPE_ERROR, ALERT_BUTTON_OK);

    std::string path_name(get_appdata_path() + CRASH_DUMP_PATH);
    create_path(path_name);

    std::string file_name(path_name + std::to_string(CAST(unsigned int, time(NULL))) + ".dmp");
    HANDLE file = CreateFileA(file_name.c_str(), GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file != INVALID_HANDLE_VALUE)
    {
        defer { CloseHandle(file); };

        MINIDUMP_EXCEPTION_INFORMATION mini_dump_info = {};
        mini_dump_info.ThreadId          = GetCurrentThreadId();
        mini_dump_info.ExceptionPointers = info;
        mini_dump_info.ClientPointers    = TRUE;

        MINIDUMP_TYPE type = CAST(MINIDUMP_TYPE, MiniDumpWithFullMemory|MiniDumpWithHandleData);
        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
            file, type, &mini_dump_info, NULL, NULL);
    }

    if (error_terminate_callback)
    {
        error_terminate_callback();
    }

    return EXCEPTION_EXECUTE_HANDLER;
}

STDDEF void setup_crash_handler ()
{
    SetUnhandledExceptionFilter(&internal__unhandled_exception_filter);
}

//
// Miscellaneous
//

STDDEF std::string get_executable_path ()
{
    char buffer[MAX_PATH] = {};
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string path(fix_path_slashes(buffer));
    // Get rid of the actual executable so it's just the path.
    size_t last_slash = path.find_last_of('/');
    if (last_slash != std::string::npos) ++last_slash;
    return path.substr(0, last_slash);
}

STDDEF std::string get_appdata_path ()
{
    char buffer[MAX_PATH] = {};
    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, buffer))) return "";
    std::string path(fix_path_slashes(buffer));
    path += "/TheEndEditor/";
    if (!does_path_exist(path)) create_path(path);
    return path;
}

FILDEF void make_window_a_child (std::string name)
{
    HWND hwnd = internal__win32_get_window_handle(get_window(name).window);
    LONG old = GetWindowLongA(hwnd, GWL_EXSTYLE);
    SetWindowLongA(hwnd, GWL_EXSTYLE, old|WS_EX_TOOLWINDOW);
}

FILDEF bool run_executable (std::string exe)
{
    PROCESS_INFORMATION process_info = {};
    STARTUPINFOA        startup_info = {};

    startup_info.cb = sizeof(STARTUPINFOA);

    if (!CreateProcessA(exe.c_str(), NULL,NULL,NULL, FALSE, 0, NULL,
        strip_file_name(exe).c_str(), &startup_info, &process_info))
    {
        return false;
    }

    // Win32 API docs state these should be closed.
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);

    return true;
}

FILDEF void load_webpage (std::string url)
{
    ShellExecuteA(NULL, NULL, url.c_str(), NULL, NULL, SW_SHOW);
}
