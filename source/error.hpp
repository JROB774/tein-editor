#pragma once

#define LOG_ERROR(...) internal__log_error(__FILE__, __LINE__, __VA_ARGS__)

// Set this callback and it will be called during fatal exception termination.
GLOBAL void(*error_terminate_callback)(void);
GLOBAL void(*error_maximum_callback)(void);

enum Error_Level { ERR_MIN, ERR_MED, ERR_MAX };

FILDEF void quit_error_system ();

// DO NOT CALL DIRECTLY!
STDDEF void internal__log_error (const char* file, int line, Error_Level level, const char* format, ...);
