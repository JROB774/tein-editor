GLOBAL constexpr float TAB_LENGTH_IN_SPACES  = 4.0f;
GLOBAL constexpr float FONT_GLYPH_CACHE_PADS = 6.0f;

GLOBAL constexpr int TOTAL_GLYPH_COUNT = 128;

FILDEF bool internal__set_font_point_size (Font& _font, int _pt)
{
    // We use the current display's DPI to determine the point size.
    float hdpi, vdpi;
    if (SDL_GetDisplayDPI(0, NULL, &hdpi, &vdpi) != 0) {
        LOG_ERROR(ERR_MIN, "Failed to determine display DPI! (%s)", SDL_GetError());
        return false;
    }

    FT_UInt hres = CAST(FT_UInt, hdpi);
    FT_UInt vres = CAST(FT_UInt, vdpi);

    FT_F26Dot6 pt_height = _pt * 64;

    if (FT_Set_Char_Size(_font.face, 0, pt_height, hres, vres) != 0) {
        LOG_ERROR(ERR_MIN, "Failed to set font glyph size!");
        return false;
    }

    return true;
}

STDDEF bool internal__create_font (Font& _font, int _pt, float _csz)
{
    // Make sure the glyph cache size is within the GL texture bounds.
    // If not we set it to that size and log a low-priority error.
    GLfloat cache_size = MIN(get_max_texture_size(), _csz);
    if (cache_size < _csz) {
        LOG_ERROR(ERR_MIN, "Font cache size shrunk to %f!", cache_size);
    }

    if (!internal__set_font_point_size(_font, _pt)) { return false; }
    _font.current_pt_size = _pt;

    // An 8-bit buffer that we can easily write our rasterized glyph data
    // into before building a GPU texture using our built-in texture code.
    size_t cache_row = CAST(size_t, cache_size);
    size_t cache_bytes = cache_row * cache_row;

    // We use calloc to fill the buffer with black instead of garbage.
    u8* buffer = cstd_calloc(u8, cache_bytes);
    if (!buffer) {
        LOG_ERROR(ERR_MIN, "Failed to create glyph buffer!");
        return false;
    }
    defer { cstd_free(buffer); };

    // Cache some useful information and metrics about the font for later.
    _font.has_kerning = FT_HAS_KERNING(_font.face);
    _font.color       = { 1.0f, 1.0f, 1.0f, 1.0f };
    _font.line_gap.insert(std::pair<int,float>(_pt, CAST(float, _font.face->size->metrics.height >> 6)));

    // Go through glyph-by-glyph and bake all of the bitmaps to the final
    // glyph cache texture so that they can easily and quickly be rendered.
    //
    // Our current primitive method of packing involves simply moving from
    // left-to-right and top-to-bottom packing glyphs until we hit end up
    // hitting the size of the cache and move down to the next glyph row.

    FT_GlyphSlot slot = _font.face->glyph;
    FT_Bitmap* bitmap = &slot->bitmap;
    Vec2       cursor = { 0.0f, 0.0f };

    _font.glyphs.insert(std::pair<int, std::vector<Font_Glyph>>(_pt, std::vector<Font_Glyph>(TOTAL_GLYPH_COUNT)));
    ASSERT(_font.glyphs.at(_font.current_pt_size).size() == TOTAL_GLYPH_COUNT);

    for (int i=0; i<TOTAL_GLYPH_COUNT; ++i) {
        int index = FT_Get_Char_Index(_font.face, i);
        if (FT_Load_Glyph(_font.face, index, FT_LOAD_RENDER) != 0) {
            LOG_ERROR(ERR_MIN, "Failed to load glyph '%c'!", i);
            return false;
        }

        float bitmap_advance = CAST(float, slot->advance.x >> 6);
        float bitmap_left    = CAST(float, slot->bitmap_left);
        float bitmap_top     = CAST(float, slot->bitmap_top);
        float bitmap_width   = CAST(float, bitmap->width);
        float bitmap_height  = CAST(float, bitmap->rows);

        // Move down a row if we have reached the edge of the cache.
        if (cursor.x + bitmap_width >= cache_size) {
            cursor.y += (_font.line_gap[_pt] + FONT_GLYPH_CACHE_PADS);
            cursor.x = 0.0f;
            // If we hit the bottom edge then we are out of space.
            if (cursor.y + bitmap_height >= cache_size) {
                LOG_ERROR(ERR_MIN, "Font cache too small!");
                return false;
            }
        }

        // Cache various metrics regarding each of the packed glyphs.
        _font.glyphs[_pt][i].advance   = bitmap_advance;
        _font.glyphs[_pt][i].bearing.x = bitmap_left;
        _font.glyphs[_pt][i].bearing.y = bitmap_top;
        _font.glyphs[_pt][i].bounds.x  = cursor.x;
        _font.glyphs[_pt][i].bounds.y  = cursor.y;
        _font.glyphs[_pt][i].bounds.w  = bitmap_width;
        _font.glyphs[_pt][i].bounds.h  = bitmap_height+1.0f;

        // Write the bitmap content into our cache buffer line-by-line.
        size_t cx = CAST(size_t, cursor.x), cy = CAST(size_t, cursor.y);
        for (FT_UInt y=0; y<bitmap->rows; ++y) {
            void* dst = buffer + ((cy+y)*cache_row+cx);
            void* src = bitmap->buffer + (y*bitmap->pitch);

            memcpy(dst, src, bitmap->pitch);
        }

        // Move to the right to pack the next glyph for the font.
        cursor.x += bitmap_width + FONT_GLYPH_CACHE_PADS;
    }

    // We can now convert the buffer into a GPU accelerated texture.
    int cache_w = CAST(int, cache_size);
    int cache_h = CAST(int, cache_size);

    _font.cache.insert(std::pair<int,Texture>(_pt, Texture()));
    return create_texture(_font.cache[_pt], cache_w, cache_h, 1, buffer);
}

