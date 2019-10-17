GLOBAL Quad control_panel_bounds;

FILDEF void do_control_panel ()
{
    control_panel_bounds.w = CONTROL_PANEL_WIDTH + CONTROL_PANEL_SCROLLBAR_WIDTH;
    control_panel_bounds.h = get_viewport().h;
    control_panel_bounds.x = get_viewport().w - control_panel_bounds.w;
    control_panel_bounds.y = 0.0f;

    // Determine if we need scrollbars for either sub-panels.
    bool scrollbar = tile_panel_needs_scrollbar() || layer_panel_needs_scrollbar();
    if (!scrollbar) {
        control_panel_bounds.w = CONTROL_PANEL_WIDTH;
        control_panel_bounds.x = get_viewport().w - control_panel_bounds.w;
    }

    if (are_there_any_level_tabs()) {
        begin_panel(control_panel_bounds, UI_NONE);
        do_tile_panel (scrollbar);
        do_layer_panel(scrollbar);
        end_panel();
    }
}

FILDEF float get_control_panel_w ()
{
    return (are_there_any_level_tabs()) ? control_panel_bounds.w : 0.0f;
}
