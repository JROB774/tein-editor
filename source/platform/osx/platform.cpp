//
// Alert Prompt
//

STDDEF Alert_Result show_alert (std::string title, std::string msg, Alert_Type type, Alert_Button buttons, std::string window)
{
    // @Incomplete: ...
    return ALERT_RESULT_INVALID;
}

//
// File Dialog
//

STDDEF std::vector<std::string> open_dialog (Dialog_Type type, bool multiselect)
{
    // @Incomplete: ...
    return std::vector<std::string>();
}
STDDEF std::string save_dialog (Dialog_Type type)
{
    ASSERT(type != Dialog_Type::LVL_CSV);
    // @Incomplete: ...
    return "";
}
STDDEF std::vector<std::string> path_dialog (bool multiselect)
{
    // @Incomplete: ...
    return std::vector<std::string>();
}

//
// Crash Handler
//

STDDEF void setup_crash_handler ()
{
    // @Incomplete: ...
}

//
// Miscellaneous
//

STDDEF std::string get_executable_path ()
{
    // @Incomplete: ...
    return "";
}
STDDEF std::string get_appdata_path ()
{
    // @Incomplete: ...
    return "";
}
FILDEF bool run_executable (std::string exe)
{
    // @Incomplete: ...
    return true;
}
FILDEF void load_webpage (std::string url)
{
    // @Incomplete: ...
}
