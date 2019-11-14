#pragma once

enum Cursor { CURSOR_ARROW, CURSOR_BEAM, CURSOR_POINTER, CURSOR_BRUSH, CURSOR_FILL, CURSOR_SELECT, CURSOR_TOTAL };

FILDEF bool load_editor_cursors    ();
FILDEF void free_editor_cursors    ();

FILDEF void   set_cursor           (Cursor _cursor);
FILDEF Cursor get_cursor           ();

FILDEF bool custom_cursors_enabled ();
