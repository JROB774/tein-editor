// Fallback copy of the key bindings file we can load in the case that the
// key bindings file is not present and then we just use these defaults.

GLOBAL constexpr const char* KEY_BINDINGS_FALLBACK =
"level_new { main [\"Ctrl\" \"N\"] }\n"
"level_open { main [\"Ctrl\" \"O\"] }\n"
"level_save  { main [\"Ctrl\" \"S\"] }\n"
"level_save_as { main [\"Ctrl\" \"Shift\" \"S\"] }\n"
"level_close { main [\"Ctrl\" \"W\"] }\n"
"level_close_all { main [\"Ctrl\" \"Alt\" \"W\"] }\n"
"level_resize { main [\"Ctrl\" \"R\"] }\n"
"undo { main [\"Ctrl\" \"Z\"] }\n"
"redo { main [\"Ctrl\" \"Y\"] }\n"
"history_begin { main [\"Ctrl\" \"Shift\" \"Z\"] }\n"
"history_end { main [\"Ctrl\" \"Shift\" \"Y\"] }\n"
"camera_zoom_out { main [\"Ctrl\" \"-\"] }\n"
"camera_zoom_in { main [\"Ctrl\" \"=\"] }\n"
"run_game { main [\"F5\"] }\n"
"preferences { main [\"F2\"] }\n"
"about { main [\"F3\"] }\n"
"help { main [\"F1\"] }\n"
"tool_brush { main [\"B\"] }\n"
"tool_fill { main [\"F\"] }\n"
"tool_select { main [\"S\"] }\n"
"flip_h { main [\"J\"] }\n"
"flip_v { main [\"K\"] }\n"
"mirror_h_toggle { main [\"N\"] }\n"
"mirror_v_toggle { main [\"M\"] }\n"
"gpak_unpack { main [\"Ctrl\" \"U\"] }\n"
"gpak_pack { main [\"Ctrl\" \"P\"] }\n"
"toggle_large_entity { main [\"Ctrl\" \"L\"] }\n"
"toggle_entity_guides { main [\"Ctrl\" \"G\"] }\n"
"grid_toggle { main [\"G\"] }\n"
"bounds_toggle { main [\"C\"] }\n"
"layer_trans_toggle { main [\"L\"] }\n"
"camera_reset { main [\"Ctrl\" \"0\"] }\n"
"clear_select { main [\"Delete\"] }\n"
"deselect { main [\"Ctrl\" \"D\"] }\n"
"select_all { main [\"Ctrl\" \"A\"] }\n"
"copy { main [\"Ctrl\" \"C\"] }\n"
"cut { main [\"Ctrl\" \"X\"] }\n"
"paste { main [\"Ctrl\" \"V\"] }\n"
"increment_tile { main [\"E\"] }\n"
"decrement_tile { main [\"Q\"] }\n"
"increment_group { main [\"Alt\" \"E\"] }\n"
"decrement_group { main [\"Alt\" \"Q\"] }\n"
"increment_category { main [\"Alt\" \"Shift\" \"E\"] }\n"
"decrement_category { main [\"Alt\" \"Shift\" \"Q\"] }\n"
"toggle_layer_active { main [\"Ctrl\" \"1\"] alt [\"Ctrl\" \"4\"] }\n"
"toggle_layer_tag { main [\"Ctrl\" \"2\"] }\n"
"toggle_layer_overlay { main [\"Ctrl\" \"3\"] }\n"
"toggle_layer_back1 { main [\"Ctrl\" \"5\"] }\n"
"toggle_layer_back2 { main [\"Ctrl\" \"6\"] }\n"
"category_basic { main [\"1\"] }\n"
"category_tag { main [\"2\"] }\n"
"category_overlay { main [\"3\"] }\n"
"category_entity { main [\"4\"] }\n"
"category_back1 { main [\"5\"] }\n"
"category_back2 { main [\"6\"] }\n"
"increment_tab { main [\"Ctrl\" \"Tab\"] }\n"
"decrement_tab { main [\"Ctrl\" \"Shift\" \"Tab\"] }\n"
"move_tab_left { main [\"Left\"] }\n"
"move_tab_right { main [\"Right\"] }\n"
"open_recent_tab { main [\"Ctrl\" \"Shift\" \"T\"] }\n"
"load_prev_level { main [\"Ctrl\" \"Left\"] }\n"
"load_next_level { main [\"Ctrl\" \"Right\"] }\n"
"add_left { main [\"Ctrl\" \"Left\"] }\n"
"add_right { main [\"Ctrl\" \"Right\"] }\n"
"add_up { main [\"Ctrl\" \"Up\"] }\n"
"add_down { main [\"Ctrl\" \"Down\"] }\n"
"check_connections { main [\"Ctrl\" \"Shift\" \"S\"] }\n"
"generate_level_info { main [\"Ctrl\" \"Shift\" \"I\"] }\n";

