#pragma once

GLOBAL constexpr float MAP_NODE_W = 88.0f;
GLOBAL constexpr float MAP_NODE_H = 22.0f;

struct Map_History
{
    int current_position;
    std::vector<Map> state;
};

struct Map_Select
{
    Vec2i a; // Start
    Vec2i b; // End
};

typedef std::vector<Map_Node> Map_Clipboard;

struct Map_Node_Info
{
    std::string cached_lvl_text;

    Vec2i     pressed_node_pos;
    Vec2i     active_pos;
    Map_Node* active;

    size_t cursor;
    size_t select; // Start point of text selection.
    bool   selecting;
};

struct Map_Editor
{
    struct Color_Map_Compare
    {
        inline bool operator() (const Vec4& _lhs, const Vec4& _rhs) const
        {
            return ((_lhs.x+_lhs.y+_lhs.z+_lhs.w) < (_rhs.x+_rhs.y+_rhs.z+_rhs.w));
        }
    };

    Map_Clipboard clipboard;

    Vec2 mouse_world;
    Vec2 mouse;
    Vec2 mouse_tile;

    bool pressed;
    bool left_pressed;

    SDL_TimerID cursor_blink_timer;
    bool        cursor_visible;

    Quad bounds;
    Quad viewport;

    std::map<Vec4,Vec4, Color_Map_Compare> text_color_map;
};

GLOBAL Map_Editor map_editor;

FILDEF void init_map_editor ();
FILDEF void do_map_editor   ();

FILDEF void handle_map_editor_events ();

FILDEF void load_map_tab    (std::string _file_name);
FILDEF bool save_map_tab    (Tab& _tab);
FILDEF void save_map_tab_as ();
FILDEF void map_drop_file   (Tab* _tab, std::string _file_name);
FILDEF void backup_map_tab  (const Tab& _tab, const std::string& _file_name);

FILDEF bool is_current_map_empty ();

FILDEF float get_min_map_bounds_x ();
FILDEF float get_min_map_bounds_y ();
FILDEF float get_max_map_bounds_x ();
FILDEF float get_max_map_bounds_y ();

FILDEF void me_cut          ();
FILDEF void me_copy         ();
FILDEF void me_paste        ();
FILDEF void me_deselect     ();
FILDEF void me_clear_select ();
FILDEF void me_select_all   ();

FILDEF void me_undo ();
FILDEF void me_redo ();

FILDEF void me_history_begin ();
FILDEF void me_history_end   ();

FILDEF void new_map_history_state (Map& _map);

FILDEF bool map_select_box_present ();
FILDEF void get_map_select_bounds (int* _l, int* _t, int* _r, int* _b);

FILDEF void me_check_connections   ();
FILDEF void me_generate_level_info ();

FILDEF void me_add_left  ();
FILDEF void me_add_right ();
FILDEF void me_add_up    ();
FILDEF void me_add_down  ();
