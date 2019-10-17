// These are fallback values for if certain settings values cannot be found.

GLOBAL constexpr const char* SETTINGS_DEFAULT_UI_THEME            = "dark";
GLOBAL constexpr const char* SETTINGS_DEFAULT_FONT_FACE           = "OpenSans";
GLOBAL constexpr const char* SETTINGS_DEFAULT_TILE_GRAPHICS       = "new";
GLOBAL constexpr bool        SETTINGS_DEFAULT_CUSTOM_CURSORS      = true;
GLOBAL constexpr bool        SETTINGS_DEFAULT_SHOW_TOOLTIPS       = true;
GLOBAL constexpr bool        SETTINGS_DEFAULT_UNLIMITED_BACKUPS   = false;
GLOBAL constexpr int         SETTINGS_DEFAULT_BACKUP_COUNT        = 5;
GLOBAL constexpr bool        SETTINGS_DEFAULT_AUTO_BACKUP         = true;
GLOBAL constexpr int         SETTINGS_DEFAULT_BACKUP_INTERVAL     = 180;
GLOBAL constexpr Vec4        SETTINGS_DEFAULT_SELECT_COLOR        = { 0.94f, 0.0f, 1.0f, 0.25f };
GLOBAL constexpr Vec4        SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR = { 0.25f, 0.1f, 0.1f, 0.40f };
GLOBAL constexpr Vec4        SETTINGS_DEFAULT_CURSOR_COLOR        = { 0.20f, 0.9f, 0.2f, 0.40f };
GLOBAL constexpr Vec4        SETTINGS_DEFAULT_MIRROR_LINE_COLOR   = { 0.80f, 0.2f, 0.2f, 0.80f };

// Fallback copy of the settings file we can load in the case that the
// settings file is not present and then we just save these defaults.

GLOBAL constexpr const char* SETTINGS_FALLBACK =
"user_interface_theme dark\n"
"font_face OpenSans\n"
"tile_graphics new\n"
"custom_cursors true\n"
"show_tooltips true\n"
"unlimited_backups false\n"
"backup_count 5\n"
"auto_backup true\n"
"auto_backup_interval 120\n"
"background_color none\n"
"select_color [0.900000 0.000000 1.000000 0.250000]\n"
"out_of_bounds_color [0.250000 0.100000 0.100000 0.400000]\n"
"cursor_color [0.200000 0.900000 0.200000 0.400000]\n"
"mirror_line_color [0.800000 0.200000 0.200000 0.800000]\n"
"tile_grid_color none\n";

GLOBAL bool settings_loaded;

FILDEF Vec4 internal__get_settings_color (const GonObject& _gon, const char* _name, Vec4 _default, bool* _did_default=NULL)
{
    if (_did_default) { *_did_default = true; }

    // If the color couldn't be found we just return back default.
    if (!_gon.Contains(_name)) { return _default; }
    if (_gon[_name].type != GonObject::g_array) { return _default; }

    Vec4 color;

    color.r = CAST(float, _gon[_name][0].Number(1));
    color.g = CAST(float, _gon[_name][1].Number(1));
    color.b = CAST(float, _gon[_name][2].Number(1));
    color.a = CAST(float, _gon[_name][3].Number(1));

    if (_did_default) { *_did_default = false; }
    return color;
}

FILDEF bool operator== (const Settings& _a, const Settings& _b)
{
    return (_a.background_color_defaulted == _b.background_color_defaulted &&
            _a.tile_grid_color_defaulted  == _b.tile_grid_color_defaulted  &&
            _a.ui_theme                   == _b.ui_theme                   &&
            _a.font_face                  == _b.font_face                  &&
            _a.tile_graphics              == _b.tile_graphics              &&
            _a.custom_cursors             == _b.custom_cursors             &&
            _a.show_tooltips              == _b.show_tooltips              &&
            _a.unlimited_backups          == _b.unlimited_backups          &&
            _a.backup_count               == _b.backup_count               &&
            _a.auto_backup                == _b.auto_backup                &&
            _a.backup_interval            == _b.backup_interval            &&
            _a.background_color           == _b.background_color           &&
            _a.select_color               == _b.select_color               &&
            _a.out_of_bounds_color        == _b.out_of_bounds_color        &&
            _a.cursor_color               == _b.cursor_color               &&
            _a.mirror_line_color          == _b.mirror_line_color          &&
            _a.tile_grid_color            == _b.tile_grid_color);
}
FILDEF bool operator!= (const Settings& _a, const Settings& _b)
{
    return !(_a == _b);
}

