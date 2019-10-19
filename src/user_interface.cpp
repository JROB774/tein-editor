GLOBAL constexpr Vec4 UI_D_COLOR_BLACK     = { 0.00f, 0.00f, 0.00f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_EX_DARK   = { 0.20f, 0.20f, 0.20f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_DARK      = { 0.20f, 0.20f, 0.20f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_MED_DARK  = { 0.25f, 0.25f, 0.25f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_MEDIUM    = { 0.33f, 0.33f, 0.33f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_MED_LIGHT = { 0.43f, 0.43f, 0.43f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_LIGHT     = { 0.60f, 0.60f, 0.60f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_EX_LIGHT  = { 0.90f, 0.90f, 0.90f, 1.0f };
GLOBAL constexpr Vec4 UI_D_COLOR_WHITE     = { 1.00f, 1.00f, 1.00f, 1.0f };

GLOBAL constexpr Vec4 UI_L_COLOR_BLACK     = { 0.15f, 0.15f, 0.15f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_EX_DARK   = { 0.35f, 0.35f, 0.35f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_DARK      = { 0.55f, 0.55f, 0.55f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_MED_DARK  = { 0.70f, 0.70f, 0.70f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_MEDIUM    = { 0.80f, 0.80f, 0.80f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_MED_LIGHT = { 0.93f, 0.93f, 0.93f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_LIGHT     = { 0.93f, 0.93f, 0.93f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_EX_LIGHT  = { 0.96f, 0.96f, 0.96f, 1.0f };
GLOBAL constexpr Vec4 UI_L_COLOR_WHITE     = { 1.00f, 1.00f, 1.00f, 1.0f };

struct Panel
{
    Quad absolute_bounds; // Panel position and size on the window.
    Quad viewport;        // Viewport clipped inside parent.
    Vec2 relative_offset; // Panel position relative to its viewport.

    UI_Flag flags;        // Flags that get applied to a panel's content.

    Vec2*  cursor;
    UI_Dir cursor_dir;

    bool cursor_advance_enabled;
};

// Typedef this just so it's clear what is being referred to in code.
typedef u32 UI_ID;

GLOBAL constexpr UI_ID UI_INVALID_ID = UINT32_MAX;

// Highly unlikely we will ever need more embedded scissors than this but if we
// do we will know about it through various code ASSERTS and can just increase.
GLOBAL Stack<Panel, 256> ui_panels;

GLOBAL UI_ID ui_current_id;

GLOBAL UI_ID ui_hot_id;
GLOBAL UI_ID ui_hit_id;

GLOBAL UI_ID  ui_active_text_box;
GLOBAL UI_ID  ui_hot_text_box;
GLOBAL size_t ui_text_box_cursor;

GLOBAL UI_ID  ui_hot_hyperlink;

GLOBAL UI_ID ui_active_hotkey_rebind;

GLOBAL Texture* ui_texture;
GLOBAL Font*    ui_font;

GLOBAL Vec2 ui_mouse_relative;

GLOBAL bool ui_mouse_up;
GLOBAL bool ui_mouse_down;

GLOBAL bool ui_mouse_r_up;
GLOBAL bool ui_mouse_r_down;

GLOBAL bool ui_is_light;

// We also store the active window ID at the time of the tab press so that the
// system does not move from window-to-window when the user presseses tab.
GLOBAL Window_ID ui_text_box_tab_window_id;
GLOBAL bool      ui_make_next_text_box_active;
GLOBAL bool      ui_tab_handled;
GLOBAL bool      ui_text_event_happened;

enum UI_Text_Event_Type: u32
{
    UI_TEXT_EVENT_TEXT,
    UI_TEXT_EVENT_KEY,
};

struct UI_Text_Event
{
    UI_Text_Event_Type type;

    char       text;
    SDL_Keycode key;
};

GLOBAL std::vector<UI_Text_Event> ui_text_events;

GLOBAL constexpr u32 UI_CURSOR_BLINK_INTERVAL = 700;

GLOBAL SDL_TimerID ui_cursor_blink_timer;
GLOBAL bool        ui_cursor_visible;

FILDEF bool internal__isfilepath (char _c)
{
    return std::string("<>\"|?*").find(_c) == std::string::npos;
}

FILDEF u32 internal__cursor_blink_callback (u32 _interval, void* _user_data)
{
    push_editor_event(EDITOR_EVENT_BLINK_CURSOR);
    return _interval;
}

FILDEF bool internal__is_hot ()
{
    return (ui_current_id == ui_hot_id);
}

FILDEF bool internal__is_hit ()
{
    return (ui_current_id == ui_hit_id);
}

FILDEF Quad internal__get_clipped_bounds (float _x, float _y, float _w, float _h)
{
    // Clip the widget's bounds to be within the panel's visible area.
    // This stops the user being able to click on invisible portions.
    //
    // We also make the bounds relative to the window, so that they can
    // properly be compared with the mouse cursor without any issues.
    const Quad& v = get_viewport();
    Quad clipped_bounds;

    clipped_bounds.x1 = MAX(_x,            0.0f) + v.x;
    clipped_bounds.y1 = MAX(_y,            0.0f) + v.y;
    clipped_bounds.x2 = MIN(_x + (_w-1.0f), v.w) + v.x;
    clipped_bounds.y2 = MIN(_y + (_h-1.0f), v.h) + v.y;

    return clipped_bounds;
}

FILDEF Quad internal__get_clipped_bounds (Quad& _p)
{
    // Clip the widget's bounds to be within the panel's visible area.
    // This stops the user being able to click on invisible portions.
    //
    // We also make the bounds relative to the window, so that they can
    // properly be compared with the mouse cursor without any issues.
    const Quad& v = get_viewport();
    Quad clipped_bounds;

    clipped_bounds.x1 = MAX(_p.x,              0.0f) + v.x;
    clipped_bounds.y1 = MAX(_p.y,              0.0f) + v.y;
    clipped_bounds.x2 = MIN(_p.x + (_p.w-1.0f), v.w) + v.x;
    clipped_bounds.y2 = MIN(_p.y + (_p.h-1.0f), v.h) + v.y;

    return clipped_bounds;
}

FILDEF bool internal__handle_widget (float _x, float _y, float _w, float _h, bool _locked)
{
    // Don't bother handling widgets during resize to avoid ugly redraw stuff.
    if (is_a_window_resizing()) { return false; }

    // If we're not the focused window then we do not handle.
    if (!get_render_target()->focus) { return false; }
    // If we're not the moused window then we do not handle.
    if (!get_render_target()->mouse) { return false; }

    bool result = false;

    Quad clipped_bounds = internal__get_clipped_bounds(_x, _y, _w, _h);
    Vec2 mouse = get_mouse_pos();

    // Determine the hot and active states for the global UI context.
    bool inside = point_in_bounds_xyxy(mouse, clipped_bounds);
    if (!_locked && ui_hit_id == ui_current_id) {
        if (ui_mouse_up) {
            if (ui_hot_id == ui_current_id) {
                result = true;
            }
            ui_hit_id = UI_INVALID_ID;
        }
    }
    if (ui_hot_id == ui_current_id) {
        if (!_locked && inside) {
            if (ui_mouse_down) {
                ui_hit_id = ui_current_id;
            }
        } else {
            ui_hot_id = UI_INVALID_ID;
        }
    }
    if (inside) {
        ui_hot_id = ui_current_id;
    }

    // If true then the widget being checked was activated this frame.
    return result;
}

FILDEF bool internal__handle_widget (Quad _b, bool _locked)
{
    return internal__handle_widget(_b.x, _b.y, _b.w, _b.h, _locked);
}

FILDEF Vec2 internal__get_relative_cursor (Panel& _panel)
{
    ASSERT(_panel.cursor);
    Vec2 cur = *_panel.cursor;

    cur.x += _panel.relative_offset.x;
    cur.y += _panel.relative_offset.y;

    return cur;
}

FILDEF Vec2 internal__get_cursor (Panel& _panel)
{
    ASSERT(_panel.cursor);
    return *_panel.cursor;
}

FILDEF void internal__draw_separator (Vec2 _cursor, UI_Dir _dir, float _w, float _h, Vec4 _color)
{
    float x1 = _cursor.x;
    float y1 = _cursor.y;
    float x2 = _cursor.x;
    float y2 = _cursor.y;

    switch (_dir) {
    case (UI_DIR_UP):    { x1+=1;  x2+=(_w-1); y1+=1;  y2+=1;      } break;
    case (UI_DIR_RIGHT): { x1+=_w; x2+=_w;     y1+=1;  y2+=(_h-1); } break;
    case (UI_DIR_DOWN):  { x1+=1;  x2+=(_w-1); y1+=_h; y2+=_h;     } break;
    case (UI_DIR_LEFT):  { x1+=1;  x2+=1;      y1+=1;  y2+=(_h-1); } break;
    }

    set_draw_color(_color);
    draw_line(x1, y1, x2, y2);
}

FILDEF void internal__advance_ui_cursor_start (Panel& _panel, float _w, float _h)
{
    if (!_panel.cursor_advance_enabled) { return; }

    ASSERT(_panel.cursor);
    Vec2& cur = *_panel.cursor;

    switch (_panel.cursor_dir) {
    case(UI_DIR_UP):    { cur.y -= _h; } break;
    case(UI_DIR_LEFT):  { cur.x -= _w; } break;
    }
}

FILDEF void internal__advance_ui_cursor_end (Panel& _panel, float _w, float _h)
{
    if (!_panel.cursor_advance_enabled) { return; }

    ASSERT(_panel.cursor);
    Vec2& cur = *_panel.cursor;

    switch (_panel.cursor_dir) {
    case(UI_DIR_RIGHT): { cur.x += _w; } break;
    case(UI_DIR_DOWN):  { cur.y += _h; } break;
    }
}

FILDEF void internal__align_text (UI_Align _horz, UI_Align _vert, float& _x, float& _y, float _tw, float _th, float _w, float _h)
{
    // Determine how to place the text based on alignment.
    switch (_horz) {
    case (UI_ALIGN_LEFT  ): { /* No need to do anything. */         } break;
    case (UI_ALIGN_RIGHT ): { _x += roundf( (_w-_tw));              } break;
    case (UI_ALIGN_CENTER): { _x += roundf(((_w-_tw)/2.0f));        } break;
    }
    switch (_vert) {
    case (UI_ALIGN_TOP   ): { _y += ui_font->line_gap;              } break;
    case (UI_ALIGN_BOTTOM): { _y += roundf(((_h)-(_th/4.0f)));      } break;
    case (UI_ALIGN_CENTER): { _y += roundf(((_h/2.0f)+(_th/4.0f))); } break;
    }
}

FILDEF bool internal__is_ui_mouse_down ()
{
    return (get_render_target()->focus) ? ui_mouse_down : false;
}

FILDEF bool internal__is_ui_mouse_r_down ()
{
    return (get_render_target()->focus) ? ui_mouse_r_down : false;
}

FILDEF bool init_ui_system ()
{
    ui_panels.count = 0;

    ui_hot_id = UI_INVALID_ID;
    ui_hit_id = UI_INVALID_ID;

    ui_active_text_box = UI_INVALID_ID;
    ui_hot_text_box    = UI_INVALID_ID;
    ui_text_box_cursor = std::string::npos;

    ui_hot_hyperlink = UI_INVALID_ID;

    ui_active_hotkey_rebind = UI_INVALID_ID;

    ui_texture = NULL;
    ui_font    = NULL;

    ui_mouse_relative = { 0.0f, 0.0f };

    ui_mouse_up     = false;
    ui_mouse_down   = false;
    ui_mouse_r_up   = false;
    ui_mouse_r_down = false;

    ui_text_box_tab_window_id = 0;
    ui_make_next_text_box_active = false;
    ui_tab_handled = false;

    ui_cursor_blink_timer = NULL;
    ui_cursor_visible = true;

    return true;
}

FILDEF void load_ui_theme ()
{
    std::string theme = editor_settings.ui_theme;
    if (theme == "dark") {
        ui_color_black     = UI_D_COLOR_BLACK;
        ui_color_ex_dark   = UI_D_COLOR_EX_DARK;
        ui_color_dark      = UI_D_COLOR_DARK;
        ui_color_med_dark  = UI_D_COLOR_MED_DARK;
        ui_color_medium    = UI_D_COLOR_MEDIUM;
        ui_color_med_light = UI_D_COLOR_MED_LIGHT;
        ui_color_light     = UI_D_COLOR_LIGHT;
        ui_color_ex_light  = UI_D_COLOR_EX_LIGHT;
        ui_color_white     = UI_D_COLOR_WHITE;
        ui_is_light        = false;
    } else {
        ui_color_black     = UI_L_COLOR_BLACK;
        ui_color_ex_dark   = UI_L_COLOR_EX_DARK;
        ui_color_dark      = UI_L_COLOR_DARK;
        ui_color_med_dark  = UI_L_COLOR_MED_DARK;
        ui_color_medium    = UI_L_COLOR_MEDIUM;
        ui_color_med_light = UI_L_COLOR_MED_LIGHT;
        ui_color_light     = UI_L_COLOR_LIGHT;
        ui_color_ex_light  = UI_L_COLOR_EX_LIGHT;
        ui_color_white     = UI_L_COLOR_WHITE;
        ui_is_light        = true;
    }

    // Reload cursors because the beam cursor changes based on theme.
    load_editor_cursors();

    // These colors, if default, also depend on the UI theme.
    Vec4 default_background_color = ui_color_light;
    Vec4 default_tile_grid_color = is_ui_light() ? ui_color_black : ui_color_ex_dark;

    if (editor_settings.background_color_defaulted) {
        editor_settings.background_color = default_background_color;
    }
    if (editor_settings.tile_grid_color_defaulted) {
        editor_settings.tile_grid_color = default_tile_grid_color;
    }
}

FILDEF void reset_ui_state ()
{
    // Reset the internal UI ID back to the beginning for a new update/cycle.
    ui_current_id = 0;

    ui_text_events.clear();
    ui_text_event_happened = false;
    ui_tab_handled = false;

    // We do this during every event otherwise we can end up with some weird
    // values provided by SDL_GetRelativeMouseState, so we just cache here.
    int imx, imy; SDL_GetRelativeMouseState(&imx, &imy);
    ui_mouse_relative = { CAST(float, imx), CAST(float, imy) };

    ui_mouse_down   = false;
    ui_mouse_up     = false;
    ui_mouse_r_down = false;
    ui_mouse_r_up   = false;
}

FILDEF void handle_ui_events ()
{
    bool prev_down = ui_mouse_down;
    bool prev_up = ui_mouse_up;

    switch (main_event.type) {
    case (SDL_MOUSEBUTTONDOWN): { if (main_event.button.button == SDL_BUTTON_LEFT) { ui_mouse_down = true; } else if (main_event.button.button == SDL_BUTTON_RIGHT) { ui_mouse_r_down = true; } } break;
    case (SDL_MOUSEBUTTONUP):   { if (main_event.button.button == SDL_BUTTON_LEFT) { ui_mouse_up   = true; } else if (main_event.button.button == SDL_BUTTON_RIGHT) { ui_mouse_r_up   = true; } } break;
    case (SDL_WINDOWEVENT): {
        // When focus changes to a new window then the current text box should be deselected.
        // We also do not want the current hit and hot IDs to persist to the new window.
        if (main_event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
            deselect_active_text_box();
            deselect_active_hotkey_rebind();

            ui_hot_id = UI_INVALID_ID;
            ui_hit_id = UI_INVALID_ID;
        }
    } break;
    case (SDL_USEREVENT): {
        if (main_event.user.code == EDITOR_EVENT_BLINK_CURSOR) {
            ui_cursor_visible = !ui_cursor_visible;
        }
    } break;
    }

    // Handle events specifically for UI text boxes.
    if (ui_active_text_box != UI_INVALID_ID) {
        UI_Text_Event text_event;
        switch (main_event.type) {
        case (SDL_TEXTINPUT): {
            text_event.type = UI_TEXT_EVENT_TEXT;
            text_event.text = main_event.text.text[0];
            ui_text_events.push_back(text_event);
        } break;
        case (SDL_KEYDOWN): {
            text_event.type = UI_TEXT_EVENT_KEY;
            text_event.key  = main_event.key.keysym.sym;
            ui_text_events.push_back(text_event);
        } break;
        }
    } else {
        if (main_event.type == SDL_KEYDOWN) {
            if (main_event.key.keysym.sym == SDLK_TAB) { // We do this so we can focus on the first text box in the window!
                ui_make_next_text_box_active = true;
                ui_text_box_tab_window_id = get_focused_window().id;
            }
        }
    }

    // The UI has not changed state so we don't have to worry about redraws.
    if (prev_down == ui_mouse_down && prev_up == ui_mouse_up) { return; }

    // This event exists to perform a second redraw of the user interface. Due
    // to the fact we are using an immediate mode GUI, there is a frame delay
    // that causes some gross visual issues due to our program being mainly
    // event-driven. This method of redrawing again prevents the issue easily.
    should_push_ui_redraw_event = true;
}

FILDEF bool is_ui_light ()
{
    return ui_is_light;
}

FILDEF Vec2 ui_get_relative_mouse ()
{
    return ui_mouse_relative;
}

FILDEF bool mouse_in_ui_bounds_xywh (float _x, float _y, float _w, float _h)
{
    Quad clipped_bounds = internal__get_clipped_bounds(_x, _y, _w, _h);
    Vec2 mouse = get_mouse_pos();

    return point_in_bounds_xyxy(mouse, clipped_bounds);
}

FILDEF bool mouse_in_ui_bounds_xywh (Quad _b)
{
    Quad clipped_bounds = internal__get_clipped_bounds(_b.x, _b.y, _b.w, _b.h);
    Vec2 mouse = get_mouse_pos();

    return point_in_bounds_xyxy(mouse, clipped_bounds);
}

FILDEF void set_ui_texture (Texture* _tex)
{
    ui_texture = _tex;
}

FILDEF void set_ui_font (Font* _font)
{
    ui_font = _font;
}

FILDEF bool is_there_a_hot_ui_element ()
{
    return (ui_hot_id != UI_INVALID_ID);
}

FILDEF bool is_there_a_hit_ui_element ()
{
    return (ui_hit_id != UI_INVALID_ID);
}

FILDEF void deselect_active_text_box ()
{
    if (ui_cursor_blink_timer) {
        SDL_RemoveTimer(ui_cursor_blink_timer);
        ui_cursor_blink_timer = NULL;
    }

    ui_text_box_cursor = std::string::npos;
    ui_active_text_box = UI_INVALID_ID;

    SDL_StopTextInput();
}

FILDEF void deselect_active_text_box (std::string& _text, const char* _default)
{
    // If specified and the text box is empty on exit then we assign
    // the content of the text box to be the passed in default value.
    if (_default && !_text.length()) { _text = _default; }
    deselect_active_text_box();
}

FILDEF bool text_box_is_active ()
{
    return (ui_active_text_box != UI_INVALID_ID);
}

FILDEF bool hotkey_is_active ()
{
    return (ui_active_hotkey_rebind != UI_INVALID_ID);
}

FILDEF void deselect_active_hotkey_rebind ()
{
    ui_active_hotkey_rebind = UI_INVALID_ID;
}

STDDEF void begin_panel (float _x, float _y, float _w, float _h, UI_Flag _flags, Vec4 _c)
{
    Panel panel;

    // The method of adding a new panel varies depending on whether the panel
    // is a child to an existing panel or if it is a lone panel in the window.
    panel.absolute_bounds = { _x, _y, _w, _h };
    if (ui_panels.count > 0) {
        const Quad& p_ab = ui_panels.peek().absolute_bounds;
        const Quad& p_v  = ui_panels.peek().viewport;
        const Vec2& p_ro = ui_panels.peek().relative_offset;

        Quad& c_ab = panel.absolute_bounds;
        Quad& c_v  = panel.viewport;
        Vec2& c_ro = panel.relative_offset;

        c_ab.x += p_ab.x + p_ro.x;
        c_ab.y += p_ab.y + p_ro.y;

        c_v = c_ab;

        // We also clip the panel's viewport to be inside of the
        // parent panel to avoid issues with overlapping/spill.
        float dx = c_v.x - p_v.x;
        float dy = c_v.y - p_v.y;

        if (c_v.x < p_v.x) { c_v.x = p_v.x; c_v.w -= roundf(abs(dx)); dx = c_v.x - p_v.x; }
        if (c_v.y < p_v.y) { c_v.y = p_v.y; c_v.h -= roundf(abs(dy)); dy = c_v.y - p_v.y; }

        if (c_v.x+c_v.w > p_v.x+p_v.w) { c_v.w = p_v.w - roundf(abs(dx)); }
        if (c_v.y+c_v.h > p_v.y+p_v.h) { c_v.h = p_v.h - roundf(abs(dy)); }

        if (c_v.w < 0.0f) { c_v.w = 0.0f; }
        if (c_v.h < 0.0f) { c_v.h = 0.0f; }

        // And determine the panel's offset to its viewport.
        c_ro.x = c_ab.x - c_v.x;
        c_ro.y = c_ab.y - c_v.y;

        // Inherit the parent panel's flags.
        panel.flags = _flags | ui_panels.peek().flags;
    } else {
        panel.viewport = panel.absolute_bounds;
        panel.relative_offset = { 0.0f, 0.0f };
        panel.flags = _flags;
    }

    panel.cursor = NULL;
    panel.cursor_dir = UI_DIR_RIGHT;
    panel.cursor_advance_enabled = true;

    set_viewport(panel.viewport);
    ui_panels.push(panel);

    set_draw_color(_c);
    fill_quad(0.0f, 0.0f, panel.viewport.w, panel.viewport.h);
}

FILDEF void begin_panel (Quad _bounds, UI_Flag _flags, Vec4 _c)
{
    begin_panel(_bounds.x, _bounds.y, _bounds.w, _bounds.h, _flags, _c);
}

STDDEF bool begin_click_panel (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _info)
{
    Panel& parent = ui_panels.peek();

    Vec2 rcur = internal__get_relative_cursor(parent);
    Vec2 cur = internal__get_cursor(parent);

    // Cache the panel's flags so they are easily accessible.
    bool locked    = (_flags & UI_LOCKED);
    bool highlight = (_flags & UI_HIGHLIGHT);

    bool result = internal__handle_widget(rcur.x, rcur.y, _w, _h, locked);
    if (result && _action) { _action(); } // Make sure action is valid!

    Vec4 back = ui_color_medium;

    if      (locked)             { back = ui_color_med_dark;  }
    else if (internal__is_hit()) { back = ui_color_dark;      }
    else if (internal__is_hot()) { back = ui_color_med_light; }

    begin_panel(cur.x, cur.y, _w, _h, _flags, back);
    internal__advance_ui_cursor_start(parent, _w, _h);

    if (highlight && !internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        set_draw_color(color);
        fill_quad(0.0f, 0.0f, get_viewport().w, get_viewport().h);
    }

    Vec4 separator_color = (locked) ? ui_color_dark : ui_color_med_dark;
    Vec2 cursor = ui_panels.peek().relative_offset;

    internal__draw_separator(cursor, parent.cursor_dir, _w, _h, separator_color);
    internal__advance_ui_cursor_end(parent, _w, _h);

    // If we are currently hot then we push our info to the status bar.
    if (!locked && _info && internal__is_hot()) { push_status_bar_message(_info); }

    ++ui_current_id;

    return result;
}

STDDEF void end_panel ()
{
    ui_panels.pop();

    // We either go back to a previous nested panel or this is the last panel
    // and we go back to placing things relative to the entire program window.
    if (ui_panels.count > 0) { set_viewport(ui_panels.peek().viewport); }
    else { set_viewport(0, 0, get_render_target_w(), get_render_target_h()); }
}

FILDEF float get_panel_w ()
{
    return ui_panels.peek().absolute_bounds.w;
}

FILDEF float get_panel_h ()
{
    return ui_panels.peek().absolute_bounds.h;
}

FILDEF Vec2 get_panel_offset ()
{
    return ui_panels.peek().relative_offset;
}

FILDEF Vec2 get_panel_cursor ()
{
    return internal__get_cursor(ui_panels.peek());
}

FILDEF void disable_panel_cursor_advance ()
{
    ui_panels.peek().cursor_advance_enabled = false;
}

FILDEF void enable_panel_cursor_advance ()
{
    ui_panels.peek().cursor_advance_enabled = true;
}

FILDEF void advance_panel_cursor (float _advance)
{
    internal__advance_ui_cursor_start(ui_panels.peek(), _advance, _advance);
    internal__advance_ui_cursor_end(ui_panels.peek(), _advance, _advance);
}

FILDEF void set_panel_cursor (Vec2* _cursor)
{
    ui_panels.peek().cursor = _cursor;
}

FILDEF void set_panel_cursor_dir (UI_Dir _dir)
{
    ui_panels.peek().cursor_dir = _dir;
}

FILDEF void set_panel_flags (UI_Flag _flags)
{
    ui_panels.peek().flags = _flags;
}

FILDEF UI_Flag get_panel_flags ()
{
    return ui_panels.peek().flags;
}

STDDEF bool do_button_img (UI_Action _action, float _w, float _h, UI_Flag _flags, const Quad* _clip, const char* _info, const char* _kb, const char* _name)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_texture);

    _flags |= ui_panels.peek().flags;

    // Cache the button's flags so they are easily accessible.
    bool inactive  = (_flags & UI_INACTIVE);
    bool locked    = (_flags & UI_LOCKED);
    bool highlight = (_flags & UI_HIGHLIGHT);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Texture& tex = *ui_texture;
    Vec2     cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid image overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    // Locked buttons cannot be interacted with.
    bool result = internal__handle_widget(cur.x, cur.y, _w, _h, locked);
    if (result && _action) { _action(); } // Make sure action is valid!

    Vec4 front  = (ui_is_light) ? Vec4 { 0.4f,0.4f,0.4f,1.0f } : Vec4 { 0.73f,0.73f,0.73f,1.0f };
    Vec4 back   =  ui_color_medium;
    Vec4 shadow = (ui_is_light) ? Vec4 { 0.9f,0.9f,0.9f,1.0f } : Vec4 { 0.16f,0.16f,0.16f,1.0f };

    if      (locked)             { back = ui_color_med_dark;  }
    else if (internal__is_hit()) { back = ui_color_dark;      }
    else if (internal__is_hot()) { back = ui_color_med_light; }

    if (locked || inactive) {
        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    set_draw_color(back); // Draw the button's background quad.
    fill_quad(cur.x, cur.y, cur.x + _w, cur.y + _h);

    if (highlight && !internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        set_draw_color(color);
        fill_quad(0.0f, 0.0f, get_viewport().w, get_viewport().h);
    }

    // The ((_w)-1.0f) and ((_h)-1.0f) are used to ensure the separator
    // does not mess with the centering of the image based on direction.

    UI_Dir dir = ui_panels.peek().cursor_dir;

    float w = (dir == UI_DIR_RIGHT || dir == UI_DIR_LEFT) ? ((_w)-1.0f) : (_w);
    float h = (dir == UI_DIR_UP    || dir == UI_DIR_DOWN) ? ((_h)-1.0f) : (_h);

    // Center the image within the button.
    float x = roundf(cur.x + (w / 2.0f) + ((dir == UI_DIR_LEFT) ? 1.0f : 0.0f));
    float y = roundf(cur.y + (h / 2.0f) + ((dir == UI_DIR_UP)   ? 1.0f : 0.0f));

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    Flip flip = FLIP_NONE;

    if (_flags&UI_FLIP_HORZ) { flip |= FLIP_HORZ; }
    if (_flags&UI_FLIP_VERT) { flip |= FLIP_VERT; }

    tex.color = shadow;
    draw_texture(tex, x, y-offset, flip, _clip);
    tex.color = front;
    draw_texture(tex, x, y, flip, _clip);

    internal__draw_separator(internal__get_relative_cursor(ui_panels.peek()), ui_panels.peek().cursor_dir, _w, _h, ui_color_med_dark);
    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    // If we are currently hot then we push our info to the status bar.
    if (!locked && _info && internal__is_hot()) {
        std::string kb_info;
        if (_kb) {
            kb_info = format_string("(%s)", get_key_binding_main_string(_kb).c_str());
            if (get_key_binding(_kb).alt_code && get_key_binding(_kb).alt_mod) {
                kb_info += format_string(" or (%s)", get_key_binding_alt_string(_kb).c_str());
            }
        }
        std::string info((kb_info.empty()) ? _info : format_string("%s %s", kb_info.c_str(), _info));
        push_status_bar_message(info.c_str());
    }
    // If we are currently hot then set the tooltip.
    if (!locked && _name && internal__is_hot()) {
        set_current_tooltip(_name);
    }

    ++ui_current_id;

    return result;
}

STDDEF bool do_button_txt (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _text, const char* _info, const char* _kb, const char* _name)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    _flags |= ui_panels.peek().flags;

    // Cache the button's flags so they are easily accessible.
    bool inactive  = (_flags & UI_INACTIVE);
    bool locked    = (_flags & UI_LOCKED);
    bool highlight = (_flags & UI_HIGHLIGHT);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2  cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid text overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    // Locked buttons cannot be interacted with.
    bool result = internal__handle_widget(cur.x, cur.y, _w, _h, locked);
    if (result && _action) { _action(); } // Make sure action is valid!

    Vec4 front  = (ui_is_light) ? ui_color_black    : ui_color_ex_light;
    Vec4 back   = ui_color_medium;
    Vec4 shadow = (ui_is_light) ? ui_color_ex_light : ui_color_black;

    if      (locked)             { back = ui_color_med_dark;  }
    else if (internal__is_hit()) { back = ui_color_dark;      }
    else if (internal__is_hot()) { back = ui_color_med_light; }

    if (locked || inactive) {
        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    set_draw_color(back); // Draw the button's background quad.
    fill_quad(cur.x, cur.y, cur.x + _w, cur.y + _h);

    if (highlight && !internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        set_draw_color(color);
        fill_quad(0.0f, 0.0f, get_viewport().w, get_viewport().h);
    }

    float w = get_text_width(fnt, _text) * get_font_draw_scale();
    float h = fnt.line_gap * get_font_draw_scale();
    // Center the text within the button.
    float x = roundf(cur.x + ((_w - w) / 2.0f));
    float y = roundf(cur.y + ((_h / 2.0f) + (h / 4.0f)));

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    fnt.color = shadow;
    draw_text(fnt, x, y-offset, _text);
    fnt.color = front;
    draw_text(fnt, x, y, _text);

    if (!(_flags&UI_SINGLE)) {
        internal__draw_separator(internal__get_relative_cursor(ui_panels.peek()), ui_panels.peek().cursor_dir, _w, _h, ui_color_med_dark);
    }
    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    // If we are currently hot then we push our info to the status bar.
    if (!locked && _info && internal__is_hot()) {
        std::string kb_info;
        if (_kb) {
            kb_info = format_string("(%s)", get_key_binding_main_string(_kb).c_str());
            if (get_key_binding(_kb).alt_code && get_key_binding(_kb).alt_mod) {
                kb_info += format_string(" or (%s)", get_key_binding_alt_string(_kb).c_str());
            }
        }
        std::string info((kb_info.empty()) ? _info : format_string("%s %s", kb_info.c_str(), _info));
        push_status_bar_message(info.c_str());
    }
    // If we are currently hot then set the tooltip.
    if (!locked && _name && internal__is_hot()) {
        set_current_tooltip(_name);
    }

    ++ui_current_id;

    return result;
}

FILDEF bool do_button_txt (UI_Action _action, float _h, UI_Flag _flags, const char* _text, const char* _info, const char* _kb, const char* _name)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);
    Font& fnt = *ui_font;

    // Important to return ceiled value otherwise the next button using the
    // cursor to position itself might overlap the previous button by 1px.
    constexpr float X_PADDING = 20.0f;
    float w = ceilf(get_text_width(fnt, _text) * get_font_draw_scale()) + X_PADDING;

    // Perform a normal text button now we know the width.
    return do_button_txt(_action, w, _h, _flags, _text, _info, _kb, _name);
}

STDDEF void do_label (UI_Align _horz, UI_Align _vert, float _w, float _h, const char* _text, Vec4 _bg)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    UI_Flag flags = ui_panels.peek().flags;

    // Cache the label's flags so they are easily accessible.
    bool inactive = (flags & UI_INACTIVE);
    bool locked   = (flags & UI_LOCKED  );
    bool tooltip  = (flags & UI_TOOLTIP );
    bool darken   = (flags & UI_DARKEN  );

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2  cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid text overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    // Draw the background color, by default this is transparent.
    set_draw_color(_bg);
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);

    float tw = get_text_width(fnt, _text) * get_font_draw_scale();
    float th = get_text_height(fnt, _text) * get_font_draw_scale();

    // If text is a single line we calculate how much we can fit in the width
    // and if necessary trim any off and replace the end with and ellipsis.
    std::string text(_text);
    if (get_line_count(text.c_str()) == 1) {
        if (tw > _w) { // Our text goes out of the label bounds.
            if (text.length() <= 3) {
                text = "...";
                tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
            } else {
                text.replace(text.length()-3, 3, "...");
                while (tw > _w && text.length() > 3) {
                    text.erase(text.length()-4, 1);
                    tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
                }
            }
        }
    }

    float x = cur.x;
    float y = cur.y;

    internal__align_text(_horz, _vert, x, y, tw, th, _w, _h);

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    Vec4 shadow = (ui_is_light) ? ui_color_ex_light : ui_color_black;
    Vec4 front = (ui_is_light) ? ui_color_black : ui_color_ex_light;

    if (locked || inactive) {
        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    // Hack: Just to get tooltips working nicely...
    if (tooltip) {
        shadow = UI_D_COLOR_BLACK;
        front = UI_D_COLOR_EX_LIGHT;
        if (darken) {
            front = { 0.70f, 0.70f, 0.70f, 1.0f };
        }
    }

    fnt.color = shadow;
    draw_text(fnt, x, y-offset, text.c_str());
    fnt.color = front;
    draw_text(fnt, x, y, text.c_str());

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);
}

FILDEF void do_label (UI_Align _horz, UI_Align _vert, float _h, const char* _text, Vec4 _bg)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);
    Font& fnt = *ui_font;

    // Important to return ceiled value otherwise the next label using the
    // cursor to position itself might overlap the previous label by 1px.
    float w = ceilf(get_text_width(fnt, _text) * get_font_draw_scale());

    // Perform a normal text label now we know the width.
    return do_label(_horz, _vert, w, _h, _text, _bg);
}

STDDEF void do_label_hyperlink (UI_Align _horz, UI_Align _vert, float _w, float _h, const char* _text, const char* _link, const char* _href, Vec4 _bg)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2  cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid text overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    // Draw the background color, by default this is transparent.
    set_draw_color(_bg);
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);

    float tw = get_text_width(fnt, _text) * get_font_draw_scale();
    float th = get_text_height(fnt, _text) * get_font_draw_scale();

    // If text is a single line we calculate how much we can fit in the width
    // and if necessary trim any off and replace the end with and ellipsis.
    std::string text(_text);
    if (get_line_count(text.c_str()) == 1) {
        if (tw > _w) { // Our text goes out of the label bounds.
            if (text.length() <= 3) {
                text = "...";
                tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
            } else {
                text.replace(text.length()-3, 3, "...");
                while (tw > _w && text.length() > 3) {
                    text.erase(text.length()-4, 1);
                    tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
                }
            }
        }
    }

    // Handle setting the application's cursor to the correct graphic.
    if (internal__is_hot()) {
        ui_hot_hyperlink = ui_current_id;
        set_cursor(CURSOR_POINTER);
    } else {
        if (ui_hot_hyperlink == ui_current_id) { ui_hot_hyperlink = UI_INVALID_ID; }

        // We have this check so that we can know it's okay to set
        // the cursor back to arrow as no text box elements are hot.
        if (ui_hot_hyperlink == UI_INVALID_ID && ui_hot_text_box == UI_INVALID_ID) {
            // NOTE: Kind of hacky to put this here, but it prevents issues with
            // the flickering of the cursor due to hyperlinks. Could be cleaned.
            if (are_there_any_level_tabs()) {
                if (mouse_inside_level_editor_viewport() && is_window_focused("WINMAIN")) {
                    switch (level_editor.tool_type) {
                    case (TOOL_TYPE_BRUSH):  { set_cursor(CURSOR_BRUSH);  } break;
                    case (TOOL_TYPE_FILL):   { set_cursor(CURSOR_FILL);   } break;
                    case (TOOL_TYPE_SELECT): { set_cursor(CURSOR_SELECT); } break;
                    }
                } else {
                    set_cursor(CURSOR_ARROW);
                }
            } else {
                set_cursor(CURSOR_ARROW);
            }
        }
    }

    float wx = cur.x + (get_text_width(fnt, text.c_str()) * get_font_draw_scale());
    float wy = cur.y;
    float ww = get_text_width (fnt, _link) * get_font_draw_scale();
    float wh = get_text_height(fnt, _link) * get_font_draw_scale();

    if (internal__handle_widget(wx,wy,ww,wh, false)) {
        load_webpage(_href);
    }

    float x = cur.x;
    float y = cur.y;

    internal__align_text(_horz, _vert, x, y, tw, th, _w, _h);

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    Vec4 shadow = (ui_is_light) ? ui_color_ex_light : ui_color_black;
    Vec4 front = (ui_is_light) ? ui_color_black : ui_color_ex_light;
    Vec4 link = front;

    if      (internal__is_hit()) { link = (ui_is_light) ? ui_color_ex_dark : ui_color_white; }
    else if (internal__is_hot()) { link = (ui_is_light) ? ui_color_ex_dark : ui_color_white; }

    fnt.color = shadow;
    draw_text(fnt, x, y-offset, text.c_str());
    fnt.color = front;
    draw_text(fnt, x, y, text.c_str());

    x += (get_text_width(fnt, text.c_str()) * get_font_draw_scale());

    set_draw_color(shadow);
    draw_line(x, (y+2.0f)-offset, x+ww, (y+2.0f)-offset);
    set_draw_color(link);
    draw_line(x, y+2.0f, x+ww, y+2.0f);

    fnt.color = shadow;
    draw_text(fnt, x, y-offset, _link);
    fnt.color = link;
    draw_text(fnt, x, y, _link);

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    ++ui_current_id;
}

STDDEF void do_text_box (float _w, float _h, UI_Flag _flags, std::string& _text, const char* _default, UI_Align _halign)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    // Cache the text box's flags so they are easily accessible.
    _flags |= ui_panels.peek().flags;
    bool locked = (_flags & UI_LOCKED);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2 cur = internal__get_relative_cursor(ui_panels.peek());

    // Locked text boxes cannot be interacted with.
    if (!locked) {
        if (internal__handle_widget(cur.x, cur.y, _w, _h, locked)) {
            // If the cursor was blinking before then reset the timer.
            if (ui_cursor_blink_timer) {
                SDL_RemoveTimer(ui_cursor_blink_timer);
                ui_cursor_blink_timer = NULL;
            }

            // Start the blinking of the cursor.
            ui_cursor_visible = true;
            ui_cursor_blink_timer = SDL_AddTimer(UI_CURSOR_BLINK_INTERVAL, internal__cursor_blink_callback, NULL);
            if (!ui_cursor_blink_timer) {
                LOG_ERROR(ERR_MIN, "Failed to setup cursor blink timer! (%s)", SDL_GetError());
            }

            ui_text_box_cursor = _text.length();
            ui_active_text_box = ui_current_id;

            SDL_StartTextInput();
        }
    } else {
        if (ui_active_text_box == ui_current_id) {
            deselect_active_text_box(_text, _default);
        }
    }

    // If we are the active text box and the mouse was pressed this update
    // and we're not hit then that means the press was outside of us and
    // therefore we need to become deselected and can no longer be active.
    if (ui_active_text_box == ui_current_id && internal__is_ui_mouse_down() && !internal__is_hit()) {
        deselect_active_text_box(_text, _default);
    }
    // If the right mouse button is pressed then we just always deselect.
    if (ui_active_text_box == ui_current_id && internal__is_ui_mouse_r_down()) {
        deselect_active_text_box(_text, _default);
    }

    // Handle setting the application's cursor to the correct graphic.
    if (internal__is_hot()) {
        ui_hot_text_box = ui_current_id;
        set_cursor(CURSOR_BEAM);
    } else {
        if (ui_hot_text_box == ui_current_id) { ui_hot_text_box = UI_INVALID_ID; }

        // We have this check so that we can know it's okay to set
        // the cursor back to arrow as no text box elements are hot.
        if (ui_hot_text_box == UI_INVALID_ID && ui_hot_hyperlink == UI_INVALID_ID) {
            // NOTE: Kind of hacky to put this here, but it prevents issues with
            // the flickering of the cursor due to text boxes. Could be cleaned.
            if (are_there_any_level_tabs()) {
                if (mouse_inside_level_editor_viewport() && is_window_focused("WINMAIN")) {
                    switch (level_editor.tool_type) {
                    case (TOOL_TYPE_BRUSH):  { set_cursor(CURSOR_BRUSH);  } break;
                    case (TOOL_TYPE_FILL):   { set_cursor(CURSOR_FILL);   } break;
                    case (TOOL_TYPE_SELECT): { set_cursor(CURSOR_SELECT); } break;
                    }
                } else {
                    set_cursor(CURSOR_ARROW);
                }
            } else {
                set_cursor(CURSOR_ARROW);
            }
        }
    }

    if (!locked && ui_make_next_text_box_active && get_render_target()->id == ui_text_box_tab_window_id) {
        ui_text_box_cursor = std::string::npos;
        ui_active_text_box = ui_current_id;

        ui_make_next_text_box_active = false;
        ui_text_box_tab_window_id = 0;
    }

    Vec4 front   = (ui_is_light) ? ui_color_black : ui_color_ex_light;
    Vec4 shadow  = (ui_is_light) ? ui_color_ex_light : ui_color_black;
    Vec4 outline = ui_color_dark;
    Vec4 back    = ui_color_med_dark;

    if (locked) {
        outline = ui_color_med_dark;
        back = ui_color_medium;

        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    set_draw_color(outline); // Draw the text box's outline quad.
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);
    set_draw_color(back); // Draw the text box's background quad.
    fill_quad(cur.x+1.0f, cur.y+1.0f, cur.x+_w-1.0f, cur.y+_h-1.0f);

    constexpr float X_PAD = 5.0f;
    constexpr float Y_PAD = 2.0f;

    float x = cur.x+(X_PAD     );
    float y = cur.y+(Y_PAD     );
    float w = _w   -(X_PAD*2.0f);
    float h = _h   -(Y_PAD*2.0f);

    // Handle text input events if we are the active text box.
    if (ui_active_text_box == ui_current_id) {
        // Make sure that the cursor is in the bounds of the string.
        if (ui_text_box_cursor > _text.length()) {
            ui_text_box_cursor = _text.length();
        }

        if (get_render_target()->focus) {
            for (auto& text_event: ui_text_events) {
                switch (text_event.type) {
                case (UI_TEXT_EVENT_TEXT): {
                    char c = text_event.text;

                    if ((_flags&UI_ALPHANUM)   && !          isalnum   (c)) { break; }
                    if ((_flags&UI_ALPHABETIC) && !          isalpha   (c)) { break; }
                    if ((_flags&UI_NUMERIC)    && !          isdigit   (c)) { break; }
                    if ((_flags&UI_FILEPATH)   && !internal__isfilepath(c)) { break; }

                    // Clear out the default text and enter what the user actually wants.
                    if ((_default) && _text == _default) {
                        ui_text_box_cursor = 0;
                        _text.clear();
                    }

                    auto pos = _text.begin()+(ui_text_box_cursor++);
                    _text.insert(pos, c);

                    ui_text_event_happened = true;
                } break;
                case (UI_TEXT_EVENT_KEY): {
                    switch (text_event.key)
                    {
                    case (SDLK_TAB): {
                        if (!ui_tab_handled) {
                            ui_make_next_text_box_active = true;
                            ui_text_box_tab_window_id = get_render_target()->id;
                            ui_tab_handled = true;
                            ui_text_event_happened = true;
                        }
                    } break;
                    case (SDLK_LEFT): {
                        if (ui_text_box_cursor > 0) {
                            --ui_text_box_cursor;
                            ui_text_event_happened = true;
                        }
                    } break;
                    case (SDLK_RIGHT): {
                        if (ui_text_box_cursor < _text.length()) {
                            ++ui_text_box_cursor;
                            ui_text_event_happened = true;
                        }
                    } break;
                    case (SDLK_UP): {
                        if (_flags&UI_NUMERIC) {
                            if (atoi(_text.c_str()) < INT_MAX) {
                                _text = std::to_string(atoi(_text.c_str())+1);
                                ui_text_box_cursor = _text.length();
                                ui_text_event_happened = true;
                            }
                        }
                    } break;
                    case (SDLK_DOWN): {
                        if (_flags&UI_NUMERIC) {
                            if (atoi(_text.c_str()) > 0) {
                                _text = std::to_string(atoi(_text.c_str())-1);
                                ui_text_box_cursor = _text.length();
                                ui_text_event_happened = true;
                            }
                        }
                    } break;
                    case (SDLK_HOME): {
                        ui_text_box_cursor = 0;
                        ui_text_event_happened = true;
                    } break;
                    case (SDLK_END): {
                        ui_text_box_cursor = _text.length();
                        ui_text_event_happened = true;
                    } break;
                    case (SDLK_BACKSPACE): {
                        if (ui_text_box_cursor != 0) {
                            _text.erase(--ui_text_box_cursor, 1);
                            ui_text_event_happened = true;
                        }
                    } break;
                    case (SDLK_DELETE): {
                        if (ui_text_box_cursor < _text.length()) {
                            _text.erase(ui_text_box_cursor, 1);
                            ui_text_event_happened = true;
                        }
                    } break;
                    case (SDLK_RETURN): {
                        deselect_active_text_box(_text, _default);
                    } break;

                    case (SDLK_v): {
                        if (SDL_GetModState()&KMOD_CTRL) {
                            if (SDL_HasClipboardText()) {
                                char* text = SDL_GetClipboardText();
                                if (text) {
                                    defer { SDL_free(text); }; // Docs say we need to free!

                                    bool add_text = true;
                                    std::string t(text);

                                    for (auto c: t) {
                                        if ((_flags&UI_ALPHANUM)   && !          isalnum   (c)) { add_text = false; break; }
                                        if ((_flags&UI_ALPHABETIC) && !          isalpha   (c)) { add_text = false; break; }
                                        if ((_flags&UI_NUMERIC)    && !          isdigit   (c)) { add_text = false; break; }
                                        if ((_flags&UI_FILEPATH)   && !internal__isfilepath(c)) { add_text = false; break; }
                                    }

                                    if (add_text) {
                                        // Clear out the default text and enter what the user actually wants.
                                        if ((_default) && _text == _default) {
                                            ui_text_box_cursor = 0;
                                            _text.clear();
                                        }

                                        _text.insert(ui_text_box_cursor, t);
                                        ui_text_box_cursor += t.length();
                                    }
                                }
                            }
                        }
                    } break;
                    }
                } break;
                }
            }

            ui_text_events.clear();

            // Reset the cursor blink interval.
            if (ui_text_event_happened) {
                // If the cursor was blinking before then reset the timer.
                if (ui_cursor_blink_timer) {
                    SDL_RemoveTimer(ui_cursor_blink_timer);
                    ui_cursor_blink_timer = NULL;
                }

                // Start the blinking of the cursor.
                ui_cursor_visible = true;
                ui_cursor_blink_timer = SDL_AddTimer(UI_CURSOR_BLINK_INTERVAL, internal__cursor_blink_callback, NULL);
                if (!ui_cursor_blink_timer) {
                    LOG_ERROR(ERR_MIN, "Failed to setup cursor blink timer! (%s)", SDL_GetError());
                }
            }
        }

        // Cursor should always be at the end of the default text.
        if ((_default) && _text == _default) {
            ui_text_box_cursor = _text.length();
        }
    }

    // We scissor the contents to avoid text overspill.
    begin_scissor(x, y, w, h);

    // Calculate the position of the text and draw it.
    float tx = x;
    float ty = y;
    float tw = get_text_width(fnt, _text.c_str()) * get_font_draw_scale();
    float th = get_text_height(fnt, _text.c_str()) * get_font_draw_scale();

    if (th == 0.0f) { th = h; }

    internal__align_text(_halign, UI_ALIGN_CENTER, tx, ty, tw, th, w, h);

    float x_off = 0.0f;
    float y_off = (ui_is_light) ? -1.0f : 1.0f;

    // Adjust text position/offsetrun based on the current cursor.
    if (ui_active_text_box == ui_current_id) {
        if (_halign == UI_ALIGN_LEFT) {
            std::string sub(_text.substr(0, ui_text_box_cursor));
            float cursor_x = tx+(get_text_width(fnt, sub.c_str()) * get_font_draw_scale());
            // @Incomplete: Need to figure out the offset...
            if (cursor_x > x+w) {
                float diff = abs(w - (get_text_width(fnt, sub.c_str())*get_font_draw_scale()));
                x_off = -diff;
            }
        } else {
            std::string sub(_text.substr(0, ui_text_box_cursor));
            float cursor_x = tx+(get_text_width(fnt, sub.c_str()) * get_font_draw_scale());
            if (cursor_x < x) {
                x_off = (x - cursor_x);
            }
        }
    }

    fnt.color = shadow;
    draw_text(fnt, tx+x_off, ty-y_off, _text.c_str());
    fnt.color = front;
    draw_text(fnt, tx+x_off, ty, _text.c_str());

    end_scissor();

    // If we're active then draw the text box cursor as well.
    if (ui_active_text_box == ui_current_id && ui_cursor_visible) {
        begin_scissor(x-1.0f, y-1.0f, w+2.0f, h+2.0f);

        std::string sub(_text.substr(0, ui_text_box_cursor));

        float xo = (get_text_width(fnt, sub.c_str()) * get_font_draw_scale());
        float yo = (h-th)/2.0f; // Center the cursor vertically.

        // Just looks nicer...
        if ((ui_text_box_cursor != 0 && _text.length()) || (!_text.length())) {
            xo += 1.0f;
        }

        set_draw_color((ui_is_light) ? ui_color_black : ui_color_ex_light);
        draw_line(tx+xo+x_off, y+yo, tx+xo+x_off, y+yo+th);

        end_scissor();
    }

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    ++ui_current_id;
}

STDDEF void do_text_box_labeled (float _w, float _h, UI_Flag _flags, std::string& _text, float _label_w, const char* _label, const char* _default, UI_Align _halign)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    float lw = _label_w;
    float tw = _w - lw;

    if (tw < 0.0f) { return; } // Won't draw anything!

    // Cache this stuff because we are going to temporarily change it.
    Vec2 cursor = *ui_panels.peek().cursor;
    UI_Dir dir = ui_panels.peek().cursor_dir;

    set_panel_cursor_dir(UI_DIR_RIGHT);
    do_label(UI_ALIGN_LEFT, UI_ALIGN_CENTER, lw, _h, _label);

    set_panel_cursor_dir(dir);
    do_text_box(tw, _h, _flags, _text, _default, _halign);

    // Reset the X location of the cursor for the caller.
    if (dir == UI_DIR_UP || dir == UI_DIR_DOWN) {
        ui_panels.peek().cursor->x = cursor.x;
    }
}

STDDEF void do_hotkey_rebind_main (float _w, float _h, UI_Flag _flags, Key_Binding& _kb)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    // Cache the rebind's flags so they are easily accessible.
    _flags |= ui_panels.peek().flags;
    bool locked = (_flags & UI_LOCKED);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2 cur = internal__get_relative_cursor(ui_panels.peek());

    // Locked hotkey rebinds cannot be interacted with.
    if (!locked) {
        if (internal__handle_widget(cur.x, cur.y, _w, _h, locked)) {
            ui_active_hotkey_rebind = ui_current_id;
        }
    } else {
        if (ui_active_hotkey_rebind == ui_current_id) {
            deselect_active_hotkey_rebind();
        }
    }

    // If we are the active KB rebind and the mouse was pressed this update
    // and we're not hit then that means the press was outside of us and
    // therefore we need to become deselected and can no longer be active.
    if (ui_active_hotkey_rebind == ui_current_id && internal__is_ui_mouse_down() && !internal__is_hit()) {
        deselect_active_hotkey_rebind();
    }
    // If the right mouse button is pressed then we just always deselect.
    if (ui_active_hotkey_rebind == ui_current_id && internal__is_ui_mouse_r_down()) {
        deselect_active_hotkey_rebind();
    }

    Vec4 front   = (ui_is_light) ? ui_color_black : ui_color_ex_light;
    Vec4 shadow  = (ui_is_light) ? ui_color_ex_light : ui_color_black;
    Vec4 outline = ui_color_dark;
    Vec4 back    = ui_color_med_dark;

    if (locked) {
        outline = ui_color_med_dark;
        back = ui_color_medium;

        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    set_draw_color(outline); // Draw the rebind's outline quad.
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);
    set_draw_color(back); // Draw the rebind's background quad.
    fill_quad(cur.x+1.0f, cur.y+1.0f, cur.x+_w-1.0f, cur.y+_h-1.0f);

    constexpr float X_PAD = 5.0f;
    constexpr float Y_PAD = 2.0f;

    float x = cur.x+(X_PAD     );
    float y = cur.y+(Y_PAD     );
    float w = _w   -(X_PAD*2.0f);
    float h = _h   -(Y_PAD*2.0f);

    // If we're active then we check if the user has entered a new binding.
    if (ui_active_hotkey_rebind == ui_current_id) {
        if (main_event.type == SDL_KEYDOWN) {
            SDL_Keycode k = main_event.key.keysym.sym;
            // We do not want the key binding to be set when just the mod is pressed!
            if (k != SDLK_LCTRL  && k != SDLK_RCTRL  &&
                k != SDLK_LALT   && k != SDLK_RALT   &&
                k != SDLK_MODE                       &&
                k != SDLK_RSHIFT && k != SDLK_LSHIFT &&
                k != SDLK_LGUI   && k != SDLK_RGUI) {

                _kb.code = main_event.key.keysym.sym;

                // Remove CAPSLOCK and NUMLOCK because we don't care about them at all.
                _kb.mod = CAST(int, (SDL_GetModState() & ~(KMOD_NUM|KMOD_CAPS)));

                // We do not care whether the right or left variants have been pressed.
                if (_kb.mod&KMOD_LCTRL  || _kb.mod&KMOD_RCTRL)  { _kb.mod |= KMOD_CTRL;  }
                if (_kb.mod&KMOD_LALT   || _kb.mod&KMOD_RALT)   { _kb.mod |= KMOD_ALT;   }
                if (_kb.mod&KMOD_LSHIFT || _kb.mod&KMOD_RSHIFT) { _kb.mod |= KMOD_SHIFT; }
                if (_kb.mod&KMOD_LGUI   || _kb.mod&KMOD_RGUI)   { _kb.mod |= KMOD_GUI;   }

                deselect_active_hotkey_rebind();
            }
        }
    }

    // We scissor the contents to avoid text overspill.
    begin_scissor(x, y, w, h);

    // The text to display depends on if we're active or not.
    std::string text;
    if (ui_active_hotkey_rebind == ui_current_id) {
        text = "Enter new key binding...";
    } else {
        text = get_key_binding_main_string(_kb);
    }

    // Calculate the position of the text and draw it
    float tx = x;
    float ty = y;
    float tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
    float th = get_text_height(fnt, text.c_str()) * get_font_draw_scale();

    internal__align_text(UI_ALIGN_RIGHT, UI_ALIGN_CENTER, tx, ty, tw, th, w, h);

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    fnt.color = shadow;
    draw_text(fnt, tx, ty-offset, text.c_str());
    fnt.color = front;
    draw_text(fnt, tx, ty, text.c_str());

    end_scissor();

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    ++ui_current_id;
}

STDDEF void do_hotkey_rebind_alt (float _w, float _h, UI_Flag _flags, Key_Binding& _kb)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_font);

    // Cache the rebind's flags so they are easily accessible.
    _flags |= ui_panels.peek().flags;
    bool locked = (_flags & UI_LOCKED);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Font& fnt = *ui_font;
    Vec2 cur = internal__get_relative_cursor(ui_panels.peek());

    // Locked hotkey rebinds cannot be interacted with.
    if (!locked) {
        if (internal__handle_widget(cur.x, cur.y, _w, _h, locked)) {
            ui_active_hotkey_rebind = ui_current_id;
        }
    } else {
        if (ui_active_hotkey_rebind == ui_current_id) {
            deselect_active_hotkey_rebind();
        }
    }

    // If we are the active KB rebind and the mouse was pressed this update
    // and we're not hit then that means the press was outside of us and
    // therefore we need to become deselected and can no longer be active.
    if (ui_active_hotkey_rebind == ui_current_id && internal__is_ui_mouse_down() && !internal__is_hit()) {
        deselect_active_hotkey_rebind();
    }
    // If the right mouse button is pressed then we just always deselect.
    if (ui_active_hotkey_rebind == ui_current_id && internal__is_ui_mouse_r_down()) {
        deselect_active_hotkey_rebind();
    }

    Vec4 front   = (ui_is_light) ? ui_color_black : ui_color_ex_light;
    Vec4 shadow  = (ui_is_light) ? ui_color_ex_light : ui_color_black;
    Vec4 outline = ui_color_dark;
    Vec4 back    = ui_color_med_dark;

    if (locked) {
        outline = ui_color_med_dark;
        back = ui_color_medium;

        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    set_draw_color(outline); // Draw the rebind's outline quad.
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);
    set_draw_color(back); // Draw the rebind's background quad.
    fill_quad(cur.x+1.0f, cur.y+1.0f, cur.x+_w-1.0f, cur.y+_h-1.0f);

    constexpr float X_PAD = 5.0f;
    constexpr float Y_PAD = 2.0f;

    float x = cur.x+(X_PAD     );
    float y = cur.y+(Y_PAD     );
    float w = _w   -(X_PAD*2.0f);
    float h = _h   -(Y_PAD*2.0f);

    // If we're active then we check if the user has entered a new binding.
    if (ui_active_hotkey_rebind == ui_current_id) {
        if (main_event.type == SDL_KEYDOWN) {
            SDL_Keycode k = main_event.key.keysym.sym;
            // We do not want the key binding to be set when just the mod is pressed!
            if (k != SDLK_LCTRL  && k != SDLK_RCTRL  &&
                k != SDLK_LALT   && k != SDLK_RALT   &&
                k != SDLK_MODE                       &&
                k != SDLK_RSHIFT && k != SDLK_LSHIFT &&
                k != SDLK_LGUI   && k != SDLK_RGUI) {

                _kb.alt_code = main_event.key.keysym.sym;

                // Remove CAPSLOCK and NUMLOCK because we don't care about them at all.
                _kb.alt_mod = CAST(int, (SDL_GetModState() & ~(KMOD_NUM|KMOD_CAPS)));

                // We do not care whether the right or left variants have been pressed.
                if (_kb.alt_mod&KMOD_LCTRL  || _kb.alt_mod&KMOD_RCTRL)  { _kb.alt_mod |= KMOD_CTRL;  }
                if (_kb.alt_mod&KMOD_LALT   || _kb.alt_mod&KMOD_RALT)   { _kb.alt_mod |= KMOD_ALT;   }
                if (_kb.alt_mod&KMOD_LSHIFT || _kb.alt_mod&KMOD_RSHIFT) { _kb.alt_mod |= KMOD_SHIFT; }
                if (_kb.alt_mod&KMOD_LGUI   || _kb.alt_mod&KMOD_RGUI)   { _kb.alt_mod |= KMOD_GUI;   }

                deselect_active_hotkey_rebind();

                _kb.has_alt = true;
            }
        }
    }

    // We scissor the contents to avoid text overspill.
    begin_scissor(x, y, w, h);

    // The text to display depends on if we're active or not.
    std::string text;
    if (ui_active_hotkey_rebind == ui_current_id) {
        text = "Enter new key binding...";
    } else {
        text = get_key_binding_alt_string(_kb);
    }

    // Calculate the position of the text and draw it
    float tx = x;
    float ty = y;
    float tw = get_text_width(fnt, text.c_str()) * get_font_draw_scale();
    float th = get_text_height(fnt, text.c_str()) * get_font_draw_scale();

    internal__align_text(UI_ALIGN_RIGHT, UI_ALIGN_CENTER, tx, ty, tw, th, w, h);

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    fnt.color = shadow;
    draw_text(fnt, tx, ty-offset, text.c_str());
    fnt.color = front;
    draw_text(fnt, tx, ty, text.c_str());

    end_scissor();

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    ++ui_current_id;
}

