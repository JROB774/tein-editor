GLOBAL constexpr const char* TILE_DATA_FILE = "data/editor_tiles.txt";
GLOBAL constexpr const char* FLIP_DATA_FILE = "data/editor_flips.txt";

GLOBAL constexpr float TILE_PANEL_ITEM_PAD   =  4.0f;
GLOBAL constexpr float TILE_PANEL_ITEM_SIZE  = 20.0f;
GLOBAL constexpr float TILE_PANEL_COLUMNS    = 11.0f;
GLOBAL constexpr float TILE_PANEL_INNER_PAD  =  3.0f;
GLOBAL constexpr float TILE_PANEL_LABEL_H    = 20.0f;
GLOBAL constexpr float TILE_PANEL_INACTIVE_A = 0.33f;

typedef std::pair<Tile_ID, Tile_ID> Tile_Flip_Map;

struct Tile_Group
{
    std::string              name;
    std::string              desc;
    std::vector<Tile_ID>     tile;
    int            selected_index;
};

namespace Tile_Panel
{
    GLOBAL std::vector<Tile_Flip_Map> flip_map_horz;
    GLOBAL std::vector<Tile_Flip_Map> flip_map_vert;

    GLOBAL std::map<Tile_Category, std::vector<Tile_Group>> category;

    GLOBAL Quad bounds;

    GLOBAL int selected_category;
    GLOBAL int selected_group;

    GLOBAL bool mouse_down;

    GLOBAL float content_height;
    GLOBAL float scroll_offset;
}

FILDEF bool internal__is_category_active (Tile_Category _category)
{
    if (!current_tab_is_level()) { return false; }
    const Tab& tab = get_current_tab();

    return tab.tile_layer_active[category_to_layer(_category)];
}

