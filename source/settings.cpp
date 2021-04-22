// These are default values for if certain settings values cannot be found.

GLOBAL constexpr const char* SETTINGS_DEFAULT_GAME_PATH           = "";
GLOBAL constexpr const char* SETTINGS_DEFAULT_UI_THEME            = "dark";
GLOBAL constexpr const char* SETTINGS_DEFAULT_FONT_FACE           = "OpenSans";
GLOBAL constexpr const char* SETTINGS_DEFAULT_TILE_GRAPHICS       = "new";
GLOBAL constexpr bool        SETTINGS_DEFAULT_CUSTOM_CURSORS      = true;
GLOBAL constexpr bool        SETTINGS_DEFAULT_SHOW_TOOLTIPS       = true;
GLOBAL constexpr bool        SETTINGS_DEFAULT_UNLIMITED_BACKUPS   = false;
GLOBAL constexpr int         SETTINGS_DEFAULT_BACKUP_COUNT        = 5;
GLOBAL constexpr bool        SETTINGS_DEFAULT_AUTO_BACKUP         = true;
GLOBAL constexpr int         SETTINGS_DEFAULT_BACKUP_INTERVAL     = 180;
GLOBAL           const vec4  SETTINGS_DEFAULT_SELECT_COLOR        = { .94f, .0f, 1.0f, .25f };
GLOBAL           const vec4  SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR = { .25f, .1f,  .1f, .40f };
GLOBAL           const vec4  SETTINGS_DEFAULT_CURSOR_COLOR        = { .20f, .9f,  .2f, .40f };
GLOBAL           const vec4  SETTINGS_DEFAULT_MIRROR_LINE_COLOR   = { .80f, .2f,  .2f, .80f };

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

FILDEF vec4 internal__get_settings_color (const GonObject& gon, std::string name, vec4 default_value, bool* did_default = NULL)
{
    if (did_default) *did_default = true;

    // If the color couldn't be found we just return back default.
    if (!gon.Contains(name) || gon[name].type != GonObject::g_array)
    {
        return default_value;
    }

    vec4 color;

    color.r = CAST(float, gon[name][0].Number(1));
    color.g = CAST(float, gon[name][1].Number(1));
    color.b = CAST(float, gon[name][2].Number(1));
    color.a = CAST(float, gon[name][3].Number(1));

    if (did_default) *did_default = false;

    return color;
}

FILDEF bool operator== (const Settings& a, const Settings& b)
{
    return (a.game_path                  == b.game_path                  &&
            a.background_color_defaulted == b.background_color_defaulted &&
            a.tile_grid_color_defaulted  == b.tile_grid_color_defaulted  &&
            a.ui_theme                   == b.ui_theme                   &&
            a.font_face                  == b.font_face                  &&
            a.tile_graphics              == b.tile_graphics              &&
            a.custom_cursors             == b.custom_cursors             &&
            a.show_tooltips              == b.show_tooltips              &&
            a.unlimited_backups          == b.unlimited_backups          &&
            a.backup_count               == b.backup_count               &&
            a.auto_backup                == b.auto_backup                &&
            a.backup_interval            == b.backup_interval            &&
            a.background_color           == b.background_color           &&
            a.select_color               == b.select_color               &&
            a.out_of_bounds_color        == b.out_of_bounds_color        &&
            a.cursor_color               == b.cursor_color               &&
            a.mirror_line_color          == b.mirror_line_color          &&
            a.tile_grid_color            == b.tile_grid_color);
}

FILDEF bool operator!= (const Settings& a, const Settings& b)
{
    return !(a == b);
}

FILDEF void update_systems_that_rely_on_settings (bool tile_graphics_changed)
{
    update_backup_timer();
    update_editor_font ();
    load_ui_theme      ();

    if (tile_graphics_changed)
    {
        reload_tile_graphics();
    }
}