STDDEF void do_icon (float _w, float _h, Texture& _tex, const Quad* _clip)
{
    UI_ID flags = ui_panels.peek().flags;

    // Cache the image's flags so they are easily accessible.
    bool inactive = (flags & UI_INACTIVE);
    bool locked = (flags & UI_LOCKED);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Vec2 cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid image overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    Vec4 front  = (ui_is_light) ? Vec4 { 0.4f,0.4f,0.4f,1.0f } : Vec4 { 0.73f,0.73f,0.73f,1.0f };
    Vec4 shadow = (ui_is_light) ? Vec4 { 0.9f,0.9f,0.9f,1.0f } : Vec4 { 0.16f,0.16f,0.16f,1.0f };

    if (locked || inactive) {
        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    UI_Dir dir = ui_panels.peek().cursor_dir;

    // Center the image within the space.
    float x = roundf(cur.x + (_w / 2.0f) + ((dir == UI_DIR_LEFT) ? 1.0f : 0.0f));
    float y = roundf(cur.y + (_h / 2.0f) + ((dir == UI_DIR_UP)   ? 1.0f : 0.0f));

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    _tex.color = shadow;
    draw_texture(_tex, x, y-offset, _clip);
    _tex.color = front;
    draw_texture(_tex, x, y, _clip);

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);
}