FILDEF float internal__do_tile_panel_category (Vec2& _cursor, Tile_Category _category_index, std::vector<Tile_Group>& _category)
{
    using namespace Tile_Panel;

    // Determine how many rows of entities are present in the category.
    float items = CAST(float, _category.size());
    float rows = ceilf(items / TILE_PANEL_COLUMNS);

    float total_item_pad = (rows - 1.0f) * TILE_PANEL_ITEM_PAD;
    float category_pad = TILE_PANEL_INNER_PAD * 2.0f;

    // Do a separate panel for the category's label before the main panel.
    float x = TILE_PANEL_INNER_PAD;
    float y = _cursor.y;
    float w = (CONTROL_PANEL_WIDTH - category_pad);
    float h = TILE_PANEL_LABEL_H;

    bool is_active = internal__is_category_active(_category_index);

    Vec2 label_cur = { 0.0f, 0.0f };
    begin_panel(x, y, w, h, (is_active) ? UI_NONE : UI_INACTIVE);

    set_panel_cursor(&label_cur);
    set_panel_cursor_dir(UI_DIR_DOWN);

    const char* label_name = NULL;
    switch (_category_index) {
    case (TILE_CATEGORY_BASIC  ): { label_name = "Basic";   } break;
    case (TILE_CATEGORY_TAG    ): { label_name = "Tag";     } break;
    case (TILE_CATEGORY_OVERLAY): { label_name = "Overlay"; } break;
    case (TILE_CATEGORY_ENTITY ): { label_name = "Entity";  } break;
    case (TILE_CATEGORY_BACK1  ): { label_name = "Back 1";  } break;
    case (TILE_CATEGORY_BACK2  ): { label_name = "Back 2";  } break;
    }

    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, w, TILE_PANEL_LABEL_H, label_name);
    end_panel();

    _cursor.y += TILE_PANEL_LABEL_H;

    // Bounding box for the particular category in the panel.
    x = TILE_PANEL_INNER_PAD;
    y = _cursor.y;
    w = (CONTROL_PANEL_WIDTH - category_pad);
    h = (rows * TILE_PANEL_ITEM_SIZE) + category_pad + total_item_pad;

    Vec2 cur = { TILE_PANEL_INNER_PAD, TILE_PANEL_INNER_PAD };
    begin_panel(x, y, w, h, UI_NONE, ui_color_med_dark);

    set_draw_color(ui_color_ex_dark); // The outline/border for the category.
    draw_quad(0.0f, get_panel_offset().y, w, get_panel_offset().y+h);

    Texture_Atlas& atlas = get_editor_atlas_small();

    set_tile_texture(atlas.texture);
    set_tile_color((is_active) ? Vec4{1,1,1,1} : Vec4{1,1,1,TILE_PANEL_INACTIVE_A});

    for (size_t i=0; i<_category.size(); ++i) {
        Vec2 tile_cursor = cur;
        tile_cursor.y += get_panel_offset().y;

        const Tile_Group& tile_group = _category[i];
        Quad tile_group_bounds = { tile_cursor.x, tile_cursor.y, TILE_PANEL_ITEM_SIZE, TILE_PANEL_ITEM_SIZE };

        if (is_active) {
            bool in_bounds = mouse_in_ui_bounds_xywh(tile_group_bounds);
            if (in_bounds) {
                push_status_bar_message("Tile Group: %s", tile_group.name.c_str());
                set_current_tooltip(tile_group.name, tile_group.desc);
            }
            if (mouse_down && !is_there_a_hit_ui_element()) {
                if (in_bounds) {
                    selected_category = _category_index;
                    selected_group = CAST(int, i);
                }
            }
        }

        if (current_tab_is_level() && !are_all_layers_inactive()) {
            float qx = tile_cursor.x        - 1.0f;
            float qy = tile_cursor.y        - 1.0f;
            float qw = TILE_PANEL_ITEM_SIZE + 2.0f;
            float qh = TILE_PANEL_ITEM_SIZE + 2.0f;

            // If we are the currently selected group then we draw the highlight.
            if ((_category_index == CAST(Tile_Category, selected_category)) && (CAST(int, i) == selected_group)) {
                set_draw_color(ui_color_light);
                fill_quad(qx, qy, qx+qw, qy+qh);
            }
        }

        // We scissor the contents to avoid overspill.
        begin_scissor(tile_cursor.x, tile_cursor.y, TILE_PANEL_ITEM_SIZE, TILE_PANEL_ITEM_SIZE);

        float ex = tile_cursor.x + (TILE_PANEL_ITEM_SIZE/2.0f);
        float ey = tile_cursor.y + (TILE_PANEL_ITEM_SIZE/2.0f);

        Tile_ID selected_id = tile_group.tile[tile_group.selected_index];
        draw_tile(ex, ey, &get_atlas_clip(atlas, selected_id));

        end_scissor();

        // Advance the cursor for the next entity's placement.
        float advance = TILE_PANEL_ITEM_SIZE + TILE_PANEL_ITEM_PAD;
        cur.x += advance;
        if (cur.x + TILE_PANEL_ITEM_SIZE > w) {
            cur.x = TILE_PANEL_INNER_PAD;
            cur.y += advance;
        }
    }

    flush_tile_draw();

    end_panel();

    // Set the cursor for the next category (if there is one).
    _cursor.x  = TILE_PANEL_INNER_PAD;
    _cursor.y += h;

    // Return the category height for use with the scrollbar.
    return h;
}

FILDEF void internal__load_flip_data (const GonObject& _data, std::vector<Tile_Flip_Map>& _flip)
{
    for (int i=0; i<CAST(int, _data.children_array.size()); ++i) {
        Tile_ID a = CAST(Tile_ID, _data[i][0].Int());
        Tile_ID b = CAST(Tile_ID, _data[i][1].Int());

        _flip.push_back(Tile_Flip_Map(a, b));
    }
}

FILDEF float internal__calculate_tile_panel_height ()
{
    using namespace Tile_Panel;

    float height = TILE_PANEL_INNER_PAD;
    for (auto& it: category) {
        const std::vector<Tile_Group>& c = it.second;

        float items          = CAST(float, c.size());
        float rows           = ceilf(items / TILE_PANEL_COLUMNS);
        float total_item_pad = (rows - 1.0f) * TILE_PANEL_ITEM_PAD;
        float category_pad   = (TILE_PANEL_INNER_PAD * 2.0f);

        height += (rows * TILE_PANEL_ITEM_SIZE) + category_pad + total_item_pad;
        height += TILE_PANEL_LABEL_H;
    }
    return height;
}