typedef std::pair<std::string, Key_Binding> KB_Pair;

GLOBAL const std::map<std::string, int> KEY_MOD_MAP
{
{ "None",  0          },
{ "Ctrl",  KMOD_CTRL  },
{ "Alt",   KMOD_ALT   },
{ "AltGr", KMOD_MODE  },
{ "Shift", KMOD_SHIFT },
{ "Gui",   KMOD_GUI   }
};

#define internal__load_editor_key_bindings(_gon1, _gon2)                                       \
key_bindings.clear();                                                                          \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_NEW,            hb_new);                      \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_OPEN,           hb_load);                     \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_SAVE,           hb_save);                     \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_SAVE_AS,        hb_save_as);                  \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_CLOSE,          close_current_tab);           \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_CLOSE_ALL,      close_all_tabs);              \
internal__add_key_binding(_gon1, _gon2, KB_LEVEL_RESIZE,         le_resize);                   \
internal__add_key_binding(_gon1, _gon2, KB_UNDO,                 hb_undo_action);              \
internal__add_key_binding(_gon1, _gon2, KB_REDO,                 hb_redo_action);              \
internal__add_key_binding(_gon1, _gon2, KB_HISTORY_BEGIN,        hb_history_begin);            \
internal__add_key_binding(_gon1, _gon2, KB_HISTORY_END,          hb_history_end);              \
internal__add_key_binding(_gon1, _gon2, KB_CAMERA_ZOOM_OUT,      hb_zoom_out);                 \
internal__add_key_binding(_gon1, _gon2, KB_CAMERA_ZOOM_IN,       hb_zoom_in);                  \
internal__add_key_binding(_gon1, _gon2, KB_RUN_GAME,             hb_run_game);                 \
internal__add_key_binding(_gon1, _gon2, KB_PREFERENCES,          hb_preferences);              \
internal__add_key_binding(_gon1, _gon2, KB_ABOUT,                hb_about);                    \
internal__add_key_binding(_gon1, _gon2, KB_HELP,                 hb_help);                     \
internal__add_key_binding(_gon1, _gon2, KB_TOOL_BRUSH,           tb_set_tool_to_brush);        \
internal__add_key_binding(_gon1, _gon2, KB_TOOL_FILL,            tb_set_tool_to_fill);         \
internal__add_key_binding(_gon1, _gon2, KB_TOOL_SELECT,          tb_set_tool_to_select);       \
internal__add_key_binding(_gon1, _gon2, KB_FLIP_H,               tb_flip_level_h);             \
internal__add_key_binding(_gon1, _gon2, KB_FLIP_V,               tb_flip_level_v);             \
internal__add_key_binding(_gon1, _gon2, KB_MIRROR_H_TOGGLE,      tb_toggle_mirror_h);          \
internal__add_key_binding(_gon1, _gon2, KB_MIRROR_V_TOGGLE,      tb_toggle_mirror_v);          \
internal__add_key_binding(_gon1, _gon2, KB_GPAK_UNPACK,          hb_gpak_unpack);              \
internal__add_key_binding(_gon1, _gon2, KB_GPAK_PACK,            hb_gpak_pack);                \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_ENTITY,        tb_toggle_entity);            \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_GUIDES,        tb_toggle_guides);            \
internal__add_key_binding(_gon1, _gon2, KB_GRID_TOGGLE,          tb_toggle_grid);              \
internal__add_key_binding(_gon1, _gon2, KB_BOUNDS_TOGGLE,        tb_toggle_bounds);            \
internal__add_key_binding(_gon1, _gon2, KB_LAYERS_TOGGLE,        tb_toggle_layer_trans);       \
internal__add_key_binding(_gon1, _gon2, KB_CAMERA_RESET,         tb_reset_camera);             \
internal__add_key_binding(_gon1, _gon2, KB_CLEAR_SELECT,         tb_clear_select);             \
internal__add_key_binding(_gon1, _gon2, KB_DESELECT,             tb_deselect);                 \
internal__add_key_binding(_gon1, _gon2, KB_SELECT_ALL,           editor_select_all);           \
internal__add_key_binding(_gon1, _gon2, KB_COPY,                 tb_copy);                     \
internal__add_key_binding(_gon1, _gon2, KB_CUT,                  tb_cut);                      \
internal__add_key_binding(_gon1, _gon2, KB_PASTE,                editor_paste);                \
internal__add_key_binding(_gon1, _gon2, KB_INCREMENT_TILE,       increment_selected_tile);     \
internal__add_key_binding(_gon1, _gon2, KB_DECREMENT_TILE,       decrement_selected_tile);     \
internal__add_key_binding(_gon1, _gon2, KB_INCREMENT_GROUP,      increment_selected_group);    \
internal__add_key_binding(_gon1, _gon2, KB_DECREMENT_GROUP,      decrement_selected_group);    \
internal__add_key_binding(_gon1, _gon2, KB_INCREMENT_CATEGORY,   increment_selected_category); \
internal__add_key_binding(_gon1, _gon2, KB_DECREMENT_CATEGORY,   decrement_selected_category); \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_LAYER_ACTIVE,  toggle_layer_active);         \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_LAYER_TAG,     toggle_layer_tag);            \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_LAYER_OVERLAY, toggle_layer_overlay);        \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_LAYER_BACK1,   toggle_layer_back1);          \
internal__add_key_binding(_gon1, _gon2, KB_TOGGLE_LAYER_BACK2,   toggle_layer_back2);          \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_BASIC,       jump_to_category_basic);      \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_TAG,         jump_to_category_tag);        \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_OVERLAY,     jump_to_category_overlay);    \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_ENTITY,      jump_to_category_entity);     \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_BACK1,       jump_to_category_back1);      \
internal__add_key_binding(_gon1, _gon2, KB_CATEGORY_BACK2,       jump_to_category_back2);      \
internal__add_key_binding(_gon1, _gon2, KB_INCREMENT_TAB,        increment_tab);               \
internal__add_key_binding(_gon1, _gon2, KB_DECREMENT_TAB,        decrement_tab);               \
internal__add_key_binding(_gon1, _gon2, KB_OPEN_RECENT_TAB,      open_recently_closed_tab);    \
internal__add_key_binding(_gon1, _gon2, KB_MOVE_TAB_LEFT,        move_tab_left);               \
internal__add_key_binding(_gon1, _gon2, KB_MOVE_TAB_RIGHT,       move_tab_right);              \
internal__add_key_binding(_gon1, _gon2, KB_LOAD_PREV_LEVEL,      le_load_prev_level);          \
internal__add_key_binding(_gon1, _gon2, KB_LOAD_NEXT_LEVEL,      le_load_next_level);          \
internal__add_key_binding(_gon1, _gon2, KB_ADD_LEFT,             tb_add_left);                 \
internal__add_key_binding(_gon1, _gon2, KB_ADD_RIGHT,            tb_add_right);                \
internal__add_key_binding(_gon1, _gon2, KB_ADD_UP,               tb_add_up);                   \
internal__add_key_binding(_gon1, _gon2, KB_ADD_DOWN,             tb_add_down);                 \
internal__add_key_binding(_gon1, _gon2, KB_CHECK_CONNECTIONS,    tb_check_connections);        \
internal__add_key_binding(_gon1, _gon2, KB_GEN_LEVEL_INFO,       tb_gen_level_info);

