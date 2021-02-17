#pragma once

GLOBAL constexpr int APP_VER_MAJOR = 1;
GLOBAL constexpr int APP_VER_MINOR = 0;
GLOBAL constexpr int APP_VER_PATCH = 13;
GLOBAL constexpr int APP_VER_BUILD = 0;

GLOBAL constexpr const char* APP_VER_STR = "1.0.13.0";
GLOBAL constexpr int         APP_VER_NUM =  11300;

GLOBAL SDL_Event main_event;
GLOBAL bool      main_running;

FILDEF void init_application (int argc, char** argv);
FILDEF void quit_application ();

FILDEF void do_application ();

FILDEF bool handle_application_events ();