FILDEF void internal__set_category_as_active (Tile_Category _category)
{
    using namespace Tile_Panel;

    int old_selected_category = selected_category;
    int old_selected_group = selected_group;

    selected_category = _category;
    selected_group = 0;

    // Make sure we are actually jumping to an active category.
    if (!internal__is_category_active(CAST(Tile_Category, selected_category))) {
        select_next_active_group();
    }

    if (old_selected_category != selected_category || old_selected_group != selected_group) {
        // When the selected gets changed then we make a new state.
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void internal__jump_to_category (Tile_Category _category)
{
    if (!current_tab_is_level())       { return; }
    if ( are_all_layers_inactive())    { return; }
    if (!is_window_focused("WINMAIN")) { return; }

    internal__set_category_as_active(_category);
}

FILDEF bool init_tile_panel ()
{
    using namespace Tile_Panel;

    flip_map_horz.clear();
    flip_map_vert.clear();

    category.clear();

    try {
        // Load all of the tile groups and sort them into their categories.
        GonObject tile_gon_data = GonObject::LoadFromBuffer(load_string_resource(TILE_DATA_FILE))["tiles"];

        for (auto& it: tile_gon_data.children_map) {
            const GonObject& category_data = tile_gon_data.children_array[it.second];
            if (std::stoi(it.first) < TILE_CATEGORY_TOTAL) {
                Tile_Category category_id = CAST(Tile_Category, std::stoi(it.first));
                for (auto& tile_group_gon_data: category_data.children_array) {
                    Tile_Group group;
                    group.selected_index = 0;
                    group.name = tile_group_gon_data["name"].String();
                    group.desc = tile_group_gon_data["tooltip"].String();
                    for (int i=0; i<CAST(int, tile_group_gon_data["id"].size()); ++i) {
                        Tile_ID tile_id = CAST(Tile_ID, tile_group_gon_data["id"][i].Int());
                        group.tile.push_back(tile_id);
                    }
                    category[category_id].push_back(group);
                }
            }
        }

        // Load flip mappings between the tile IDs for smart level flipping.
        GonObject flip_gon_data = GonObject::LoadFromBuffer(load_string_resource(FLIP_DATA_FILE))["flip"];

        internal__load_flip_data(flip_gon_data["horz"], flip_map_horz);
        internal__load_flip_data(flip_gon_data["vert"], flip_map_vert);
    } catch (const char* _msg) {
        LOG_ERROR(ERR_MED, "%s", _msg);
        return false;
    }

    // The starting selected is always the first entry in the first category.
    selected_category = TILE_CATEGORY_BASIC;
    selected_group = 0;

    // We need to calculate the height of all the tiles panel content so that
    // we can use this height value during the panel do_scrollbar operation.
    content_height = internal__calculate_tile_panel_height();
    scroll_offset = 0.0f;

    return true;
}

FILDEF void do_tile_panel (bool _scrollbar)
{
    using namespace Tile_Panel;

    // begin_debug_timer("do_tile_panel");
    // defer { end_debug_timer(); };

    set_ui_font(&get_editor_font());

    Vec2 cursor = { TILE_PANEL_INNER_PAD, 0.0f };
    bounds = { 0.0f, 0.0f, get_panel_w(), get_panel_h() };
    if (is_layer_panel_present()) {
        bounds.h = roundf(bounds.h - get_layer_panel_height());
    }

    begin_panel(bounds, UI_NONE, ui_color_medium);

    if (_scrollbar) {
        Quad sb = { CONTROL_PANEL_WIDTH, CONTROL_PANEL_INNER_PAD, (CONTROL_PANEL_SCROLLBAR_WIDTH - CONTROL_PANEL_INNER_PAD), (get_viewport().h - (CONTROL_PANEL_INNER_PAD * 2.0f)) };
        do_scrollbar(sb, content_height, scroll_offset);
    }

    for (auto& it: category) { internal__do_tile_panel_category(cursor, it.first, it.second); }

    end_panel();
}

FILDEF bool tile_panel_needs_scrollbar ()
{
    return (Tile_Panel::content_height > Tile_Panel::bounds.h);
}

FILDEF void handle_tile_panel_events ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level())       { return; }
    if ( are_all_layers_inactive())    { return; }
    if (!is_window_focused("WINMAIN")) { return; }

    switch (main_event.type) {
    case (SDL_MOUSEBUTTONDOWN):
    case (SDL_MOUSEBUTTONUP): {
        if (main_event.button.button == SDL_BUTTON_LEFT) {
            mouse_down = (main_event.button.state == SDL_PRESSED);
        }
    } break;
    case (SDL_MOUSEWHEEL): {
        if        (is_key_mod_state_active(0)) {
            if      (main_event.wheel.y > 0) { increment_selected_tile();     }
            else if (main_event.wheel.y < 0) { decrement_selected_tile();     }
        } else if (is_key_mod_state_active(KMOD_ALT)) {
            if      (main_event.wheel.y > 0) { increment_selected_group();    }
            else if (main_event.wheel.y < 0) { decrement_selected_group();    }
        } else if (is_key_mod_state_active(KMOD_ALT|KMOD_SHIFT)) {
            if      (main_event.wheel.y > 0) { increment_selected_category(); }
            else if (main_event.wheel.y < 0) { decrement_selected_category(); }
        }
    } break;
    }
}

