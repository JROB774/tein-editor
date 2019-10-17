#pragma once

// Globally accessible and generic resources that can be used by the editor.
// We also have a global copy of the no tile/spawn image texture so that we
// can use it in the level editor in case a level is loaded that has IDs we
// no longer recognise -- just so that the user doesn't think they're empty.

GLOBAL Texture       resource_icons;
GLOBAL Font          resource_font_sans;
GLOBAL Font          resource_font_dyslexic;
GLOBAL Texture       resource_checker_14;
GLOBAL Texture       resource_checker_16;
GLOBAL Texture       resource_checker_20;
GLOBAL Texture_Atlas resource_large;
GLOBAL Texture_Atlas resource_small;

FILDEF void get_resource_location ();
FILDEF bool init_resource_manager ();

FILDEF bool            load_texture_resource (std::string _file_name, Texture& _tex, TextureWrap _wrap = TEXTURE_WRAP_CLAMP_TO_EDGE);
FILDEF bool            load_atlas_resource   (std::string _file_name, Texture_Atlas& _atlas);
FILDEF bool            load_font_resource    (std::string _file_name, Font& _font);
FILDEF Shader          load_shader_resource  (std::string _file_name);
FILDEF std::vector<u8> load_binary_resource  (std::string _file_name);
FILDEF SDL_Surface*    load_surface_resource (std::string _file_name);
FILDEF std::string     load_string_resource  (std::string _file_name);

FILDEF bool load_editor_resources ();
FILDEF void free_editor_resources ();

FILDEF std::string build_resource_string (std::string _str);

FILDEF void  update_editor_font      ();
FILDEF Font& get_editor_font         ();
FILDEF bool  is_editor_font_opensans ();

FILDEF Texture_Atlas& get_editor_atlas_large ();
FILDEF Texture_Atlas& get_editor_atlas_small ();
