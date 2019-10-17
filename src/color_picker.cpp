enum Channel_Type { INVALID_CHANNEL, CHANNEL_R, CHANNEL_G, CHANNEL_B, CHANNEL_A };

GLOBAL constexpr float COLOR_PICKER_CHANNEL_W =  40.0f;
GLOBAL constexpr float COLOR_PICKER_CHANNEL_H = 180.0f;

GLOBAL constexpr float COLOR_PICKER_XPAD = 8.0f;
GLOBAL constexpr float COLOR_PICKER_YPAD = 8.0f;

GLOBAL constexpr float COLOR_PICKER_TEXT_BOX_H = 20.0f;
GLOBAL constexpr float COLOR_PICKER_ALPHA_H    = 20.0f;

GLOBAL constexpr float COLOR_PICKER_BOTTOM_BORDER = 26.0f;

GLOBAL constexpr float COLOR_PICKER_SWATCH_LG    = 32.0f;
GLOBAL constexpr float COLOR_PICKER_SWATCH_SM    = 16.0f;
GLOBAL constexpr float COLOR_PICKER_SWATCH_XPAD  =  7.0f;
GLOBAL constexpr float COLOR_PICKER_SWATCH_YPAD  =  8.0f;
GLOBAL constexpr float COLOR_PICKER_SWATCH_GAP   =  6.0f;
GLOBAL constexpr int   COLOR_PICKER_SWATCH_COUNT =     9;

GLOBAL Channel_Type color_picker_active_channel;
GLOBAL bool color_picker_mouse_pressed;

GLOBAL std::deque<Vec4> color_picker_swatches;

// When the color picker menu is opened we cache the current color value.
// This allows the color picker menu to modify the current color immediately
// for instant feedback. If the user then wants to cancel the changes made,
// we can just restore the cached version of the color to turn it back.

GLOBAL Vec4* current_color_picker_color;
GLOBAL Vec4  cached_color_picker_color;

FILDEF void internal__do_color_channel (Vec2& _cursor, Vec4 _min, Vec4 _max, float& _channel, Channel_Type _type)
{
    float xpad = COLOR_PICKER_XPAD;
    float ypad = COLOR_PICKER_YPAD;

    float cw = COLOR_PICKER_CHANNEL_W;
    float ch = COLOR_PICKER_CHANNEL_H;

    float x1 = _cursor.x;
    float y1 = _cursor.y;
    float x2 = _cursor.x + cw;
    float y2 = _cursor.y + ch;

    // The dark and light border surrounding the channel quad.
    set_draw_color(ui_color_light);
    fill_quad(x1-2.0f, y1-2.0f, x2+2.0f, y2+2.0f);
    set_draw_color(ui_color_ex_dark);
    fill_quad(x1-1.0f, y1-1.0f, x2+1.0f, y2+1.0f);

    begin_polygon();
    put_vertex(_cursor.x   , _cursor.y+ch, _min); // BL
    put_vertex(_cursor.x   , _cursor.y   , _max); // TL
    put_vertex(_cursor.x+cw, _cursor.y+ch, _min); // BR
    put_vertex(_cursor.x+cw, _cursor.y   , _max); // TR
    end_polygon();

    float percent = std::clamp(roundf(_channel*100.0f), 0.0f, 100.0f);
    std::string channel_str(std::to_string(CAST(int, percent)));
    _cursor.y += (ch + ypad);
    do_text_box(cw, COLOR_PICKER_TEXT_BOX_H, UI_NUMERIC, channel_str, "0");
    if (atoi(channel_str.c_str()) > 100) { channel_str = "100"; }
    float new_channel = CAST(float, atoi(channel_str.c_str())) / 100.0f;
    if (_channel != new_channel) { _channel = new_channel; }
    // Reset cursor after text box.
    _cursor.x -=  cw;
    _cursor.y -= (ch + ypad);

    // Draw the indicator for what value is currently selected.
    float pos = (_cursor.y + ch) - roundf(ch * _channel);

    float ix1 = _cursor.x   -2.0f;
    float iy1 = pos         -2.0f;
    float ix2 = _cursor.x+cw+2.0f;
    float iy2 = pos         +2.0f;

    Vec4 cur = _min;
    switch (_type) {
    case (CHANNEL_R): { cur.r = _channel; } break;
    case (CHANNEL_G): { cur.g = _channel; } break;
    case (CHANNEL_B): { cur.b = _channel; } break;
    }

    set_draw_color(ui_color_light);
    fill_quad(ix1-2.0f, iy1-2.0f, ix2+2.0f, iy2+2.0f);
    set_draw_color(ui_color_ex_dark);
    fill_quad(ix1-1.0f, iy1-1.0f, ix2+1.0f, iy2+1.0f);
    set_draw_color(cur);
    fill_quad(ix1-0.0f, iy1-0.0f, ix2+0.0f, iy2+0.0f);

    // Handle the indicator both being selected, deselected, and moved.
    if (color_picker_mouse_pressed) {
        if (mouse_in_ui_bounds_xywh(ix1-1.0f, iy1-1.0f, cw+2.0f, 7.0f)) {
            color_picker_active_channel = _type;
        } else if (mouse_in_ui_bounds_xywh(_cursor.x, _cursor.y, cw, ch)) {
            color_picker_active_channel = _type;
            // Determine where the click was and jump to that position.
            float my = ch - (get_mouse_pos().y - get_viewport().y - _cursor.y);
            _channel = my / ch;
        }
    }
    if (color_picker_active_channel == _type) {
        _channel -= (ui_get_relative_mouse().y / ch);
        _channel = std::clamp(_channel, 0.0f, 1.0f);
    }

    // Move the cursor into position for next channel.
    _cursor.x += cw + (xpad*3.0f);
}

