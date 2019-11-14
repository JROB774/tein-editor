#pragma once

enum Resize_Dir
{
    RESIZE_DIR_N,  RESIZE_DIR_E,   RESIZE_DIR_S, RESIZE_DIR_W,
    RESIZE_DIR_NE, RESIZE_DIR_SE, RESIZE_DIR_SW, RESIZE_DIR_NW,

    RESIZE_DIR_CENTER,
};

FILDEF void open_resize   (int _lw=-1, int _lh=-1);
FILDEF void do_resize     ();
FILDEF void cancel_resize ();

FILDEF void handle_resize_events ();

FILDEF int get_resize_w ();
FILDEF int get_resize_h ();

FILDEF Resize_Dir get_resize_dir ();

FILDEF bool resize_dir_is_north (Resize_Dir _dir);
FILDEF bool resize_dir_is_east  (Resize_Dir _dir);
FILDEF bool resize_dir_is_south (Resize_Dir _dir);
FILDEF bool resize_dir_is_west  (Resize_Dir _dir);
