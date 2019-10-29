#pragma once

GLOBAL constexpr float MIN_LVL_EDITOR_ZOOM   = 0.25f;
GLOBAL constexpr float MAX_LVL_EDITOR_ZOOM   = 4.00f;
GLOBAL constexpr float MIN_MAP_EDITOR_ZOOM   = 0.25f;
GLOBAL constexpr float MAX_MAP_EDITOR_ZOOM   = 1.00f;
GLOBAL constexpr float EDITOR_ZOOM_INCREMENT = 0.10f;

struct Camera
{
    float x;
    float y;

    float zoom;
};

enum Tab_Type
{
    TAB_TYPE_LEVEL,
    TAB_TYPE_MAP,
};

struct Tab
{
    // GENERAL
    Tab_Type        type;
    std::string     name;
    Camera        camera;
    bool unsaved_changes;

    // LEVEL
    Level         level;
    Tool_Info     tool_info;
    Level_History level_history;
    bool tile_layer_active[LEVEL_LAYER_TOTAL];
    std::vector<Select_Bounds> old_select_state; // We use this for the selection history undo/redo system.

    // MAP
    Map         map;
    Map_History map_history;
    Map_Select  map_select;
};

struct Editor
{
    std::vector<Tab> tabs;
    size_t current_tab;

    SDL_TimerID backup_timer;
    SDL_TimerID cooldown_timer;

    bool grid_visible;
    bool is_panning;
    bool dialog_box; // NOTE: See inside open_dialog, save_dialog, or path_dialog for info.
};

GLOBAL Editor editor;

FILDEF void init_editor (int _argc, char** _argv);
FILDEF void quit_editor ();
FILDEF void do_editor   ();

FILDEF void handle_editor_events ();
FILDEF void update_backup_timer  ();

FILDEF void set_current_tab    (size_t _index);
FILDEF Tab& get_current_tab    ();
FILDEF Tab& get_tab_at_index   (size_t _index);
FILDEF bool are_there_any_tabs ();

FILDEF void increment_tab ();
FILDEF void decrement_tab ();

FILDEF void set_main_window_subtitle_for_tab (const std::string& _subtitle);

FILDEF bool are_there_any_level_tabs ();
FILDEF bool are_there_any_map_tabs   ();

FILDEF void create_new_level_tab_and_focus (int _w=DEFAULT_LEVEL_WIDTH, int _h=DEFAULT_LEVEL_HEIGHT);
FILDEF void create_new_map_tab_and_focus   ();

FILDEF bool current_tab_is_level ();
FILDEF bool current_tab_is_map   ();

FILDEF void close_tab         (size_t _index);
FILDEF void close_current_tab ();
FILDEF void close_all_tabs    ();

FILDEF void push_editor_camera_transform ();
FILDEF void pop_editor_camera_transform  ();

FILDEF int  save_changes_prompt (Tab& _tab);

FILDEF void backup_tab (Tab& _tab);

FILDEF bool is_current_tab_empty ();

FILDEF void editor_select_all ();
FILDEF void editor_paste      ();
