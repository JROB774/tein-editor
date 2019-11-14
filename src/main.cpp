#include "compiler.hpp"

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
#include "platform.hpp"

#include "application.hpp"
#include "application.cpp"

int main (int argc_, char** argv_)
{
    defer { quit_application(); };
    error_terminate_callback = quit_application;
    init_application(argc_, argv_);
    while (main_running && handle_application_events()) {
        do_application();
    }
    return 0;
}
