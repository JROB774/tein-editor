#pragma once

// Set this callback and it will be called during fatal exception termination.
GLOBAL void(*error_terminate_callback)(void);

FILDEF bool init_error_system ();
FILDEF void quit_error_system ();

// It is best to not call log_error and just call the LOG_ERROR macro instead.
#define LOG_ERROR(...) log_error(__FILE__, __LINE__, __VA_ARGS__)

enum Error_Level
{
    ERR_MIN, // Log to file.
    ERR_MED, // Log to file, display alert.
    ERR_MAX  // Log to file, display alert, terminate.
};

STDDEF void log_error (const char* _file, int _line,
                       Error_Level _level,
                       const char* _format, ...);
