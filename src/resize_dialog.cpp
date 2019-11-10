GLOBAL constexpr float RESIZE_BOTTOM_BORDER = 26.0f;

GLOBAL constexpr float RESIZE_XPAD = 8.0f;
GLOBAL constexpr float RESIZE_YPAD = 8.0f;

GLOBAL constexpr float RESIZE_TEXT_BOX_H = 20.0f;

GLOBAL constexpr const char* RESIZE_WIDTH_LABEL = "Level Width:  ";
GLOBAL constexpr const char* RESIZE_HEIGHT_LABEL = "Level Height:  ";

GLOBAL int current_resize_width  = CAST(int, DEFAULT_LEVEL_WIDTH);
GLOBAL int current_resize_height = CAST(int, DEFAULT_LEVEL_HEIGHT);

GLOBAL Resize_Dir resize_dialog_dir = RESIZE_DIR_CENTER;

GLOBAL const Quad* nw_clip     = &CLIP_RESIZE_NW;
GLOBAL const Quad* n_clip      = &CLIP_RESIZE_N;
GLOBAL const Quad* ne_clip     = &CLIP_RESIZE_NE;
GLOBAL const Quad* w_clip      = &CLIP_RESIZE_W;
GLOBAL const Quad* center_clip = &CLIP_BULLET;
GLOBAL const Quad* e_clip      = &CLIP_RESIZE_E;
GLOBAL const Quad* sw_clip     = &CLIP_RESIZE_SW;
GLOBAL const Quad* s_clip      = &CLIP_RESIZE_S;
GLOBAL const Quad* se_clip     = &CLIP_RESIZE_SE;

FILDEF void internal__calculate_dir_clips ()
{
    switch (resize_dialog_dir) {
    case (RESIZE_DIR_NW): {
        nw_clip     = &CLIP_BULLET;
        n_clip      = &CLIP_RESIZE_E;
        ne_clip     = &CLIP_NONE;
        w_clip      = &CLIP_RESIZE_S;
        center_clip = &CLIP_RESIZE_SE;
        e_clip      = &CLIP_NONE;
        sw_clip     = &CLIP_NONE;
        s_clip      = &CLIP_NONE;
        se_clip     = &CLIP_NONE;
    } break;
    case (RESIZE_DIR_N): {
        nw_clip     = &CLIP_RESIZE_W;
        n_clip      = &CLIP_BULLET;
        ne_clip     = &CLIP_RESIZE_E;
        w_clip      = &CLIP_RESIZE_SW;
        center_clip = &CLIP_RESIZE_S;
        e_clip      = &CLIP_RESIZE_SE;
        sw_clip     = &CLIP_NONE;
        s_clip      = &CLIP_NONE;
        se_clip     = &CLIP_NONE;
    } break;
    case (RESIZE_DIR_NE): {
        nw_clip     = &CLIP_NONE;
        n_clip      = &CLIP_RESIZE_W;
        ne_clip     = &CLIP_BULLET;
        w_clip      = &CLIP_NONE;
        center_clip = &CLIP_RESIZE_SW;
        e_clip      = &CLIP_RESIZE_S;
        sw_clip     = &CLIP_NONE;
        s_clip      = &CLIP_NONE;
        se_clip     = &CLIP_NONE;
    } break;
    case (RESIZE_DIR_W): {
        nw_clip     = &CLIP_RESIZE_N;
        n_clip      = &CLIP_RESIZE_NE;
        ne_clip     = &CLIP_NONE;
        w_clip      = &CLIP_BULLET;
        center_clip = &CLIP_RESIZE_E;
        e_clip      = &CLIP_NONE;
        sw_clip     = &CLIP_RESIZE_S;
        s_clip      = &CLIP_RESIZE_SE;
        se_clip     = &CLIP_NONE;
    } break;
    case (RESIZE_DIR_CENTER): {
        nw_clip     = &CLIP_RESIZE_NW;
        n_clip      = &CLIP_RESIZE_N;
        ne_clip     = &CLIP_RESIZE_NE;
        w_clip      = &CLIP_RESIZE_W;
        center_clip = &CLIP_BULLET;
        e_clip      = &CLIP_RESIZE_E;
        sw_clip     = &CLIP_RESIZE_SW;
        s_clip      = &CLIP_RESIZE_S;
        se_clip     = &CLIP_RESIZE_SE;
    } break;
    case (RESIZE_DIR_E): {
        nw_clip     = &CLIP_NONE;
        n_clip      = &CLIP_RESIZE_NW;
        ne_clip     = &CLIP_RESIZE_N;
        w_clip      = &CLIP_NONE;
        center_clip = &CLIP_RESIZE_W;
        e_clip      = &CLIP_BULLET;
        sw_clip     = &CLIP_NONE;
        s_clip      = &CLIP_RESIZE_SW;
        se_clip     = &CLIP_RESIZE_S;
    } break;
    case (RESIZE_DIR_SW): {
        nw_clip     = &CLIP_NONE;
        n_clip      = &CLIP_NONE;
        ne_clip     = &CLIP_NONE;
        w_clip      = &CLIP_RESIZE_N;
        center_clip = &CLIP_RESIZE_NE;
        e_clip      = &CLIP_NONE;
        sw_clip     = &CLIP_BULLET;
        s_clip      = &CLIP_RESIZE_E;
        se_clip     = &CLIP_NONE;
    } break;
    case (RESIZE_DIR_S): {
        nw_clip     = &CLIP_NONE;
        n_clip      = &CLIP_NONE;
        ne_clip     = &CLIP_NONE;
        w_clip      = &CLIP_RESIZE_NW;
        center_clip = &CLIP_RESIZE_N;
        e_clip      = &CLIP_RESIZE_NE;
        sw_clip     = &CLIP_RESIZE_W;
        s_clip      = &CLIP_BULLET;
        se_clip     = &CLIP_RESIZE_E;
    } break;
    case (RESIZE_DIR_SE): {
        nw_clip     = &CLIP_NONE;
        n_clip      = &CLIP_NONE;
        ne_clip     = &CLIP_NONE;
        w_clip      = &CLIP_NONE;
        center_clip = &CLIP_RESIZE_NW;
        e_clip      = &CLIP_RESIZE_N;
        sw_clip     = &CLIP_NONE;
        s_clip      = &CLIP_RESIZE_W;
        se_clip     = &CLIP_BULLET;
    } break;
    }
}