FILDEF void internal__do_color_preview (Vec2& _cursor, Vec4 _c, float _size)
{
    const Texture& tex = (CAST(int, _size) % 14 == 0) ? resource_checker_14 : resource_checker_16;

    float x = _cursor.x;
    float y = _cursor.y;

    // The dark and light border surrounding the color.
    set_draw_color(ui_color_light);
    fill_quad(x-2.0f, y-2.0f, x+_size+2.0f, y+_size+2.0f);
    set_draw_color(ui_color_ex_dark);
    fill_quad(x-1.0f, y-1.0f, x+_size+1.0f, y+_size+1.0f);

    float tx = x + (_size / 2.0f);
    float ty = y + (_size / 2.0f);

    Quad clip = { 0.0f, 0.0f, _size, _size };
    draw_texture(tex, tx, ty, &clip);

    Vec4 max = { _c.r, _c.g, _c.b, 1.0f };
    Vec4 min = { _c.r, _c.g, _c.b, _c.a };

    begin_polygon();
    put_vertex(x      , y+_size, min); // BL
    put_vertex(x      , y      , max); // TL
    put_vertex(x+_size, y+_size, min); // BR
    put_vertex(x+_size, y      , max); // TR
    end_polygon();
}

FILDEF void internal__okay_color ()
{
    // Special checks for background and tile grid color because of the defaulting.
    if (current_color_picker_color == &editor_settings.background_color) {
        editor_settings.background_color_defaulted = false;
    }
    if (current_color_picker_color == &editor_settings.tile_grid_color) {
        editor_settings.tile_grid_color_defaulted = false;
    }

    hide_window("WINCOLOR");
}

FILDEF void internal__save_color_swatch ()
{
    ASSERT(current_color_picker_color);

    color_picker_swatches.pop_front();
    color_picker_swatches.push_back(*current_color_picker_color);
}

FILDEF void internal__cancel_color ()
{
    ASSERT(current_color_picker_color);
    *current_color_picker_color = cached_color_picker_color;

    hide_window("WINCOLOR");
}

FILDEF void internal__do_swatch_panel (Vec2& _cursor)
{
    ASSERT(current_color_picker_color);

    _cursor.y += COLOR_PICKER_SWATCH_LG + COLOR_PICKER_YPAD;

    set_draw_color(ui_color_med_dark);
    draw_quad(_cursor.x, _cursor.y, _cursor.x+COLOR_PICKER_SWATCH_LG, get_panel_h()-COLOR_PICKER_YPAD);

    float x = _cursor.x                                  +1.0f;
    float y = _cursor.y                                  +1.0f;
    float w = COLOR_PICKER_SWATCH_LG                     -2.0f;
    float h = (get_panel_h()-COLOR_PICKER_YPAD)-_cursor.y-2.0f;

    Vec2 cursor = { COLOR_PICKER_SWATCH_XPAD, COLOR_PICKER_SWATCH_YPAD };
    begin_panel(x, y, w, h, UI_NONE);

    for (auto& c: color_picker_swatches) {
        internal__do_color_preview(cursor, c, COLOR_PICKER_SWATCH_SM);
        if (color_picker_mouse_pressed) {
            if (mouse_in_ui_bounds_xywh(cursor.x, cursor.y, COLOR_PICKER_SWATCH_SM, COLOR_PICKER_SWATCH_SM)) {
                *current_color_picker_color = c;
            }
        }

        cursor.y += COLOR_PICKER_SWATCH_SM;
        cursor.y += COLOR_PICKER_SWATCH_GAP;
    }

    end_panel();
}

