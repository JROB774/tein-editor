/*******************************************************************************
 * Debug facilities for logging messages and timing sections of code.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef DEBUG_HPP__ /*////////////////////////////////////////////////////////*/
#define DEBUG_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#define LOG_DEBUG(format, ...) internal__log_debug(format, __VA_ARGS__)

/* -------------------------------------------------------------------------- */

// Used to handle indentation of debug messages to the log.
FILDEF void begin_debug_section (const char* name = NULL);
FILDEF void end_debug_section   ();

/* -------------------------------------------------------------------------- */

FILDEF void quit_debug_system ();

/* -------------------------------------------------------------------------- */

#if defined(BUILD_DEBUG) /*****************************************************/

FILDEF void begin_debug_timer         (const char* name);
FILDEF void end_debug_timer           ();
FILDEF void clear_debug_timer_results ();
FILDEF void dump_debug_timer_results  ();

#else /************************************************************************/

FILDEF void begin_debug_timer         (const char* name) { /* Nothing */ }
FILDEF void end_debug_timer           ()                 { /* Nothing */ }
FILDEF void clear_debug_timer_results ()                 { /* Nothing */ }
FILDEF void dump_debug_timer_results  ()                 { /* Nothing */ }

#endif /* BUILD_DEBUG *********************************************************/

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* DEBUG_HPP__ ////////////////////////////////////////////////////////*/

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
