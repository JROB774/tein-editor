#pragma once

enum TextureWrap: GLenum
{
    TEXTURE_WRAP_REPEAT          = GL_REPEAT,
    TEXTURE_WRAP_MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
    TEXTURE_WRAP_CLAMP_TO_EDGE   = GL_CLAMP_TO_EDGE
};

struct Texture
{
    GLuint handle;
    float  w;
    float  h;
    Vec4   color;
};

STDDEF bool load_texture_from_data (Texture& _tex, const std::vector<u8>& _file_data, TextureWrap _wrap = TEXTURE_WRAP_CLAMP_TO_EDGE);
FILDEF bool load_texture_from_file (Texture& _tex, const char*            _file_name, TextureWrap _wrap = TEXTURE_WRAP_CLAMP_TO_EDGE);

FILDEF void free_texture (Texture& _tex);

// RGBA ordering of pixel components is expected when using create_texture().
STDDEF bool create_texture (Texture& _tex, int _w, int _h, int _bpp, void* _data, TextureWrap _wrap = TEXTURE_WRAP_CLAMP_TO_EDGE);
