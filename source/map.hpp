/*******************************************************************************
 * Loads and saves raw world map data ot and from the CSV file format.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef MAP_HPP__ /*//////////////////////////////////////////////////////////*/
#define MAP_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

struct Map_Node
{
    int x;
    int y;

    std::string lvl;
};

typedef std::vector<Map_Node> Map;

/* -------------------------------------------------------------------------- */

STDDEF bool load_map         (      Tab& tab, std::string file_name);
STDDEF bool save_map         (const Tab& tab, std::string file_name);

// A custom file format. Exactly the same as the default world format except
// the first part of the file until zero is the name of the level. This is
// done so that the name of the file can also be restored when the editor
// is loaded again after a fatal failure occurs and restore files are saved.

struct Tab; // Defined in <editor.hpp>

STDDEF bool load_restore_map (      Tab& tab, std::string file_name);
STDDEF bool save_restore_map (const Tab& tab, std::string file_name);

/* -------------------------------------------------------------------------- */

FILDEF int  get_map_x_pos    (const Map& map);
FILDEF int  get_map_y_pos    (const Map& map);
FILDEF int  get_map_width    (const Map& map);
FILDEF int  get_map_height   (const Map& map);

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* MAP_HPP__ //////////////////////////////////////////////////////////*/

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