FILDEF bool load_editor_settings ()
{
    GonObject settings_gon;
    try {
        std::string file_name = make_path_absolute(SETTINGS_FILE_NAME);
        settings_gon = GonObject::Load(file_name);
    } catch (const char* _msg) {
        LOG_ERROR(ERR_MED, "%s", _msg);

        // If we already have settings data then we just inform the user that the operation
        // failed. Otherwise, we just fallback to using the default application settings.
        if (settings_loaded) {
            LOG_ERROR(ERR_MED, "Failed to reload settings data!");
            return false;
        } else {
            settings_gon = GonObject::LoadFromBuffer(SETTINGS_FALLBACK);
        }
    }

    // If we reach this point and there are no settings then we just use the defaults.
    // This could be the case if the settings failed to load or haven't been modified.
    if (settings_gon.type != GonObject::g_object) {
        LOG_DEBUG("No settings file found -- using defaults.");
        settings_gon = GonObject::LoadFromBuffer(SETTINGS_FALLBACK);
    }

    LOG_DEBUG("Loaded Editor Settings");

    // Load the settings values from the GON into the actual values.
    editor_settings.ui_theme          = settings_gon[SETTING_UI_THEME         ].String(SETTINGS_DEFAULT_UI_THEME         );
    editor_settings.font_face         = settings_gon[SETTING_FONT_FACE        ].String(SETTINGS_DEFAULT_FONT_FACE        );
    editor_settings.tile_graphics     = settings_gon[SETTING_TILE_GRAPHICS    ].String(SETTINGS_DEFAULT_TILE_GRAPHICS    );
    editor_settings.custom_cursors    = settings_gon[SETTING_CUSTOM_CURSORS   ].Bool  (SETTINGS_DEFAULT_CUSTOM_CURSORS   );
    editor_settings.show_tooltips     = settings_gon[SETTING_SHOW_TOOLTIPS    ].Bool  (SETTINGS_DEFAULT_SHOW_TOOLTIPS    );
    editor_settings.unlimited_backups = settings_gon[SETTING_UNLIMITED_BACKUPS].Bool  (SETTINGS_DEFAULT_UNLIMITED_BACKUPS);
    editor_settings.backup_count      = settings_gon[SETTING_BACKUP_COUNT     ].Int   (SETTINGS_DEFAULT_BACKUP_COUNT     );
    editor_settings.auto_backup       = settings_gon[SETTING_AUTO_BACKUP      ].Bool  (SETTINGS_DEFAULT_AUTO_BACKUP      );
    editor_settings.backup_interval   = settings_gon[SETTING_BACKUP_INTERVAL  ].Int   (SETTINGS_DEFAULT_BACKUP_INTERVAL  );

    // NOTE: IF WE MAKE CHANGES TO THESE SYSTEMS WE WILL PROBABLY NEED TO REFLECT
    // THOSE CHANGES IN THE PREFERENCES MENU, SO IT'S BEST TO CHECK THERE AS WELL!

    // Update any systems that rely on settings values.
    update_level_backup_timer();
    update_editor_font();
    load_ui_theme();
    reload_tile_graphics();

    // Load the colors afterwards because some of them depend on the UI theme.
    Vec4 default_background_color = ui_color_light;
    Vec4 default_tile_grid_color = is_ui_light() ? ui_color_black : ui_color_ex_dark;

    editor_settings.background_color    = internal__get_settings_color(settings_gon, SETTING_BACKGROUND_COLOR,    default_background_color,            &editor_settings.background_color_defaulted);
    editor_settings.select_color        = internal__get_settings_color(settings_gon, SETTING_SELECT_COLOR,        SETTINGS_DEFAULT_SELECT_COLOR        );
    editor_settings.out_of_bounds_color = internal__get_settings_color(settings_gon, SETTING_OUT_OF_BOUNDS_COLOR, SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR );
    editor_settings.cursor_color        = internal__get_settings_color(settings_gon, SETTING_CURSOR_COLOR,        SETTINGS_DEFAULT_CURSOR_COLOR        );
    editor_settings.mirror_line_color   = internal__get_settings_color(settings_gon, SETTING_MIRROR_LINE_COLOR,   SETTINGS_DEFAULT_MIRROR_LINE_COLOR   );
    editor_settings.tile_grid_color     = internal__get_settings_color(settings_gon, SETTING_TILE_GRID_COLOR,     default_tile_grid_color,             &editor_settings.tile_grid_color_defaulted);

    settings_loaded = true;
    return true;
}

FILDEF void restore_editor_settings ()
{
    bool tile_graphics_changed = (editor_settings.tile_graphics != SETTINGS_DEFAULT_TILE_GRAPHICS);

    // Restore the editor settings values to their default values.
    editor_settings.ui_theme          = SETTINGS_DEFAULT_UI_THEME;
    editor_settings.font_face         = SETTINGS_DEFAULT_FONT_FACE;
    editor_settings.tile_graphics     = SETTINGS_DEFAULT_TILE_GRAPHICS;
    editor_settings.custom_cursors    = SETTINGS_DEFAULT_CUSTOM_CURSORS;
    editor_settings.show_tooltips     = SETTINGS_DEFAULT_SHOW_TOOLTIPS;
    editor_settings.unlimited_backups = SETTINGS_DEFAULT_UNLIMITED_BACKUPS;
    editor_settings.backup_count      = SETTINGS_DEFAULT_BACKUP_COUNT;
    editor_settings.auto_backup       = SETTINGS_DEFAULT_AUTO_BACKUP;
    editor_settings.backup_interval   = SETTINGS_DEFAULT_BACKUP_INTERVAL;

    // NOTE: IF WE MAKE CHANGES TO THESE SYSTEMS WE WILL PROBABLY NEED TO REFLECT
    // THOSE CHANGES IN THE PREFERENCES MENU, SO IT'S BEST TO CHECK THERE AS WELL!

    // Update any systems that rely on settings values.
    update_level_backup_timer();
    update_editor_font();
    load_ui_theme();
    if (tile_graphics_changed) { reload_tile_graphics(); }

    // Restore the colors afterwards because some of them depend on the UI theme.
    Vec4 default_background_color = ui_color_light;
    Vec4 default_tile_grid_color = is_ui_light() ? ui_color_black : ui_color_ex_dark;

    editor_settings.background_color    = default_background_color;
    editor_settings.select_color        = SETTINGS_DEFAULT_SELECT_COLOR;
    editor_settings.out_of_bounds_color = SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR;
    editor_settings.cursor_color        = SETTINGS_DEFAULT_CURSOR_COLOR;
    editor_settings.mirror_line_color   = SETTINGS_DEFAULT_MIRROR_LINE_COLOR;
    editor_settings.tile_grid_color     = default_tile_grid_color;
}
