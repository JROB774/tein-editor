GLOBAL constexpr Vec4 LAYER_COLORS[LEVEL_LAYER_TOTAL]
{
{ 0.75f, 0.38f, 0.38f, 1.0f }, // Tag
{ 0.44f, 0.51f, 0.72f, 1.0f }, // Overlay
{ 0.79f, 0.69f, 0.20f, 1.0f }, // Active
{ 0.45f, 0.59f, 0.41f, 1.0f }, // Back 1
{ 0.57f, 0.48f, 0.71f, 1.0f }  // Back 2
};

GLOBAL constexpr const char* TILE_LAYER_INFO  = "Toggle this tile layer's visibility (invisible layers can't be interacted with).";

GLOBAL constexpr float LAYER_PANEL_INNER_PAD =  3.0f;
GLOBAL constexpr float LAYER_PANEL_BUTTON_H  = 24.0f;

GLOBAL float layer_panel_content_height;
GLOBAL float layer_panel_panel_height;

GLOBAL float layer_panel_scroll_offset;

GLOBAL Quad layer_panel_bounds;

FILDEF bool internal__do_layer_button (UI_Flag _flags, int _layer, const char* _name, const char* _info)
{
    const Quad& clip = (_flags & UI_INACTIVE) ? CLIP_CROSS : CLIP_EYE;

    float pad = 5.0f;
    Vec2 cursor = { pad, 0.0f };

    float bw = get_panel_w();
    float bh = LAYER_PANEL_BUTTON_H;

    // If not inactive then we need to determine if this is the active layer.
    if (!(_flags & UI_INACTIVE)) {
        // If the tool is the select tool then technically all of the layers
        // are active (except for disabled ones). So it makes sense to just
        // highlight ever single layer when using this particular tool.
        if (level_editor.tool_type == TOOL_TYPE_SELECT) {
            _flags |= UI_HIGHLIGHT;
        } else {
            Tile_Category category = get_selected_category();
            if (category_to_layer(category) == CAST(Level_Layer, _layer)) {
                _flags |= UI_HIGHLIGHT;
            }
        }
    }

    bool result = begin_click_panel(NULL, bw,bh, _flags, _info);

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_RIGHT);

    float w = 10.0f;
    float h = (LAYER_PANEL_BUTTON_H-4.0f)-1.0f; // -1.0f due to separator!

    cursor.y = (bh-h)/2.0f;
    do_quad(w, h, LAYER_COLORS[_layer]);
    cursor.y = 0.0f;
    advance_panel_cursor(pad);
    do_icon(24.0f, get_panel_h(), resource_icons, &clip);
    advance_panel_cursor(pad);
    do_label(UI_ALIGN_LEFT, UI_ALIGN_CENTER, get_panel_h(), _name);

    end_panel();
    return result;
}

FILDEF void internal__toggle_layer (Level_Layer _layer)
{
    ASSERT(current_tab_is_level());

    Tab& tab = get_current_tab();
    tab.tile_layer_active[_layer] = !tab.tile_layer_active[_layer];
    select_next_active_group();
}

FILDEF void internal__toggle_layer_action (Level_Layer _layer)
{
    if (!current_tab_is_level()) { return; }
    if (!is_window_focused("WINMAIN")) { return; }

    bool all_layers_were_inactive = are_all_layers_inactive();

    internal__toggle_layer(_layer);

    // If we're coming from all layers being inactive we need to find an entity
    // we can select now that there are entities that can be selected again.
    if (all_layers_were_inactive && !are_all_layers_inactive()) {
        reset_selected_group();
    }
}

FILDEF void init_layer_panel ()
{
    layer_panel_scroll_offset = 0.0f;
    layer_panel_bounds = {};

    // Calculate the content height for the layer panel.
    layer_panel_content_height  = LAYER_PANEL_BUTTON_H * LEVEL_LAYER_TOTAL;
    layer_panel_content_height -= 1.0f; // We don't care about the last separator!

    layer_panel_panel_height = 0.0f;
}

