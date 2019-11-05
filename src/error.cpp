GLOBAL constexpr const char* CRASH_DUMP_NAME = "TheEndEditor-Crash.dmp";
GLOBAL constexpr const char* DEBUG_DUMP_NAME = "TheEndEditor-Debug.dmp";
GLOBAL constexpr const char*  ERROR_LOG_NAME =  "logs/error_editor.log";

GLOBAL FILE* error_log;

STDDEF void internal__handle_terminate ()
{
    LOG_ERROR(ERR_MAX, "Unhandled exception!");
    if (error_terminate_callback) { error_terminate_callback(); }
}

// Unhandled exception dump taken from here: https://stackoverflow.com/a/700108
#if defined(PLATFORM_WINNT)
FILDEF LONG WINAPI internal__unhandled_exception_filter (struct _EXCEPTION_POINTERS* _info)
{
    show_alert("Error", "Fatal exception occurred!\nCreating crash dump!", ALERT_TYPE_ERROR, ALERT_BUTTON_OK);

    std::string file_name(make_path_absolute(CRASH_DUMP_NAME));
    HANDLE file = CreateFile(file_name.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    defer { CloseHandle(file); };

    MINIDUMP_EXCEPTION_INFORMATION mini_dump_info = {};
    mini_dump_info.ThreadId          = GetCurrentThreadId();
    mini_dump_info.ExceptionPointers = _info;
    mini_dump_info.ClientPointers    = TRUE;

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file,
      CAST(MINIDUMP_TYPE, MiniDumpWithFullMemory|MiniDumpWithHandleData),
      &mini_dump_info, NULL, NULL);

    if (error_terminate_callback) { error_terminate_callback(); }

    return EXCEPTION_EXECUTE_HANDLER;
}
#endif // PLATFORM_WINNT

FILDEF bool init_error_system ()
{
    std::set_terminate(internal__handle_terminate);
    #if defined(PLATFORM_WINNT)
    SetUnhandledExceptionFilter(&internal__unhandled_exception_filter);
    #endif // PLATFORM_WINNT

    return true;
}

FILDEF void quit_error_system ()
{
    // This condition is important because, for some reason, calling
    // fclose(NULL) results in a long hang-time during program exit.
    if (error_log) {
        fclose(error_log);
        error_log = NULL;
    }
}

#if defined(PLATFORM_WINNT)
FILDEF void generate_minidump ()
{
    std::string file_name(make_path_absolute(DEBUG_DUMP_NAME));
    HANDLE file = CreateFile(file_name.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    defer { CloseHandle(file); };

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file,
      CAST(MINIDUMP_TYPE, MiniDumpWithFullMemory|MiniDumpWithHandleData),
      NULL, NULL, NULL);
}
#endif // PLATFORM_WINNT

STDDEF void log_error (const char* _file, int _line, Error_Level _level, const char* _format, ...)
{
    // We only open the error log once the first error occurs.
    if (!error_log) {
        std::string error_log_name(build_resource_string(ERROR_LOG_NAME));
        create_path(strip_file_name(error_log_name.c_str()).c_str());
        error_log = fopen(error_log_name.c_str(), "a");
    }

    va_list args;

    // Make sure file slashes are consistent -- we prefer forward slashes;
    // and format the time so we can print it with the error in the log.
    std::string file_str = fix_path_slashes(_file);
    std::string time_str = format_time("%m/%d/%Y %H:%M:%S");

    const char* format = "[%s] Error in %s at line %d: ";

    // Writes the formatted error message to the error log file.
    va_start(args, _format);
    fprintf (error_log,  format, time_str.c_str(), file_str.c_str(), _line);
    vfprintf(error_log, _format, args);
    fprintf (error_log, "\n");
    va_end  (args);
    fflush  (error_log);

    // In debug mode it is helpful to print to console/terminal.
    #if defined(DEBUG_BUILD)
    va_start(args, _format);
    fprintf (stderr,  format, time_str.c_str(), file_str.c_str(), _line);
    vfprintf(stderr, _format, args);
    fprintf (stderr, "\n");
    va_end  (args);
    fflush  (stderr);
    #endif // DEBUG_BUILD

    if (_level == ERR_MIN) { return; }

    va_start(args, _format);
    std::string msg = format_string_v(_format, args);
    show_alert("Error!", msg.c_str(), ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "WINMAIN");
    va_end(args);

    if (_level == ERR_MED) { return; }

    main_running = false;

    // We also attempt to save the current tabs in the hopes that the
    // content can be restored even though there was a fatal error.
    for (size_t i=0; i<editor.tabs.size(); ++i) {
        std::string file_name;
        if      (editor.tabs.at(i).type == TAB_TYPE_LEVEL) { file_name = ".lvl.restore" + std::to_string(i);           }
        else if (editor.tabs.at(i).type == TAB_TYPE_MAP  ) { file_name = ".csv.restore" + std::to_string(i);           }
        file_name = make_path_absolute(file_name.c_str());
        if      (editor.tabs.at(i).type == TAB_TYPE_LEVEL) { save_restore_level(editor.tabs.at(i), file_name.c_str()); }
        else if (editor.tabs.at(i).type == TAB_TYPE_MAP  ) { save_restore_map  (editor.tabs.at(i), file_name.c_str()); }
    }
}
