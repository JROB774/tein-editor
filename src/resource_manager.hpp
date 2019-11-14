#pragma once

// Various clips for the different icons that are found in resources_icons.

GLOBAL constexpr Quad CLIP_NONE        = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_BULLET      = {  96.0f, 108.0f, 24.0f, 12.0f };
GLOBAL constexpr Quad CLIP_BRUSH       = {   0.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FILL        = {  24.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_SELECT      = {  48.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_GRID        = {  72.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_BOUNDS      = {   0.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_LAYERS      = {  24.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CAMERA      = {  48.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FLIP_H      = {   0.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FLIP_V      = {  24.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_MIRROR_H    = {  48.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_MIRROR_V    = {  72.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CUT         = {   0.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_COPY        = {  24.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_DESELECT    = {  48.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CLEAR       = {  72.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ARROW_UP    = {  48.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_RIGHT = {  60.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_LEFT  = {  48.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_DOWN  = {  60.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_CROSS       = {  72.0f,  96.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_EYE         = {  96.0f,  96.0f, 24.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_N    = {  24.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_E    = {  36.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_S    = {  36.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_W    = {  24.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_NE   = {  12.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_SE   = {  12.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_SW   = {   0.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_NW   = {   0.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE      = {  72.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_PACK        = {  96.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_UNPACK      = {  96.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_GUIDES      = {  96.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ENTITY      = {  96.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_NEW         = { 120.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_LOAD        = { 144.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_SAVE        = { 168.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_SAVE_AS     = { 192.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_UNDO        = { 216.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_REDO        = { 120.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ZOOM_OUT    = { 144.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ZOOM_IN     = { 168.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_RUN         = { 192.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_SETTINGS    = { 216.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ABOUT       = { 120.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_HELP        = { 144.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_UPDATE      = { 168.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CONNECT     = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_GEN_INFO    = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_ADD_LEFT    = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_ADD_RIGHT   = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_ADD_UP      = {   0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_ADD_DOWN    = {   0.0f,   0.0f,  0.0f,  0.0f };

// Globally accessible and generic resources that can be used by the editor.
// We also have a global copy of the no tile/spawn image texture so that we
// can use it in the level editor in case a level is loaded that has IDs we
// no longer recognise -- just so that the user doesn't think they're empty.

GLOBAL Texture       resource_icons;
GLOBAL Font          resource_font_regular_sans;
GLOBAL Font          resource_font_regular_dyslexic;
GLOBAL Font          resource_font_regular_libmono;
GLOBAL Font          resource_font_mono_dyslexic;
GLOBAL Font          resource_font_bold_sans;
GLOBAL Font          resource_font_bold_dyslexic;
GLOBAL Texture       resource_checker_14;
GLOBAL Texture       resource_checker_16;
GLOBAL Texture       resource_checker_20;
GLOBAL Texture_Atlas resource_large;
GLOBAL Texture_Atlas resource_small;

FILDEF void get_resource_location ();
FILDEF bool init_resource_manager ();

FILDEF bool            load_texture_resource (std::string _file_name, Texture& _tex, TextureWrap _wrap = TEXTURE_WRAP_CLAMP_TO_EDGE);
FILDEF bool            load_atlas_resource   (std::string _file_name, Texture_Atlas& _atlas);
FILDEF bool            load_font_resource    (std::string _file_name, Font& _font, std::vector<int> _pt={DEFAULT_FONT_GLYPH_POINT_SIZE}, float _csz=DEFAULT_FONT_GLYPH_CACHE_SIZE);
FILDEF Shader          load_shader_resource  (std::string _file_name);
FILDEF std::vector<u8> load_binary_resource  (std::string _file_name);
FILDEF SDL_Surface*    load_surface_resource (std::string _file_name);
FILDEF std::string     load_string_resource  (std::string _file_name);

FILDEF bool load_editor_resources ();
FILDEF void free_editor_resources ();

FILDEF std::string build_resource_string (std::string _str);

FILDEF void update_editor_font      ();
FILDEF bool is_editor_font_opensans ();

FILDEF Font& get_editor_regular_font ();
FILDEF Font& get_editor_bold_font    ();

FILDEF Texture_Atlas& get_editor_atlas_large ();
FILDEF Texture_Atlas& get_editor_atlas_small ();