FILDEF void do_quad (float _w, float _h, Vec4 _color)
{
    UI_ID flags = ui_panels.peek().flags;

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Vec2 cur = internal__get_relative_cursor(ui_panels.peek());

    // Cache the quad's flags so they are easily accessible.
    bool inactive = (flags & UI_INACTIVE);
    bool locked = (flags & UI_LOCKED);

    if (locked || inactive) { _color.a = 0.5f; }

    set_draw_color(_color);
    fill_quad(cur.x, cur.y, cur.x+_w, cur.y+_h);

    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);
}

FILDEF void do_separator (float _size)
{
    float w = (ui_panels.peek().cursor_dir == UI_DIR_RIGHT || ui_panels.peek().cursor_dir == UI_DIR_LEFT) ? 0.0f : _size;
    float h = (ui_panels.peek().cursor_dir == UI_DIR_UP    || ui_panels.peek().cursor_dir == UI_DIR_DOWN) ? 0.0f : _size;

    internal__advance_ui_cursor_start(ui_panels.peek(), 1.0f, 1.0f);
    internal__draw_separator(internal__get_relative_cursor(ui_panels.peek()), ui_panels.peek().cursor_dir, w, h, ui_color_med_dark);
    internal__advance_ui_cursor_end(ui_panels.peek(), 1.0f, 1.0f);
}

