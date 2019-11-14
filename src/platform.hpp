#pragma once

// Determine which known platform we are running on to check support.

#if   (defined(WIN32) || defined(_WIN32) || defined(__WIN32__)) || \
      (defined(WIN64) || defined(_WIN64) || defined(__WIN64__)) || \
      (defined(__NT__))
#define PLATFORM_WINNT 1
#elif (defined(__linux__) || defined(__linux))
#define PLATFORM_LINUX 1
#elif (defined(__APPLE__) && defined(__MACH__))
#define PLATFORM_MACOS 1
#else
// We throw an error here in case we try to compile on an unknown
// platform, so that we clearly know that we need to add support.
#error Attempting to compile on an unknown platform!
#endif

#if defined(PLATFORM_WINNT)

// Microsoft's Windows header, unless prompted otherwise, will often
// define macros called 'min' and 'max'. These macros usually cause
// a number of issues and so if they are defined we undefine them.
//
// This is just a precaution in case a copy of the windows.h header
// has already been included without the use of the NOMINMAX define.
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

// Removes less-used APIs from <windows.h> include.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
// Removes the global min() and max() macros.
#ifndef NOMINMAX
#define NOMINMAX
#endif
// Stricter type-checking, no implicits.
#ifndef STRICT
#define STRICT
#endif

#include       <windows.h>
#include       <commdlg.h>
#include       <shlwapi.h>
#include      <shellapi.h>
#include       <objbase.h>
#include <shobjidl_core.h>
#include       <dbghelp.h>

#endif // PLATFORM_WINNT
