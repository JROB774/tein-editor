FILDEF bool internal__mouse_inside_map_editor_viewport ()
{
    Vec2 m = map_editor.mouse;
    Quad v = map_editor.viewport;

    // We do this check for the disabling of cursor drawing during a resize.
    // As once the resize is done normally this function would end up being
    // true and would then draw the cursor at the wrong place after resize
    // so this check prevents that from happening and looks visually better.
    if (!SDL_GetMouseFocus()) { return false; }

    return ((m.x>=v.x) && (m.y>=v.y) && (m.x<=(v.x+v.w)) && (m.y<=(v.y+v.h)));
}

FILDEF std::string internal__get_tileset (std::string _lvl)
{
    if (_lvl == "..") { return _lvl; }
    if (_lvl.empty()) { return ""; }
    if (_lvl.at(0) == '$') { _lvl.erase(0, 1); }
    size_t end = _lvl.find_first_of("-");
    if (end == std::string::npos) { return ""; }
    return _lvl.substr(0, end);
}

FILDEF Vec4 internal__get_node_text_color (Vec4 _bg)
{
    if (map_editor.text_color_map.count(_bg)) { return map_editor.text_color_map.at(_bg); }

    Vec4 bg = _bg;

    // Useful way of determining whether we want white or black text based on the brightness of the node's bg color.
    // The second W3C guideline-based method was used from this answer here: https://stackoverflow.com/a/3943023
    if (_bg.r <= 0.03928f) { _bg.r /= 12.92f; } else { _bg.r = powf(((_bg.r + 0.055f) / 1.055f), 2.4f); }
    if (_bg.g <= 0.03928f) { _bg.g /= 12.92f; } else { _bg.g = powf(((_bg.g + 0.055f) / 1.055f), 2.4f); }
    if (_bg.b <= 0.03928f) { _bg.b /= 12.92f; } else { _bg.b = powf(((_bg.b + 0.055f) / 1.055f), 2.4f); }

    float l = 0.2126f * _bg.r + 0.7152f * _bg.g + 0.0722f * _bg.b;

    map_editor.text_color_map.insert(std::pair<Vec4,Vec4>(bg, ((l > 0.179f) ? Vec4 { 0,0,0,1 } : Vec4 { 1,1,1,1 })));
    return map_editor.text_color_map.at(bg);
}
FILDEF Vec4 internal__get_node_shadow_color (Vec4 _bg)
{
    return ((internal__get_node_text_color(_bg) == Vec4 { 1,1,1,1 }) ? Vec4 { 0,0,0,1 } : Vec4 { 1,1,1,1 });
}

FILDEF Vec2 internal__mouse_to_node_position ()
{
    Vec2 m = map_editor.mouse_world;

    m.x = floorf((m.x - map_editor.bounds.x) / MAP_NODE_W);
    m.y = floorf((m.y - map_editor.bounds.y) / MAP_NODE_H);

    return m;
}
FILDEF Vec2i internal__mouse_to_node_position_int ()
{
    Vec2 m = map_editor.mouse_world;

    m.x = floorf((m.x - map_editor.bounds.x) / MAP_NODE_W);
    m.y = floorf((m.y - map_editor.bounds.y) / MAP_NODE_H);

    return Vec2i { CAST(int, m.x), CAST(int, m.y) };
}

FILDEF u32 internal__map_cursor_blink_callback (u32 _interval, void* _user_data)
{
    push_editor_event(EDITOR_EVENT_BLINK_CURSOR);
    return _interval;
}

FILDEF void internal__init_map_editor_cursor ()
{
    map_editor.cursor_visible = true;
    map_editor.cursor_blink_timer = SDL_AddTimer(UI_CURSOR_BLINK_INTERVAL, internal__map_cursor_blink_callback, NULL);
    if (!map_editor.cursor_blink_timer) {
        LOG_ERROR(ERR_MIN, "Failed to setup cursor blink timer! (%s)", SDL_GetError());
    }
}
FILDEF void internal__quit_map_editor_cursor ()
{
    if (map_editor.cursor_blink_timer) {
        SDL_RemoveTimer(map_editor.cursor_blink_timer);
        map_editor.cursor_blink_timer = NULL;
    }
}

FILDEF void internal__create_new_active_node ()
{
    if (!current_tab_is_map()) { return; }
    Tab& tab = get_current_tab();

    tab.map.push_back(Map_Node { tab.map_node_info.active_pos.x, tab.map_node_info.active_pos.y, "" });
    tab.map_node_info.active = &tab.map.back();
    tab.map_node_info.select = 0;
    tab.map_node_info.cursor = 0;
    tab.map_node_info.cached_lvl_text = "";
}

FILDEF bool internal__remove_active_node_with_no_content ()
{
    if (!current_tab_is_map()) { return false; }
    Tab& tab = get_current_tab();

    if (tab.map_node_info.active && tab.map_node_info.active->lvl.empty()) {
        for (size_t i=0; i<tab.map.size(); ++i) {
            auto& node = tab.map.at(i);
            if (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y) {
                tab.map.erase(tab.map.begin()+i);
                return true;
            }
        }
    }
    return false;
}

FILDEF void internal__deselect_active_node ()
{
    if (!current_tab_is_map()) { return; }
    Tab& tab = get_current_tab();

    internal__quit_map_editor_cursor();
    if (!internal__remove_active_node_with_no_content()) { // Didn't remove.
        if (tab.map_node_info.active) {
            if (tab.map_node_info.cached_lvl_text != tab.map_node_info.active->lvl) {
                new_map_history_state(tab.map);
                tab.unsaved_changes = true;
            }
        }
    } else {
        if (!tab.map_node_info.cached_lvl_text.empty()) {
            new_map_history_state(tab.map);
            tab.unsaved_changes = true;
        }
    }

    tab.map_node_info.active = NULL;
    tab.map_node_info.selecting = false;
}

