// We use separate GL texture units for texture and font rendering to cut down
// on the number of texture swpas that need to be done. OpenGL ensures that
// the minimum number of texture units will be two so we don't need to query.
GLOBAL constexpr GLenum FONT_UNIT    = GL_TEXTURE0;
GLOBAL constexpr GLenum TEXTURE_UNIT = GL_TEXTURE0;

GLOBAL SDL_GLContext gl_context;
GLOBAL Window*    render_target;

GLOBAL Quad renderer_viewport;
GLOBAL Vec4 renderer_draw_color;

// Highly unlikely we will ever need more embedded scissors than this but if we
// do we will know about it through various code ASSERTS and can just increase.
GLOBAL Stack<Quad, 256> scissor_stack;

GLOBAL Shader untextured_shader;
GLOBAL Shader textured_shader;
GLOBAL Shader text_shader;

GLOBAL float texture_draw_scale_x;
GLOBAL float texture_draw_scale_y;

GLOBAL float font_draw_scale;

GLOBAL GLfloat max_gl_texture_size;

GLOBAL GLuint vao;
GLOBAL GLuint vbo;

struct Vertex
{
    GLfloat x, y;       // Position
    GLfloat s, t;       // TexCoord
    GLfloat r, g, b, a; // Color
};

GLOBAL std::vector<Vertex> polygon_verts;

FILDEF Quad internal__convert_viewport (Quad _viewport)
{
    // Converts a viewport in our top-left format to GL's bottom-left format.
    Quad converted;

    converted.x = _viewport.x;
    converted.y = (get_render_target_h() - (_viewport.y + _viewport.h));
    converted.w = _viewport.w;
    converted.h = _viewport.h;

    return converted;
}

FILDEF void internal__set_texture0_uniform (Shader _shader, GLenum _unit)
{
    GLint location = glGetUniformLocation(_shader, "texture0");
    glUniform1i(location, _unit);
}

FILDEF void internal__init_tile_draw_stuff(); // Predefine.
FILDEF void internal__init_text_draw_stuff(); // Predefine.

FILDEF bool init_renderer ()
{
    // Initialise the renderer and it's GL context for use with our window.
    gl_context = SDL_GL_CreateContext(get_window("WINMAIN").window);
    if (!gl_context) {
        LOG_ERROR(ERR_MIN, "Failed to create GL context! (%s)", SDL_GetError());
        return false;
    }

    // Dynamically load the available OpenGL functions for rendering.
    // This needs to happen after we have created our SDL GL context.
    if (!GLL_load_gl_procs(GL_CONTEXT_VERSION_MAJOR, GL_CONTEXT_VERSION_MINOR, GLL_LOAD_COMP_PROFILE, SDL_GL_GetProcAddress)) {
        LOG_ERROR(ERR_MIN, "Failed to load GL%d.%d procedures!", GL_CONTEXT_VERSION_MAJOR, GL_CONTEXT_VERSION_MINOR);
        return false;
    }

    // DUMP DEBUG INFO //////////////////////////////////////////////
    LOG_DEBUG("Initialized OpenGL Renderer");
    const GLubyte* gl_version   = glGetString(GL_VERSION);
    const GLubyte* gl_slversion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    const GLubyte* gl_renderer  = glGetString(GL_RENDERER);
    const GLubyte* gl_vendor    = glGetString(GL_VENDOR);

    GLint max_texture_size;
    GLint max_texture_units;

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_texture_size);
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &max_texture_units);

    begin_debug_section("OpenGL:");
    LOG_DEBUG("Version %s", gl_version);
    LOG_DEBUG("GLSL Version %s", gl_slversion);
    LOG_DEBUG("Renderer: %s", gl_renderer);
    LOG_DEBUG("Vendor: %s", gl_vendor);
    LOG_DEBUG("Max Texture Size: %d", max_texture_size);
    LOG_DEBUG("Max Texture Units: %d", max_texture_units);
    end_debug_section();
    // DUMP DEBUG INFO //////////////////////////////////////////////

    scissor_stack.count     = 0;
    renderer_draw_color     = { 1.0f, 1.0f, 1.0f, 1.0f };
    texture_draw_scale_x    = 1.0f;
    texture_draw_scale_y    = 1.0f;
    font_draw_scale         = 1.0f;

    glGetFloatv(GL_MAX_TEXTURE_SIZE, &max_gl_texture_size);

    untextured_shader = load_shader_resource("shaders/untextured.shader");
    if (!untextured_shader) { LOG_ERROR(ERR_MAX, "Failed to load the untextured shader!"); return false; }
    textured_shader = load_shader_resource("shaders/textured.shader");
    if (!textured_shader) { LOG_ERROR(ERR_MAX, "Failed to load the textured shader!"); return false; }

    // We carry on even on failure because text will still be drawn it
    // will just be extremely ugly... but it's not worth failing over.
    text_shader = load_shader_resource("shaders/text.shader");
    if (!text_shader) { LOG_ERROR(ERR_MED, "Failed to load the text shader!"); }

    // By default we render to the main window.
    set_render_target(&get_window("WINMAIN"));

    set_viewport(0, 0, get_render_target_w(), get_render_target_h());

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexPointer  (2, GL_FLOAT, sizeof(Vertex), (void*)(0*sizeof(GLfloat)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (void*)(2*sizeof(GLfloat)));
    glColorPointer   (4, GL_FLOAT, sizeof(Vertex), (void*)(4*sizeof(GLfloat)));

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    internal__init_tile_draw_stuff();
    internal__init_text_draw_stuff();

    return true;
}

