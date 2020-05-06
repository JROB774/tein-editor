/*******************************************************************************
 * Facilities for creating a vertex buffer for storing/drawing vertices.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef VERTEX_BUFFER_HPP__ /*////////////////////////////////////////////////*/
#define VERTEX_BUFFER_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

enum class Buffer_Mode: GLenum
{
    POINTS         = GL_POINTS,
    LINE_STRIP     = GL_LINE_STRIP,
    LINE_LOOP      = GL_LINE_LOOP,
    LINES          = GL_LINES,
    TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
    TRIANGLE_FAN   = GL_TRIANGLE_FAN,
    TRIANGLES      = GL_TRIANGLES
};

typedef GLuint VBO;
typedef GLuint VAO;

struct Vertex
{
    vec2 position;
    vec2 texcoord;
    vec4 outcolor;
};

struct Vertex_Buffer
{
    VAO vao;
    VBO vbo;

    std::vector<Vertex> verts;
};

/* -------------------------------------------------------------------------- */

FILDEF void create_vertex_buffer (Vertex_Buffer& buffer);
FILDEF void free_vertex_buffer   (Vertex_Buffer& buffer);

FILDEF void put_buffer_vertex  (Vertex_Buffer& buffer, Vertex vertex);
FILDEF void draw_vertex_buffer (Vertex_Buffer& buffer, Buffer_Mode mode);

FILDEF void clear_vertex_buffer (Vertex_Buffer& buffer);

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* VERTEX_BUFFER_HPP__ ////////////////////////////////////////////////*/

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