FILDEF void do_scrollbar (Quad _bounds, float _content_height, float& _scroll_offset)
{
    do_scrollbar(_bounds.x, _bounds.y, _bounds.w, _bounds.h, _content_height, _scroll_offset);
}

STDDEF void do_scrollbar (float _x, float _y, float _w, float _h, float _content_height, float& _scroll_offset)
{
    // --_content_height;

    // Allows scrollbars to be outside the panel they are scrolling.
    set_viewport(0.0f, 0.0f, get_render_target_w(), get_render_target_h());
    defer { set_viewport(ui_panels.peek().viewport); };

    _x += ui_panels.peek().viewport.x;
    _y += ui_panels.peek().viewport.y;

    // We scissor the contents to avoid any overspill.
    begin_scissor(_x, _y, _w, _h);
    defer { end_scissor(); };

    constexpr float PAD = 1.0f;

    float x = _x +  PAD;
    float y = _y +  PAD;
    float w = _w - (PAD*2);
    float h = _h;

    // Determine the percentage of content visible.
    float percent_visible = get_panel_h() / _content_height;
    if (percent_visible > 1.0f) { percent_visible = 1.0f; }

    // Represent this amount in the scrollbar.
    h = (h*percent_visible) - (PAD*2);

    // Ensure the normalized scroll offset is in bounds.
    float ndc_h = (_h-h-(PAD*2)) / (_h-(PAD*2));
    _scroll_offset = std::clamp(_scroll_offset, 0.0f, ndc_h);

    // Convert the normalized scroll offset into pixel offset.
    y += _scroll_offset * (_h-(PAD*2));

    internal__handle_widget(x, y, w, h, false);

    // Adjust the offset by however much the mouse has moved.
    if (internal__is_hit()) {
        _scroll_offset += (ui_mouse_relative.y / (_h-(PAD*2)));
        _scroll_offset = std::clamp(_scroll_offset, 0.0f, ndc_h);
    }

    set_draw_color(ui_color_ex_dark);
    fill_quad(_x, _y, _x+_w, _y+_h);

    Vec4 color = ui_color_med_dark;

    if      (internal__is_hit()) { color = ui_color_med_light; }
    else if (internal__is_hot()) { color = ui_color_medium;    }

    set_draw_color(color);
    fill_quad(x, y, x+w, y+h);

    // Draw the three lines on the scrollbar (avoid overspill).
    //
    // We do not bother though if it's really small because then
    // adding these lines just looks sort of gross and cluttered.
    if (h > 10) {
        constexpr float LINE_GAP = 2.0f;

        begin_scissor(x, y, w, h);
        set_draw_color(ui_color_ex_dark);

        float y1 = y+(h/2.0f) - LINE_GAP;
        float y2 = y+(h/2.0f);
        float y3 = y+(h/2.0f) + LINE_GAP;

        draw_line(x+1.0f, y1, x+w-1.0f, y1);
        draw_line(x+1.0f, y2, x+w-1.0f, y2);
        draw_line(x+1.0f, y3, x+w-1.0f, y3);

        end_scissor();
    }

    // Set the panels relative offset to apply the actual scroll.
    //
    // We do this extra check stuff because towards the end of
    // scrolling there can be offset issues which result in
    // moving past the content bounds so we just perform manual
    // adjustment of the scroll in order to correct this issue.
    float final_offset = roundf(_content_height * _scroll_offset);
    float resulting_height = _content_height - final_offset;
    if (_scroll_offset != 0.0f && resulting_height < get_panel_h()) {
        float difference = get_panel_h() - resulting_height;
        ui_panels.peek().relative_offset.y -= (final_offset - difference);
    } else {
        ui_panels.peek().relative_offset.y -= roundf(_content_height * _scroll_offset);
    }

    ++ui_current_id;
}