FILDEF bool internal__key_binding_code_active (int _code)
{
    int key_count; // So we know the length of the returned array.
    const u8* key_state = SDL_GetKeyboardState(&key_count);

    // Need to convert the keycode to a scancode for this.
    SDL_Scancode scan = SDL_GetScancodeFromKey(CAST(SDL_Keycode, _code));
    return (scan < key_count) ? key_state[scan] : false;
}

FILDEF void internal__add_key_binding (const GonObject& _gon, const GonObject& _gon_fallback, const char* _name, KB_Action _action)
{
    // Assign both to zero in case there are no values.
    int code = 0, alt_code = 0;
    int mod = 0, alt_mod = 0;

    // Make sure the key binding actually exists.
    bool gon_contains = _gon.Contains(_name);
    if (!gon_contains && !_gon_fallback.Contains(_name)) {
        LOG_ERROR(ERR_MIN, "No key binding for '%s'!", _name);
        return;
    }

    // Go through each component of the key binding.
    const GonObject& key_binding = (gon_contains) ? _gon[_name] : _gon_fallback[_name];
    if (key_binding.Contains("main")) {
        const GonObject& kb_main = key_binding["main"];
        for (int i=0; i<kb_main.size(); ++i) {
            // Convert the key mode and code names into actual values.
            std::string name = kb_main[i].String();
            SDL_Keycode key_code = SDL_GetKeyFromName(name.c_str());

            if (key_code != SDLK_UNKNOWN) { code = CAST(int, key_code); }
            else {
                if (KEY_MOD_MAP.count(name)) {
                    mod |= KEY_MOD_MAP.at(name);
                } else {
                    LOG_ERROR(ERR_MED, "Invalid key mod '%s'!", name.c_str());
                    return;
                }
            }
        }
    }

    bool has_alt = key_binding.Contains("alt");
    if (has_alt) {
        const GonObject& kb_alt = key_binding["alt"];
        for (int i=0; i<kb_alt.size(); ++i) {
            // Convert the key mode and code names into actual values.
            std::string name = kb_alt[i].String();
            SDL_Keycode key_code = SDL_GetKeyFromName(name.c_str());

            if (key_code != SDLK_UNKNOWN) { alt_code = CAST(int, key_code); }
            else {
                if (KEY_MOD_MAP.count(name)) {
                    alt_mod |= KEY_MOD_MAP.at(name);
                } else {
                    LOG_ERROR(ERR_MED, "Invalid key mod '%s'!", name.c_str());
                    return;
                }
            }
        }
    }

    // If neither are set then input was malformed or empty.
    if (!code && !mod) {
        LOG_ERROR(ERR_MED, "Invalid key binding '%s'!", _name);
        return;
    }

    // Check that a key binding with the name doesn't already exist.
    if (key_bindings.count(_name) > 0) {
        LOG_ERROR(ERR_MED, "Duplicate key binding '%s'!", _name);
        return;
    }

    key_bindings.insert(KB_Pair(_name, { _action, has_alt, mod, code, alt_mod, alt_code }));
}