FILDEF bool internal__is_text_select_active ()
{
    if (!current_tab_is_map()) return false;
    const Tab& tab = get_current_tab();

    return (tab.map_node_info.cursor != tab.map_node_info.select);
}

FILDEF bool internal__map_clipboard_empty ()
{
    return (map_editor.clipboard.empty());
}

FILDEF void internal__map_copy ()
{
    if (!current_tab_is_map    ()) { return; }
    if (!map_select_box_present()) { return; }

    Tab& tab = get_current_tab();

    int sx1 = std::min(tab.map_select.a.x, tab.map_select.b.x);
    int sy1 = std::min(tab.map_select.a.y, tab.map_select.b.y);
    int sx2 = std::max(tab.map_select.a.x, tab.map_select.b.x);
    int sy2 = std::max(tab.map_select.a.y, tab.map_select.b.y);

    map_editor.clipboard.clear();

    for (auto& node: tab.map) {
        if (node.x >= sx1 && node.x <= sx2 && node.y >= sy1 && node.y <= sy2) { // Inside select bounds.
            map_editor.clipboard.push_back({ node.x-sx1, node.y-sy1, node.lvl });
        }
    }
}

FILDEF void init_map_editor ()
{
    map_editor.mouse_world = { 0.0f, 0.0f };
    map_editor.mouse       = { 0.0f, 0.0f };
    map_editor.mouse_tile  = { 0.0f, 0.0f };

    map_editor.cursor_blink_timer = NULL;
    map_editor.cursor_visible     = true;

    map_editor.bounds   = { 0.0f, 0.0f, 0.0f, 0.0f };
    map_editor.viewport = { 0.0f, 0.0f, 0.0f, 0.0f };
}