FILDEF void quit_renderer ()
{
    free_shader(untextured_shader);
    free_shader(  textured_shader);
    free_shader(      text_shader);

    SDL_GL_DeleteContext(gl_context);
    gl_context = NULL;
}

FILDEF void render_clear (Vec4 _clear)
{
    glClearColor(_clear.r, _clear.g, _clear.b, _clear.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

FILDEF void render_present ()
{
    ASSERT(render_target);
    if (render_target) {
        SDL_GL_SwapWindow(render_target->window);
    }
}

STDDEF Vec2 screen_to_world (Vec2 _screen)
{
    // GL expects bottom-left so we have to convert our viewport first.
    Quad v = internal__convert_viewport(renderer_viewport);

    // We also need to do flip the Y coordinate to use this system.
    _screen.y = get_render_target_h() - _screen.y;
    glm::vec3 coord(_screen.x, _screen.y, 0.0f);

    glm::mat4 projection;
    glm::mat4 model;

    float matrix[16];

    glGetFloatv(GL_PROJECTION_MATRIX, matrix);
    projection = glm::make_mat4(matrix);
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    model = glm::make_mat4(matrix);

    glm::vec4 viewport(v.x, v.y, v.w, v.h);

    coord = glm::unProject(coord, model, projection, viewport);

    Vec2 world = { coord.x, coord.y };
    return world;
}

STDDEF Vec2 world_to_screen (Vec2 _world)
{
    // GL expects bottom-left so we have to convert our viewport first.
    Quad v = internal__convert_viewport(renderer_viewport);

    glm::vec3 coord(_world.x, _world.y, 0.0f);

    glm::mat4 projection;
    glm::mat4 model;

    float matrix[16];

    glGetFloatv(GL_PROJECTION_MATRIX, matrix);
    projection = glm::make_mat4(matrix);
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    model = glm::make_mat4(matrix);

    glm::vec4 viewport(v.x, v.y, v.w, v.h);

    coord = glm::project(coord, model, projection, viewport);

    // We also need to do flip the Y coordinate to use this system.
    Vec2 screen = { coord.x, coord.y };

    screen.x -= v.x;
    screen.y  = get_render_target_h() - (screen.y + renderer_viewport.y);

    return screen;
}

FILDEF Window* get_render_target ()
{
    return render_target;
}

FILDEF void set_render_target (Window* _window)
{
    render_target = _window;
    ASSERT(render_target);

    if (SDL_GL_MakeCurrent(render_target->window, gl_context) < 0) {
        render_target = NULL;
        LOG_ERROR(ERR_MED, "Failed to set render target! (%s)", SDL_GetError());
    }
}

FILDEF float get_render_target_w ()
{
    int w = 0;
    if (render_target) { SDL_GL_GetDrawableSize(render_target->window, &w, NULL); }
    return CAST(float, w);
}

FILDEF float get_render_target_h ()
{
    int h = 0;
    if (render_target) { SDL_GL_GetDrawableSize(render_target->window, NULL, &h); }
    return CAST(float, h);
}

FILDEF float get_max_texture_size ()
{
    return CAST(float, max_gl_texture_size);
}

STDDEF void set_orthographic (float _l, float _r, float _b, float _t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(_l, _r, _b, _t, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

STDDEF void set_viewport (float _x, float _y, float _w, float _h)
{
    // GL expects bottom-left so we have to flip the Y coordinate around.
    renderer_viewport = { _x, _y, _w, _h };
    Quad v = internal__convert_viewport(renderer_viewport);

    GLint   x = CAST(GLint,   v.x);
    GLint   y = CAST(GLint,   v.y);
    GLsizei w = CAST(GLsizei, v.w);
    GLsizei h = CAST(GLsizei, v.h);

    glViewport(x, y, w, h);

    set_orthographic(0.0f, _w, _h, 0.0f);
}

FILDEF void set_viewport (Quad _v)
{
    set_viewport(_v.x, _v.y, _v.w, _v.h);
}

FILDEF Quad get_viewport ()
{
    return renderer_viewport;
}

FILDEF void set_draw_color (float _r, float _g, float _b, float _a)
{
    renderer_draw_color = { _r, _g, _b, _a };
}

FILDEF void set_draw_color (Vec4 _color)
{
    renderer_draw_color = _color;
}

FILDEF void set_line_width (float _width)
{
    glLineWidth(_width);
}

FILDEF void set_texture_draw_scale (float _sx, float _sy)
{
    texture_draw_scale_x = _sx;
    texture_draw_scale_y = _sy;
}

FILDEF float get_texture_draw_scale_x ()
{
    return texture_draw_scale_x;
}

FILDEF float get_texture_draw_scale_y ()
{
    return texture_draw_scale_y;
}

FILDEF void set_font_draw_scale (float _scale)
{
    font_draw_scale = _scale;
}

FILDEF float get_font_draw_scale ()
{
    return font_draw_scale;
}

STDDEF void begin_scissor (float _x, float _y, float _w, float _h)
{
    // Our version of setting the scissor region takes the currently set
    // viewport into consideration rather than basing the region on the
    // size of the screen/window. As a result, we need to perform a few
    // operations on the values passed in to make sure this the case.

    // We push scissor regions onto a stack so we can stack scissor calls.
    // This is particularly useful for the GUI which uses many scissors.
    if (scissor_stack.count == 0) { glEnable(GL_SCISSOR_TEST); }
    scissor_stack.push({ _x, _y, _w, _h });

    // GL expects bottom-left so we have to flip the Y coordinate around.
    GLint   x = CAST(GLint,   renderer_viewport.x + _x);
    GLint   y = CAST(GLint,   get_render_target_h() - (renderer_viewport.y + (_y + _h)));
    GLsizei w = CAST(GLsizei, _w);
    GLsizei h = CAST(GLsizei, _h);

    glScissor(x, y, w, h);
}

STDDEF void end_scissor ()
{
    // Pop the last scissor region off the stack.
    Quad s = scissor_stack.pop();

    // GL expects bottom-left so we have to flip the Y coordinate around.
    GLint   x = CAST(GLint,   renderer_viewport.x + s.x);
    GLint   y = CAST(GLint,   get_render_target_h() - (renderer_viewport.y + (s.y + s.h)));
    GLsizei w = CAST(GLsizei, s.w);
    GLsizei h = CAST(GLsizei, s.h);

    glScissor(x, y, w, h);

    if (scissor_stack.count == 0) { glDisable(GL_SCISSOR_TEST); }
}

FILDEF void begin_stencil ()
{
    glEnable(GL_STENCIL_TEST);

    glClearStencil(0);
    glClear(GL_STENCIL_BUFFER_BIT);
}

FILDEF void end_stencil ()
{
    stencil_mode_draw();
    glDisable(GL_STENCIL_TEST);
}

FILDEF void stencil_mode_erase ()
{
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_FALSE);
    glStencilFunc(GL_ALWAYS, CAST(GLuint, 1), CAST(GLuint, ~0));
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
}

FILDEF void stencil_mode_draw ()
{
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);
    glStencilFunc(GL_NOTEQUAL, CAST(GLuint, 1), CAST(GLuint, ~0));
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
}

FILDEF void draw_point (float _x, float _y)
{
    glUseProgram(untextured_shader);

    Vec4 c = renderer_draw_color;
    Vertex verts[1] = { { _x, _y, 0.0f, 0.0f, c.r, c.g, c.b, c.a } };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_POINTS, 0, 1);
}

FILDEF void draw_line (float _x1, float _y1, float _x2, float _y2)
{
    glUseProgram(untextured_shader);

    Vec4 c = renderer_draw_color;
    Vertex verts[2]
    {
    { _x1, _y1, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x2, _y2, 0.0f, 0.0f, c.r, c.g, c.b, c.a }
    };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_LINES, 0, 2);
}