FILDEF float get_tile_panel_height ()
{
    return Tile_Panel::bounds.h + 1.0f;
}

FILDEF void reload_tile_graphics ()
{
    using namespace Tile_Panel;

    free_texture_atlas(resource_large);
    free_texture_atlas(resource_small);

    if (editor_settings.tile_graphics == "new") {
        load_atlas_resource("textures/editor_icons/new_large.txt", resource_large);
        load_atlas_resource("textures/editor_icons/new_small.txt", resource_small);
    } else {
        load_atlas_resource("textures/editor_icons/old_large.txt", resource_large);
        load_atlas_resource("textures/editor_icons/old_small.txt", resource_small);
    }
}

FILDEF Tile_Category get_selected_category ()
{
    return CAST(Tile_Category, Tile_Panel::selected_category);
}

FILDEF Tile_ID get_selected_tile ()
{
    using namespace Tile_Panel;
    const auto& group = category[selected_category][selected_group];
    return group.tile[group.selected_index];
}

FILDEF Level_Layer get_selected_layer ()
{
    return category_to_layer(Tile_Panel::selected_category);
}

FILDEF Level_Layer category_to_layer (Tile_Category _category)
{
    switch (_category) {
    case (TILE_CATEGORY_BASIC  ): { return LEVEL_LAYER_ACTIVE;  } break;
    case (TILE_CATEGORY_TAG    ): { return LEVEL_LAYER_TAG;     } break;
    case (TILE_CATEGORY_OVERLAY): { return LEVEL_LAYER_OVERLAY; } break;
    case (TILE_CATEGORY_ENTITY ): { return LEVEL_LAYER_ACTIVE;  } break;
    case (TILE_CATEGORY_BACK1  ): { return LEVEL_LAYER_BACK1;   } break;
    case (TILE_CATEGORY_BACK2  ): { return LEVEL_LAYER_BACK2;   } break;
    }

    return LEVEL_LAYER_ACTIVE;
}

STDDEF void select_next_active_group ()
{
    using namespace Tile_Panel;

    if (!are_all_layers_inactive()) {
        while (!internal__is_category_active(selected_category)) {
            ++selected_category;
            if (selected_category > TILE_CATEGORY_BACK2) {
                selected_category = TILE_CATEGORY_BASIC;
            }
            selected_group = 0;
        }
    }
}

STDDEF void select_prev_active_group ()
{
    using namespace Tile_Panel;

    if (!are_all_layers_inactive()) {
        while (!internal__is_category_active(selected_category)) {
            --selected_category;
            if (selected_category < TILE_CATEGORY_BASIC) {
                selected_category = TILE_CATEGORY_BACK2;
            }
            selected_group = 0;
        }
    }
}

FILDEF void reset_selected_group ()
{
    Tile_Panel::selected_category = 0;
    select_next_active_group();
}

