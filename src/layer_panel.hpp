#pragma once

FILDEF void init_layer_panel            ();
FILDEF void do_layer_panel              (bool _scrollbar);
FILDEF bool layer_panel_needs_scrollbar ();
FILDEF bool is_layer_panel_present      ();

FILDEF float get_layer_panel_height ();

FILDEF void toggle_layer_active  ();
FILDEF void toggle_layer_tag     ();
FILDEF void toggle_layer_overlay ();
FILDEF void toggle_layer_back1   ();
FILDEF void toggle_layer_back2   ();