FILDEF void internal__do_resize_alignment (Vec2& _cursor)
{
    // Do the long horizontal separator first.
    float w = get_viewport().w - (RESIZE_XPAD*2.0f);

    advance_panel_cursor(RESIZE_YPAD*1.5f);
    do_separator(w);
    advance_panel_cursor(RESIZE_YPAD*1.5f);

    set_panel_cursor_dir(UI_DIR_RIGHT);

    float bw = 25.0f;
    float bh = 25.0f;

    float x = (get_viewport().w/2.0f) - ((bw*3.0f)/2.0f);

    _cursor.x  = x;
    _cursor.y -= 2.0f; // Just to get the spacing above and below even.

    float qx1 = _cursor.x               - 1.0f;
    float qy1 = _cursor.y               - 1.0f;
    float qx2 = _cursor.x + (bw * 3.0f) + 1.0f;
    float qy2 = _cursor.y + (bh * 3.0f) + 1.0f;

    set_draw_color(ui_color_ex_dark);
    fill_quad(qx1, qy1, qx2, qy2);

    Resize_Dir old_dir = resize_dialog_dir;

    if (do_button_img(NULL, bw,bh, UI_NONE, nw_clip))     { resize_dialog_dir = RESIZE_DIR_NW;     }
    if (do_button_img(NULL, bw,bh, UI_NONE, n_clip))      { resize_dialog_dir = RESIZE_DIR_N;      }
    if (do_button_img(NULL, bw,bh, UI_NONE, ne_clip))     { resize_dialog_dir = RESIZE_DIR_NE;     }

    _cursor.x  = x;
    _cursor.y += bh;

    if (do_button_img(NULL, bw,bh, UI_NONE, w_clip))      { resize_dialog_dir = RESIZE_DIR_W;      }
    if (do_button_img(NULL, bw,bh, UI_NONE, center_clip)) { resize_dialog_dir = RESIZE_DIR_CENTER; }
    if (do_button_img(NULL, bw,bh, UI_NONE, e_clip))      { resize_dialog_dir = RESIZE_DIR_E;      }

    _cursor.x  = x;
    _cursor.y += bh;

    if (do_button_img(NULL, bw,bh, UI_NONE, sw_clip))     { resize_dialog_dir = RESIZE_DIR_SW;     }
    if (do_button_img(NULL, bw,bh, UI_NONE, s_clip))      { resize_dialog_dir = RESIZE_DIR_S;      }
    if (do_button_img(NULL, bw,bh, UI_NONE, se_clip))     { resize_dialog_dir = RESIZE_DIR_SE;     }

    if (old_dir != resize_dialog_dir) {
        internal__calculate_dir_clips();
    }
}