FILDEF void do_map_editor ()
{
    set_cursor(CURSOR_ARROW);

    Quad p1;

    p1.x = get_toolbar_w() + 1.0f;
    p1.y = TAB_BAR_HEIGHT  + 1.0f;
    p1.w = get_viewport().w - get_toolbar_w() - (get_control_panel_w()) - 2.0f;
    p1.h = get_viewport().h - STATUS_BAR_HEIGHT - TAB_BAR_HEIGHT - 2.0f;

    // To account for the control panel disappearing.
    p1.w += 1.0f;

    begin_panel(p1.x, p1.y, p1.w, p1.h, UI_NONE, editor_settings.background_color);

    // We cache the mouse position so that systems such as paste which can
    // potentially happen outside of this section of code (where the needed
    // transforms will be applied) can use the mouse position reliably as
    // prior to doing this there were bugs with the cursor's position being
    // slightly off during those operations + it's probably a bit faster.
    push_editor_camera_transform();
    map_editor.mouse_world = screen_to_world(get_mouse_pos());
    map_editor.mouse = get_mouse_pos();
    map_editor.mouse_tile = internal__mouse_to_node_position();
    pop_editor_camera_transform();

    // We cache this just in case anyone else wants to use it (status bar).
    map_editor.viewport = get_viewport();

    const Tab& tab = get_current_tab();

    push_editor_camera_transform();

    map_editor.bounds.x = 0.0f;
    map_editor.bounds.y = 0.0f;
    map_editor.bounds.w = get_map_width (tab.map) * MAP_NODE_W;
    map_editor.bounds.h = get_map_height(tab.map) * MAP_NODE_H;

    float x = map_editor.bounds.x;
    float y = map_editor.bounds.y;
    float w = map_editor.bounds.w;
    float h = map_editor.bounds.h;

    // Because we mess with the orthographic projection matrix a pixel is no
    // longer 1.0f so we need to adjust by the current zoom to get a pixel.
    //
    // We do this because otherwise the outer border gets scaled incorrectly
    // and looks quite ugly. This method ensures it always remains 1px thick.
    float px = (1.0f / tab.camera.zoom);

    constexpr float TEXT_CUT_OFF = 0.5f;
    constexpr float TEXT_PAD = 3.0f;

    bool active_node_pos_been_drawn = false;
    bool mouse_over_node = false;

    // DRAW NODES
    Font& fnt = (is_editor_font_opensans()) ? resource_font_regular_libmono : resource_font_mono_dyslexic;
    set_text_batch_font(fnt);
    for (auto node: tab.map) {
        float nx = CAST(float, node.x) * MAP_NODE_W;
        float ny = CAST(float, node.y) * MAP_NODE_H;

        float x1 = nx;
        float y1 = ny;
        float x2 = nx+MAP_NODE_W;
        float y2 = ny+MAP_NODE_H;

        std::string tileset(internal__get_tileset(node.lvl));
        set_draw_color(0,0,0,1);
        fill_quad(x1,y1,x2,y2);
        x2-=px;
        y2-=px;

        Vec4 bg = get_tileset_main_color(tileset);

        // Highlight the moused over node and the active node.
        Vec2i m = internal__mouse_to_node_position_int();
        if ((m.x == node.x && m.y == node.y) || ((tab.map_node_info.active) && (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y))) {
            if ((m.x == node.x && m.y == node.y)) {
                push_status_bar_message(node.lvl.c_str());
                mouse_over_node = true;

                if (is_window_focused("WINMAIN")) {
                    bg.r += ((1.0f-bg.r)*0.4f);
                    bg.g += ((1.0f-bg.g)*0.4f);
                    bg.b += ((1.0f-bg.b)*0.4f);
                }
            }
            if (((tab.map_node_info.active) && (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y))) {
                active_node_pos_been_drawn = true;
                bg = ui_color_ex_light;
            }
        }

        set_draw_color(bg);
        fill_quad(x1,y1,x2,y2);

        // Don't bother drawing text when it's this zoomed out (can't even see it).
        if (tab.camera.zoom >= TEXT_CUT_OFF) {
            float tw = get_text_width_scaled (fnt, node.lvl.c_str());
            float th = get_text_height_scaled(fnt, node.lvl.c_str());
            float tx = x1+TEXT_PAD;
            float ty = y1+roundf(((MAP_NODE_H/2.0f)+(th/4.0f)));

            if ((tw > (MAP_NODE_W-(TEXT_PAD*2.0f))) || ((tab.map_node_info.active) && (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y))) {
                Vec2 sa = world_to_screen({ x+x1+TEXT_PAD, y+y1 });
                Vec2 sb = world_to_screen({ x+x2-TEXT_PAD, y+y2 });

                float scx = floorf(sa.x);
                float scy = floorf(sa.y);
                float scw = ceilf (sb.x - scx);
                float sch = ceilf (sb.y - scy);

                flush_batched_text();
                begin_scissor(scx,scy,scw,sch);
            }

            float x_off = 0.0f;
            if (tab.map_node_info.active && (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y)) {
                std::string sub(node.lvl.substr(0, tab.map_node_info.cursor));
                float cursor_x = tx+get_text_width_scaled(fnt, sub.c_str());
                if (cursor_x > tx+(MAP_NODE_W-(TEXT_PAD*2.0f))) {
                    float diff = abs((MAP_NODE_W-(TEXT_PAD*2.0f)) - get_text_width_scaled(fnt, sub.c_str()));
                    x_off = -diff;
                }
            }

            set_text_batch_color(internal__get_node_shadow_color(bg));
            draw_batched_text(tx+x_off+1.0f, ty+1.0f, node.lvl.c_str());
            set_text_batch_color(internal__get_node_text_color(bg));
            draw_batched_text(tx+x_off, ty, node.lvl.c_str());

            if ((tw > (MAP_NODE_W-(TEXT_PAD*2.0f))) || ((tab.map_node_info.active) && (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y))) {
                flush_batched_text();
                end_scissor();
            }
        } else {
            if (CAST(int, m.x) == node.x && CAST(int, m.y) == node.y) {
                set_current_tooltip(node.lvl);
            }
        }
    }
    flush_batched_text();

    // DRAW HIGHLIGHT
    if (!mouse_over_node && internal__mouse_inside_map_editor_viewport()) {
        if (is_window_focused("WINMAIN")) {
            Vec2 m = internal__mouse_to_node_position();
            m.x *= MAP_NODE_W;
            m.y *= MAP_NODE_H;
            set_draw_color(1,1,1,0.5f);
            fill_quad(m.x,m.y,m.x+MAP_NODE_W,m.y+MAP_NODE_H);
        }
    }
    if (tab.map_node_info.active && !active_node_pos_been_drawn) {
        Vec2i m = internal__mouse_to_node_position_int();
        float nx = tab.map_node_info.active_pos.x * MAP_NODE_W;
        float ny = tab.map_node_info.active_pos.y * MAP_NODE_H;
        set_draw_color(((is_ui_light()) ? Vec4 { 1,1,1,1 } : ui_color_ex_light));
        fill_quad(nx,ny,nx+MAP_NODE_W,ny+MAP_NODE_H);
    }

    // DRAW TEXT CURSOR/SELECT
    if (tab.map_node_info.active) {
        if (tab.camera.zoom >= TEXT_CUT_OFF) {
            std::string text = (tab.map_node_info.active) ? tab.map_node_info.active->lvl : "";

            float nx = CAST(float, tab.map_node_info.active_pos.x) * MAP_NODE_W;
            float ny = CAST(float, tab.map_node_info.active_pos.y) * MAP_NODE_H;

            float x1 = nx;
            float y1 = ny;
            float x2 = nx+MAP_NODE_W;
            float y2 = ny+MAP_NODE_H;

            float tw = get_text_width_scaled (fnt, text.c_str());
            float th = get_text_height_scaled(fnt, text.c_str());

            if (th <= 0.0f) { th = fnt.line_gap.at(fnt.current_pt_size) * get_font_draw_scale(); } // So the cursor still draws when there is no text present.

            float tx = x1+TEXT_PAD;
            float ty = y1+roundf(((MAP_NODE_H/2.0f)+(th/4.0f)));

            float x_off = 0.0f;
            std::string sub(text.substr(0, tab.map_node_info.cursor));
            float cursor_x = tx+get_text_width_scaled(fnt, sub.c_str());
            if (cursor_x > tx+(MAP_NODE_W-(TEXT_PAD*2.0f))) {
                float diff = abs((MAP_NODE_W-(TEXT_PAD*2.0f)) - get_text_width_scaled(fnt, sub.c_str()));
                x_off = -diff;
            }

            float xo = get_text_width_scaled(fnt, sub.c_str());
            float yo = ((y2-y1)-th)/2.0f; // Center the cursor vertically.
            // Just looks nicer...
            if ((tab.map_node_info.cursor != 0 && text.length()) || (!text.length())) {
                xo += 1.0f;
            }

            if (internal__is_text_select_active()) {
                if (!text.empty()) {
                    size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                    size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);

                    Vec2 sa = world_to_screen({ x+x1+TEXT_PAD, y+y1 });
                    Vec2 sb = world_to_screen({ x+x2-TEXT_PAD, y+y2 });

                    float scx = floorf(sa.x);
                    float scy = floorf(sa.y);
                    float scw = ceilf (sb.x - scx);
                    float sch = ceilf (sb.y - scy);

                    begin_scissor(scx,scy,scw,sch);

                    float x_off2 = 0.0f;
                    std::string sub2(text.substr(0, tab.map_node_info.select));
                    float cursor_x2 = tx+get_text_width_scaled(fnt, sub2.c_str());
                    if (cursor_x2 > tx+(MAP_NODE_W-(TEXT_PAD*2.0f))) {
                        float diff = abs((MAP_NODE_W-(TEXT_PAD*2.0f)) - get_text_width_scaled(fnt, sub2.c_str()));
                        x_off2 = -diff;
                    }

                    float xo2 = get_text_width_scaled(fnt, sub2.c_str());
                    // Just looks nicer...
                    if ((tab.map_node_info.select != 0 && text.length()) || (!text.length())) {
                        xo2 += 1.0f;
                    }

                    set_draw_color(editor_settings.select_color);
                    fill_quad(tx+xo+x_off, y1+yo, tx+xo2+x_off2, y1+yo+th);

                    end_scissor();
                }
            } else {
                if (map_editor.cursor_visible) {
                    set_draw_color(internal__get_node_shadow_color(ui_color_ex_light));
                    draw_line(tx+xo+x_off+1.0f, y1+yo+1.0f, tx+xo+x_off+1.0f, y1+yo+th+1.0f);
                    set_draw_color(internal__get_node_text_color(ui_color_ex_light));
                    draw_line(tx+xo+x_off, y1+yo, tx+xo+x_off, y1+yo+th);
                }
            }
        }
    }

    // DRAW SELECT
    if (map_select_box_present()) {
        float sx1 = std::min(tab.map_select.a.x, tab.map_select.b.x) * MAP_NODE_W;
        float sy1 = std::min(tab.map_select.a.y, tab.map_select.b.y) * MAP_NODE_H;
        float sx2 = std::max(tab.map_select.a.x, tab.map_select.b.x) * MAP_NODE_W;
        float sy2 = std::max(tab.map_select.a.y, tab.map_select.b.y) * MAP_NODE_H;

        sx2 += MAP_NODE_W;
        sy2 += MAP_NODE_H;

        set_draw_color(editor_settings.select_color);
        fill_quad(sx1,sy1,sx2,sy2);
    }

    pop_editor_camera_transform();

    end_panel();
}