STDDEF void begin_panel_gradient (float _x, float _y, float _w, float _h, UI_Flag _flags, Vec4 _cl, Vec4 _cr)
{
    Panel panel;

    // The method of adding a new panel varies depending on whether the panel
    // is a child to an existing panel or if it is a lone panel in the window.
    panel.absolute_bounds = { _x, _y, _w, _h };
    if (ui_panels.count > 0) {
        const Quad& p_ab = ui_panels.peek().absolute_bounds;
        const Quad& p_v  = ui_panels.peek().viewport;
        const Vec2& p_ro = ui_panels.peek().relative_offset;

        Quad& c_ab = panel.absolute_bounds;
        Quad& c_v  = panel.viewport;
        Vec2& c_ro = panel.relative_offset;

        c_ab.x += p_ab.x + p_ro.x;
        c_ab.y += p_ab.y + p_ro.y;

        c_v = c_ab;

        // We also clip the panel's viewport to be inside of the
        // parent panel to avoid issues with overlapping/spill.
        float dx = c_v.x - p_v.x;
        float dy = c_v.y - p_v.y;

        if (c_v.x < p_v.x) { c_v.x = p_v.x; c_v.w -= roundf(abs(dx)); dx = c_v.x - p_v.x; }
        if (c_v.y < p_v.y) { c_v.y = p_v.y; c_v.h -= roundf(abs(dy)); dy = c_v.y - p_v.y; }

        if (c_v.x+c_v.w > p_v.x+p_v.w) { c_v.w = p_v.w - roundf(abs(dx)); }
        if (c_v.y+c_v.h > p_v.y+p_v.h) { c_v.h = p_v.h - roundf(abs(dy)); }

        if (c_v.w < 0.0f) { c_v.w = 0.0f; }
        if (c_v.h < 0.0f) { c_v.h = 0.0f; }

        // And determine the panel's offset to its viewport.
        c_ro.x = c_ab.x - c_v.x;
        c_ro.y = c_ab.y - c_v.y;

        // Inherit the parent panel's flags.
        panel.flags = _flags | ui_panels.peek().flags;
    } else {
        panel.viewport = panel.absolute_bounds;
        panel.relative_offset = { 0.0f, 0.0f };
        panel.flags = _flags;
    }

    panel.cursor = NULL;
    panel.cursor_dir = UI_DIR_RIGHT;
    panel.cursor_advance_enabled = true;

    set_viewport(panel.viewport);
    ui_panels.push(panel);

    begin_polygon();
    put_vertex(0.0f,             panel.viewport.h, _cl); // BL
    put_vertex(0.0f,             0.0f,             _cl); // TL
    put_vertex(panel.viewport.w, panel.viewport.h, _cr); // BR
    put_vertex(panel.viewport.w, 0.0f,             _cr); // TR
    end_polygon();
}
FILDEF void begin_panel_gradient (Quad _bounds, UI_Flag _flags, Vec4 _cl, Vec4 _cr)
{
    begin_panel_gradient(_bounds.x, _bounds.y, _bounds.w, _bounds.h, _flags, _cl, _cr);
}

