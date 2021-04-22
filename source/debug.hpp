#pragma once

#define LOG_DEBUG(...) internal__log_debug(__VA_ARGS__)

FILDEF void quit_debug_system ();

FILDEF void begin_debug_timer (const char* name);
FILDEF void end_debug_timer   ();
