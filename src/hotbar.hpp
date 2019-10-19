#pragma once

GLOBAL constexpr float HOTBAR_HEIGHT = 26.0f;

FILDEF void do_hotbar ();

// Functionality for the various commands/actions located on the hotbar.

FILDEF void hb_new_level     ();
FILDEF void hb_load_level    ();
FILDEF void hb_save_level    ();
FILDEF void hb_save_level_as ();
FILDEF void hb_undo_action   ();
FILDEF void hb_redo_action   ();
FILDEF void hb_history_begin ();
FILDEF void hb_history_end   ();
FILDEF void hb_zoom_out      ();
FILDEF void hb_zoom_in       ();
FILDEF void hb_run_game      ();
FILDEF void hb_preferences   ();
FILDEF void hb_about         ();
FILDEF void hb_help          ();
