// The order in which layer data is stored within the .lvl files is different
// from the order it is actually represented in the editor so we use an array
// to get the correct order in which to read & write the layers to the files.

constexpr Level_Layer LEVEL_IO_ORDER[LEVEL_LAYER_TOTAL]
{
    LEVEL_LAYER_BACK1,
    LEVEL_LAYER_ACTIVE,
    LEVEL_LAYER_TAG,
    LEVEL_LAYER_OVERLAY,
    LEVEL_LAYER_BACK2
};

FILDEF bool internal__load_level (FILE* _file, Level& _level)
{
    fread(&_level.header.version, sizeof(s32), 1, _file);
    fread(&_level.header.width  , sizeof(s32), 1, _file);
    fread(&_level.header.height , sizeof(s32), 1, _file);
    fread(&_level.header.layers , sizeof(s32), 1, _file);

    _level.header.version = SDL_SwapBE32(_level.header.version);
    _level.header.width   = SDL_SwapBE32(_level.header.width  );
    _level.header.height  = SDL_SwapBE32(_level.header.height );
    _level.header.layers  = SDL_SwapBE32(_level.header.layers );

    if (_level.header.version != 1) {
        std::string msg(format_string("Invalid level file version '%d'!", _level.header.version));
        show_alert("Error", msg.c_str(), ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "WINMAIN");
        return false;
    }

    s32 lw = _level.header.width;
    s32 lh = _level.header.height;

    for (int i=0; i<LEVEL_LAYER_TOTAL; ++i) {
        auto& layer = _level.data[LEVEL_IO_ORDER[i]];
        layer.assign(lw*lh, 0);
        for (auto& tile: layer) {
            fread(&tile, sizeof(Tile_ID), 1, _file);
            tile = SDL_SwapBE32(tile);
        }
    }

    return true;
}

FILDEF void internal__save_level (FILE* _file, const Level& _level)
{
    s32 version = SDL_SwapBE32(_level.header.version);
    s32 width   = SDL_SwapBE32(_level.header.width  );
    s32 height  = SDL_SwapBE32(_level.header.height );
    s32 layers  = SDL_SwapBE32(_level.header.layers );

    fwrite(&version, sizeof(s32), 1, _file);
    fwrite(&width  , sizeof(s32), 1, _file);
    fwrite(&height , sizeof(s32), 1, _file);
    fwrite(&layers , sizeof(s32), 1, _file);

    for (int i=0; i<LEVEL_LAYER_TOTAL; ++i) {
        auto& layer = _level.data[LEVEL_IO_ORDER[i]];
        for (auto& tile: layer) {
            Tile_ID id = SDL_SwapBE32(tile);
            fwrite(&id, sizeof(Tile_ID), 1, _file);
        }
    }
}

STDDEF bool load_level (Level& _level, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.
    FILE* file = fopen(_file_name, "rb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to load level file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    // If the level is empty/blank we just create a blank default level.
    if (get_size_of_file(file) == 0) { return create_blank_level(_level);          }
    else                             { return internal__load_level(file, _level);  }
}

STDDEF bool save_level (const Level& _level, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.
    FILE* file = fopen(_file_name, "wb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to save level file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    internal__save_level(file, _level);
    return true;
}

STDDEF bool load_restore_level (Level_Tab& _tab, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.
    FILE* file = fopen(_file_name, "rb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to load restore file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    // Read until the null-terminator to get the name of the level.
    std::string level_name;
    char c = 0;
    do {
        fread(&c, sizeof(char), 1, file);
        if (c) { level_name.push_back(c); }
    }
    while (c);

    // Set the name of the level for the tab we are loading content into.
    _tab.name = level_name;

    internal__load_level(file, _tab.level);
    return true;
}

STDDEF bool save_restore_level (const Level_Tab& _tab, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.
    FILE* file = fopen(_file_name, "wb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to save restore file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    // Write the name of the level + null-terminator for later restoration.
    if (_tab.name.empty()) {
        char null_terminator = '\0';
        fwrite(&null_terminator, sizeof(char), 1, file);
    } else {
        const char* name = _tab.name.c_str();
        fwrite(name, sizeof(char), strlen(name)+1, file);
    }

    internal__save_level(file, _tab.level);
    return true;
}

FILDEF bool create_blank_level (Level& _level, int _w, int _h)
{
    _level.header.version = 1;
    _level.header.width   = CAST(s32, _w);
    _level.header.height  = CAST(s32, _h);
    _level.header.layers  = LEVEL_LAYER_TOTAL;

    s32 lw = _level.header.width;
    s32 lh = _level.header.height;

    for (auto& layer: _level.data) { layer.assign(lw*lh, 0); }

    return true;
}