FILDEF void handle_map_editor_events ()
{
    if (!current_tab_is_map()) { return; }
    Tab& tab = get_current_tab();

    if (!is_window_focused("WINMAIN")) { return; }

    std::string old_text = (tab.map_node_info.active) ? tab.map_node_info.active->lvl : "";
    size_t old_cursor = tab.map_node_info.cursor;

    bool movement_action   = false;
    bool just_selected     = false;
    bool do_not_set_select = false;

    switch (main_event.type) {
    case (SDL_MOUSEBUTTONDOWN): {
        if (internal__mouse_inside_map_editor_viewport()) {
            if (main_event.button.button == SDL_BUTTON_LEFT) {
                internal__deselect_active_node();
                tab.map_node_info.pressed_node_pos = internal__mouse_to_node_position_int();
                tab.map_select.a = tab.map_node_info.pressed_node_pos;
                tab.map_select.b = tab.map_node_info.pressed_node_pos;
                map_editor.left_pressed = true;
            }
            map_editor.pressed = true;
        }
    } break;
    case (SDL_MOUSEBUTTONUP): {
        if (internal__mouse_inside_map_editor_viewport()) {
            if (main_event.button.button == SDL_BUTTON_LEFT) {
                if (map_editor.pressed && (tab.map_node_info.pressed_node_pos == internal__mouse_to_node_position_int())) {
                    tab.map_node_info.active_pos = internal__mouse_to_node_position_int();
                    // Find the node and if we can't it means it's empty and we will just create one.
                    for (auto& node: tab.map) {
                        if (tab.map_node_info.active_pos.x == node.x && tab.map_node_info.active_pos.y == node.y) {
                            tab.map_node_info.active = &node;
                            tab.map_node_info.select = 0;
                            tab.map_node_info.cursor = tab.map_node_info.active->lvl.length();
                            tab.map_node_info.cached_lvl_text = tab.map_node_info.active->lvl;
                            break;
                        }
                    }
                    if (!tab.map_node_info.active) {
                        internal__create_new_active_node();
                    }
                    internal__init_map_editor_cursor();
                    just_selected = true;
                }
            } else if (main_event.button.button == SDL_BUTTON_RIGHT) {
                if (map_editor.pressed) {
                    internal__deselect_active_node();
                    tab.map_select.a = { 0,0 };
                    tab.map_select.b = { 0,0 };
                    map_editor.left_pressed = false;
                }
            }
        }
        map_editor.pressed = false;
        if (main_event.button.button == SDL_BUTTON_LEFT) {
            map_editor.left_pressed = false;
        }
    } break;
    case (SDL_MOUSEMOTION): {
        if (map_editor.left_pressed) {
            if (internal__mouse_inside_map_editor_viewport()) {
                tab.map_select.b = internal__mouse_to_node_position_int();
            }
        }
    } break;

    case (SDL_TEXTINPUT): {
        if (tab.map_node_info.active) {
            if (internal__is_text_select_active()) {
                size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                tab.map_node_info.active->lvl.erase(begin, end-begin);
                tab.map_node_info.cursor = begin;
                for (size_t i=0; i<strlen(main_event.text.text); ++i) {
                    auto pos = tab.map_node_info.active->lvl.begin()+(tab.map_node_info.cursor++);
                    tab.map_node_info.active->lvl.insert(pos, main_event.text.text[i]);
                }
                tab.map_node_info.select = tab.map_node_info.cursor;
            } else {
                for (size_t i=0; i<strlen(main_event.text.text); ++i) {
                    auto pos = tab.map_node_info.active->lvl.begin()+(tab.map_node_info.cursor++);
                    tab.map_node_info.active->lvl.insert(pos, main_event.text.text[i]);
                }
            }
        }
    } break;
    case (SDL_KEYDOWN): {
        if (tab.map_node_info.active) {
            bool shift = (SDL_GetModState()&KMOD_SHIFT);
            bool ctrl = (SDL_GetModState()&KMOD_CTRL);

            switch (main_event.key.keysym.sym) {
            case (SDLK_LEFT): {
                if (internal__is_text_select_active()) {
                    tab.map_node_info.cursor = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                }
                if (tab.map_node_info.cursor > 0) {
                    --tab.map_node_info.cursor;
                }
                movement_action = true;
            } break;
            case (SDLK_RIGHT): {
                if (internal__is_text_select_active()) {
                    tab.map_node_info.cursor = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                }
                if (tab.map_node_info.cursor < tab.map_node_info.active->lvl.length()) {
                    ++tab.map_node_info.cursor;
                }
                movement_action = true;
            } break;
            case (SDLK_HOME): {
                tab.map_node_info.cursor = 0;
                movement_action = true;
            } break;
            case (SDLK_END): {
                tab.map_node_info.cursor = tab.map_node_info.active->lvl.length();
                movement_action = true;
            } break;
            case (SDLK_BACKSPACE): {
                if (internal__is_text_select_active()) {
                    size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                    size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                    tab.map_node_info.active->lvl.erase(begin, end-begin);
                    tab.map_node_info.cursor = begin;
                    tab.map_node_info.select = begin;
                } else {
                    if (tab.map_node_info.cursor != 0) {
                        tab.map_node_info.active->lvl.erase(--tab.map_node_info.cursor, 1);
                    }
                }
            } break;
            case (SDLK_DELETE): {
                if (internal__is_text_select_active()) {
                    size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                    size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                    tab.map_node_info.active->lvl.erase(begin, end-begin);
                    tab.map_node_info.cursor = begin;
                    tab.map_node_info.select = begin;
                } else {
                    if (tab.map_node_info.cursor < tab.map_node_info.active->lvl.length()) {
                        tab.map_node_info.active->lvl.erase(tab.map_node_info.cursor, 1);
                    }
                }
            } break;
            case (SDLK_RETURN): {
                internal__deselect_active_node();
            } break;
            case (SDLK_ESCAPE): {
                tab.map_node_info.active->lvl = tab.map_node_info.cached_lvl_text;
                internal__deselect_active_node();
            } break;
            case (SDLK_c): {
                if (ctrl) {
                    if (internal__is_text_select_active()) {
                        size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                        size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                        std::string text(tab.map_node_info.active->lvl.substr(begin, end-begin));
                        if (SDL_SetClipboardText(text.c_str()) < 0) {
                            LOG_ERROR(ERR_MED, "Failed to set clipboard text! (%s)", SDL_GetError());
                        }
                    }
                }
            } break;
            case (SDLK_x): {
                if (ctrl) {
                    if (internal__is_text_select_active()) {
                        size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                        size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                        std::string text(tab.map_node_info.active->lvl.substr(begin, end-begin));
                        if (SDL_SetClipboardText(text.c_str()) < 0) {
                            LOG_ERROR(ERR_MED, "Failed to set clipboard text! (%s)", SDL_GetError());
                        } else {
                            tab.map_node_info.active->lvl.erase(begin, end-begin);
                            tab.map_node_info.cursor    = begin;
                            tab.map_node_info.select    = begin;
                            tab.map_node_info.selecting = false;
                        }
                    }
                }
            } break;
            case (SDLK_v): {
                if (ctrl) {
                    if (SDL_HasClipboardText()) {
                        char* text = SDL_GetClipboardText();
                        if (text) {
                            defer { SDL_free(text); }; // Docs say we need to free.
                            if (internal__is_text_select_active()) {
                                size_t begin = std::min(tab.map_node_info.cursor, tab.map_node_info.select);
                                size_t end   = std::max(tab.map_node_info.cursor, tab.map_node_info.select);
                                tab.map_node_info.active->lvl.erase(begin, end-begin);
                                tab.map_node_info.cursor = begin;
                                for (size_t i=0; i<strlen(text); ++i) {
                                    auto pos = tab.map_node_info.active->lvl.begin()+(tab.map_node_info.cursor++);
                                    if (text[i] != '\n' && text[i] != '\r') {
                                        tab.map_node_info.active->lvl.insert(pos, text[i]);
                                    }
                                }
                                tab.map_node_info.select = tab.map_node_info.cursor;
                                tab.map_node_info.selecting = false;
                            } else {
                                for (size_t i=0; i<strlen(text); ++i) {
                                    auto pos = tab.map_node_info.active->lvl.begin()+(tab.map_node_info.cursor++);
                                    tab.map_node_info.active->lvl.insert(pos, text[i]);
                                }
                            }
                        }
                    }
                }
            } break;
            case (SDLK_a): {
                if (ctrl) {
                    tab.map_node_info.select = 0;
                    tab.map_node_info.cursor = tab.map_node_info.active->lvl.length();
                    do_not_set_select = true;
                }
            } break;
            case (SDLK_LSHIFT):
            case (SDLK_RSHIFT): {
                tab.map_node_info.selecting = true;
            } break;
            }
        }
    } break;
    case (SDL_KEYUP): {
        if (tab.map_node_info.active) {
            if (main_event.key.keysym.sym == SDLK_LSHIFT || main_event.key.keysym.sym == SDLK_RSHIFT) {
                tab.map_node_info.selecting = false;
            }
        }
    }

    case (SDL_USEREVENT): {
        if (main_event.user.code == EDITOR_EVENT_BLINK_CURSOR) {
            map_editor.cursor_visible = !map_editor.cursor_visible;
        }
    } break;
    }

    // Reset the cursor blink interval.
    if (tab.map_node_info.active) {
        if (old_text != tab.map_node_info.active->lvl || old_cursor != tab.map_node_info.cursor) {
            // If the cursor was blinking before then reset the timer.
            if (map_editor.cursor_blink_timer) {
                SDL_RemoveTimer(map_editor.cursor_blink_timer);
                map_editor.cursor_blink_timer = NULL;
            }
            // Start the blinking of the cursor.
            map_editor.cursor_visible = true;
            map_editor.cursor_blink_timer = SDL_AddTimer(UI_CURSOR_BLINK_INTERVAL, internal__map_cursor_blink_callback, NULL);
            if (!map_editor.cursor_blink_timer) {
                LOG_ERROR(ERR_MIN, "Failed to setup cursor blink timer! (%s)", SDL_GetError());
            }
        }
    }

    if (!do_not_set_select) {
        if (!just_selected) {
            if ((old_cursor != tab.map_node_info.cursor) || movement_action) {
                if (!tab.map_node_info.selecting) {
                    tab.map_node_info.select = tab.map_node_info.cursor;
                }
            }
        }
    }

    // Important to stop select issues when holding shift for CAPS.
    if (tab.map_node_info.active) {
        if (!just_selected) {
            if (old_text != tab.map_node_info.active->lvl) {
                tab.map_node_info.select = tab.map_node_info.cursor;
            }
        }
    }
}

