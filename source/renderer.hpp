/*******************************************************************************
 * Simplisitic 2D renderer implemented using OpenGL 3.0 as the backend.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef RENDERER_HPP__ /*/////////////////////////////////////////////////////*/
#define RENDERER_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#define OPENGL_LOAD_GL_VERSION_MAJOR 3
#define OPENGL_LOAD_GL_VERSION_MINOR 0

#define OPENGL_USE_COMPATIBILITY_PROFILE

#include <opengl.hpp>

/* -------------------------------------------------------------------------- */

enum class Matrix_Mode: GLenum { PROJECTION = GL_PROJECTION, MODELVIEW = GL_MODELVIEW };

struct Texture; // Defined in <texture.hpp>
struct Font;    // Defined in <font.hpp>

/* -------------------------------------------------------------------------- */

FILDEF bool init_renderer ();
FILDEF void quit_renderer ();

FILDEF void render_clear   (vec4 clear);
FILDEF void render_present ();

STDDEF vec2 screen_to_world (vec2 screen);
STDDEF vec2 world_to_screen (vec2 world);

FILDEF float get_max_texture_size ();

FILDEF Window* get_render_target ();
FILDEF void    set_render_target (Window* window);

FILDEF float get_render_target_w ();
FILDEF float get_render_target_h ();

STDDEF void set_orthographic (float l, float r, float b, float t);

STDDEF void set_viewport (float x, float y, float w, float h);
FILDEF void set_viewport (quad v);
FILDEF quad get_viewport ();

FILDEF void set_draw_color (float r, float g, float b, float a);
FILDEF void set_draw_color (vec4 color);

FILDEF void set_line_width (float width);

FILDEF void  set_texture_draw_scale   (float sx, float sy);
FILDEF float get_texture_draw_scale_x ();
FILDEF float get_texture_draw_scale_y ();

FILDEF void  set_font_draw_scale (float scale);
FILDEF float get_font_draw_scale ();

STDDEF void begin_scissor (float x, float y, float w, float h);
STDDEF void end_scissor   ();

FILDEF void begin_stencil      ();
FILDEF void end_stencil        ();
FILDEF void stencil_mode_erase ();
FILDEF void stencil_mode_draw  ();

FILDEF void draw_line (float x1, float y1, float x2, float y2);
FILDEF void draw_quad (float x1, float y1, float x2, float y2);
FILDEF void fill_quad (float x1, float y1, float x2, float y2);

STDDEF void draw_texture (const Texture& tex, float x, float y, const quad* clip);
STDDEF void draw_text    (const Font&    fnt, float x, float y, std::string text);

FILDEF void begin_polygon ();
FILDEF void end_polygon   ();

FILDEF void put_vertex (float x, float y, vec4 color);

FILDEF void push_matrix (Matrix_Mode mode);
FILDEF void pop_matrix  (Matrix_Mode mode);

FILDEF void translate (float x, float y);
FILDEF void rotate    (float x, float y, float angle);
FILDEF void scale     (float x, float y);

FILDEF void set_tile_batch_texture (Texture& tex);
FILDEF void set_text_batch_font    (Font&    fnt);
FILDEF void set_tile_batch_color   (vec4 color);
FILDEF void set_text_batch_color   (vec4 color);

FILDEF void draw_batched_tile  (float x, float y, const quad* clip);
FILDEF void draw_batched_text  (float x, float y, std::string text);

FILDEF void flush_batched_tile ();
FILDEF void flush_batched_text ();

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* RENDERER_HPP__ /////////////////////////////////////////////////////*/

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