FILDEF void increment_selected_tile ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    if (are_all_layers_inactive()) { return; }
    auto& group = category[selected_category][selected_group];
    int old_selected_index = group.selected_index;
    if ((++group.selected_index) > CAST(int, group.tile.size()-1)) {
        group.selected_index = 0;
    }

    // Feels correct that a new history state should be made.
    if (old_selected_index != group.selected_index) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void decrement_selected_tile ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    if (are_all_layers_inactive()) { return; }
    auto& group = category[selected_category][selected_group];
    int old_selected_index = group.selected_index;
    if ((--group.selected_index) < 0) {
        group.selected_index = CAST(int, group.tile.size()-1);
    }

    // Feels correct that a new history state should be made.
    if (old_selected_index != group.selected_index) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void increment_selected_group ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    if (are_all_layers_inactive()) { return; }
    auto& cat = category[selected_category];
    int old_selected_group = selected_group;
    if ((++selected_group) > CAST(int, cat.size()-1)) {
        selected_group = 0;
    }

    // Feels correct that a new history state should be made.
    if (old_selected_group != selected_group) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void decrement_selected_group ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    if (are_all_layers_inactive()) { return; }
    auto& cat = category[selected_category];
    int old_selected_group = selected_group;
    if ((--selected_group) < 0) {
        selected_group = CAST(int, cat.size()-1);
    }

    // Feels correct that a new history state should be made.
    if (old_selected_group != selected_group) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void increment_selected_category ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    int old_selected_category = selected_category;
    int old_selected_group = selected_group;

    if (are_all_layers_inactive()) { return; }
    if ((++selected_category) > CAST(int, TILE_CATEGORY_BACK2)) {
        selected_category = TILE_CATEGORY_BASIC;
    }
    selected_group = 0;
    select_next_active_group();

    // Feels correct that a new history state should be made.
    if (old_selected_category != selected_category || old_selected_group != selected_group) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF void decrement_selected_category ()
{
    using namespace Tile_Panel;

    if (!current_tab_is_level()) { return; }

    int old_selected_category = selected_category;
    int old_selected_group = selected_group;

    if (are_all_layers_inactive()) { return; }
    if ((--selected_category) < CAST(int, TILE_CATEGORY_BASIC)) {
        selected_category = TILE_CATEGORY_BACK2;
    }
    selected_group = 0;
    select_prev_active_group();

    // Feels correct that a new history state should be made.
    if (old_selected_category != selected_category || old_selected_group != selected_group) {
        if (level_editor.tool_type == TOOL_TYPE_BRUSH || level_editor.tool_type == TOOL_TYPE_FILL) {
            if (level_editor.tool_state != TOOL_STATE_IDLE) {
                new_level_history_state(LEVEL_HISTORY_ACTION_NORMAL);
            }
        }
    }
}

FILDEF Tile_ID get_tile_horizontal_flip (Tile_ID _id)
{
    using namespace Tile_Panel;
    if (_id) {
        for (const auto& pair: flip_map_horz) {
            if (_id == pair.first)  { return pair.second; }
            if (_id == pair.second) { return pair.first;  }
        }
    }
    return _id;
}
FILDEF Tile_ID get_tile_vertical_flip (Tile_ID _id)
{
    using namespace Tile_Panel;
    if (_id) {
        for (const auto& pair: flip_map_vert) {
            if (_id == pair.first)  { return pair.second; }
            if (_id == pair.second) { return pair.first;  }
        }
    }
    return _id;
}

FILDEF void jump_to_category_basic ()
{
    internal__jump_to_category(TILE_CATEGORY_BASIC);
}
FILDEF void jump_to_category_tag ()
{
    internal__jump_to_category(TILE_CATEGORY_TAG);
}
FILDEF void jump_to_category_overlay ()
{
    internal__jump_to_category(TILE_CATEGORY_OVERLAY);
}
FILDEF void jump_to_category_entity ()
{
    internal__jump_to_category(TILE_CATEGORY_ENTITY);
}
FILDEF void jump_to_category_back1 ()
{
    internal__jump_to_category(TILE_CATEGORY_BACK1);
}
FILDEF void jump_to_category_back2 ()
{
    internal__jump_to_category(TILE_CATEGORY_BACK2);
}
