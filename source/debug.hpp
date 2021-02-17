#pragma once

#define LOG_DEBUG(...) internal__log_debug(__VA_ARGS__)

// Used to handle indentation of debug messages to the log.
FILDEF void begin_debug_section (const char* name = NULL);
FILDEF void end_debug_section   ();

FILDEF void quit_debug_system ();

#if defined(BUILD_DEBUG)
FILDEF void begin_debug_timer         (const char* name);
FILDEF void end_debug_timer           ();
FILDEF void clear_debug_timer_results ();
FILDEF void dump_debug_timer_results  ();
#else
FILDEF void begin_debug_timer         (const char* name) { /* Nothing */ }
FILDEF void end_debug_timer           ()                 { /* Nothing */ }
FILDEF void clear_debug_timer_results ()                 { /* Nothing */ }
FILDEF void dump_debug_timer_results  ()                 { /* Nothing */ }
#endif
