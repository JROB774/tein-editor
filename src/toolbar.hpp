#pragma once

GLOBAL constexpr Quad CLIP_NONE        = {  0.0f,   0.0f,  0.0f,  0.0f };
GLOBAL constexpr Quad CLIP_BULLET      = { 96.0f, 108.0f, 24.0f, 12.0f };
GLOBAL constexpr Quad CLIP_BRUSH       = {  0.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FILL        = { 24.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_SELECT      = { 48.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_GRID        = { 72.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_BOUNDS      = {  0.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_LAYERS      = { 24.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CAMERA      = { 48.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FLIP_H      = {  0.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_FLIP_V      = { 24.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_MIRROR_H    = { 48.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_MIRROR_V    = { 72.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CUT         = {  0.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_COPY        = { 24.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_DESELECT    = { 48.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_CLEAR       = { 72.0f,  72.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ARROW_UP    = { 48.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_RIGHT = { 60.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_LEFT  = { 48.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_ARROW_DOWN  = { 60.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_CROSS       = { 72.0f,  96.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_EYE         = { 96.0f,  96.0f, 24.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_N    = { 24.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_E    = { 36.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_S    = { 36.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_W    = { 24.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_NE   = { 12.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_SE   = { 12.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_SW   = {  0.0f, 108.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE_NW   = {  0.0f,  96.0f, 12.0f, 12.0f };
GLOBAL constexpr Quad CLIP_RESIZE      = { 72.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_PACK        = { 96.0f,  24.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_UNPACK      = { 96.0f,  48.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_GUIDES      = { 96.0f,   0.0f, 24.0f, 24.0f };
GLOBAL constexpr Quad CLIP_ENTITY      = { 96.0f,  72.0f, 24.0f, 24.0f };

GLOBAL constexpr float TOOLBAR_INNER_PAD =  1.0f;
GLOBAL constexpr float TOOLBAR_WIDTH     = 30.0f;

FILDEF void  do_toolbar    ();
FILDEF float get_toolbar_w ();

// Functionality for the various buttons/tools located on the toolbar.

FILDEF void tb_set_tool_to_brush  ();
FILDEF void tb_set_tool_to_fill   ();
FILDEF void tb_set_tool_to_select ();
FILDEF void tb_toggle_grid        ();
FILDEF void tb_toggle_bounds      ();
FILDEF void tb_toggle_layer_trans ();
FILDEF void tb_reset_camera       ();
FILDEF void tb_flip_level_h       ();
FILDEF void tb_flip_level_v       ();
FILDEF void tb_toggle_mirror_h    ();
FILDEF void tb_toggle_mirror_v    ();
FILDEF void tb_cut                ();
FILDEF void tb_copy               ();
FILDEF void tb_deselect           ();
FILDEF void tb_clear_select       ();
FILDEF void tb_gpak_unpack        ();
FILDEF void tb_gpak_pack          ();
FILDEF void tb_resize             ();
FILDEF void tb_toggle_entity      ();
FILDEF void tb_toggle_guides      ();