FILDEF void load_map_tab (std::string _file_name)
{
    // If there is just one tab and it is completely empty with no changes
    // then we close this tab before opening the new world map(s) in editor.
    if (editor.tabs.size() == 1) {
        if (is_current_tab_empty() && !get_current_tab().unsaved_changes && get_current_tab().name.empty()) {
            close_current_tab();
        }
    }

    create_new_map_tab_and_focus();
    Tab& tab = get_current_tab();
    tab.name = _file_name;
    set_main_window_subtitle_for_tab(tab.name);
    if (!load_map(tab, tab.name.c_str())) {
        close_current_tab();
    }
    tab.map_history.state.at(0) = tab.map;
}

FILDEF bool save_map_tab (Tab& _tab)
{
    // If the current file already has a name (has been saved before) then we
    // just do a normal Save to that file. Otherwise, we perform a Save As.
    if (_tab.name.empty()) {
        std::string file_name = save_dialog(DIALOG_TYPE_CSV);
        if (file_name.empty()) { return false; }
        _tab.name = file_name;
    }

    save_map(_tab, _tab.name.c_str());
    backup_map_tab(_tab, _tab.name);

    _tab.unsaved_changes = false;
    set_main_window_subtitle_for_tab(_tab.name);

    return true;
}

FILDEF void save_map_tab_as ()
{
std::string file_name = save_dialog(DIALOG_TYPE_CSV);
    if (file_name.empty()) { return; }

    Tab& tab = get_current_tab();

    tab.name = file_name;
    save_map(tab, tab.name.c_str());
    backup_map_tab(tab, tab.name);

    tab.unsaved_changes = false;
    set_main_window_subtitle_for_tab(tab.name);
}