STDDEF bool begin_click_panel_gradient (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _info)
{
    Panel& parent = ui_panels.peek();

    Vec2 rcur = internal__get_relative_cursor(parent);
    Vec2 cur = internal__get_cursor(parent);

    // Cache the panel's flags so they are easily accessible.
    bool locked    = (_flags & UI_LOCKED);
    bool highlight = (_flags & UI_HIGHLIGHT);

    bool result = internal__handle_widget(rcur.x, rcur.y, _w, _h, locked);
    if (result && _action) { _action(); } // Make sure action is valid!

    Vec4 bl = ui_color_medium;
    Vec4 br = ui_color_medium;

    if      (locked)             { bl = ui_color_med_dark, br = ui_color_med_dark; }
    else if (internal__is_hit()) { bl = ui_color_dark;      }
    else if (internal__is_hot()) { bl = ui_color_med_light; }

    begin_panel_gradient(cur.x, cur.y, _w, _h, _flags, bl,br);
    internal__advance_ui_cursor_start(parent, _w, _h);

    if (highlight && !internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        set_draw_color(color);
        fill_quad(0.0f, 0.0f, get_viewport().w, get_viewport().h);
    }
    if (highlight && internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        begin_polygon();
        put_vertex(0.0f,             get_viewport().h, Vec4 { 0,0,0,0 }); // BL
        put_vertex(0.0f,             0.0f,             Vec4 { 0,0,0,0 }); // TL
        put_vertex(get_viewport().w, get_viewport().h,            color); // BR
        put_vertex(get_viewport().w, 0.0f,                        color); // TR
        end_polygon();
    }

    Vec4 separator_color = (locked) ? ui_color_dark : ui_color_med_dark;
    Vec2 cursor = ui_panels.peek().relative_offset;

    internal__draw_separator(cursor, parent.cursor_dir, _w, _h, separator_color);
    internal__advance_ui_cursor_end(parent, _w, _h);

    // If we are currently hot then we push our info to the status bar.
    if (!locked && _info && internal__is_hot()) { push_status_bar_message(_info); }

    ++ui_current_id;

    return result;
}

