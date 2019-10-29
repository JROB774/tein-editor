GLOBAL constexpr const char* ERROR_LOG_NAME = "logs/error_editor.log";

GLOBAL FILE* error_log;

// This function handles the graceful termination in the case of an unexpected
// exception, or issue with the exception handling system that requires exit.
//
// We do not really handle exceptions in our own code but systems such as STL
// do so, we implement this terminate handler to clean-up properly and exit as
// gracefully as possible in the case of any exceptional run-time behaviour.

STDDEF void internal__handle_terminate ()
{
    // Perform the standard program clean-up and termination that would
    // occur during a normal/graceful exit of the program. We do this
    // in the hopes to free memory and system resources during failure.

    LOG_ERROR(ERR_MAX, "Unhandled exception!");
    if (error_terminate_callback) { error_terminate_callback(); }
}

FILDEF bool init_error_system ()
{
    std::set_terminate(internal__handle_terminate);
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

    // In debug mode it is helpful to print to console/terminal.
    #if defined(DEBUG_BUILD)
    va_start(args, _format);
    fprintf (stderr,  format, time_str.c_str(), file_str.c_str(), _line);
    vfprintf(stderr, _format, args);
    fprintf (stderr, "\n");
    va_end  (args);
    #endif // DEBUG_BUILD

    if (_level == ERR_MIN) { return; }

    va_start(args, _format);
    std::string msg = format_string_v(_format, args);
    show_alert("Error!", msg.c_str(), ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "WINMAIN");
    va_end(args);

    if (_level == ERR_MED) { return; }

    main_running = false;

    // We also attempt to save the current levels in the hopes that the
    // content can be restored even though there was a fatal exception.
    for (size_t i=0; i<editor.tabs.size(); ++i) {
        std::string file_name;
        if      (editor.tabs.at(i).type == TAB_TYPE_LEVEL) { file_name = ".lvl.restore" + std::to_string(i);           }
        else if (editor.tabs.at(i).type == TAB_TYPE_MAP  ) { file_name = ".csv.restore" + std::to_string(i);           }
        file_name = make_path_absolute(file_name.c_str());
        if      (editor.tabs.at(i).type == TAB_TYPE_LEVEL) { save_restore_level(editor.tabs.at(i), file_name.c_str()); }
        else if (editor.tabs.at(i).type == TAB_TYPE_MAP  ) { save_restore_map  (editor.tabs.at(i), file_name.c_str()); }
    }
}
