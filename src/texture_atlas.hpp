#pragma once

GLOBAL constexpr s32 ALT_OFFSET = 60000;

// We use the texture atlas system to cache a bunch of tile graphics.
struct Texture_Atlas
{
    std::map<s32, Quad> clips;
    Texture texture;
};

FILDEF bool load_texture_atlas_from_file (Texture_Atlas& _atlas, const char*            _file_name);
FILDEF bool load_texture_atlas_from_data (Texture_Atlas& _atlas, const std::vector<u8>& _file_data);
FILDEF void free_texture_atlas           (Texture_Atlas& _atlas);

FILDEF Quad& get_atlas_clip (Texture_Atlas& _atlas, s32 _key);

// Debug build only so that we can generate new tile atlases for use.
#if defined(DEBUG_BUILD)
FILDEF void generate_texture_atlases ();
#else
#define generate_texture_atlases()
#endif // DEBUG_BUILD
