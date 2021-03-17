#pragma once

GLOBAL constexpr int APP_VER_MAJOR = 1;
GLOBAL constexpr int APP_VER_MINOR = 0;
GLOBAL constexpr int APP_VER_PATCH = 15;

GLOBAL constexpr const char* CRASH_DUMP_PATH = "crashes/";
GLOBAL constexpr const char* BACKUPS_PATH = "backups/";
GLOBAL constexpr const char* LOGS_PATH = "logs/";

GLOBAL SDL_Event main_event;
GLOBAL bool main_running;

FILDEF void init_application (int argc, char** argv);
FILDEF void quit_application ();

FILDEF void do_application ();

FILDEF bool handle_application_events ();
