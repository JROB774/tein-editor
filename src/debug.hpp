#pragma once

FILDEF void quit_debug_system ();

// Used to handle indentation of debug messages to the log.
FILDEF void begin_debug_section (const char* _name = NULL);
FILDEF void end_debug_section   ();

STDDEF void log_debug (const char* _format, ...);
#define LOG_DEBUG(_fmt, ...) log_debug(_fmt, __VA_ARGS__)

#if defined(DEBUG_BUILD)
FILDEF void begin_debug_timer (const char* _name);
FILDEF void end_debug_timer   ();
FILDEF void clear_debug_timer_results ();
FILDEF void dump_debug_timer_results  ();
#else
#define begin_debug_timer(_name)
#define end_debug_timer()
#define clear_debug_timer_results()
#define dump_debug_timer_results()
#endif // DEBUG_BUILD
