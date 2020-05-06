/*******************************************************************************
 * Defines regarding the compiler in use and compiler-specific functionality.
 * Authored By Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef COMPILER_H__ /*///////////////////////////////////////////////////////*/
#define COMPILER_H__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

// List of Compiler Defines: https://sourceforge.net/p/predef/wiki/Compilers/
// This can be used to define more potential compilers when support is added.
#ifdef _MSC_VER
#define COMPILER_MSVC  1
#else
#error Attempting to compile on an unsupported compiler!
#endif

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
#define COMPILER_HAS_CPLUSPLUS __cplusplus
#endif

#define STDCPP98 199711L
#define STDCPP11 201103L
#define STDCPP14 201402L
#define STDCPP17 201703L

#ifdef COMPILER_HAS_CPLUSPLUS
#if (COMPILER_HAS_CPLUSPLUS >= STDCPP98)
#define COMPILER_HAS_STDCPP98 1
#endif
#if (COMPILER_HAS_CPLUSPLUS >= STDCPP11)
#define COMPILER_HAS_STDCPP11 1
#endif
#if (COMPILER_HAS_CPLUSPLUS >= STDCPP14)
#define COMPILER_HAS_STDCPP14 1
#endif
#if (COMPILER_HAS_CPLUSPLUS >= STDCPP17)
#define COMPILER_HAS_STDCPP17 1
#endif
#endif

/* -------------------------------------------------------------------------- */

#if defined(COMPILER_MSVC)
#define COMPILER_HAS_PRAGMA_ONCE 1
#endif

/* -------------------------------------------------------------------------- */

#ifdef COMPILER_MSVC /*********************************************************/

// Microsoft Visual C++ Compiler Information
#define COMPILER_STRING COMPILER_NAME " (" COMPILER_VERSTR ")"
#define COMPILER_NAME   "Microsoft Visual C++"
#define COMPILER_VERNUM _MSC_VER
#define COMPILER_VERSTR STRINGIFY(COMPILER_VERNUM)
#define COMPILER_MAJOR  0
#define COMPILER_MINOR  0
#define COMPILER_PATCH  0

// We do not intend on using the secure CRT.
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#endif /* COMPILER_MSVC *******************************************************/

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* COMPILER_H__ ///////////////////////////////////////////////////////*/

/*******************************************************************************
 *
 * Copyright (c) 2020 Joshua Robertson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
*******************************************************************************/
