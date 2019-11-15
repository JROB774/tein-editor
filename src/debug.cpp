GLOBAL constexpr const char* DEBUG_LOG_NAME = "logs/debug_editor.log";

GLOBAL int   current_debug_section = 0;
GLOBAL FILE* debug_log;

// Highly unlikely we will ever need any more debug timers than this but if we
// do we will know about it through various code ASSERTS and can just increase.
GLOBAL constexpr size_t DEBUG_TIMER_COUNT = 256;

struct Debug_Timer
{
    std::string  name;
    u64 start_counter;
};

GLOBAL Stack<Debug_Timer, DEBUG_TIMER_COUNT> debug_timers;
GLOBAL std::vector<std::string> debug_timer_results;

FILDEF void quit_debug_system ()
{
    // This condition is important because, for some reason, calling
    // fclose(NULL) results in a long hang-time during program exit.
    if (debug_log) {
        fclose(debug_log);
        debug_log = NULL;
    }
}

FILDEF void begin_debug_section (const char* _name)
{
    if (_name) { log_debug("%s", _name); }
    ++current_debug_section;
}
FILDEF void end_debug_section ()
{
    if (current_debug_section > 0) { --current_debug_section; }
}

STDDEF void log_debug (const char* _format, ...)
{
    // We only open the debug log once the first debug occurs.
    if (!debug_log) {
        std::string debug_log_name(build_resource_string(DEBUG_LOG_NAME));
        create_path(strip_file_name(debug_log_name.c_str()).c_str());
        debug_log = fopen(debug_log_name.c_str(), "w");
        if (debug_log) {
            LOG_DEBUG("DEBUG LOG [%s]", format_time("%m/%d/%Y %H:%M:%S").c_str());
        }
    }

    va_list args;

    // Writes the formatted debug message to the debug log file.
    if (debug_log) {
        va_start(args, _format);
        for (int i=0; i<current_debug_section; ++i) {
            fprintf(debug_log, "  ");
        }
        vfprintf(debug_log, _format, args);
        fprintf(debug_log, "\n");
        va_end(args);
        fflush(debug_log);
    }

    // In debug mode it is helpful to print to console/terminal.
    #if defined(DEBUG_BUILD)
    va_start(args, _format);
    for (int i=0; i<current_debug_section; ++i) {
        fprintf(stdout, "  ");
    }
    vfprintf(stdout, _format, args);
    fprintf(stdout, "\n");
    va_end(args);
    fflush(stdout);
    #endif // DEBUG_BUILD
}

#if defined(DEBUG_BUILD)
FILDEF void begin_debug_timer (const char* _name)
{
    Debug_Timer timer = {};
    timer.name = _name;
    timer.start_counter = SDL_GetPerformanceCounter();

    debug_timers.push(timer);
}
FILDEF void end_debug_timer ()
{
    Debug_Timer timer = debug_timers.pop();

    u64 start_counter = timer.start_counter;
    u64 end_counter = SDL_GetPerformanceCounter();

    float frequency = CAST(float, SDL_GetPerformanceFrequency());
    float elapsed   = CAST(float, end_counter - start_counter);
    float seconds   = (elapsed / frequency);

    debug_timer_results.push_back(format_string("%s took %f seconds.", timer.name.c_str(), seconds));
}
FILDEF void clear_debug_timer_results ()
{
    debug_timer_results.clear();
}
FILDEF void dump_debug_timer_results  ()
{
    if (!debug_timer_results.empty()) {
        begin_debug_section("Debug Timer Results:");
        for (auto str: debug_timer_results) {
            LOG_DEBUG(str.c_str());
        }
        end_debug_section();
    }
}
#endif // DEBUG_BUILD
