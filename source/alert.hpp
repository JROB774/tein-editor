#pragma once

#if defined(PLATFORM_WIN32)
GLOBAL constexpr int ALERT_BUTTON_YES_NO_CANCEL = MB_YESNOCANCEL;
GLOBAL constexpr int ALERT_BUTTON_YES_NO        = MB_YESNO;
GLOBAL constexpr int ALERT_BUTTON_OK            = MB_OK;
GLOBAL constexpr int ALERT_BUTTON_OK_CANCEL     = MB_OKCANCEL;
#else
#error ALERT_BUTTON enumeration not defined!
#endif

#if defined(PLATFORM_WIN32)
GLOBAL constexpr int ALERT_TYPE_INFO    = MB_ICONINFORMATION;
GLOBAL constexpr int ALERT_TYPE_WARNING = MB_ICONWARNING;
GLOBAL constexpr int ALERT_TYPE_ERROR   = MB_ICONERROR;
#else
#error ALERT_TYPE enumeration not defined!
#endif

#if defined(PLATFORM_WIN32)
GLOBAL constexpr int ALERT_RESULT_INVALID = 0;
GLOBAL constexpr int ALERT_RESULT_CANCEL  = IDCANCEL;
GLOBAL constexpr int ALERT_RESULT_OK      = IDOK;
GLOBAL constexpr int ALERT_RESULT_NO      = IDNO;
GLOBAL constexpr int ALERT_RESULT_YES     = IDYES;
#else
#error ALERT_RESULT enumeration not defined!
#endif

STDDEF int show_alert (std::string title, std::string msg, int type,
                       int buttons, std::string window = "");