FILDEF void map_drop_file (Tab* _tab, std::string _file_name)
{
    std::string file_name(fix_path_slashes(_file_name.c_str()));

    // If there is just one tab and it is completely empty with no changes
    // then we close this tab before opening the new world map(s) in editor.
    if (editor.tabs.size() == 1) {
        if (is_current_tab_empty() && !get_current_tab().unsaved_changes && get_current_tab().name.empty()) {
            close_current_tab();
        }
    }

    create_new_map_tab_and_focus();
    _tab = &get_current_tab();
    _tab->name = file_name;
    set_main_window_subtitle_for_tab(_tab->name);
    if (!load_map(*_tab, _tab->name.c_str())) {
        close_current_tab();
    }
    _tab->map_history.state.at(0) = _tab->map;
}

FILDEF void backup_map_tab (const Tab& _tab, const std::string& _file_name)
{
    // Determine how many backups the user wants saved for a given map.
    int backup_count = editor_settings.backup_count;
    if (backup_count <= 0) { return; } // No backups are wanted!

    // Create the backup path if it does not exist.
    std::string backup_path(make_path_absolute("backups/"));
    if (!does_path_exist(backup_path.c_str())) {
        if (!create_path(backup_path.c_str())) {
            LOG_ERROR(ERR_MED, "Failed to create backup directory!\nSaving to base directory instead.");
            backup_path = get_executable_path(); // Fallback to just saving here instead.
        }
    }

    std::string map_name((_file_name.empty()) ? "untitled" : strip_file_path_and_ext(_file_name.c_str()));

    // Determine how many backups are already saved of this map.
    std::vector<std::string> backups;
    list_path_content(backup_path.c_str(), backups);

    int map_count = 0;
    for (auto& file: backups) {
        if (is_file(file.c_str())) {
            // We strip extension twice because there are two extension parts to backups the .bak and the .csv.
            std::string file_name(strip_file_ext(strip_file_path_and_ext(file.c_str()).c_str()));
            if (insensitive_compare(map_name, file_name)) { ++map_count; }
        }
    }

    // If there is still room to create a new backup then that is what
    // we do. Otherwise, we overwrite the oldest backup of the map.
    std::string backup_name = backup_path + map_name + ".bak";
    if (editor_settings.unlimited_backups || (map_count < backup_count)) {
        backup_name += std::to_string(map_count) + ".csv";
        save_map(_tab, backup_name.c_str());
    } else {
        u64 oldest = UINT64_MAX;
        int oldest_index = 0;

        for (int i=0; i<map_count; ++i) {
            std::string name(backup_name + std::to_string(i) + ".csv");
            u64 current = last_file_write_time(name.c_str());
            if (current < oldest) {
                oldest = current;
                oldest_index = i;
            }
        }

        backup_name += std::to_string(oldest_index) + ".csv";
        save_map(_tab, backup_name.c_str());
    }
}

