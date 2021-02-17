FILDEF bool init_renderer ()
{
    // @Incomplete: ...
}

FILDEF void quit_renderer ()
{
    // @Incomplete: ...
}

FILDEF void render_clear (vec4 clear)
{
    // @Incomplete: ...
}

FILDEF void render_present ()
{
    // @Incomplete: ...
}

STDDEF vec2 screen_to_world (vec2 screen)
{
    // @Incomplete: ...
    return vec2(0,0);
}
STDDEF vec2 world_to_screen (vec2 world)
{
    // @Incomplete: ...
    return vec2(0,0);
}

FILDEF float get_max_texture_size ()
{
    // @Incomplete: ...
    return 0.0f;
}

FILDEF Window* get_render_target ()
{
    // @Incomplete: ...
    return NULL;
}
FILDEF void set_render_target (Window* window)
{
    // @Incomplete: ...
}

FILDEF float get_render_target_w ()
{
    // @Incomplete: ...
    return 0.0f;
}
FILDEF float get_render_target_h ()
{
    // @Incomplete: ...
    return 0.0f;
}

STDDEF void set_orthographic (float l, float r, float b, float t)
{
    // @Incomplete: ...
}

STDDEF void set_viewport (float x, float y, float w, float h)
{
    // @Incomplete: ...
}
FILDEF void set_viewport (quad v)
{
    // @Incomplete: ...
}
FILDEF quad get_viewport ()
{
    // @Incomplete: ...
    return { 0,0,0,0 };
}

FILDEF void set_draw_color (float r, float g, float b, float a)
{
    // @Incomplete: ...
}
FILDEF void set_draw_color (vec4 color)
{
    // @Incomplete: ...
}

FILDEF void set_line_width (float width)
{
    // @Incomplete: ...
}

FILDEF void  set_texture_draw_scale   (float sx, float sy)
{
    // @Incomplete: ...
}
FILDEF float get_texture_draw_scale_x ()
{
    // @Incomplete: ...
    return 0.0f;
}
FILDEF float get_texture_draw_scale_y ()
{
    // @Incomplete: ...
    return 0.0f;
}

FILDEF void set_font_draw_scale (float scale)
{
    // @Incomplete: ...
}
FILDEF float get_font_draw_scale ()
{
    // @Incomplete: ...
    return 0.0f;
}

STDDEF void begin_scissor (float x, float y, float w, float h)
{
    // @Incomplete: ...
}
STDDEF void end_scissor ()
{
    // @Incomplete: ...
}

FILDEF void begin_stencil ()
{
    // @Incomplete: ...
}
FILDEF void end_stencil ()
{
    // @Incomplete: ...
}
FILDEF void stencil_mode_erase ()
{
    // @Incomplete: ...
}
FILDEF void stencil_mode_draw ()
{
    // @Incomplete: ...
}

FILDEF void draw_line (float x1, float y1, float x2, float y2)
{
    // @Incomplete: ...
}
FILDEF void draw_quad (float x1, float y1, float x2, float y2)
{
    // @Incomplete: ...
}
FILDEF void fill_quad (float x1, float y1, float x2, float y2)
{
    // @Incomplete: ...
}

STDDEF void draw_texture (const Texture& tex, float x, float y, const quad* clip)
{
    // @Incomplete: ...
}
STDDEF void draw_text (const Font& fnt, float x, float y, std::string text)
{
    // @Incomplete: ...
}

FILDEF void begin_draw (Buffer_Mode mode)
{
    // @Incomplete: ...
}
FILDEF void end_draw ()
{
    // @Incomplete: ...
}

FILDEF void put_vertex (float x, float y, vec4 color)
{
    // @Incomplete: ...
}

FILDEF void push_matrix (Matrix_Mode mode)
{
    // @Incomplete: ...
}
FILDEF void pop_matrix (Matrix_Mode mode)
{
    // @Incomplete: ...
}

FILDEF void translate (float x, float y)
{
    // @Incomplete: ...
}
FILDEF void rotate (float x, float y, float angle)
{
    // @Incomplete: ...
}
FILDEF void scale (float x, float y)
{
    // @Incomplete: ...
}

FILDEF void set_tile_batch_texture (Texture& tex)
{
    // @Incomplete: ...
}
FILDEF void set_text_batch_font (Font& fnt)
{
    // @Incomplete: ...
}
FILDEF void set_tile_batch_color (vec4 color)
{
    // @Incomplete: ...
}
FILDEF void set_text_batch_color (vec4 color)
{
    // @Incomplete: ...
}

FILDEF void draw_batched_tile (float x, float y, const quad* clip)
{
    // @Incomplete: ...
}
FILDEF void draw_batched_text (float x, float y, std::string text)
{
    // @Incomplete: ...
}

FILDEF void flush_batched_tile ()
{
    // @Incomplete: ...
}
FILDEF void flush_batched_text ()
{
    // @Incomplete: ...
}
