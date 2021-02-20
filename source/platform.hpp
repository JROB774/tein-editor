#pragma once

//
// Alert Prompt
//

enum Alert_Button
{
    ALERT_BUTTON_YES_NO_CANCEL,
    ALERT_BUTTON_YES_NO,
    ALERT_BUTTON_OK,
    ALERT_BUTTON_OK_CANCEL
};

enum Alert_Type
{
    ALERT_TYPE_INFO,
    ALERT_TYPE_WARNING,
    ALERT_TYPE_ERROR
};

enum Alert_Result
{
    ALERT_RESULT_INVALID,
    ALERT_RESULT_CANCEL,
    ALERT_RESULT_OK,
    ALERT_RESULT_NO,
    ALERT_RESULT_YES
};

STDDEF Alert_Result show_alert (std::string title, std::string msg, Alert_Type type, Alert_Button buttons, std::string window = "");

//
// File Dialog
//

enum class Dialog_Type { LVL, CSV, LVL_CSV, GPAK, EXE };

STDDEF std::vector<std::string> open_dialog (Dialog_Type type, bool multiselect = true);
STDDEF std::string              save_dialog (Dialog_Type type);
STDDEF std::vector<std::string> path_dialog (                  bool multiselect = true);

//
// Crash Handler
//

STDDEF void setup_crash_handler ();

//
// Miscellaneous
//

STDDEF std::string get_executable_path ();
STDDEF std::string get_appdata_path    ();
FILDEF bool        run_executable      (std::string exe);
FILDEF void        load_webpage        (std::string url);
