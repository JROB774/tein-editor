#pragma once

// We determine what level of C++ standard support we have available to use.

#if (__cplusplus >= 201703L)
#define COMPILER_SUPPORTS_STDCPP17 1
#endif
#if (__cplusplus >= 201402L)
#define COMPILER_SUPPORTS_STDCPP14 1
#endif
#if (__cplusplus >= 201103L)
#define COMPILER_SUPPORTS_STDCPP11 1
#endif
#if (__cplusplus >= 199711L)
#define COMPILER_SUPPORTS_STDCPP98 1
#endif

// Many compilers may be missing, as this is just a list of compilers that
// we personally use; however, this listing can easilby be expanded later.
//
// Compiler listing at: <https://sourceforge.net/p/predef/wiki/Compilers/>

#if   defined(_MSC_VER)
#define COMPILER_NAME "MSVC"
#define COMPILER_MSVC  1
#elif defined(__GNUC__)
#define COMPILER_NAME "GCC"
#define COMPILER_GCC   1
#endif

// Due to Microsoft's confusing method of tracking versions of the MSVC
// compiler we have to employ this long list to obtain specific major,
// minor, and patch versions for the Visual Studio compiler... oh well.

#if defined(COMPILER_MSVC)
#if   (_MSC_VER ==  800)
#define COMPILER_VERSION_MAJOR  1
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER ==  900)
#define COMPILER_VERSION_MAJOR  3
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1000)
#define COMPILER_VERSION_MAJOR  4
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1020)
#define COMPILER_VERSION_MAJOR  4
#define COMPILER_VERSION_MINOR  2
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1100)
#define COMPILER_VERSION_MAJOR  5
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1200)
#define COMPILER_VERSION_MAJOR  6
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1300)
#define COMPILER_VERSION_MAJOR  7
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1310)
#define COMPILER_VERSION_MAJOR  7
#define COMPILER_VERSION_MINOR  1
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1400)
#define COMPILER_VERSION_MAJOR  8
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1500)
#define COMPILER_VERSION_MAJOR  9
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1600)
#define COMPILER_VERSION_MAJOR 10
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1700)
#define COMPILER_VERSION_MAJOR 11
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1800)
#define COMPILER_VERSION_MAJOR 12
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1900)
#define COMPILER_VERSION_MAJOR 14
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1910)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1911)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  3
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1912)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  5
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1913)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  6
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1914)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  7
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1915)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  8
#define COMPILER_VERSION_PATCH  0
#elif (_MSC_VER == 1916)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  9
#define COMPILER_VERSION_PATCH  0
#endif
#endif

// GCC did not introduce the patch level define until version 3.0. So if
// we don't have access to that define then we just set the patch to zero.

#if defined(COMPILER_GCC)
#define COMPILER_VERSION_MAJOR __GNUC__
#define COMPILER_VERSION_MINOR __GNUC_MINOR__
#if (__GNUC__ >= 3)
#define COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
#else
#define COMPILER_VERSION_PATCH 0
#endif
#endif

// If the compiler being used is unknown then the compiler version number
// is simply assigned default values of -1 to clarify that it is unknown.

#ifndef COMPILER_VERSION_MAJOR
#define COMPILER_VERSION_MAJOR -1
#endif
#ifndef COMPILER_VERSION_MINOR
#define COMPILER_VERSION_MINOR -1
#endif
#ifndef COMPILER_VERSION_PATCH
#define COMPILER_VERSION_PATCH -1
#endif

// We do not care about using the secure C run-time on the MSVC compiler.
// We rarely use the C run-time library as it is so this is not important.

#if defined(COMPILER_MSVC)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#endif