STDDEF bool do_button_img_gradient (UI_Action _action, float _w, float _h, UI_Flag _flags, const Quad* _clip, const char* _info, const char* _kb, const char* _name)
{
    // Make sure that the necessary components are assigned.
    ASSERT(ui_texture);

    _flags |= ui_panels.peek().flags;

    // Cache the button's flags so they are easily accessible.
    bool inactive  = (_flags & UI_INACTIVE);
    bool locked    = (_flags & UI_LOCKED);
    bool highlight = (_flags & UI_HIGHLIGHT);

    internal__advance_ui_cursor_start(ui_panels.peek(), _w, _h);

    Texture& tex = *ui_texture;
    Vec2     cur = internal__get_relative_cursor(ui_panels.peek());

    // We scissor the contents to avoid image overspill.
    begin_scissor(cur.x, cur.y, _w, _h);
    defer { end_scissor(); };

    // Locked buttons cannot be interacted with.
    bool result = internal__handle_widget(cur.x, cur.y, _w, _h, locked);
    if (result && _action) { _action(); } // Make sure action is valid!

    Vec4 front  = (ui_is_light) ? Vec4 { 0.4f,0.4f,0.4f,1.0f } : Vec4 { 0.73f,0.73f,0.73f,1.0f };
    Vec4 bl     =  ui_color_medium;
    Vec4 br     =  ui_color_medium;
    Vec4 shadow = (ui_is_light) ? Vec4 { 0.9f,0.9f,0.9f,1.0f } : Vec4 { 0.16f,0.16f,0.16f,1.0f };

    if      (locked)             { br = ui_color_med_dark, bl = ui_color_med_dark; }
    else if (internal__is_hit()) { br = ui_color_dark;      }
    else if (internal__is_hot()) { br = ui_color_med_light; }

    if (locked || inactive) {
        shadow.a = 0.5f;
        front.a = 0.5f;
    }

    // Draw the button's background quad.
    begin_polygon();
    put_vertex(cur.x,    cur.y+_h, bl); // BL
    put_vertex(cur.x,    cur.y,    bl); // TL
    put_vertex(cur.x+_w, cur.y+_h, br); // BR
    put_vertex(cur.x+_w, cur.y,    br); // TR
    end_polygon();

    if (highlight && !internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        set_draw_color(color);
        fill_quad(0.0f, 0.0f, get_viewport().w, get_viewport().h);
    }
    if (highlight && internal__is_hit()) {
        Vec4 color = ui_color_med_light; color.a = 0.66f;
        begin_polygon();
        put_vertex(cur.x,    cur.y+_h,            color); // BL
        put_vertex(cur.x,    cur.y,               color); // TL
        put_vertex(cur.x+_w, cur.y+_h, Vec4 { 0,0,0,0 }); // BR
        put_vertex(cur.x+_w, cur.y,    Vec4 { 0,0,0,0 }); // TR
        end_polygon();
    }

    // The ((_w)-1.0f) and ((_h)-1.0f) are used to ensure the separator
    // does not mess with the centering of the image based on direction.

    UI_Dir dir = ui_panels.peek().cursor_dir;

    float w = (dir == UI_DIR_RIGHT || dir == UI_DIR_LEFT) ? ((_w)-1.0f) : (_w);
    float h = (dir == UI_DIR_UP    || dir == UI_DIR_DOWN) ? ((_h)-1.0f) : (_h);

    // Center the image within the button.
    float x = roundf(cur.x + (w / 2.0f) + ((dir == UI_DIR_LEFT) ? 1.0f : 0.0f));
    float y = roundf(cur.y + (h / 2.0f) + ((dir == UI_DIR_UP)   ? 1.0f : 0.0f));

    float offset = (ui_is_light) ? -1.0f : 1.0f;

    Flip flip = FLIP_NONE;

    if (_flags&UI_FLIP_HORZ) { flip |= FLIP_HORZ; }
    if (_flags&UI_FLIP_VERT) { flip |= FLIP_VERT; }

    tex.color = shadow;
    draw_texture(tex, x, y-offset, flip, _clip);
    tex.color = front;
    draw_texture(tex, x, y, flip, _clip);

    internal__draw_separator(internal__get_relative_cursor(ui_panels.peek()), ui_panels.peek().cursor_dir, _w, _h, ui_color_med_dark);
    internal__advance_ui_cursor_end(ui_panels.peek(), _w, _h);

    // If we are currently hot then we push our info to the status bar.
    if (!locked && _info && internal__is_hot()) {
        std::string kb_info;
        if (_kb) {
            kb_info = format_string("(%s)", get_key_binding_main_string(_kb).c_str());
            if (get_key_binding(_kb).alt_code && get_key_binding(_kb).alt_mod) {
                kb_info += format_string(" or (%s)", get_key_binding_alt_string(_kb).c_str());
            }
        }
        std::string info((kb_info.empty()) ? _info : format_string("%s %s", kb_info.c_str(), _info));
        push_status_bar_message(info.c_str());
    }
    // If we are currently hot then set the tooltip.
    if (!locked && _name && internal__is_hot()) {
        set_current_tooltip(_name);
    }

    ++ui_current_id;

    return result;
}