FILDEF void internal__do_alpha_channel (Vec2& _cursor, Vec4& _c)
{
    float xpad = COLOR_PICKER_XPAD;
    float ypad = COLOR_PICKER_YPAD;

    float cw = COLOR_PICKER_CHANNEL_W;
    float ch = COLOR_PICKER_CHANNEL_H;

    _cursor.x =  xpad;
    _cursor.y = (ypad*3.25f) + ch + COLOR_PICKER_TEXT_BOX_H;

    set_panel_cursor_dir(UI_DIR_DOWN);
    do_separator((cw*3.0f)+(xpad*6.0f));
    _cursor.y -= 1.0f;
    set_panel_cursor_dir(UI_DIR_RIGHT);

    _cursor.y += (ypad*1.25f);

    float percent = std::clamp(roundf(_c.a*100.0f), 0.0f, 100.0f);
    std::string alpha_str(std::to_string(CAST(int, percent)));
    do_text_box(cw, COLOR_PICKER_TEXT_BOX_H, UI_NUMERIC, alpha_str, "0");
    if (atoi(alpha_str.c_str()) > 100) { alpha_str = "100"; }
    float new_alpha = CAST(float, atoi(alpha_str.c_str())) / 100.0f;
    if (_c.a != new_alpha) { _c.a = new_alpha; }

    _cursor.x += xpad;

    float x1 = _cursor.x;
    float y1 = _cursor.y;
    float x2 = _cursor.x + ((cw*2.0f)+(xpad*5.0f));
    float y2 = _cursor.y + COLOR_PICKER_ALPHA_H;

    set_draw_color(ui_color_light);
    fill_quad(x1-2.0f, y1-2.0f, x2+2.0f, y2+2.0f);
    set_draw_color(ui_color_ex_dark);
    fill_quad(x1-1.0f, y1-1.0f, x2+1.0f, y2+1.0f);

    float tw = x2-x1;
    float th = COLOR_PICKER_ALPHA_H;
    float tx = _cursor.x + (tw / 2.0f);
    float ty = _cursor.y + (th / 2.0f);

    Quad clip1 = { 0.0f, 0.0f, tw, th };
    draw_texture(resource_checker_20, tx, ty, &clip1);

    Vec4 min = { _c.r, _c.g, _c.b, 0.0f };
    Vec4 max = { _c.r, _c.g, _c.b, 1.0f };

    begin_polygon();
    put_vertex(x1, y2, min); // BL
    put_vertex(x1, y1, min); // TL
    put_vertex(x2, y2, max); // BR
    put_vertex(x2, y1, max); // TR
    end_polygon();

    // Draw the indicator for what value is currently selected.
    float pos = (_cursor.x + tw) - roundf(tw * (1.0f-_c.a));

    float ix1 = pos         -2.0f;
    float iy1 = _cursor.y   -2.0f;
    float ix2 = pos         +2.0f;
    float iy2 = _cursor.y+th+2.0f;

    set_draw_color(ui_color_light);
    fill_quad(ix1-2.0f, iy1-2.0f, ix2+2.0f, iy2+2.0f);
    set_draw_color(ui_color_ex_dark);
    fill_quad(ix1-1.0f, iy1-1.0f, ix2+1.0f, iy2+1.0f);

    float itw = ix2-ix1;
    float ith = iy2-iy1;
    float itx = ix1 + (itw / 2.0f);
    float ity = iy1 + (ith / 2.0f);

    Quad clip2 = { ix1-_cursor.x, -2.0f, itw, ith };
    draw_texture(resource_checker_20, itx, ity, &clip2);

    set_draw_color(_c);
    fill_quad(ix1-0.0f, iy1-0.0f, ix2+0.0f, iy2+0.0f);

    // Handle the indicator both being selected, deselected, and moved.
    if (color_picker_mouse_pressed) {
        if (mouse_in_ui_bounds_xywh(ix1-1.0f, iy1-1.0f, 7.0f, th+2.0f)) {
            color_picker_active_channel = CHANNEL_A;
        } else if (mouse_in_ui_bounds_xywh(_cursor.x, _cursor.y, tw, th)) {
            color_picker_active_channel = CHANNEL_A;
            // Determine where the click was and jump to that position.
            float mx = tw - (get_mouse_pos().x - get_viewport().x - _cursor.x);
            _c.a = 1.0f - (mx / tw);
        }
    }
    if (color_picker_active_channel == CHANNEL_A) {
        _c.a += (ui_get_relative_mouse().x / tw);
        _c.a = std::clamp(_c.a, 0.0f, 1.0f);
    }
}

