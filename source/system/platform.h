/*******************************************************************************
 * Defines regarding the current platform and the architecture being used.
 * Authored By Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef PLATFORM_H__ /*///////////////////////////////////////////////////////*/
#define PLATFORM_H__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__)) || \
    (defined(WIN64) || defined(_WIN64) || defined(__WIN64__)) || \
    (defined(__NT__))
#define PLATFORM_WIN32 1
#else
#error Attempting to compile on an unsupported platform!
#endif

/* -------------------------------------------------------------------------- */

#ifdef PLATFORM_WIN32 /********************************************************/

// Windows Platform Information
#define PLATFORM_STRING PLATFORM_NAME " (" ARCHITECTURE_NAME ")"
#define PLATFORM_NAME   "Windows"

#if defined(_M_AMD64) || defined(_AMD64_) || defined(__x86_64__)
#define ARCHITECTURE_X64   1
#endif
#if defined(_M_IX86) || defined(_X86_)
#define ARCHITECTURE_X86   1
#endif
#if defined(_M_ARM64)
#define ARCHITECTURE_ARM64 1
#endif
#if defined(_M_ARM)
#define ARCHITECTURE_ARM32 1
#endif
#if defined(_M_IA64) || defined(_IA64_)
#define ARCHITECTURE_IA64  1
#endif

// Windows Architecture Information
#ifdef ARCHITECTURE_X64
#define ARCHITECTURE_NAME  "x64"
#define ARCHITECTURE_64BIT 1
#endif
#ifdef ARCHITECTURE_X86
#define ARCHITECTURE_NAME  "x86"
#define ARCHITECTURE_32BIT 1
#endif
#ifdef ARCHITECTURE_ARM64
#define ARCHITECTURE_NAME  "ARM64"
#define ARCHITECTURE_64BIT 1
#endif
#ifdef ARCHITECTURE_ARM32
#define ARCHITECTURE_NAME  "ARM32"
#define ARCHITECTURE_32BIT 1
#endif
#ifdef ARCHITECTURE_IA64
#define ARCHITECTURE_NAME  "IA-64"
#define ARCHITECTURE_64BIT 1
#endif

#endif /* PLATFORM_WIN32 ******************************************************/

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* PLATFORM_H__ ///////////////////////////////////////////////////////*/

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