FILDEF bool internal__key_binding_active (const Key_Binding& _kb)
{
    // Not all key bindings necessarily have a key code so we assign a
    // default value of true. However, key mods should always be checked
    // even if they are not present. Otherwise issues can occur where
    // key bindings get checked as active even when they shouldn't be.
    bool code_active = true, alt_code_active = true;
    bool mod_active = false, alt_mod_active = false;

    if (_kb.code) { code_active = internal__key_binding_code_active(_kb.code); }
    mod_active = is_key_mod_state_active(_kb.mod);

    if (_kb.has_alt) {
        if (_kb.alt_code) { alt_code_active = internal__key_binding_code_active(_kb.alt_code); }
        alt_mod_active = is_key_mod_state_active(_kb.alt_mod);
    }

    return (code_active && mod_active) || (_kb.has_alt && (alt_code_active && alt_mod_active));
}

FILDEF std::string internal__get_key_binding_string (int _code, int _mod)
{
    std::string str;
    if (_mod) {
        if (_mod & KMOD_CTRL ) { str += "Ctrl ";  }
        if (_mod & KMOD_ALT  ) { str += "Alt ";   }
        if (_mod & KMOD_MODE ) { str += "AltGr "; }
        if (_mod & KMOD_SHIFT) { str += "Shift "; }
        if (_mod & KMOD_GUI  ) { str += "Gui ";   }
    }

    str += SDL_GetKeyName(_code);

    // Trim trailing whitespace from the key binding name.
    size_t pos = str.find_last_not_of(" ");
    if (pos != std::string::npos) { str.erase(pos+1); }

    return str;
}

FILDEF bool operator== (const Key_Binding& _a, const Key_Binding& _b)
{
    return ((_a.action == _b.action) && (_a.code == _b.code) && (_a.mod == _b.mod) && (_a.alt_code == _b.alt_code) && (_a.alt_mod == _b.alt_mod));
}
FILDEF bool operator!= (const Key_Binding& _a, const Key_Binding& _b)
{
    return !(_a == _b);
}

