#pragma once

GLOBAL constexpr const char* KEY_BINDINGS_FILE_NAME = "editor_settings.txt";

// The names for all of the key bindings found in the user settings file.
// We store them here so that if we ever want to change any of the names
// then we only have to update them here rather than everywhere they are
// referenced throughout the program's source code -- would be annoying!

GLOBAL constexpr const char* KB_LEVEL_NEW            = "level_new";
GLOBAL constexpr const char* KB_LEVEL_OPEN           = "level_open";
GLOBAL constexpr const char* KB_LEVEL_SAVE           = "level_save";
GLOBAL constexpr const char* KB_LEVEL_SAVE_AS        = "level_save_as";
GLOBAL constexpr const char* KB_LEVEL_CLOSE          = "level_close";
GLOBAL constexpr const char* KB_LEVEL_CLOSE_ALL      = "level_close_all";
GLOBAL constexpr const char* KB_LEVEL_RESIZE         = "level_resize";
GLOBAL constexpr const char* KB_UNDO                 = "undo";
GLOBAL constexpr const char* KB_REDO                 = "redo";
GLOBAL constexpr const char* KB_HISTORY_BEGIN        = "history_begin";
GLOBAL constexpr const char* KB_HISTORY_END          = "history_end";
GLOBAL constexpr const char* KB_CAMERA_ZOOM_OUT      = "camera_zoom_out";
GLOBAL constexpr const char* KB_CAMERA_ZOOM_IN       = "camera_zoom_in";
GLOBAL constexpr const char* KB_RUN_GAME             = "run_game";
GLOBAL constexpr const char* KB_PREFERENCES          = "preferences";
GLOBAL constexpr const char* KB_ABOUT                = "about";
GLOBAL constexpr const char* KB_HELP                 = "help";
GLOBAL constexpr const char* KB_TOOL_BRUSH           = "tool_brush";
GLOBAL constexpr const char* KB_TOOL_FILL            = "tool_fill";
GLOBAL constexpr const char* KB_TOOL_SELECT          = "tool_select";
GLOBAL constexpr const char* KB_FLIP_H               = "flip_h";
GLOBAL constexpr const char* KB_FLIP_V               = "flip_v";
GLOBAL constexpr const char* KB_MIRROR_H_TOGGLE      = "mirror_h_toggle";
GLOBAL constexpr const char* KB_MIRROR_V_TOGGLE      = "mirror_v_toggle";
GLOBAL constexpr const char* KB_GPAK_UNPACK          = "gpak_unpack";
GLOBAL constexpr const char* KB_GPAK_PACK            = "gpak_pack";
GLOBAL constexpr const char* KB_TOGGLE_ENTITY        = "toggle_large_entity";
GLOBAL constexpr const char* KB_TOGGLE_GUIDES        = "toggle_entity_guides";
GLOBAL constexpr const char* KB_GRID_TOGGLE          = "grid_toggle";
GLOBAL constexpr const char* KB_BOUNDS_TOGGLE        = "bounds_toggle";
GLOBAL constexpr const char* KB_LAYERS_TOGGLE        = "layer_trans_toggle";
GLOBAL constexpr const char* KB_CAMERA_RESET         = "camera_reset";
GLOBAL constexpr const char* KB_CLEAR_SELECT         = "clear_select";
GLOBAL constexpr const char* KB_DESELECT             = "deselect";
GLOBAL constexpr const char* KB_SELECT_ALL           = "select_all";
GLOBAL constexpr const char* KB_COPY                 = "copy";
GLOBAL constexpr const char* KB_CUT                  = "cut";
GLOBAL constexpr const char* KB_PASTE                = "paste";
GLOBAL constexpr const char* KB_INCREMENT_TILE       = "increment_tile";
GLOBAL constexpr const char* KB_DECREMENT_TILE       = "decrement_tile";
GLOBAL constexpr const char* KB_INCREMENT_GROUP      = "increment_group";
GLOBAL constexpr const char* KB_DECREMENT_GROUP      = "decrement_group";
GLOBAL constexpr const char* KB_INCREMENT_CATEGORY   = "increment_category";
GLOBAL constexpr const char* KB_DECREMENT_CATEGORY   = "decrement_category";
GLOBAL constexpr const char* KB_TOGGLE_LAYER_ACTIVE  = "toggle_layer_active";
GLOBAL constexpr const char* KB_TOGGLE_LAYER_TAG     = "toggle_layer_tag";
GLOBAL constexpr const char* KB_TOGGLE_LAYER_OVERLAY = "toggle_layer_overlay";
GLOBAL constexpr const char* KB_TOGGLE_LAYER_BACK1   = "toggle_layer_back1";
GLOBAL constexpr const char* KB_TOGGLE_LAYER_BACK2   = "toggle_layer_back2";
GLOBAL constexpr const char* KB_CATEGORY_BASIC       = "category_basic";
GLOBAL constexpr const char* KB_CATEGORY_TAG         = "category_tag";
GLOBAL constexpr const char* KB_CATEGORY_OVERLAY     = "category_overlay";
GLOBAL constexpr const char* KB_CATEGORY_ENTITY      = "category_entity";
GLOBAL constexpr const char* KB_CATEGORY_BACK1       = "category_back1";
GLOBAL constexpr const char* KB_CATEGORY_BACK2       = "category_back2";
GLOBAL constexpr const char* KB_INCREMENT_TAB        = "increment_tab";
GLOBAL constexpr const char* KB_DECREMENT_TAB        = "decrement_tab";
GLOBAL constexpr const char* KB_MOVE_TAB_LEFT        = "move_tab_left";
GLOBAL constexpr const char* KB_MOVE_TAB_RIGHT       = "move_tab_right";
GLOBAL constexpr const char* KB_OPEN_RECENT_TAB      = "open_recent_tab";
GLOBAL constexpr const char* KB_LOAD_PREV_LEVEL      = "load_prev_level";
GLOBAL constexpr const char* KB_LOAD_NEXT_LEVEL      = "load_next_level";
GLOBAL constexpr const char* KB_ADD_LEFT             = "add_left";
GLOBAL constexpr const char* KB_ADD_RIGHT            = "add_right";
GLOBAL constexpr const char* KB_ADD_UP               = "add_up";
GLOBAL constexpr const char* KB_ADD_DOWN             = "add_down";
GLOBAL constexpr const char* KB_CHECK_CONNECTIONS    = "check_connections";
GLOBAL constexpr const char* KB_GEN_LEVEL_INFO       = "generate_level_info";

typedef void(*KB_Action)(void);

struct Key_Binding
{
    KB_Action action;

    bool has_alt;

    int mod;
    int code;

    int alt_mod;
    int alt_code;
};

FILDEF bool operator== (const Key_Binding& _a, const Key_Binding& _b);
FILDEF bool operator!= (const Key_Binding& _a, const Key_Binding& _b);

GLOBAL std::map<std::string, Key_Binding> key_bindings;

FILDEF bool load_editor_key_bindings    ();
FILDEF void restore_editor_key_bindings ();
FILDEF void handle_key_binding_events   ();

FILDEF const Key_Binding& get_key_binding (const char* _name);

FILDEF bool is_key_binding_active   (const char* _name);
FILDEF bool is_key_mod_state_active (int _mod);
FILDEF bool is_key_code_active      (int _code);

FILDEF std::string get_key_binding_main_string (const Key_Binding& _kb);
FILDEF std::string get_key_binding_main_string (const char* _name);

FILDEF std::string get_key_binding_alt_string  (const Key_Binding& _kb);
FILDEF std::string get_key_binding_alt_string  (const char* _name);
