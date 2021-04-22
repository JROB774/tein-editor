#pragma once

GLOBAL constexpr const char* APP_TITLE = "The End is Nigh: Editor";

GLOBAL constexpr int APP_VER_MAJOR = 1;
GLOBAL constexpr int APP_VER_MINOR = 0;
GLOBAL constexpr int APP_VER_PATCH = 16;

#if defined(BUILD_DEBUG)
GLOBAL constexpr const char* APP_BUILD = "Debug";
#else
GLOBAL constexpr const char* APP_BUILD = "Release";
#endif

#if defined(BUILD_X64)
GLOBAL constexpr const char* APP_ARCH = "64-bit";
#endif
#if defined(BUILD_X86)
GLOBAL constexpr const char* APP_ARCH = "32-bit";
#endif

GLOBAL constexpr const char* CRASH_DUMP_PATH = "crashes/";
GLOBAL constexpr const char* BACKUPS_PATH = "backups/";
GLOBAL constexpr const char* LOGS_PATH = "logs/";

GLOBAL SDL_Event main_event;
GLOBAL bool main_running;

FILDEF void init_application (int argc, char** argv);
FILDEF void quit_application ();

FILDEF void do_application ();

FILDEF bool handle_application_events ();
