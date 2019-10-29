#pragma once

GLOBAL constexpr u32 UI_CURSOR_BLINK_INTERVAL = 700;

// These colors are filled with the appropriate values based on whether the
// user would prefer to use the dark or light theme for the level editor.

GLOBAL Vec4 ui_color_black;
GLOBAL Vec4 ui_color_ex_dark;
GLOBAL Vec4 ui_color_dark;
GLOBAL Vec4 ui_color_med_dark;
GLOBAL Vec4 ui_color_medium;
GLOBAL Vec4 ui_color_med_light;
GLOBAL Vec4 ui_color_light;
GLOBAL Vec4 ui_color_ex_light;
GLOBAL Vec4 ui_color_white;

// The function type that is called by various UI widgets when triggered.
typedef void (*UI_Action)(void);

typedef u32 UI_Flag;

GLOBAL constexpr UI_Flag UI_NONE       = 0x00000000;
GLOBAL constexpr UI_Flag UI_LOCKED     = 0x00000001;
GLOBAL constexpr UI_Flag UI_INACTIVE   = 0x00000002;
GLOBAL constexpr UI_Flag UI_HIGHLIGHT  = 0x00000004;
GLOBAL constexpr UI_Flag UI_DARKEN     = 0x00000008;
GLOBAL constexpr UI_Flag UI_TOOLTIP    = 0x00000010;
GLOBAL constexpr UI_Flag UI_SINGLE     = 0x00000020;
// Flags for what type of characters can be written into a text box.
GLOBAL constexpr UI_Flag UI_ALPHABETIC = 0x00000040;
GLOBAL constexpr UI_Flag UI_NUMERIC    = 0x00000080;
GLOBAL constexpr UI_Flag UI_ALPHANUM   = 0x00000100;
GLOBAL constexpr UI_Flag UI_FILEPATH   = 0x00000200;
// Flags for flipping images drawn with the user interface.
GLOBAL constexpr UI_Flag UI_FLIP_HORZ  = 0x00000400;
GLOBAL constexpr UI_Flag UI_FLIP_VERT  = 0x00000800;
GLOBAL constexpr UI_Flag UI_FLIP_BOTH  = UI_FLIP_HORZ|UI_FLIP_VERT;

enum UI_Align
{
    UI_ALIGN_CENTER,
    UI_ALIGN_LEFT,
    UI_ALIGN_RIGHT,
    UI_ALIGN_TOP,
    UI_ALIGN_BOTTOM
};

enum UI_Dir
{
    UI_DIR_UP,
    UI_DIR_RIGHT,
    UI_DIR_DOWN,
    UI_DIR_LEFT
};

GLOBAL bool should_push_ui_redraw_event;

FILDEF bool init_ui_system   ();
FILDEF void load_ui_theme    ();
FILDEF void reset_ui_state   ();
FILDEF void handle_ui_events ();

// Determines if we are using the light theme for the user interface or not.
FILDEF bool is_ui_light ();

FILDEF Vec2 ui_get_relative_mouse ();

// Check whether the mouse is inside bounds relative to the current panels.
FILDEF bool mouse_in_ui_bounds_xywh (float _x, float _y, float _w, float _h);
FILDEF bool mouse_in_ui_bounds_xywh (Quad _b);

FILDEF void set_ui_texture (Texture* _tex);
FILDEF void set_ui_font    (Font*   _font);

FILDEF bool is_there_a_hot_ui_element ();
FILDEF bool is_there_a_hit_ui_element ();

FILDEF void deselect_active_text_box ();
FILDEF void deselect_active_text_box (std::string& _text, const char* _default);
FILDEF bool text_box_is_active       ();

FILDEF bool hotkey_is_active              ();
FILDEF void deselect_active_hotkey_rebind ();

// Leaving the color parameter as default will make a transparent panel.
STDDEF void    begin_panel       (float _x, float _y, float _w, float _h, UI_Flag _flags, Vec4 _c = {});
FILDEF void    begin_panel       (Quad _bounds, UI_Flag _flags, Vec4 _c = {});
STDDEF bool    begin_click_panel (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _info = NULL);
STDDEF void    end_panel         ();
FILDEF float   get_panel_w       ();
FILDEF float   get_panel_h       ();
FILDEF Vec2    get_panel_offset  ();
FILDEF Vec2    get_panel_cursor  ();
FILDEF void    disable_panel_cursor_advance ();
FILDEF void    enable_panel_cursor_advance  ();
FILDEF void    advance_panel_cursor (float _advance);
FILDEF void    set_panel_cursor     (Vec2* _cursor);
FILDEF void    set_panel_cursor_dir (UI_Dir   _dir);
FILDEF void    set_panel_flags      (UI_Flag _flags);
FILDEF UI_Flag get_panel_flags      ();

FILDEF float calculate_button_txt_width (const char* _text);

STDDEF bool do_button_img (UI_Action _action, float _w, float _h, UI_Flag _flags, const Quad* _clip = NULL, const char* _info = NULL, const char* _kb = NULL, const char* _name = NULL);
STDDEF bool do_button_txt (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _text,        const char* _info = NULL, const char* _kb = NULL, const char* _name = NULL);
FILDEF bool do_button_txt (UI_Action _action,           float _h, UI_Flag _flags, const char* _text,        const char* _info = NULL, const char* _kb = NULL, const char* _name = NULL);

STDDEF void do_label (UI_Align _horz, UI_Align _vert, float _w, float _h, const char* _text, Vec4 _bg = {});
FILDEF void do_label (UI_Align _horz, UI_Align _vert,           float _h, const char* _text, Vec4 _bg = {});

STDDEF void do_label_hyperlink (UI_Align _horz, UI_Align _vert, float _w, float _h, const char* _text, const char* _link, const char* _href, Vec4 _bg = {});

STDDEF void do_text_box         (float _w, float _h, UI_Flag _flags, std::string& _text,                                     const char* _default = NULL, UI_Align _halign=UI_ALIGN_RIGHT);
STDDEF void do_text_box_labeled (float _w, float _h, UI_Flag _flags, std::string& _text, float _label_w, const char* _label, const char* _default = NULL, UI_Align _halign=UI_ALIGN_RIGHT);

STDDEF void do_hotkey_rebind (float _w, float _h, UI_Flag _flags, Key_Binding& _kb);

STDDEF void do_icon (float _w, float _h, Texture& _tex, const Quad* _clip = NULL);
FILDEF void do_quad (float _w, float _h, Vec4 _color);

FILDEF void do_separator (float _size);

FILDEF void do_scrollbar (Quad _bounds,                           float _content_height, float& _scroll_offset);
STDDEF void do_scrollbar (float _x, float _y, float _w, float _h, float _content_height, float& _scroll_offset);

// Hack: These are implemented only for use with the tab bar.
STDDEF void begin_panel_gradient       (float _x, float _y, float _w, float _h, UI_Flag _flags, Vec4 _cl = {}, Vec4 _cr = {});
FILDEF void begin_panel_gradient       (Quad _bounds, UI_Flag _flags, Vec4 _cl = {}, Vec4 _cr = {});
STDDEF bool begin_click_panel_gradient (UI_Action _action, float _w, float _h, UI_Flag _flags, const char* _info = NULL);
STDDEF bool do_button_img_gradient     (UI_Action _action, float _w, float _h, UI_Flag _flags, const Quad* _clip = NULL, const char* _info = NULL, const char* _kb = NULL, const char* _name = NULL);
