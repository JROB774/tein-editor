GLOBAL constexpr const char* CURSOR_FILE_ARROW   = "textures/editor_ui/cursor_arrow.bmp";
GLOBAL constexpr const char* CURSOR_FILE_BEAM_D  = "textures/editor_ui/cursor_beam_dark.bmp";
GLOBAL constexpr const char* CURSOR_FILE_BEAM_L  = "textures/editor_ui/cursor_beam_light.bmp";
GLOBAL constexpr const char* CURSOR_FILE_POINTER = "textures/editor_ui/cursor_pointer.bmp";
GLOBAL constexpr const char* CURSOR_FILE_BRUSH   = "textures/editor_ui/cursor_brush.bmp";
GLOBAL constexpr const char* CURSOR_FILE_FILL    = "textures/editor_ui/cursor_fill.bmp";
GLOBAL constexpr const char* CURSOR_FILE_SELECT  = "textures/editor_ui/cursor_select.bmp";

GLOBAL SDL_Cursor* cursors[CAST(size_t, Cursor::Total)];
GLOBAL Cursor      current_cursor;
GLOBAL bool        cursors_enabled;
GLOBAL bool        cursors_loaded;

FILDEF bool internal__load_cursor (Cursor cursor, const char* file_name, int x, int y)
{
    SDL_Surface* surface = load_surface_resource(file_name);
    if (!surface)
    {
        LOG_ERROR(ERR_MIN, "Failed to load cursor file '%s'!", file_name);
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
    if (SDL_SetColorKey(surface, SDL_TRUE, color_key) < 0)
    {
        LOG_ERROR(ERR_MIN, "Failed to color key cursor '%s'!", file_name);
        return false;
    }

    cursors[CAST(int, cursor)] = SDL_CreateColorCursor(surface, x, y);
    if (!cursors[CAST(int, cursor)])
    {
        LOG_ERROR(ERR_MIN, "Failed to create cursor '%s'!", file_name);
        return false;
    }

    return true;
}

FILDEF bool load_editor_cursors ()
{
    // We have a special case for the beam cursor as we want a specific
    // version based on whether a light or dark UI is currently loaded.
    const char* CURSOR_FILE_BEAM = (is_ui_light()) ? CURSOR_FILE_BEAM_D : CURSOR_FILE_BEAM_L;

    // This needs to be here for when we potentially reload the cursors.
    free_editor_cursors();

    cursors_enabled = false;
    cursors_loaded = false;

    if (!internal__load_cursor(Cursor::ARROW,   CURSOR_FILE_ARROW  ,  6,  3)) return false;
    if (!internal__load_cursor(Cursor::BEAM,    CURSOR_FILE_BEAM   , 11, 12)) return false;
    if (!internal__load_cursor(Cursor::POINTER, CURSOR_FILE_POINTER,  8,  1)) return false;
    if (!internal__load_cursor(Cursor::BRUSH,   CURSOR_FILE_BRUSH  ,  3, 20)) return false;
    if (!internal__load_cursor(Cursor::FILL,    CURSOR_FILE_FILL   , 19, 16)) return false;
    if (!internal__load_cursor(Cursor::SELECT,  CURSOR_FILE_SELECT , 11, 12)) return false;

    cursors_enabled = editor_settings.custom_cursors;
    cursors_loaded = true;

    // By default we want to be using the arrow cursor.
    if (!cursors_enabled)
    {
        SDL_SetCursor(SDL_GetDefaultCursor());
        current_cursor = Cursor::ARROW;
    }
    else
    {
        if (cursors_loaded)
        {
            SDL_SetCursor(cursors[CAST(int, Cursor::ARROW)]);
            current_cursor = Cursor::ARROW;
        }
    }

    return true;
}

FILDEF void free_editor_cursors ()
{
    for (int i=0; i<CAST(int, Cursor::Total); ++i)
    {
        SDL_FreeCursor(cursors[i]);
        cursors[i] = NULL;
    }

    cursors_enabled = false;
    cursors_loaded = false;
}

FILDEF void set_cursor (Cursor cursor)
{
    if (cursors_enabled && cursors_loaded && current_cursor != cursor && cursors[CAST(int, cursor)])
    {
        SDL_SetCursor(cursors[CAST(int, cursor)]);
        current_cursor = cursor;
    }
}

FILDEF Cursor get_cursor ()
{
    return ((cursors_enabled && cursors_loaded) ? current_cursor : Cursor::ARROW);
}

FILDEF bool custom_cursors_enabled ()
{
    return cursors_enabled;
}
