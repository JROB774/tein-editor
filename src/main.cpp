#include "compiler.hpp"
#include "platform.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <cstdarg>

#include <exception>
#include <type_traits>
#include <atomic>
#include <algorithm>
#include <fstream>
#include <sstream>

#include <vector>
#include <array>
#include <map>
#include <deque>
#include <string>

#include "external.hpp"

#include "application.hpp"
#include "application.cpp"

int main (int _argc, char* _argv[])
{
    defer { quit_editor(); };

    // We keep this here just to catch and handle any potentially missed GON
    // errors/exceptions that may be in the code -- but it's highly unlikely.
    try {
        error_terminate_callback = quit_editor;
        init_editor(_argc, _argv);
        while (main_running && handle_editor_events()) {
            do_editor();
        }
    } catch (const char* _msg) {
        LOG_ERROR(ERR_MAX, "%s", _msg);
    }

    return 0;
}
