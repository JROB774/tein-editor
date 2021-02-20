#pragma once

GLOBAL constexpr const char* SETTINGS_FILE_NAME = "settings.dat";

// The names for all of the user settings found in the user settings file.
// We store them here so that if we ever want to change any of the names
// then we only have to update them here rather than everywhere they are
// referenced throughout the program's source code -- would be annoying!

GLOBAL constexpr const char* SETTING_GAME_PATH           = "game_path";
GLOBAL constexpr const char* SETTING_UI_THEME            = "user_interface_theme";
GLOBAL constexpr const char* SETTING_FONT_FACE           = "font_face";
GLOBAL constexpr const char* SETTING_TILE_GRAPHICS       = "tile_graphics";
GLOBAL constexpr const char* SETTING_CUSTOM_CURSORS      = "custom_cursors";
GLOBAL constexpr const char* SETTING_SHOW_TOOLTIPS       = "show_tooltips";
GLOBAL constexpr const char* SETTING_UNLIMITED_BACKUPS   = "unlimited_backups";
GLOBAL constexpr const char* SETTING_BACKUP_COUNT        = "backup_count";
GLOBAL constexpr const char* SETTING_AUTO_BACKUP         = "auto_backup";
GLOBAL constexpr const char* SETTING_BACKUP_INTERVAL     = "auto_backup_interval";
GLOBAL constexpr const char* SETTING_BACKGROUND_COLOR    = "background_color";
GLOBAL constexpr const char* SETTING_SELECT_COLOR        = "select_color";
GLOBAL constexpr const char* SETTING_OUT_OF_BOUNDS_COLOR = "out_of_bounds_color";
GLOBAL constexpr const char* SETTING_CURSOR_COLOR        = "cursor_color";
GLOBAL constexpr const char* SETTING_MIRROR_LINE_COLOR   = "mirror_line_color";
GLOBAL constexpr const char* SETTING_TILE_GRID_COLOR     = "tile_grid_color";

struct Settings
{
    // Not a proper setting but we save it for convenience when running the game.
    std::string game_path;

    // Special cases for these two colors where their defaults depend on the
    // UI so we need to know if they are defaulted or not when displaying.
    bool background_color_defaulted;
    bool tile_grid_color_defaulted;

    // USER INTERFACE
    std::string      ui_theme;
    std::string     font_face;
    std::string tile_graphics;
    bool       custom_cursors;
    bool        show_tooltips;
    // LEVEL BACKUPS
    bool    unlimited_backups;
    int          backup_count;
    bool          auto_backup;
    int       backup_interval;
    // EDITOR COLORS
    vec4     background_color;
    vec4         select_color;
    vec4  out_of_bounds_color;
    vec4         cursor_color;
    vec4    mirror_line_color;
    vec4      tile_grid_color;
};

FILDEF bool operator== (const Settings& a, const Settings& b);
FILDEF bool operator!= (const Settings& a, const Settings& b);

GLOBAL Settings editor_settings;

FILDEF void update_systems_that_rely_on_settings (bool tile_graphics_changed);

FILDEF bool    load_editor_settings ();
FILDEF void restore_editor_settings ();