FILDEF void do_layer_panel (bool _scrollbar)
{
    if (!is_layer_panel_present()) { return; }

    layer_panel_bounds.x = 0.0f;
    layer_panel_bounds.y = get_tile_panel_height();
    layer_panel_bounds.w = get_panel_w();
    layer_panel_bounds.h = get_panel_h() - get_tile_panel_height();

    Vec2 cursor = { 0.0f, 0.0f };

    set_ui_texture(&resource_icons);
    set_ui_font(&get_editor_regular_font());

    float pad = LAYER_PANEL_INNER_PAD;

    begin_panel(layer_panel_bounds, UI_NONE, ui_color_medium);
    begin_panel(pad, pad, CONTROL_PANEL_WIDTH-(pad*2), layer_panel_bounds.h-(pad*2), UI_NONE, ui_color_med_dark);

    // NOTE: We do this to add a 1px border around the actual layer buttons in
    // the case that the panel is too small and needs a scrollbar it looks
    // nicer. Its a bit hacky and at some point we should probs have a feature
    // to add a padding border around a panel but for now we just do this...
    begin_panel(1.0f, 1.0f, get_panel_w()-2.0f, get_panel_h()-2.0f, UI_NONE, ui_color_med_dark);
    layer_panel_panel_height = get_panel_h();

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_DOWN);

    if (_scrollbar) {
        float sx =  1.0f + get_viewport().w + CONTROL_PANEL_INNER_PAD;
        float sy = -1.0f;
        float sw = CONTROL_PANEL_SCROLLBAR_WIDTH - CONTROL_PANEL_INNER_PAD;
        float sh =  2.0f + get_viewport().h;

        do_scrollbar(sx, sy, sw, sh, layer_panel_content_height, layer_panel_scroll_offset);
    }

    bool all_layers_were_inactive = are_all_layers_inactive();
    Tab& tab = get_current_tab();

    for (Level_Layer i=LEVEL_LAYER_TAG; i<LEVEL_LAYER_TOTAL; ++i) {
        const char* layer_name = NULL;
        switch (i) {
        case (LEVEL_LAYER_TAG    ): { layer_name = "Tag";     } break;
        case (LEVEL_LAYER_OVERLAY): { layer_name = "Overlay"; } break;
        case (LEVEL_LAYER_ACTIVE ): { layer_name = "Active";  } break;
        case (LEVEL_LAYER_BACK1  ): { layer_name = "Back 1";  } break;
        case (LEVEL_LAYER_BACK2  ): { layer_name = "Back 2";  } break;
        }

        UI_Flag tile_flag = (tab.tile_layer_active[i]) ? UI_NONE : UI_INACTIVE;
        if (internal__do_layer_button(tile_flag, i, layer_name, TILE_LAYER_INFO)) {
            internal__toggle_layer(i);
        }
    }

    // If we're coming from all layers being inactive we need to find an entity
    // we can select now that there are entities that can be selected again.
    if (all_layers_were_inactive && !are_all_layers_inactive()) {
        reset_selected_group();
    }

    end_panel();

    end_panel();
    end_panel();
}

FILDEF bool layer_panel_needs_scrollbar ()
{
    return ((current_tab_is_level()) ? (layer_panel_content_height > layer_panel_panel_height) : false);
}

FILDEF bool is_layer_panel_present ()
{
    return current_tab_is_level();
}

FILDEF float get_layer_panel_height ()
{
    return ceilf((layer_panel_content_height + 1.0f + 2.0f + (LAYER_PANEL_INNER_PAD * 2.0f)));
}

FILDEF void toggle_layer_active ()
{
    internal__toggle_layer_action(LEVEL_LAYER_ACTIVE);
}
FILDEF void toggle_layer_tag ()
{
    internal__toggle_layer_action(LEVEL_LAYER_TAG);
}
FILDEF void toggle_layer_overlay ()
{
    internal__toggle_layer_action(LEVEL_LAYER_OVERLAY);
}
FILDEF void toggle_layer_back1 ()
{
    internal__toggle_layer_action(LEVEL_LAYER_BACK1);
}
FILDEF void toggle_layer_back2 ()
{
    internal__toggle_layer_action(LEVEL_LAYER_BACK2);
}