FILDEF bool is_current_map_empty ()
{
    if (are_there_any_map_tabs()) {
        const Tab& tab = get_current_tab();
        if (tab.type == TAB_TYPE_MAP) {
            return (tab.map.empty());
        }
    }
    return false;
}

FILDEF float get_min_map_bounds_x ()
{
    float x = 0.0f;
    if (current_tab_is_map()) {
        if (!get_current_tab().map.empty()) {
            x = FLT_MAX;
            for (auto& node: get_current_tab().map) {
                if (!node.lvl.empty()) {
                    if (node.x < x) {
                        x = CAST(float, node.x);
                    }
                }
            }
        }
    }
    return (x * MAP_NODE_W);
}
FILDEF float get_min_map_bounds_y ()
{
    float y = 0.0f;
    if (current_tab_is_map()) {
        if (!get_current_tab().map.empty()) {
            y = FLT_MAX;
            for (auto& node: get_current_tab().map) {
                if (!node.lvl.empty()) {
                    if (node.y < y) {
                        y = CAST(float, node.y);
                    }
                }
            }
        }
    }
    return (y * MAP_NODE_H);
}
FILDEF float get_max_map_bounds_x ()
{
    float x = 0.0f;
    if (current_tab_is_map()) {
        x = FLT_MIN;
        if (!get_current_tab().map.empty()) {
            for (auto& node: get_current_tab().map) {
                if (!node.lvl.empty()) {
                    if (node.x > x) {
                        x = CAST(float, node.x);
                    }
                }
            }
        }
    }
    return (x * MAP_NODE_W);
}
FILDEF float get_max_map_bounds_y ()
{
    float y = 0.0f;
    if (current_tab_is_map()) {
        if (!get_current_tab().map.empty()) {
            y = FLT_MIN;
            for (auto& node: get_current_tab().map) {
                if (!node.lvl.empty()) {
                    if (node.y > y) {
                        y = CAST(float, node.y);
                    }
                }
            }
        }
    }
    return (y * MAP_NODE_H);
}

FILDEF void me_cut ()
{
    if (!current_tab_is_map())     { return; }
    if (!map_select_box_present()) { return; }

    Tab& tab = get_current_tab();

    if (tab.map_node_info.active)  { return; }

    internal__map_copy();
    me_clear_select(); // Does deselect and history for us.
}

FILDEF void me_copy ()
{
    if (!current_tab_is_map())     { return; }
    if (!map_select_box_present()) { return; }

    Tab& tab = get_current_tab();

    if (tab.map_node_info.active)  { return; }

    internal__map_copy();

    // We also deselect the region afterwards, feels right.
    me_deselect();
}

FILDEF void me_paste ()
{
    if (!current_tab_is_map())           { return; }
    if (internal__map_clipboard_empty()) { return; }

    Tab& tab = get_current_tab();

    if (tab.map_node_info.active)        { return; }

    // Clear the old content from the region before pasting new content.
    int x1 = internal__mouse_to_node_position_int().x;
    int y1 = internal__mouse_to_node_position_int().y;
    int x2 = x1 + (get_map_width (map_editor.clipboard)-1);
    int y2 = y1 + (get_map_height(map_editor.clipboard)-1);

    tab.map.erase(std::remove_if(tab.map.begin(), tab.map.end(),
    [=](const Map_Node& node)
    {
        return (node.x >= x1 && node.x <= x2 && node.y >= y1 && node.y <= y2);
    }),
    tab.map.end());

    for (auto& node: map_editor.clipboard) {
        tab.map.push_back({ node.x+x1, node.y+y1, node.lvl });
    }

    new_map_history_state(tab.map);
    tab.unsaved_changes = true;
}

FILDEF void me_deselect ()
{
    if (!current_tab_is_map())     { return; }
    if (!map_select_box_present()) { return; }

    Tab& tab = get_current_tab();

    tab.map_select.a = { 0,0 };
    tab.map_select.b = { 0,0 };
}

FILDEF void me_clear_select ()
{
    if (!current_tab_is_map())     { return; }
    if (!map_select_box_present()) { return; }

    Tab& tab = get_current_tab();

    int sx1 = std::min(tab.map_select.a.x, tab.map_select.b.x);
    int sy1 = std::min(tab.map_select.a.y, tab.map_select.b.y);
    int sx2 = std::max(tab.map_select.a.x, tab.map_select.b.x);
    int sy2 = std::max(tab.map_select.a.y, tab.map_select.b.y);

    size_t old_size = tab.map.size();

    tab.map.erase(std::remove_if(tab.map.begin(), tab.map.end(),
    [=](const Map_Node& node)
    {
        return (node.x >= sx1 && node.x <= sx2 && node.y >= sy1 && node.y <= sy2);
    }),
    tab.map.end());

    if (old_size != tab.map.size()) {
        new_map_history_state(tab.map);
        tab.unsaved_changes = true;
    }

    me_deselect();
}

FILDEF void me_select_all ()
{
    if (!current_tab_is_map())    { return; }

    Tab& tab = get_current_tab();

    if (tab.map_node_info.active) { return; }

    internal__deselect_active_node();

    int x1 = CAST(int, get_min_map_bounds_x()/MAP_NODE_W);
    int y1 = CAST(int, get_min_map_bounds_y()/MAP_NODE_H);
    int x2 = CAST(int, get_max_map_bounds_x()/MAP_NODE_W);
    int y2 = CAST(int, get_max_map_bounds_y()/MAP_NODE_H);

    tab.map_select.a = { x1,y1 };
    tab.map_select.b = { x2,y2 };
}

