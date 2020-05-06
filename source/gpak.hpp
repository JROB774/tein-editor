/*******************************************************************************
 * Facilities for packing and unpacking file data from the GPAK file format.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef GPAK_HPP__ /*/////////////////////////////////////////////////////////*/
#define GPAK_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

// The GPAK system returns error codes as we don't want to call the error log
// system on another thread. So the returned code tells us which error to log.

enum class GPAK_Error
{
    NONE,   // Successfully packed/unpacked GPAK.
    WRITE,  // Failed to open the GPAK for writing.
    READ,   // Failed to open the GPAK for reading.
    EMPTY,  // No files were found in paths to pack.
};

struct GPAK_Entry
{
    u16  name_length;
    std::string name;
    u32    file_size;
};

/* -------------------------------------------------------------------------- */

FILDEF void gpak_unpack (std::string file_name, bool overwrite);
FILDEF void gpak_pack   (std::string file_name, std::vector<std::string> paths);

FILDEF float gpak_unpack_progress ();
FILDEF float gpak_pack_progress   ();

FILDEF bool is_gpak_unpack_complete ();
FILDEF bool is_gpak_pack_complete   ();

FILDEF void do_unpack ();
FILDEF void do_pack   ();

FILDEF void cancel_unpack ();
FILDEF void cancel_pack   ();

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* GPAK_HPP__ /////////////////////////////////////////////////////////*/

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