FILDEF bool load_editor_key_bindings ()
{
    GonObject gon;
    try {
        std::string file_name = make_path_absolute(KEY_BINDINGS_FILE_NAME);
        gon = GonObject::Load(file_name);
    } catch (const char* _msg) {
        LOG_ERROR(ERR_MED, "%s", _msg);

        // If we already have key bind data then we just inform the user that the operation
        // failed. Otherwise, we just fallback to using the default application key binds.
        if (!key_bindings.empty()) {
            LOG_ERROR(ERR_MED, "Failed to reload key bindings data!");
            return false;
        } else {
            gon = GonObject::LoadFromBuffer(KEY_BINDINGS_FALLBACK);
        }
    }

    // If we reach this point and there are no key binds then we just use the defaults.
    // This could be the case if the key binds failed to load or haven't been modified.
    if (gon.type != GonObject::g_object) {
        gon = GonObject::LoadFromBuffer(KEY_BINDINGS_FALLBACK);
    }

    GonObject gon_fallback = GonObject::LoadFromBuffer(KEY_BINDINGS_FALLBACK);
    internal__load_editor_key_bindings(gon, gon_fallback)

    LOG_DEBUG("Loaded Editor Key Bindings");
    return true;
}

FILDEF void restore_editor_key_bindings ()
{
    // Load the fallback/default editor key bindings so they can be restored.
    GonObject gon = GonObject::LoadFromBuffer(KEY_BINDINGS_FALLBACK);
    internal__load_editor_key_bindings(gon, gon);
}

FILDEF void handle_key_binding_events ()
{
    if (text_box_is_active()) { return; }
    if (!is_window_focused("WINMAIN")) { return; }

    // We only care about key press events, anything else is ignored.
    if (main_event.type != SDL_KEYDOWN) { return; }

    for (auto it: key_bindings) {
        // Check that the appropriate keys and mods are pressed.
        const Key_Binding& kb = it.second;
        if (internal__key_binding_active(kb)) {
            // Do not attempt to call a NULL value!
            if (kb.action) { kb.action(); }
        }
    }
}

FILDEF const Key_Binding& get_key_binding (const char* _name)
{
    return key_bindings[_name];
}

INLDEF bool is_key_binding_active (const char* _name)
{
    if (text_box_is_active()) { return false; }
    if (!is_window_focused("WINMAIN")) { return false; }

    // If the key binding doesn't exist then it can't be active.
    if (!key_bindings.count(_name)) {
        LOG_ERROR(ERR_MIN, "No key binding with name '%s'!", _name);
        return false;
    }

    return internal__key_binding_active(key_bindings.at(_name));
}

FILDEF bool is_key_mod_state_active (int _mod)
{
    if (text_box_is_active()) { return false; }
    if (!is_window_focused("WINMAIN")) { return false; }

    // Remove CAPSLOCK and NUMLOCK because we don't care about them at all.
    int mod = CAST(int, (SDL_GetModState() & ~(KMOD_NUM|KMOD_CAPS)));

    // We do not care whether the right or left variants have been pressed.
    if (mod&KMOD_LCTRL  || mod&KMOD_RCTRL)  { mod |= KMOD_CTRL;  }
    if (mod&KMOD_LALT   || mod&KMOD_RALT)   { mod |= KMOD_ALT;   }
    if (mod&KMOD_LSHIFT || mod&KMOD_RSHIFT) { mod |= KMOD_SHIFT; }
    if (mod&KMOD_LGUI   || mod&KMOD_RGUI)   { mod |= KMOD_GUI;   }

    return (mod == _mod);
}

FILDEF bool is_key_code_active (int _code)
{
    return internal__key_binding_code_active(_code);
}

FILDEF std::string get_key_binding_main_string (const Key_Binding& _kb)
{
    return internal__get_key_binding_string(_kb.code, _kb.mod);
}

FILDEF std::string get_key_binding_main_string (const char* _name)
{
    return get_key_binding_main_string(get_key_binding(_name));
}

FILDEF std::string get_key_binding_alt_string (const Key_Binding& _kb)
{
    // There is not alternative key binding for this particular key.
    if (!_kb.alt_code && !_kb.alt_mod) { return std::string(); }
    return internal__get_key_binding_string(_kb.alt_code, _kb.alt_mod);
}

FILDEF std::string get_key_binding_alt_string (const char* _name)
{
    return get_key_binding_alt_string(get_key_binding(_name));
}
