GLOBAL constexpr const char* DEBUG_LOG_NAME = "logs/debug_editor.log";

GLOBAL int   current_debug_section = 0;
GLOBAL FILE* debug_log;

struct Debug_Timer
{
    std::string  name;
    u64 start_counter;
};

GLOBAL std::stack<Debug_Timer> debug_timers;
GLOBAL std::vector<std::string> debug_timer_results;

STDDEF void internal__log_debug (const char* format, ...)
{
    // We only open the debug log once the first debug occurs.
    if (!debug_log)
    {
        std::string debug_log_name(build_resource_string(DEBUG_LOG_NAME));
        create_path(strip_file_name(debug_log_name));
        debug_log = fopen(debug_log_name.c_str(), "w");
        if (debug_log)
        {
            LOG_DEBUG("DEBUG LOG [%s]", format_time("%m/%d/%Y %H:%M:%S").c_str());
        }
    }

    va_list args;

    #if defined(BUILD_DEBUG)
    va_start(args, format);
    for (int i=0; i<current_debug_section; ++i)
    {
        fprintf(stdout, "  ");
    }
    vfprintf(stdout, format, args);
    fprintf(stdout, "\n");
    va_end(args);
    fflush(stdout);
    #endif

    if (debug_log)
    {
        va_start(args, format);
        for (int i=0; i<current_debug_section; ++i)
        {
            fprintf(debug_log, "  ");
        }
        vfprintf(debug_log, format, args);
        fprintf(debug_log, "\n");
        va_end(args);
        fflush(debug_log);
    }
}

FILDEF void begin_debug_section (const char* name)
{
    if (name) LOG_DEBUG("%s", name);
    current_debug_section++;
}

FILDEF void end_debug_section ()
{
    if (current_debug_section > 0) current_debug_section--;
}

FILDEF void quit_debug_system ()
{
    // This condition is important because, for some reason, calling
    // fclose(NULL) results in a long hang-time during program exit.
    if (debug_log)
    {
        fclose(debug_log);
        debug_log = NULL;
    }
}

#if defined(BUILD_DEBUG)

FILDEF void begin_debug_timer (const char* name)
{
    Debug_Timer timer = {};
    timer.start_counter = SDL_GetPerformanceCounter();
    timer.name = name;
    debug_timers.push(timer);
}

FILDEF void end_debug_timer ()
{
    Debug_Timer timer = debug_timers.top();
    debug_timers.pop();

    u64   start_counter = timer.start_counter;
    u64   end_counter   = SDL_GetPerformanceCounter();
    float frequency     = CAST(float, SDL_GetPerformanceFrequency());
    float elapsed       = CAST(float, end_counter - start_counter);
    float seconds       = (elapsed / frequency);

    std::string str(format_string("%s took %fs.", timer.name.c_str(), seconds));
    debug_timer_results.push_back(str);
}

FILDEF void clear_debug_timer_results ()
{
    debug_timer_results.clear();
}

FILDEF void dump_debug_timer_results  ()
{
    if (!debug_timer_results.empty())
    {
        begin_debug_section("Debug Timer Results:");
        for (auto str: debug_timer_results) LOG_DEBUG(str.c_str());
        end_debug_section();
    }
}

#endif
