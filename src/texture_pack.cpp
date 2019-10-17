#if defined(DEBUG_BUILD)
FILDEF void internal__do_tile_padding (u8* _in, u8* _out, int _w, int _h, int _xpad, int _ypad, int _padding)
{
    constexpr int BPP = 4;

    // determine information regarding the tiles
    int tile_w = _w+(_padding*2);
    int tile_h = _h+(_padding*2);

    // create a buffer for handling each tile's padding
    u8* buffer = cstd_malloc(u8, (tile_w*tile_h)*BPP);
    if (!buffer) {
        LOG_ERROR(ERR_MIN, "Failed to allocate output padding buffer!");
        return;
    }
    defer { cstd_free(buffer); };

    for (int j=0, k=0; j<_h; ++j, ++k) {
        memcpy(&buffer[(_padding+k)*(tile_w*BPP)+(_padding*BPP)], &_in[j*(_w*BPP)], (_w*BPP));
    }

    int xpix = 0, ypix = 0;
    for (int iy=0; iy<tile_h; ++iy) {
        for (int ix=0; ix<(tile_w*BPP); ix+=BPP) {
            xpix = (ix/BPP)-_padding, ypix = iy-_padding;
            if (xpix < 0) { xpix = 0; } else if (xpix >= _w-1) { xpix = _w-1; }
            if (ypix < 0) { ypix = 0; } else if (ypix >= _h-1) { ypix = _h-1; }
            xpix += _padding, ypix += _padding;
            buffer[iy*(tile_w*BPP)+(ix+0)] = buffer[ypix*(tile_w*BPP)+((xpix*BPP)+0)];
            buffer[iy*(tile_w*BPP)+(ix+1)] = buffer[ypix*(tile_w*BPP)+((xpix*BPP)+1)];
            buffer[iy*(tile_w*BPP)+(ix+2)] = buffer[ypix*(tile_w*BPP)+((xpix*BPP)+2)];
            // if ((ix<(_padding*BPP)) || (iy<_padding) || (ix>=((_w+_padding)*BPP)) || (iy>=(_h+_padding))) {
            //     buffer[iy*(tile_w*BPP)+(ix+3)] = 0x00;
            // } else {
                buffer[iy*(tile_w*BPP)+(ix+3)] = buffer[ypix*(tile_w*BPP)+((xpix*BPP)+3)];
            // }
        }
    }

    for (int j=0, k=0; j<tile_h; ++j, ++k) {
        memcpy(&_out[j*((_w+_xpad)*BPP)], &buffer[k*(tile_w*BPP)], (tile_w*BPP));
    }
}
FILDEF void internal__pack_textures (const char* _in, const char* _out)
{
    constexpr int PADDING = 12; // Should also be updated in texture_atlas!!!
    constexpr int BPP = 4;

    std::vector<std::string> files;
    list_path_files_r(make_path_absolute(_in).c_str(), files);

    for (auto f: files) {
        int w, h;
        u8* in = stbi_load(f.c_str(), &w,&h,NULL,BPP);
        if (!in) {
            LOG_ERROR(ERR_MIN, "Failed to pad tile image \"%s\"", f.c_str());
            continue;
        }
        defer { stbi_image_free(in); };

        int xpad = PADDING*2;
        int ypad = PADDING*2;

        u8* out = cstd_malloc(u8, ((w + xpad) * (h + ypad)) * BPP);
        if (!out) {
            LOG_ERROR(ERR_MIN, "Failed to allocate padded tile image \"%s\"", f.c_str());
            continue;
        }
        defer { cstd_free(out); };

        internal__do_tile_padding(in, out, w,h, xpad,ypad, PADDING);

        std::string file_name(make_path_absolute(_out) + strip_file_path(f.c_str()));
        stbi_write_png(file_name.c_str(), w+xpad,h+ypad, BPP, out, (w+xpad)*BPP);
    }

    LOG_DEBUG("Padded Tiles: %s", _in);
}
FILDEF void pack_textures ()
{
    if (main_event.type == SDL_KEYDOWN) {
        if (main_event.key.keysym.sym == SDLK_F10) {
            internal__pack_textures("../dev/editor_icons/new_large/", "../dev/editor_icons_padded/new_large/");
            internal__pack_textures("../dev/editor_icons/new_small/", "../dev/editor_icons_padded/new_small/");
            internal__pack_textures("../dev/editor_icons/old_large/", "../dev/editor_icons_padded/old_large/");
            internal__pack_textures("../dev/editor_icons/old_small/", "../dev/editor_icons_padded/old_small/");
        }
    }
}
#endif // DEBUG_BUILD