FILDEF void internal__okay_resize ()
{
    if (current_resize_width < MINIMUM_LEVEL_WIDTH || current_resize_height < MINIMUM_LEVEL_HEIGHT) {
        show_alert("Warning", format_string("Minimum level size is %dx%d!", MINIMUM_LEVEL_WIDTH, MINIMUM_LEVEL_HEIGHT).c_str(),
            ALERT_TYPE_WARNING, ALERT_BUTTON_OK, "WINRESIZE");
        return;
    }

    le_resize_okay();
    hide_window("WINRESIZE");
}

FILDEF void open_resize (int _lw, int _lh)
{
    set_window_pos("WINRESIZE", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);

    if (_lw > 0) { current_resize_width = _lw; }
    if (_lh > 0) { current_resize_height = _lh; }

    resize_dialog_dir = RESIZE_DIR_CENTER;
    internal__calculate_dir_clips();

    show_window("WINRESIZE");
}

FILDEF void do_resize ()
{
    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    set_ui_font(&get_editor_regular_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    ////////////////////////////////////////

    float bb = RESIZE_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2.0f);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the resize.
    Vec2 btn_cursor = { 0.0f, WINDOW_BORDER };
    begin_panel(0.0f, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    // std::string okay_text((resize_dialog_type == RESIZE_DIALOG_NEW) ? "Create" : "Resize");

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Resize")) { internal__okay_resize(); }
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) { cancel_resize();         }

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

    Vec2 cursor = { RESIZE_XPAD, RESIZE_YPAD };

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    float label_w_w = get_text_width_scaled(get_editor_regular_font(), RESIZE_WIDTH_LABEL);
    float label_h_w = get_text_width_scaled(get_editor_regular_font(), RESIZE_HEIGHT_LABEL);

    float text_box_w = (vw-(RESIZE_XPAD*2.0f));
    float label_w = std::max(label_w_w, label_h_w);

    std::string w_str(std::to_string(current_resize_width));
    std::string h_str(std::to_string(current_resize_height));

    do_text_box_labeled(text_box_w, RESIZE_TEXT_BOX_H, UI_NUMERIC, w_str, label_w, RESIZE_WIDTH_LABEL, "0");
    advance_panel_cursor(RESIZE_YPAD);
    do_text_box_labeled(text_box_w, RESIZE_TEXT_BOX_H, UI_NUMERIC, h_str, label_w, RESIZE_HEIGHT_LABEL, "0");

    if (atoi(w_str.c_str()) > MAXIMUM_LEVEL_WIDTH) {
        w_str = std::to_string(MAXIMUM_LEVEL_WIDTH);
    }
    if (atoi(h_str.c_str()) > MAXIMUM_LEVEL_HEIGHT) {
        h_str = std::to_string(MAXIMUM_LEVEL_HEIGHT);
    }

    int old_resize_width = current_resize_width;
    int new_resize_width = atoi(w_str.c_str());
    if (new_resize_width != old_resize_width) {
        current_resize_width = new_resize_width;
    }
    int old_resize_height = current_resize_height;
    int new_resize_height = atoi(h_str.c_str());
    if (new_resize_height != old_resize_height) {
        current_resize_height = new_resize_height;
    }

    internal__do_resize_alignment(cursor);

    end_panel();
    end_panel();
}

FILDEF void cancel_resize ()
{
    hide_window("WINRESIZE");
}

FILDEF void handle_resize_events ()
{
    if (!is_window_focused("WINRESIZE")) { return; }

    if (!text_box_is_active()) {
        if (main_event.type == SDL_KEYDOWN) {
            switch (main_event.key.keysym.sym) {
            case (SDLK_RETURN): { internal__okay_resize(); } break;
            case (SDLK_ESCAPE): { cancel_resize();         } break;
            }
        }
    }
}

FILDEF int get_resize_w ()
{
    return current_resize_width;
}
FILDEF int get_resize_h ()
{
    return current_resize_height;
}

FILDEF Resize_Dir get_resize_dir ()
{
    return resize_dialog_dir;
}

FILDEF bool resize_dir_is_north (Resize_Dir _dir)
{
    return (_dir == RESIZE_DIR_NW || _dir == RESIZE_DIR_N || _dir == RESIZE_DIR_NE);
}
FILDEF bool resize_dir_is_east (Resize_Dir _dir)
{
    return (_dir == RESIZE_DIR_NE || _dir == RESIZE_DIR_E || _dir == RESIZE_DIR_SE);
}
FILDEF bool resize_dir_is_south (Resize_Dir _dir)
{
    return (_dir == RESIZE_DIR_SW || _dir == RESIZE_DIR_S || _dir == RESIZE_DIR_SE);
}
FILDEF bool resize_dir_is_west (Resize_Dir _dir)
{
    return (_dir == RESIZE_DIR_NW || _dir == RESIZE_DIR_W || _dir == RESIZE_DIR_SW);
}
