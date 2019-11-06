// GitHub Releases API: https://developer.github.com/v3/repos/releases/#get-the-latest-release
GLOBAL constexpr const char* GITHUB_API_USER_AGENT = "tein-editor";
GLOBAL constexpr const char* GITHUB_API_URL = "https://api.github.com/repos/thatb0y/tein-editor/releases/latest";

GLOBAL constexpr int HTTP_CODE_OK      = 200;
GLOBAL constexpr int HTTP_CODE_CREATED = 201;

GLOBAL constexpr float UPDATE_DIALOG_BOTTOM_BORDER = 26.0f;
GLOBAL constexpr float UPDATE_DIALOG_WAIT_TIME     = 0.33f; // Seconds.

GLOBAL CURL*                 curl;
GLOBAL SDL_TimerID   update_timer;
GLOBAL bool    there_is_an_update;
GLOBAL nlohmann::json update_json;

GLOBAL std::string update_title;
GLOBAL std::string update_body;

GLOBAL float update_dialog_content_height;
GLOBAL float update_dialog_scroll_offset;

FILDEF u32 internal__update_show_callback (u32 _interval, void* _user_data)
{
    push_editor_event(EDITOR_EVENT_SHOW_UPDATE);
    return 0;
}

FILDEF void internal__update_dialog_download ()
{
    load_webpage("https://github.com/thatb0y/tein-editor/releases/latest");
    hide_window("WINUPDATE");
}
FILDEF void internal__update_dialog_cancel ()
{
    hide_window("WINUPDATE");
}

FILDEF size_t internal__curl_write_callback (const char* _in, size_t _size, size_t _num, std::string* _out)
{
    size_t total_bytes = _size * _num;
    _out->append(_in, total_bytes);
    return total_bytes;
}

// Example Curl GET: https://gist.github.com/connormanning/41efa6075515019e499c
FILDEF void check_for_updates ()
{
    LOG_DEBUG("Checking for new releases...");

    curl = curl_easy_init();
    if (!curl) {
        LOG_ERROR(ERR_MIN, "Failed to initialize Curl!");
        return;
    }
    defer {
        curl_easy_cleanup(curl);
    };

    curl_easy_setopt(curl, CURLOPT_USERAGENT,      GITHUB_API_USER_AGENT);
    curl_easy_setopt(curl, CURLOPT_URL,            GITHUB_API_URL       );
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE,      CURL_IPRESOLVE_V4    );
    curl_easy_setopt(curl, CURLOPT_TIMEOUT,        10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    long http_code = 0;
    std::unique_ptr<std::string> http_data(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, internal__curl_write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,     http_data.get());

    // Run our HTTP GET command and capture the HTTP response code.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    if (http_code != HTTP_CODE_OK && http_code != HTTP_CODE_CREATED) {
        if (http_code != 0) {
            LOG_ERROR(ERR_MIN, "Failed to GET update information:\n\t%d: %s", http_code, http_data.get()->c_str());
        } else {
            LOG_ERROR(ERR_MIN, "Failed to GET update information!");
        }
        return;
    }

    update_json = nlohmann::json::parse(*http_data.get());

    std::string current_version(format_string("v%d.%d.%d", EDITOR_MAJOR,EDITOR_MINOR,EDITOR_PATCH));
    std::string latest_version(current_version);
    if (update_json.find("tag_name") != update_json.end()) {
        latest_version = update_json["tag_name"].get<std::string>();
    }

    // printf("%s\n", current_version.c_str());
    // printf("%s\n", latest_version.c_str());

    if (current_version != latest_version) {
        LOG_DEBUG("New Release Found");
        there_is_an_update = true;
    } else {
        LOG_DEBUG("No New Releases");
        there_is_an_update = false;
    }
}

FILDEF void open_update_window_timed ()
{
    // Looked weird showing immediately so we put it on a timer.
    u32 interval = CAST(u32, (UPDATE_DIALOG_WAIT_TIME * 1000.0f));
    update_timer = SDL_AddTimer(interval, internal__update_show_callback, NULL);
    if (!update_timer) { // Just show it immediately.
        open_update_window();
    }
}
FILDEF void open_update_window ()
{
    update_title = update_json["name"].get<std::string>();
    update_body  = update_json["body"].get<std::string>();

    // Remove the first line because we don't need that bit.
    update_body.erase(0, update_body.find("\n")+1);

    update_dialog_scroll_offset = 0.0f;

    show_window("WINUPDATE");
}