FILDEF bool load_editor_settings ()
{
    LOG_DEBUG("Loading editor settings...");

    GonObject gon;
    try
    {
        std::string file_name(get_appdata_path() + SETTINGS_FILE_NAME);
        if (!does_file_exist(file_name)) // Fallback for the old local settings files to still work!
        {
            file_name = make_path_absolute("settings_editor.txt");
        }
        gon = GonObject::Load(file_name);
    }
    catch (const char* msg)
    {
        LOG_ERROR(ERR_MED, "%s", msg);

        // If we already have settings data then we just inform the user that the operation
        // failed. Otherwise, we just fallback to using the default application settings.
        if (settings_loaded)
        {
            LOG_ERROR(ERR_MED, "Failed to reload settings data!");
            return false;
        }
        else
        {
            gon = GonObject::LoadFromBuffer(SETTINGS_FALLBACK);
        }
    }

    // If we reach this point and there are no settings then we just use the defaults.
    // This could be the case if the settings failed to load or haven't been modified.
    if (gon.type != GonObject::g_object)
    {
        LOG_DEBUG("No editor settings file found!");
        LOG_DEBUG("Using default settings!");
        gon = GonObject::LoadFromBuffer(SETTINGS_FALLBACK);
    }
    else
    {
        LOG_DEBUG("Loaded editor settings file!");
    }

    // Load the settings values from the GON into the actual values.
    editor_settings.game_path         = gon[SETTING_GAME_PATH        ].String(SETTINGS_DEFAULT_GAME_PATH        );
    editor_settings.ui_theme          = gon[SETTING_UI_THEME         ].String(SETTINGS_DEFAULT_UI_THEME         );
    editor_settings.font_face         = gon[SETTING_FONT_FACE        ].String(SETTINGS_DEFAULT_FONT_FACE        );
    editor_settings.tile_graphics     = gon[SETTING_TILE_GRAPHICS    ].String(SETTINGS_DEFAULT_TILE_GRAPHICS    );
    editor_settings.custom_cursors    = gon[SETTING_CUSTOM_CURSORS   ].Bool  (SETTINGS_DEFAULT_CUSTOM_CURSORS   );
    editor_settings.show_tooltips     = gon[SETTING_SHOW_TOOLTIPS    ].Bool  (SETTINGS_DEFAULT_SHOW_TOOLTIPS    );
    editor_settings.unlimited_backups = gon[SETTING_UNLIMITED_BACKUPS].Bool  (SETTINGS_DEFAULT_UNLIMITED_BACKUPS);
    editor_settings.backup_count      = gon[SETTING_BACKUP_COUNT     ].Int   (SETTINGS_DEFAULT_BACKUP_COUNT     );
    editor_settings.auto_backup       = gon[SETTING_AUTO_BACKUP      ].Bool  (SETTINGS_DEFAULT_AUTO_BACKUP      );
    editor_settings.backup_interval   = gon[SETTING_BACKUP_INTERVAL  ].Int   (SETTINGS_DEFAULT_BACKUP_INTERVAL  );

    update_systems_that_rely_on_settings(true);

    // Load the colors afterwards because some of them depend on the UI theme.
    vec4 default_background_color = ui_color_light;
    vec4 default_tile_grid_color  = is_ui_light() ? ui_color_black : ui_color_ex_dark;

    editor_settings.background_color    = internal__get_settings_color(gon, SETTING_BACKGROUND_COLOR,    default_background_color,            &editor_settings.background_color_defaulted);
    editor_settings.select_color        = internal__get_settings_color(gon, SETTING_SELECT_COLOR,        SETTINGS_DEFAULT_SELECT_COLOR                                                   );
    editor_settings.out_of_bounds_color = internal__get_settings_color(gon, SETTING_OUT_OF_BOUNDS_COLOR, SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR                                            );
    editor_settings.cursor_color        = internal__get_settings_color(gon, SETTING_CURSOR_COLOR,        SETTINGS_DEFAULT_CURSOR_COLOR                                                   );
    editor_settings.mirror_line_color   = internal__get_settings_color(gon, SETTING_MIRROR_LINE_COLOR,   SETTINGS_DEFAULT_MIRROR_LINE_COLOR                                              );
    editor_settings.tile_grid_color     = internal__get_settings_color(gon, SETTING_TILE_GRID_COLOR,     default_tile_grid_color,             &editor_settings.tile_grid_color_defaulted );

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

    update_systems_that_rely_on_settings(tile_graphics_changed);

    // Restore the colors afterwards because some of them depend on the UI theme.
    vec4 default_background_color = ui_color_light;
    vec4 default_tile_grid_color = is_ui_light() ? ui_color_black : ui_color_ex_dark;

    editor_settings.background_color    = default_background_color;
    editor_settings.select_color        = SETTINGS_DEFAULT_SELECT_COLOR;
    editor_settings.out_of_bounds_color = SETTINGS_DEFAULT_OUT_OF_BOUNDS_COLOR;
    editor_settings.cursor_color        = SETTINGS_DEFAULT_CURSOR_COLOR;
    editor_settings.mirror_line_color   = SETTINGS_DEFAULT_MIRROR_LINE_COLOR;
    editor_settings.tile_grid_color     = default_tile_grid_color;
}

FILDEF void dump_editor_settings ()
{
    #define EXPAND_VEC4(v) v.r, v.g, v.b, v.a
    LOG_DEBUG("");
    LOG_DEBUG("[[Settings]]");
    LOG_DEBUG("%s %s", SETTING_GAME_PATH, editor_settings.game_path.c_str());
    LOG_DEBUG("%s %s", SETTING_UI_THEME, editor_settings.ui_theme.c_str());
    LOG_DEBUG("%s %s", SETTING_FONT_FACE, editor_settings.font_face.c_str());
    LOG_DEBUG("%s %s", SETTING_TILE_GRAPHICS, editor_settings.tile_graphics.c_str());
    LOG_DEBUG("%s %s", SETTING_CUSTOM_CURSORS, (editor_settings.custom_cursors) ? "true" : "false");
    LOG_DEBUG("%s %s", SETTING_SHOW_TOOLTIPS, (editor_settings.show_tooltips) ? "true" : "false");
    LOG_DEBUG("%s %s", SETTING_UNLIMITED_BACKUPS, (editor_settings.unlimited_backups) ? "true" : "false");
    LOG_DEBUG("%s %d", SETTING_BACKUP_COUNT, editor_settings.backup_count);
    LOG_DEBUG("%s %s", SETTING_AUTO_BACKUP, (editor_settings.auto_backup) ? "true" : "false");
    LOG_DEBUG("%s %d", SETTING_BACKUP_INTERVAL, editor_settings.backup_interval);
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_BACKGROUND_COLOR, EXPAND_VEC4(editor_settings.background_color));
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_SELECT_COLOR, EXPAND_VEC4(editor_settings.select_color));
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_OUT_OF_BOUNDS_COLOR, EXPAND_VEC4(editor_settings.out_of_bounds_color));
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_CURSOR_COLOR, EXPAND_VEC4(editor_settings.cursor_color));
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_MIRROR_LINE_COLOR, EXPAND_VEC4(editor_settings.mirror_line_color));
    LOG_DEBUG("%s (%f %f %f %f)", SETTING_TILE_GRID_COLOR, EXPAND_VEC4(editor_settings.tile_grid_color));
    #undef EXPAND_VEC4
}
