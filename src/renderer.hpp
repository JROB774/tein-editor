#pragma once

GLOBAL constexpr int GL_CONTEXT_VERSION_MAJOR = 3;
GLOBAL constexpr int GL_CONTEXT_VERSION_MINOR = 0;

typedef u32 Flip;

GLOBAL constexpr Flip FLIP_NONE = 0x00;
GLOBAL constexpr Flip FLIP_HORZ = 0x01;
GLOBAL constexpr Flip FLIP_VERT = 0x02;
GLOBAL constexpr Flip FLIP_BOTH = 0x04;

FILDEF bool init_renderer   ();
FILDEF void quit_renderer   ();

FILDEF void render_clear    (Vec4 _clear);
FILDEF void render_present  ();

STDDEF Vec2 screen_to_world (Vec2 _screen);
STDDEF Vec2 world_to_screen (Vec2 _world);

FILDEF Window* get_render_target   ();
FILDEF void    set_render_target   (Window* _window);
FILDEF float   get_render_target_w ();
FILDEF float   get_render_target_h ();

FILDEF float get_max_texture_size ();

STDDEF void  set_orthographic         (float _l, float _r, float _b, float _t);
STDDEF void  set_viewport             (float _x, float _y, float _w, float _h);
FILDEF void  set_viewport             (Quad _v);
FILDEF Quad  get_viewport             ();
FILDEF void  set_draw_color           (float _r, float _g, float _b, float _a);
FILDEF void  set_draw_color           (Vec4  _color);
FILDEF void  set_line_width           (float _width);
FILDEF void  set_texture_draw_scale   (float _sx, float _sy);
FILDEF float get_texture_draw_scale_x ();
FILDEF float get_texture_draw_scale_y ();
FILDEF void  set_font_draw_scale      (float _scale);
FILDEF float get_font_draw_scale      ();

STDDEF void begin_scissor (float _x, float _y, float _w, float _h);
STDDEF void end_scissor   ();

FILDEF void begin_stencil      ();
FILDEF void end_stencil        ();
FILDEF void stencil_mode_erase ();
FILDEF void stencil_mode_draw  ();

FILDEF void draw_point (float _x,  float _y);
FILDEF void draw_line  (float _x1, float _y1, float _x2, float _y2);
FILDEF void draw_quad  (float _x1, float _y1, float _x2, float _y2);
FILDEF void fill_quad  (float _x1, float _y1, float _x2, float _y2);

STDDEF void draw_texture (const Texture& _tex, float _x, float _y,             const Quad* _clip);
STDDEF void draw_texture (const Texture& _tex, float _x, float _y, Flip _flip, const Quad* _clip);

STDDEF void draw_text    (const Font& _font, float _x, float _y, const char* _text);

// Interface for drawing custom polygons by specifying individual vertices.

FILDEF void begin_polygon ();
FILDEF void end_polygon   ();
FILDEF void put_vertex    (float _x, float _y, Vec4 _color);

// Interface for controlling the matrix stack and applying matrix operations.

enum Matrix_Mode: GLenum
{
    MATRIX_MODE_PROJECTION = GL_PROJECTION,
    MATRIX_MODE_MODELVIEW  = GL_MODELVIEW,
};

FILDEF void push_matrix (Matrix_Mode _mode);
FILDEF void pop_matrix  (Matrix_Mode _mode);
FILDEF void translate   (float _x, float _y);
FILDEF void rotate      (float _x, float _y, float _angle);
FILDEF void scale       (float _x, float _y);

// Batched rendering used by tile_panel, level_editor, and map_editor for fast drawing.

FILDEF void set_tile_texture (Texture& _tex);
FILDEF void set_tile_color   (Vec4 _color);
FILDEF void draw_tile        (float _x, float _y, const Quad* _clip);
FILDEF void flush_tile_draw  ();

FILDEF void set_text_batch_font  (Font& _fnt);
FILDEF void set_text_batch_color (Vec4 _color);
FILDEF void draw_batched_text    (float _x, float _y, const char* _text);
FILDEF void flush_batched_text   ();
