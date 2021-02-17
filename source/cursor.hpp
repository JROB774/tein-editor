#pragma once

enum class Cursor { ARROW, BEAM, POINTER, BRUSH, FILL, SELECT, Total };

FILDEF bool load_editor_cursors ();
FILDEF void free_editor_cursors ();

FILDEF void   set_cursor (Cursor cursor);
FILDEF Cursor get_cursor ();

FILDEF bool custom_cursors_enabled ();