FILDEF void me_undo ()
{
    Tab& tab = get_current_tab();
    // There is no history or we are already at the beginning.
    if (tab.map_history.current_position <= 0) { return; }
    tab.map = tab.map_history.state.at(--tab.map_history.current_position);
    tab.unsaved_changes = true;
    internal__deselect_active_node();
}

FILDEF void me_redo ()
{
    Tab& tab = get_current_tab();
    // There is no history or we are already at the end.
    int maximum = CAST(int, tab.map_history.state.size())-1;
    if (tab.map_history.current_position >= maximum) { return; }
    tab.map = tab.map_history.state.at(++tab.map_history.current_position);
    tab.unsaved_changes = true;
    internal__deselect_active_node();
}

FILDEF void me_history_begin ()
{
    Tab& tab = get_current_tab();
    while (tab.map_history.current_position > 0) { me_undo(); }
    tab.unsaved_changes = true;
}

FILDEF void me_history_end ()
{
    Tab& tab = get_current_tab();
    int maximum = CAST(int, tab.map_history.state.size())-1;
    while (tab.map_history.current_position < maximum) { me_redo(); }
    tab.unsaved_changes = true;
}

FILDEF void new_map_history_state (Map& map_)
{
    if (!current_tab_is_map()) { return; }
    Tab& tab = get_current_tab();

    // Clear all the history after the current position, if there is any, as
    // it will no longer apply to the timeline of map editor actions anymore.
    int delete_position = tab.map_history.current_position+1;
    if (delete_position < CAST(int, tab.map_history.state.size())) {
        auto begin = tab.map_history.state.begin();
        auto end = tab.map_history.state.end();

        tab.map_history.state.erase(begin+delete_position, end);
    }

    tab.map_history.state.push_back(map_);
    ++tab.map_history.current_position;
}

FILDEF bool map_select_box_present ()
{
    if (!current_tab_is_map()) { return false; }
    Map_Select s = get_current_tab().map_select;
    return (s.a != s.b);
}

FILDEF void get_map_select_bounds (int* _l, int* _t, int* _r, int* _b)
{
    if (_l) { *_l = 0; }
    if (_t) { *_t = 0; }
    if (_r) { *_r = 0; }
    if (_b) { *_b = 0; }

    if (!are_there_any_tabs    ()) { return; }
    if (!map_select_box_present()) { return; }

    const Tab& tab = get_current_tab();

    if (_l) { *_l = std::min(tab.map_select.a.x, tab.map_select.b.x); }
    if (_t) { *_t = std::max(tab.map_select.a.y, tab.map_select.b.y); }
    if (_r) { *_r = std::max(tab.map_select.a.x, tab.map_select.b.x); }
    if (_b) { *_b = std::min(tab.map_select.a.y, tab.map_select.b.y); }
}

// A translation of a Python utility originally by Tyler Glaiel called "check_connections.py".
FILDEF void me_check_connections ()
{
    // @Incomplete: ...
}

// A translation of a Python utility originally by Tyler Glaiel called "levelscan.py".
FILDEF void me_generate_level_info ()
{
    /*
    if (!current_tab_is_map()) return;
    const Tab& tab = get_current_tab();

    auto create_local_path = [=](std::string _append) -> std::string
    {
        std::string path(strip_file_name(tab.name.c_str()));
        if (path.back() == '/') { path.pop_back(); }
        path.erase(path.find_last_of('/'));
        path += "/" + _append + "/";
        return path;
    };

    auto translate_tile = [](Tile_ID _id) -> Tile_ID
    {
        if (_id >= 50000) { return _id-50000+349; }
        if (_id >= 40000) { return _id-40000+200; }
        if (_id >= 30000) { return _id-30000+150; }
        if (_id >= 20000) { return _id-20000+100; }
        if (_id >= 10000) { return _id-10000+ 50; }
        if (_id >=     0) { return _id-    0+  0; }

        return _id;
    };

    constexpr Tile_ID LIFE     = 237;
    constexpr Tile_ID CART     = 238;
    constexpr Tile_ID BIG_LIFE = 311;
    constexpr Tile_ID KEY      = 273;
    constexpr Tile_ID LOCK     =  33;
    constexpr Tile_ID COIN     = 300;

    struct Level_Stat
    {
        int life_ct     = 0;
        int cart_ct     = 0;
        int big_life_ct = 0;
        int key_ct      = 0;
        int lock_ct     = 0;
        int coin_ct     = 0;
    };

    if (tab.map.empty()) return;

    std::string tilemap_path(create_local_path("tilemaps"));
    std::string data_path(create_local_path("data"));

    if (!does_path_exist(tilemap_path.c_str())) {
        show_alert("Generate Level Info", "No local tilemaps folder was found.", ALERT_TYPE_INFO, ALERT_BUTTON_OK); return;
    }
    if (!does_path_exist(data_path.c_str())) {
        show_alert("Generate Level Info", "No local data folder was found.", ALERT_TYPE_INFO, ALERT_BUTTON_OK); return;
    }

    for (auto& node: tab.map) {
        std::string name(node.lvl);
        if (name.length() > 3) { // Avoids attempting to generate info for invalid and ".." nodes.
            if (name.front() == '$') { name.erase(0,1); }
            std::string file_name(tilemap_path + name);
            // @Incomplete: ...
        }
    }
    */
}

FILDEF void me_add_left ()
{
    // @Incomplete: ...
}
FILDEF void me_add_right ()
{
    // @Incomplete: ...
}
FILDEF void me_add_up ()
{
    // @Incomplete: ...
}
FILDEF void me_add_down ()
{
    // @Incomplete: ...
}
