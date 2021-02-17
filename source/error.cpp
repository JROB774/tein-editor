GLOBAL constexpr const char* ERROR_LOG_NAME =  "logs/error_editor.log";

GLOBAL FILE* error_log;

STDDEF void internal__log_error (const char* file, int line, Error_Level level, const char* format, ...)
{
    // We only open the error log once the first error occurs.
    if (!error_log)
    {
        std::string error_log_name(build_resource_string(ERROR_LOG_NAME));
        create_path(strip_file_name(error_log_name));
        error_log = fopen(error_log_name.c_str(), "a");
    }

    va_list args;

    std::string file_str = fix_path_slashes(file);
    std::string time_str = format_time("%m/%d/%Y %H:%M:%S");

    const char* err_format = "[%s] Error in %s at line %d: ";

    #if defined(BUILD_DEBUG)
    va_start(args, format);
    fprintf(stderr, err_format, time_str.c_str(), file_str.c_str(), line);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
    fflush(stderr);
    #endif

    if (error_log)
    {
        va_start(args, format);
        fprintf(error_log, err_format, time_str.c_str(), file_str.c_str(), line);
        vfprintf(error_log, format, args);
        fprintf(error_log, "\n");
        va_end(args);
        fflush(error_log);
    }

    if (level == ERR_MIN) return;

    va_start(args, format);
    std::string msg = format_string_v(format, args);
    show_alert("Error!", msg, ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "WINMAIN");
    va_end(args);

    if (level == ERR_MED) return;

    main_running = false;

    if (error_maximum_callback)
    {
        error_maximum_callback();
    }
}

FILDEF bool init_error_system ()
{
    return true;
}

FILDEF void quit_error_system ()
{
    // This condition is important because, for some reason, calling
    // fclose(NULL) results in a long hang-time during program exit.
    if (error_log)
    {
        fclose(error_log);
        error_log = NULL;
    }
}