FILDEF void draw_quad (float _x1, float _y1, float _x2, float _y2)
{
    glUseProgram(untextured_shader);

    // We want to use 0.5 otherwise the lines don't draw where we want them.
    _x1 += 0.5f;
    _y1 += 0.5f;
    _x2 -= 0.5f;
    _y2 -= 0.5f;

    Vec4 c = renderer_draw_color;
    Vertex verts[4]
    {
    { _x1, _y1, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x2, _y1, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x2, _y2, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x1, _y2, 0.0f, 0.0f, c.r, c.g, c.b, c.a }
    };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}

FILDEF void fill_quad (float _x1, float _y1, float _x2, float _y2)
{
    glUseProgram(untextured_shader);

    Vec4 c = renderer_draw_color;
    Vertex verts[4]
    {
    { _x1, _y2, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x1, _y1, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x2, _y2, 0.0f, 0.0f, c.r, c.g, c.b, c.a },
    { _x2, _y1, 0.0f, 0.0f, c.r, c.g, c.b, c.a }
    };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

STDDEF void draw_texture (const Texture& _tex, float _x, float _y, const Quad* _clip)
{
    glActiveTexture(TEXTURE_UNIT);
    glBindTexture(GL_TEXTURE_2D, _tex.handle);

    glUseProgram(textured_shader);
    internal__set_texture0_uniform(textured_shader, TEXTURE_UNIT);

    float cx1, cy1, cx2, cy2;
    float w, h;

    if (_clip) {
        cx1 =       (_clip->x / _tex.w);
        cy1 =       (_clip->y / _tex.h);
        cx2 = cx1 + (_clip->w / _tex.w);
        cy2 = cy1 + (_clip->h / _tex.h);

        w = _clip->w * texture_draw_scale_x;
        h = _clip->h * texture_draw_scale_y;
    } else {
        cx1 = 0.0f;
        cy1 = 0.0f;
        cx2 = 1.0f;
        cy2 = 1.0f;

        w = _tex.w * texture_draw_scale_x;
        h = _tex.h * texture_draw_scale_y;
    }

    float x1 = _x - (w / 2.0f); // Center anchor.
    float y1 = _y - (h / 2.0f); // Center anchor.
    float x2 = x1 + w;
    float y2 = y1 + h;

    Vertex verts[4]
    {
    { x1, y2, cx1, cy2, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x1, y1, cx1, cy1, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x2, y2, cx2, cy2, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x2, y1, cx2, cy1, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a }
    };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

STDDEF void draw_texture (const Texture& _tex, float _x, float _y, Flip _flip, const Quad* _clip)
{
    glActiveTexture(TEXTURE_UNIT);
    glBindTexture(GL_TEXTURE_2D, _tex.handle);

    glUseProgram(textured_shader);
    internal__set_texture0_uniform(textured_shader, TEXTURE_UNIT);

    float cx1, cy1, cx2, cy2;
    float w, h;

    if (_clip) {
        cx1 =       (_clip->x / _tex.w);
        cy1 =       (_clip->y / _tex.h);
        cx2 = cx1 + (_clip->w / _tex.w);
        cy2 = cy1 + (_clip->h / _tex.h);

        if (_flip&FLIP_HORZ) { std::swap(cx1, cx2); }
        if (_flip&FLIP_VERT) { std::swap(cy1, cy2); }

        w = _clip->w * texture_draw_scale_x;
        h = _clip->h * texture_draw_scale_y;
    } else {
        cx1 = 0.0f;
        cy1 = 0.0f;
        cx2 = 1.0f;
        cy2 = 1.0f;

        if (_flip&FLIP_HORZ) { std::swap(cx1, cx2); }
        if (_flip&FLIP_VERT) { std::swap(cy1, cy2); }

        w = _tex.w * texture_draw_scale_x;
        h = _tex.h * texture_draw_scale_y;
    }

    float x1 = _x - (w / 2.0f); // Center anchor.
    float y1 = _y - (h / 2.0f); // Center anchor.
    float x2 = x1 + w;
    float y2 = y1 + h;

    Vertex verts[4]
    {
    { x1, y2, cx1, cy2, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x1, y1, cx1, cy1, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x2, y2, cx2, cy2, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a },
    { x2, y1, cx2, cy1, _tex.color.r, _tex.color.g, _tex.color.b, _tex.color.a }
    };

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

STDDEF void draw_text (const Font& _font, float _x, float _y, const char* _text)
{
    glActiveTexture(FONT_UNIT);
    glBindTexture(GL_TEXTURE_2D, _font.cache.at(_font.current_pt_size).handle);

    glUseProgram(text_shader);
    internal__set_texture0_uniform(text_shader, FONT_UNIT);

    std::vector<Vertex> verts;

    int index      = 0;
    int prev_index = 0;

    float x = _x;
    float y = _y;

    const Font& font = _font;
    float scale = font_draw_scale;

    const Texture& cache = font.cache.at(font.current_pt_size);
    auto& glyphs = font.glyphs.at(font.current_pt_size);

    for (const char* c=_text; *c; ++c) {
        if (*c < 0 || *c >= TOTAL_GLYPH_COUNT) continue;
        x += (get_font_kerning(font, *c, index, prev_index) * scale);
        switch (*c) {
        case ('\r'): {
            x = _x;
        } break;
        case ('\n'): {
            x = _x, y += (font.line_gap.at(font.current_pt_size) * scale);
        } break;
        case ('\t'): {
            x += get_font_tab_width(font) * scale;
        } break;
        default: {
            const Font_Glyph& glyph = glyphs.at(*c);
            const Quad& clip = glyph.bounds;

            float bearing_x = glyph.bearing.x * scale;
            float bearing_y = glyph.bearing.y * scale;

            float advance = glyph.advance * scale;

            float cx1 =       (clip.x / cache.w);
            float cy1 =       (clip.y / cache.h);
            float cx2 = cx1 + (clip.w / cache.w);
            float cy2 = cy1 + (clip.h / cache.h);

            float w = clip.w * scale;
            float h = clip.h * scale;

            float x1 = x  + bearing_x;
            float y1 = y  - bearing_y;
            float x2 = x1 + w;
            float y2 = y1 + h;

            verts.push_back({ x1, y2, cx1, cy2, font.color.r, font.color.g, font.color.b, font.color.a }); // V0
            verts.push_back({ x1, y1, cx1, cy1, font.color.r, font.color.g, font.color.b, font.color.a }); // V1
            verts.push_back({ x2, y2, cx2, cy2, font.color.r, font.color.g, font.color.b, font.color.a }); // V2
            verts.push_back({ x2, y2, cx2, cy2, font.color.r, font.color.g, font.color.b, font.color.a }); // V2
            verts.push_back({ x1, y1, cx1, cy1, font.color.r, font.color.g, font.color.b, font.color.a }); // V1
            verts.push_back({ x2, y1, cx2, cy1, font.color.r, font.color.g, font.color.b, font.color.a }); // V3

            x += advance;
        } break;
        }
    }

    if (!verts.empty()) {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, verts.size()*sizeof(Vertex), &verts[0], GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLES, 0, CAST(GLsizei, verts.size()));
    }
}

FILDEF void begin_polygon ()
{
    glUseProgram(untextured_shader);
    polygon_verts.clear();
}

FILDEF void end_polygon ()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, polygon_verts.size()*sizeof(Vertex), &polygon_verts[0], GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CAST(GLsizei, polygon_verts.size()));
}

