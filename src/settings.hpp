#pragma once

GLOBAL constexpr const char* SETTINGS_FILE_NAME = "settings_editor.txt";

// The names for all of the user settings found in the user settings file.
// We store them here so that if we ever want to change any of the names
// then we only have to update them here rather than everywhere they are
// referenced throughout the program's source code -- would be annoying!

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
    // Special cases for these two colors where their defaults depend on the
    // UI so we need to know if they defaulted or not so the preferences
    bool background_color_defaulted;
    bool tile_grid_color_defaulted;

    // User Interface
    std::string      ui_theme;
    std::string     font_face;
    std::string tile_graphics;
    bool       custom_cursors;
    bool        show_tooltips;

    // Level Backups
    bool unlimited_backups;
    int       backup_count;
    bool       auto_backup;
    int    backup_interval;

    // Editor Colors
    Vec4    background_color;
    Vec4        select_color;
    Vec4 out_of_bounds_color;
    Vec4        cursor_color;
    Vec4   mirror_line_color;
    Vec4     tile_grid_color;
};

FILDEF bool operator== (const Settings& _a, const Settings& _b);
FILDEF bool operator!= (const Settings& _a, const Settings& _b);

GLOBAL Settings editor_settings;

FILDEF bool load_editor_settings    ();
FILDEF void restore_editor_settings ();