FILDEF bool load_font_from_data (Font& _font, const std::vector<u8>& _file_data, std::vector<int> _pt, float _csz)
{
    ASSERT(_pt.size());

    _font.data.assign(_file_data.begin(), _file_data.end());

    const FT_Byte* buffer = &_font.data[0];
    FT_Long size = CAST(FT_Long, _font.data.size());

    if (FT_New_Memory_Face(freetype, buffer, size, 0, &_font.face) != 0) {
        LOG_ERROR(ERR_MIN, "Failed to load font from data!");
        return false;
    }

    for (auto pt: _pt) {
        if (!internal__create_font(_font, pt, _csz)) {
            return false;
        }
    }
    set_font_point_size(_font, _pt.at(0)); // Default to first size.
    return true;
}

FILDEF bool load_font_from_file (Font& _font, const char* _file_name, std::vector<int> _pt, float _csz)
{
    ASSERT(_pt.size());

    // Build an absolute path to the file based on the executable location.
    std::string file_name(make_path_absolute(_file_name));

    if (FT_New_Face(freetype, _file_name, 0, &_font.face) != 0) {
        LOG_ERROR(ERR_MIN, "Failed to load font '%s'!", file_name.c_str());
        return false;
    }

    for (auto pt: _pt) {
        if (!internal__create_font(_font, pt, _csz)) {
            return false;
        }
    }
    set_font_point_size(_font, _pt.at(0)); // Default to first size.
    return true;
}

FILDEF void free_font (Font& _font)
{
    for (auto cache: _font.cache) { free_texture(cache.second); }

    FT_Done_Face(_font.face);

    _font.cache.clear   ();
    _font.data.clear    ();
    _font.line_gap.clear();
    _font.glyphs.clear  ();

    _font.current_pt_size = 0;
}

FILDEF float get_font_kerning (const Font& _font, int _c, int& _i, int& _p)
{
    FT_Vector kern = {};

    // Kerning not available or not necessary currently.
    _i = FT_Get_Char_Index(_font.face, _c);
    if (_font.has_kerning && _i && _p) {
        FT_Get_Kerning(_font.face, _p, _i, FT_KERNING_DEFAULT, &kern);
    }
    _p = _i;

    return CAST(float, kern.x >> 6);
}

FILDEF float get_font_tab_width (const Font& _font)
{
    return (_font.glyphs.at(_font.current_pt_size).at(32).advance * TAB_LENGTH_IN_SPACES);
}

FILDEF float get_glyph_advance (const Font& _font, int _c, int& _i, int& _p)
{
    return (_font.glyphs.at(_font.current_pt_size).at(_c).advance + get_font_kerning(_font, _c, _i, _p));
}

INLDEF float get_text_width (const Font& _font, const char* _text)
{
    float max_width = 0.0f;
    float width = 0.0f;

    int i = 0;
    int p = 0;

    for (const char* c=_text; *c; ++c) {
        switch (*c) {
        default:     { width += get_glyph_advance(_font, *c, i, p); } break;
        case ('\t'): { width += get_font_tab_width(_font);          } break;
        case ('\n'): {
            if (width > max_width) {
                max_width = width;
            }
            width = 0.0f;
        } break;
        }
    }

    return MAX(max_width, width);
}

INLDEF float get_text_height (const Font& _font, const char* _text)
{
    if (!_text || strlen(_text) == 0) { return 0.0f; }
    float height = _font.line_gap.at(_font.current_pt_size);
    for (const char* c=_text; *c; ++c) {
        if (*c == '\n') { height += _font.line_gap.at(_font.current_pt_size); }
    }
    return height;
}

FILDEF void set_font_point_size (Font& _font, int _pt)
{
    // Make sure we actually have that point size available.
    ASSERT(_font.glyphs.find(_pt) != _font.glyphs.end());

    internal__set_font_point_size(_font, _pt);
    _font.current_pt_size = _pt;
}