FILDEF void put_vertex (float _x, float _y, Vec4 _color)
{
    Vertex v = { _x, _y, 0.0f, 0.0f, _color.r, _color.g, _color.b, _color.a };
    polygon_verts.push_back(v);
}

FILDEF void push_matrix (Matrix_Mode _mode)
{
    glMatrixMode(_mode);
    glPushMatrix();
    glLoadIdentity();
}

FILDEF void pop_matrix (Matrix_Mode _mode)
{
    glMatrixMode(_mode);
    glPopMatrix();
}

FILDEF void translate (float _x, float _y)
{
    glTranslatef(_x, _y, 0.0f);
}

FILDEF void rotate (float _x, float _y, float _angle)
{
    glRotatef(_angle, _x, _y, 0.0f);
}

FILDEF void scale (float _x, float _y)
{
    glScalef(_x, _y, 1.0f);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

GLOBAL Vec4                tile_draw_color;
GLOBAL GLuint              tile_vao;
GLOBAL GLuint              tile_vbo;
GLOBAL std::vector<Vertex> tile_verts;
GLOBAL Texture*            tile_texture;

FILDEF void internal__init_tile_draw_stuff ()
{
    glGenVertexArrays(1, &tile_vao);
    glBindVertexArray(tile_vao);

    glGenBuffers(1, &tile_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, tile_vbo);

    glVertexPointer  (2, GL_FLOAT, sizeof(Vertex), (void*)(0*sizeof(GLfloat)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (void*)(2*sizeof(GLfloat)));
    glColorPointer   (4, GL_FLOAT, sizeof(Vertex), (void*)(4*sizeof(GLfloat)));

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

FILDEF void set_tile_texture (Texture& _tex)
{
    tile_texture = &_tex;
}

FILDEF void set_tile_color (Vec4 _color)
{
    tile_draw_color = _color;
}

FILDEF void draw_tile (float _x, float _y, const Quad* _clip)
{
    ASSERT(tile_texture);

    float cx1 =       (_clip->x / tile_texture->w);
    float cy1 =       (_clip->y / tile_texture->h);
    float cx2 = cx1 + (_clip->w / tile_texture->w);
    float cy2 = cy1 + (_clip->h / tile_texture->h);

    float w = _clip->w * texture_draw_scale_x;
    float h = _clip->h * texture_draw_scale_y;

    float x1 = _x - (w / 2.0f); // Center anchor.
    float y1 = _y - (h / 2.0f); // Center anchor.
    float x2 = x1 + w;
    float y2 = y1 + h;

    tile_verts.push_back({ x1, y2, cx1, cy2, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V0
    tile_verts.push_back({ x1, y1, cx1, cy1, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V1
    tile_verts.push_back({ x2, y2, cx2, cy2, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V2
    tile_verts.push_back({ x2, y2, cx2, cy2, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V2
    tile_verts.push_back({ x1, y1, cx1, cy1, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V1
    tile_verts.push_back({ x2, y1, cx2, cy1, tile_draw_color.r, tile_draw_color.g, tile_draw_color.b, tile_draw_color.a }); // V3
}

FILDEF void flush_tile_draw ()
{
    if (tile_verts.empty()) { return; }

    glBindTexture(GL_TEXTURE_2D, tile_texture->handle);

    glUseProgram(textured_shader);

    glBindVertexArray(tile_vao);
    glBindBuffer(GL_ARRAY_BUFFER, tile_vbo);
    glBufferData(GL_ARRAY_BUFFER, tile_verts.size()*sizeof(Vertex), &tile_verts[0], GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, CAST(GLsizei, tile_verts.size()));

    tile_verts.clear();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

GLOBAL Vec4                text_draw_color;
GLOBAL GLuint              text_vao;
GLOBAL GLuint              text_vbo;
GLOBAL std::vector<Vertex> text_verts;
GLOBAL Font*               text_font;

FILDEF void internal__init_text_draw_stuff ()
{
    glGenVertexArrays(1, &text_vao);
    glBindVertexArray(text_vao);

    glGenBuffers(1, &text_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, text_vbo);

    glVertexPointer  (2, GL_FLOAT, sizeof(Vertex), (void*)(0*sizeof(GLfloat)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (void*)(2*sizeof(GLfloat)));
    glColorPointer   (4, GL_FLOAT, sizeof(Vertex), (void*)(4*sizeof(GLfloat)));

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

FILDEF void set_text_batch_font (Font& _fnt)
{
    text_font = &_fnt;
}

FILDEF void set_text_batch_color (Vec4 _color)
{
    text_draw_color = _color;
}

FILDEF void draw_batched_text (float _x, float _y, const char* _text)
{
    int index      = 0;
    int prev_index = 0;

    float x = _x;
    float y = _y;

    const Font& font = *text_font;
    float scale = font_draw_scale;

    const auto& cache = font.cache.at(font.current_pt_size);
    const auto& glyphs = font.glyphs.at(font.current_pt_size);
    const auto& line_gap = font.line_gap.at(font.current_pt_size);

    for (const char* c=_text; *c; ++c) {
        if (*c < 0 || *c >= TOTAL_GLYPH_COUNT) continue;
        x += (get_font_kerning(font, *c, index, prev_index) * scale);
        switch (*c) {
        case ('\r'): {
            x = _x;
        } break;
        case ('\n'): {
            x = _x, y += (line_gap * scale);
        } break;
        case ('\t'): {
            x += (get_font_tab_width(font) * scale);
        } break;
        default: {
            const Font_Glyph& glyph = glyphs.at(*c);
            const Quad& clip = glyph.bounds;

            float bearing_x = glyph.bearing.x * scale;
            float bearing_y = glyph.bearing.y * scale;

            float advance = glyph.advance * scale;

            float cx1 =       (clip.x / cache.w);
            float cy1 =       (clip.y / cache.h);
            float cx2 = cx1 + (clip.w / cache.w);
            float cy2 = cy1 + (clip.h / cache.h);

            float w = clip.w * scale;
            float h = clip.h * scale;

            float x1 = roundf(x  + bearing_x);
            float y1 = roundf(y  - bearing_y);
            float x2 = roundf(x1 + w);
            float y2 = roundf(y1 + h);

            text_verts.push_back({ x1, y2, cx1, cy2, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V0
            text_verts.push_back({ x1, y1, cx1, cy1, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V1
            text_verts.push_back({ x2, y2, cx2, cy2, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V2
            text_verts.push_back({ x2, y2, cx2, cy2, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V2
            text_verts.push_back({ x1, y1, cx1, cy1, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V1
            text_verts.push_back({ x2, y1, cx2, cy1, text_draw_color.r, text_draw_color.g, text_draw_color.b, text_draw_color.a }); // V3

            x += advance;
        } break;
        }
    }
}

FILDEF void flush_batched_text ()
{
    if (text_verts.empty()) { return; }

    glBindTexture(GL_TEXTURE_2D, text_font->cache.at(text_font->current_pt_size).handle);

    glUseProgram(text_shader);

    glBindVertexArray(text_vao);
    glBindBuffer(GL_ARRAY_BUFFER, text_vbo);
    glBufferData(GL_ARRAY_BUFFER, text_verts.size()*sizeof(Vertex), &text_verts[0], GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, CAST(GLsizei, text_verts.size()));

    text_verts.clear();
}
