namespace Cursor_Globals
{
    GLOBAL SDL_Cursor* cursors[CURSOR_TOTAL];
    GLOBAL Cursor      current_cursor;
    GLOBAL bool        cursors_enabled;
    GLOBAL bool        cursors_loaded;
}

FILDEF bool internal__load_cursor (Cursor _cursor, const char* _file_name, int _x, int _y)
{
    using namespace Cursor_Globals;

    SDL_Surface* surface = load_surface_resource(_file_name);
    if (!surface) {
        LOG_ERROR(ERR_MIN, "Failed to load cursor file '%s'!", _file_name);
        return false;
    }
    defer { SDL_FreeSurface(surface); };

    // We need to color key the loaded surface because it is a bitmap so it
    // does not have any alpha transparency by default (our key is white).
    //
    // Whilst we could technically continue even if this part fails we would
    // rather not because no one will want to use cursors with giant white
    // boxes around them... So instead we just fail and instead fallback to
    // using the standard operating system cursor instead of custom cursors.
    u32 color_key = SDL_MapRGB(surface->format, 0xFF,0x00,0xFF);
    if (SDL_SetColorKey(surface, SDL_TRUE, color_key) < 0) {
        LOG_ERROR(ERR_MIN, "Failed to color key cursor '%s'!", _file_name);
        return false;
    }

    cursors[_cursor] = SDL_CreateColorCursor(surface, _x, _y);
    if (!cursors[_cursor]) {
        LOG_ERROR(ERR_MIN, "Failed to create cursor '%s'!", _file_name);
        return false;
    }

    return true;
}

FILDEF bool load_editor_cursors ()
{
    using namespace Cursor_Globals;

    bool cursors_were_loaded = cursors_loaded;

    // This needs to be here for when we potentially reload the cursors.
    free_editor_cursors();

    cursors_enabled = false;
    cursors_loaded = false;

    // We have a special case for the beam cursor as we want a specific
    // version based on whether a light or dark UI is currently loaded.
    const char* beam_file = (is_ui_light()) ? "textures/editor_ui/cursor_beam_dark.bmp" : "textures/editor_ui/cursor_beam_light.bmp";

    if (!internal__load_cursor(CURSOR_ARROW,  "textures/editor_ui/cursor_arrow.bmp",   6,  3)) { return false; }
    if (!internal__load_cursor(CURSOR_BEAM,    beam_file,                             11, 12)) { return false; }
    if (!internal__load_cursor(CURSOR_POINTER,"textures/editor_ui/cursor_pointer.bmp", 8,  1)) { return false; }
    if (!internal__load_cursor(CURSOR_BRUSH,  "textures/editor_ui/cursor_brush.bmp",   3, 20)) { return false; }
    if (!internal__load_cursor(CURSOR_FILL,   "textures/editor_ui/cursor_fill.bmp",   19, 16)) { return false; }
    if (!internal__load_cursor(CURSOR_SELECT, "textures/editor_ui/cursor_select.bmp", 11, 12)) { return false; }

    cursors_enabled = editor_settings.custom_cursors;
    cursors_loaded = true;

    // By default we want to be using the arrow cursor.
    if (!cursors_enabled) {
        SDL_SetCursor(SDL_GetDefaultCursor());
        current_cursor = CURSOR_ARROW;
    } else {
        if (cursors_loaded) {
            SDL_SetCursor(cursors[CURSOR_ARROW]);
            current_cursor = CURSOR_ARROW;
        }
    }

    if (!cursors_were_loaded) { // Stops this getting printed on settings change.
        LOG_DEBUG("Loaded Editor Cursors");
    }
    return true;
}

FILDEF void free_editor_cursors ()
{
    using namespace Cursor_Globals;

    for (int i=0; i<CURSOR_TOTAL; ++i) {
        SDL_FreeCursor(cursors[i]);
        cursors[i] = NULL;
    }

    cursors_enabled = false;
    cursors_loaded = false;
}

FILDEF void set_cursor (Cursor _cursor)
{
    using namespace Cursor_Globals;

    if (cursors_enabled && cursors_loaded) {
        if (current_cursor != _cursor) {
            if (cursors[_cursor]) {
                SDL_SetCursor(cursors[_cursor]);
                current_cursor = _cursor;
            }
        }
    }
}

FILDEF Cursor get_cursor ()
{
    using namespace Cursor_Globals;
    return ((cursors_enabled && cursors_loaded) ? current_cursor : CURSOR_ARROW);
}

FILDEF bool custom_cursors_enabled ()
{
    return Cursor_Globals::cursors_enabled;
}
