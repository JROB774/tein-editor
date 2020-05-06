/*******************************************************************************
 * General-purpose defines used throughout the codebase.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef STANDARD_H__ /*///////////////////////////////////////////////////////*/
#define STANDARD_H__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#define STRINGIFY( x) STRINGIFY1(x)
#define STRINGIFY1(x) #x

/* -------------------------------------------------------------------------- */

#define JOIN( a, b) JOIN2(a, b)
#define JOIN2(a, b) JOIN1(a, b)
#define JOIN1(a, b) a##b

/* -------------------------------------------------------------------------- */

#define CAST(t, x) ((t)(x))

/* -------------------------------------------------------------------------- */

#define PERSISTENT static
#define INTERNAL   static
#define GLOBAL     static
#define SHARED     static

/* -------------------------------------------------------------------------- */

#ifdef COMPILER_HAS_CPLUSPLUS
#define INLINE inline
#endif

#ifndef INLINE
#ifdef COMPILER_MSVC
#define INLINE __inline
#else
#error INLINE definition not implemented!
#endif
#endif

/* -------------------------------------------------------------------------- */

#ifdef COMPILER_MSVC
#define FORCE_INLINE __forceinline
#else
#error FORCE_INLINE definition not implemented!
#endif

/* -------------------------------------------------------------------------- */

#define STDDEF INTERNAL
#define INLDEF INTERNAL       INLINE
#define FILDEF INTERNAL FORCE_INLINE

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* STANDARD_H__ ///////////////////////////////////////////////////////*/

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
