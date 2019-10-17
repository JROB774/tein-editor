#pragma once

enum Tool_State { TOOL_STATE_IDLE, TOOL_STATE_PLACE, TOOL_STATE_ERASE };
enum Tool_Type  { TOOL_TYPE_BRUSH, TOOL_TYPE_FILL, TOOL_TYPE_SELECT };

struct Tool_Fill
{
    std::vector<Vec2> frontier;
    std::vector<bool> searched;

    Level_Layer layer;

    Tile_ID find_id;
    Tile_ID replace_id;

    Vec2 start;

    bool inside_select;
};

struct Select_Bounds
{
    int top;
    int right;
    int bottom;
    int left;

    bool visible;
};

struct Tool_Select
{
    std::vector<Select_Bounds> bounds;

    bool start;
    bool add;

    size_t cached_size;
};

struct Tool_Info
{
    Tool_Fill   fill;
    Tool_Select select;
};

struct Clipboard
{
    Level_Data data;

    int x;
    int y;
    int w;
    int h;
};

enum History_Action
{
    HISTORY_ACTION_NORMAL,
    HISTORY_ACTION_FLIP_LEVEL_H,
    HISTORY_ACTION_FLIP_LEVEL_V,
    HISTORY_ACTION_SELECT_STATE,
    HISTORY_ACTION_CLEAR,
    HISTORY_ACTION_RESIZE,
};

struct History_Info
{
    int x;
    int y;

    Tile_ID old_id;
    Tile_ID new_id;

    Level_Layer tile_layer;
};

struct History_State
{
    History_Action action;

    std::vector<History_Info> info;

    // What layers were active at the time. Used by flips so only those
    // layers end up getting flipped during the undo and redo actions.
    bool tile_layer_active[LEVEL_LAYER_TOTAL];

    // Used by the select box history to know the size and position.
    std::vector<Select_Bounds> old_select_state;
    std::vector<Select_Bounds> new_select_state;

    // Used by the resizing history to restore old/new size.
    Resize_Dir resize_dir;

    int old_width;
    int old_height;

    int new_width;
    int new_height;

    // The data of the level before and after a resize.
    Level_Data old_data;
    Level_Data new_data;
};

struct History
{
    int current_position;
    std::vector<History_State> state;
};

GLOBAL constexpr float DEFAULT_TILE_SIZE      = 16.00f;
GLOBAL constexpr float DEFAULT_TILE_SIZE_HALF = DEFAULT_TILE_SIZE / 2.0f;
GLOBAL constexpr float MIN_EDITOR_ZOOM        = 0.25f;
GLOBAL constexpr float MAX_EDITOR_ZOOM        = 4.00f;
GLOBAL constexpr float EDITOR_ZOOM_INCREMENT  = 0.10f;

struct Level_Camera
{
    float x;
    float y;

    float zoom;
};

struct Level_Tab
{
    History      history;
    std::string  name;
    Level        level;
    Level_Camera camera;
    Tool_Info    tool_info;

    bool unsaved_changes;
    bool can_shrink_border;
    bool cursor_visible;

    bool tile_layer_active[LEVEL_LAYER_TOTAL];

    // We use this for the selection history undo/redo system.
    std::vector<Select_Bounds> old_select_state;
};

struct Level_Editor
{
    std::vector<Level_Tab> tabs;
    size_t current_tab;

    Tool_State tool_state = TOOL_STATE_IDLE;
    Tool_Type  tool_type  = TOOL_TYPE_BRUSH;

    SDL_TimerID backup_timer;
    SDL_TimerID cooldown_timer;

    std::vector<Clipboard> clipboard;

    Vec2 mouse_world;
    Vec2 mouse;
    Vec2 mouse_tile;

    bool is_panning;
    bool grid_visible;
    bool bounds_visible;
    bool layer_transparency;
    bool large_tiles = true;
    bool entity_guides;

    bool mirror_h;
    bool mirror_v;

    Quad bounds;
    Quad viewport;

    // NOTE: See inside open_dialog and save_dialog for info.
    bool dialog_box;
};

GLOBAL Level_Editor level_editor;

FILDEF void init_level_editor (int _argc, char** _argv);
FILDEF void quit_level_editor ();

FILDEF void do_level_editor   ();

FILDEF void handle_level_editor_events ();

FILDEF void update_level_backup_timer ();

FILDEF bool mouse_inside_level_editor_viewport ();

FILDEF void       set_current_level_tab    (size_t _index);
FILDEF Level_Tab& get_current_level_tab    ();
FILDEF Level_Tab& get_level_tab_at_index   (size_t _index);
FILDEF bool       are_there_any_level_tabs ();

FILDEF void new_history_state           (History_Action _action);
FILDEF void add_to_history_normal_state (History_Info _info);
FILDEF void add_to_history_clear_state  (History_Info _info);

FILDEF bool are_all_layers_inactive ();

FILDEF bool are_any_select_boxes_visible ();
FILDEF void get_ordered_select_bounds    (const Select_Bounds& _bounds, int* _l, int* _t, int* _r, int* _b);
FILDEF void get_total_select_boundary    (int* _l, int* _t, int* _r, int *_b);

FILDEF bool le_new                 ();
FILDEF bool le_new_okay            ();
FILDEF bool le_load                ();
FILDEF bool le_save                (Level_Tab& _level);
FILDEF bool le_save_as             ();
FILDEF void le_level_close         (size_t _index);
FILDEF void le_level_close_current ();
FILDEF void le_level_close_all     ();
FILDEF void le_increment_tab       ();
FILDEF void le_decrement_tab       ();
FILDEF void le_clear_select        ();
FILDEF void le_deselect            ();
FILDEF void le_cursor_deselect     ();
FILDEF void le_select_all          ();
FILDEF void le_copy                ();
FILDEF void le_cut                 ();
FILDEF void le_paste               ();

FILDEF void flip_level_h ();
FILDEF void flip_level_v ();

FILDEF void level_has_unsaved_changes ();

FILDEF void undo ();
FILDEF void redo ();

FILDEF void history_begin ();
FILDEF void history_end   ();

FILDEF void le_resize      ();
FILDEF void le_resize_okay ();

FILDEF void le_load_prev_level ();
FILDEF void le_load_next_level ();
