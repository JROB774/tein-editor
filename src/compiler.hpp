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
#elif defined(__clang__)
#define COMPILER_NAME "Clang"
#define COMPILER_CLANG 1
#endif

// List of offical values that could potentially be assigned to _MSC_VER.
// <https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros>

#define MSVC_VER_06_00 1200
#define MSVC_VER_07_00 1300
#define MSVC_VER_07_01 1310
#define MSVC_VER_08_00 1400
#define MSVC_VER_09_00 1500
#define MSVC_VER_10_00 1600
#define MSVC_VER_11_00 1700
#define MSVC_VER_12_00 1800
#define MSVC_VER_14_00 1900
#define MSVC_VER_15_00 1910
#define MSVC_VER_15_03 1911
#define MSVC_VER_15_05 1912
#define MSVC_VER_15_06 1913
#define MSVC_VER_15_07 1914
#define MSVC_VER_15_08 1915
#define MSVC_VER_15_09 1916
#define MSVC_VER_16_00 1920
#define MSVC_VER_16_01 1921
#define MSVC_VER_16_02 1922
#define MSVC_VER_16_03 1923

// Due to Microsoft's confusing method of tracking versions of the MSVC
// compiler we have to employ this long list to obtain specific major,
// minor, and patch versions for the Visual Studio compiler... oh well.

#if defined(COMPILER_MSVC)
// Visual Studio 6.0
#if   (_MSC_VER == MSVC_VER_06_00)
#define COMPILER_VERSION_MAJOR  6
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio .NET 2002 (7.0)
#elif (_MSC_VER == MSVC_VER_07_00)
#define COMPILER_VERSION_MAJOR  7
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio .NET 2003 (7.1)
#elif (_MSC_VER == MSVC_VER_07_01)
#define COMPILER_VERSION_MAJOR  7
#define COMPILER_VERSION_MINOR  1
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2005 (8.0)
#elif (_MSC_VER == MSVC_VER_08_00)
#define COMPILER_VERSION_MAJOR  8
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2008 (9.0)
#elif (_MSC_VER == MSVC_VER_09_00)
#define COMPILER_VERSION_MAJOR  9
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2010 (10.0)
#elif (_MSC_VER == MSVC_VER_10_00)
#define COMPILER_VERSION_MAJOR 10
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2012 (11.0)
#elif (_MSC_VER == MSVC_VER_11_00)
#define COMPILER_VERSION_MAJOR 11
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2013 (12.0)
#elif (_MSC_VER == MSVC_VER_12_00)
#define COMPILER_VERSION_MAJOR 12
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2015 (14.0)
#elif (_MSC_VER == MSVC_VER_14_00)
#define COMPILER_VERSION_MAJOR 14
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 RTW (15.0)
#elif (_MSC_VER == MSVC_VER_15_00)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.3
#elif (_MSC_VER == MSVC_VER_15_03)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  3
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.5
#elif (_MSC_VER == MSVC_VER_15_05)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  5
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.6
#elif (_MSC_VER == MSVC_VER_15_06)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  6
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.7
#elif (_MSC_VER == MSVC_VER_15_07)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  7
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.8
#elif (_MSC_VER == MSVC_VER_15_08)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  8
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2017 version 15.9
#elif (_MSC_VER == MSVC_VER_15_09)
#define COMPILER_VERSION_MAJOR 15
#define COMPILER_VERSION_MINOR  9
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2019 RTW (16.0)
#elif (_MSC_VER == MSVC_VER_16_00)
#define COMPILER_VERSION_MAJOR 16
#define COMPILER_VERSION_MINOR  0
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2019 version 16.1
#elif (_MSC_VER == MSVC_VER_16_01)
#define COMPILER_VERSION_MAJOR 16
#define COMPILER_VERSION_MINOR  1
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2019 version 16.2
#elif (_MSC_VER == MSVC_VER_16_02)
#define COMPILER_VERSION_MAJOR 16
#define COMPILER_VERSION_MINOR  2
#define COMPILER_VERSION_PATCH  0
// Visual Studio 2019 version 16.3
#elif (_MSC_VER == MSVC_VER_16_03)
#define COMPILER_VERSION_MAJOR 16
#define COMPILER_VERSION_MINOR  3
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

// Clang compiler version defines to determine current compiler version.
#if defined(COMPILER_CLANG)
#define COMPILER_VERSION_MAJOR __clang_major__
#define COMPILER_VERSION_MINOR __clang_minor__
#define COMPILER_VERSION_PATCH __clang_patch__
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