FILDEF void do_update ()
{
    Quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2.0f);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2.0f);

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    ////////////////////////////////////////

    float bb = PATH_DIALOG_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2.0f);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the path dialog.
    Vec2 btn_cursor = { 0.0f, WINDOW_BORDER };
    begin_panel(0.0f, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    set_ui_font(&get_editor_regular_font());

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Download")) { internal__update_dialog_download(); }
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel"  )) { internal__update_dialog_cancel  (); }

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

    constexpr float HEADER_SECTION = 68.0f;

    constexpr float XPAD1 = 8.0f;
    constexpr float YPAD1 = 8.0f;

    Vec2 cursor = { XPAD1,YPAD1 };

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    constexpr float MAIN_H = 24.0f;
    constexpr float SUB_H = 20.0f;

    set_font_point_size(get_editor_bold_font(), LARGE_FONT_POINT_SIZE);
    set_ui_font(&get_editor_bold_font());
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, MAIN_H, update_title.c_str());

    cursor.y -= 2.0f;

    set_font_point_size(get_editor_regular_font(), SMALL_FONT_POINT_SIZE);
    set_ui_font(&get_editor_regular_font());
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, SUB_H, "There is a new editor version available!");

    cursor.y = YPAD1 + HEADER_SECTION - SUB_H;

    set_font_point_size(get_editor_bold_font(), SMALL_FONT_POINT_SIZE);
    set_ui_font(&get_editor_bold_font());
    do_label(UI_ALIGN_LEFT,UI_ALIGN_BOTTOM, SUB_H, "Version Changelog:");

    ////////////////////////////////////////

    constexpr float SCROLLBAR_WIDTH = 12.0f;

    constexpr float XPAD2 = 4.0f;
    constexpr float YPAD2 = 4.0f;

    float px = XPAD2;
    float py = YPAD1 + HEADER_SECTION + roundf(YPAD1*0.66f);
    float pw = get_viewport().w - (XPAD2*2.0f) - 1.0f - SCROLLBAR_WIDTH;
    float ph = get_viewport().h - py - YPAD2;

    begin_panel(px,py,pw,ph, UI_NONE, ui_color_ex_dark);

    constexpr float XPAD3 = 6.0f;
    constexpr float YPAD3 = 4.0f;

    begin_panel(XPAD3,YPAD3,pw-(XPAD3*2.0f),ph-(YPAD3*2.0f), UI_NONE);

    Vec2 inner_cursor = { 0.0f,0.0f };
    set_panel_cursor(&inner_cursor);

    set_font_point_size(get_editor_regular_font(), SMALL_FONT_POINT_SIZE);
    set_font_point_size(get_editor_bold_font(), SMALL_FONT_POINT_SIZE);

    float label_w = get_viewport().w;
    update_dialog_content_height = get_markdown_h(label_w, update_body.c_str()) + YPAD3;
    float sx = get_viewport().w + XPAD3 + 1.0f;
    float sy = 0.0f - YPAD3;
    float sw = SCROLLBAR_WIDTH;
    float sh = get_viewport().h + (YPAD3*2.0f);
    do_scrollbar(sx, sy, sw, sh, update_dialog_content_height, update_dialog_scroll_offset);

    do_markdown(label_w, update_dialog_content_height, update_body.c_str());

    end_panel();
    end_panel();
    end_panel();
    end_panel();

    // Reset these so they don't interfere with any other part of the editor.
    set_font_point_size(get_editor_regular_font(), SMALL_FONT_POINT_SIZE);
    set_font_point_size(get_editor_bold_font(), SMALL_FONT_POINT_SIZE);
}

FILDEF void handle_update_events ()
{
    if (main_event.type == SDL_USEREVENT) {
        if (main_event.user.code == EDITOR_EVENT_SHOW_UPDATE) {
            open_update_window();
        }
    }

    if (!is_window_focused("WINUPDATE")) { return; }

    if (main_event.type == SDL_KEYDOWN) {
        if (main_event.key.keysym.sym == SDLK_RETURN) {
            internal__update_dialog_download();
        } else if (main_event.key.keysym.sym == SDLK_ESCAPE) {
            internal__update_dialog_cancel();
        }
    }
}

FILDEF bool are_there_updates ()
{
    return there_is_an_update;
}