FILDEF void init_color_picker ()
{
    current_color_picker_color = NULL;
    // Add some empty swatches to the color picker on start-up.
    for (int i=0; i<COLOR_PICKER_SWATCH_COUNT; ++i) {
        color_picker_swatches.push_back({ 1.0f,1.0f,1.0f,0.0f });
    }
}

FILDEF void open_color_picker (Vec4* _color)
{
    raise_window("WINCOLOR");

    color_picker_active_channel = INVALID_CHANNEL;
    color_picker_mouse_pressed = false;

    ASSERT(_color);

    current_color_picker_color = _color;
    cached_color_picker_color = *_color;

    if (is_window_hidden("WINCOLOR")) {
        show_window("WINCOLOR");
    }
}

FILDEF void do_color_picker ()
{
    if (is_window_hidden("WINCOLOR")) { return; }

    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    set_ui_font(&get_editor_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    ////////////////////////////////////////

    float bb = COLOR_PICKER_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 3.0f);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the color picker.
    Vec2 btn_cursor = { 0.0f, WINDOW_BORDER };
    begin_panel(0.0f, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - (bw*2.0f);

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Okay"  )) { internal__okay_color();        }
    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Save"  )) { internal__save_color_swatch(); }
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) { internal__cancel_color();      }

    // Add a separator to the left for symmetry.
    btn_cursor.x = 1.0f;
    do_separator(bh);

    end_panel();

    ////////////////////////////////////////

    p2.x =                  1.0f;
    p2.y =                  1.0f;
    p2.w = vw             - 2.0f;
    p2.h = vh - p2.y - bb - 1.0f;

    begin_panel(p2, UI_NONE, ui_color_medium);

    ASSERT(current_color_picker_color);

    Vec4& c = *current_color_picker_color; // So much shorter to type out...
    Vec2 cursor = { COLOR_PICKER_XPAD, COLOR_PICKER_YPAD };

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    // Draw the three R G B channel selectors/sliders.
    Vec4 r_min = { 0.0f,  c.g,  c.b, 1.0f };
    Vec4 r_max = { 1.0f,  c.g,  c.b, 1.0f };

    Vec4 g_min = {  c.r, 0.0f,  c.b, 1.0f };
    Vec4 g_max = {  c.r, 1.0f,  c.b, 1.0f };

    Vec4 b_min = {  c.r,  c.g, 0.0f, 1.0f };
    Vec4 b_max = {  c.r,  c.g, 1.0f, 1.0f };

    internal__do_color_channel(cursor, r_min, r_max, c.r, CHANNEL_R);
    internal__do_color_channel(cursor, g_min, g_max, c.g, CHANNEL_G);
    internal__do_color_channel(cursor, b_min, b_max, c.b, CHANNEL_B);

    // Draw the current color to showcase to the user.
    internal__do_color_preview(cursor, c, COLOR_PICKER_SWATCH_LG);

    // Draw box surrounding the saved swatches.
    internal__do_swatch_panel(cursor);

    // Draw the alpha/opacity text box section.
    internal__do_alpha_channel(cursor, c);

    end_panel();
    end_panel();
}

FILDEF void cancel_color_picker ()
{
    internal__cancel_color();
}

FILDEF void handle_color_picker_events ()
{
    color_picker_mouse_pressed = false;

    if (!is_window_focused("WINCOLOR")) { return; }

    // Determine if the mouse was pressed this update/cycle.
    switch (main_event.type) {
    case (SDL_MOUSEBUTTONDOWN): { if (main_event.button.button == SDL_BUTTON_LEFT) { color_picker_mouse_pressed  = true;            } } break;
    case (SDL_MOUSEBUTTONUP):   { if (main_event.button.button == SDL_BUTTON_LEFT) { color_picker_active_channel = INVALID_CHANNEL; } } break;
    case (SDL_KEYDOWN): {
        if (!text_box_is_active()) {
            switch (main_event.key.keysym.sym) {
            case (SDLK_RETURN): { internal__okay_color();   } break;
            case (SDLK_ESCAPE): { internal__cancel_color(); } break;
            }
        }
    } break;
    }
}
