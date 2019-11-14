GLOBAL constexpr float TEXTURE_ATLAS_W_LARGE = 4096.0f;
GLOBAL constexpr float TEXTURE_ATLAS_H_LARGE = 4096.0f;
GLOBAL constexpr float TEXTURE_ATLAS_W_SMALL = 1024.0f;
GLOBAL constexpr float TEXTURE_ATLAS_H_SMALL = 1024.0f;

FILDEF bool internal__create_texture_atlas (Texture_Atlas& _atlas, GonObject _gon)
{
    std::string texture_file(_gon["texture"].String());
    if (!load_texture_resource(texture_file, _atlas.texture)) {
        LOG_ERROR(ERR_MIN, "Failed to load texture atlas image!");
        return false;
    }

    for (const auto& obj: _gon["clips"].children_array) {
        std::string id_str = obj["id"].String();
        const auto& clip_data = obj["clip"].children_array;

        s32 id = std::stoi(id_str);
        Quad clip = { (float)clip_data[0].Number(), (float)clip_data[1].Number(), (float)clip_data[2].Number(), (float)clip_data[3].Number() };

        // printf("%d [ %f %f %f %f ]\n", id, clip.x,clip.y,clip.w,clip.h);
        _atlas.clips.insert(std::pair<s32, Quad>(id, clip));
    }

    return true;
}

FILDEF bool load_texture_atlas_from_file (Texture_Atlas& _atlas, const char* _file_name)
{
    return internal__create_texture_atlas(_atlas, GonObject::Load(_file_name));
}
FILDEF bool load_texture_atlas_from_data (Texture_Atlas& _atlas, const std::vector<u8>& _file_data)
{
    return internal__create_texture_atlas(_atlas, GonObject::LoadFromBuffer(std::string(_file_data.begin(), _file_data.end())));
}

FILDEF void free_texture_atlas (Texture_Atlas& _atlas)
{
    free_texture(_atlas.texture);
    _atlas.clips.clear();
}

FILDEF Quad& get_atlas_clip (Texture_Atlas& _atlas, s32 _key)
{
    return _atlas.clips[_key];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if defined(DEBUG_BUILD)
STDDEF void internal__generate_texture_atlas (const char* _file_name, const char* _path, float _w, float _h)
{
    // This is some old code ported over to here so I'm not sure how good it is.
    // Doesn't really matter though as it is not being shipped with the release.

    const int atlas_w = CAST(int, _w);
    const int atlas_h = CAST(int, _h);

    std::vector<std::string> files;
    list_path_files_r(make_path_absolute(_path).c_str(), files);

    // We will be loading all textures in the same 8-bit component RGBA format.
    constexpr u32 SURFACE_FORMAT  = SDL_PIXELFORMAT_RGBA32;
    constexpr int BYTES_PER_PIXEL = 4;
    constexpr int BITS_PER_PIXEL  = BYTES_PER_PIXEL * 8;

    size_t surface_count = files.size();

    // It is important to use calloc to ensure all pointers are set to NULL!
    // We must also keep the raw texture data until we are done with the SDL
    // surfaces as they do not make a copy of the pixel data during creation.
    SDL_Surface** surfaces = cstd_calloc(SDL_Surface*, surface_count);
    u8** raw_data = cstd_calloc(u8*, surface_count);
    if (!surfaces || !raw_data) {
        LOG_ERROR(ERR_MIN, "Failed to allocate texture atlas surfaces!");
        return;
    }

    defer {
        for (size_t i=0; i<surface_count; ++i) {
            SDL_FreeSurface(surfaces[i]);
            stbi_image_free(raw_data[i]);
        }
        cstd_free(surfaces); surfaces = NULL;
        cstd_free(raw_data); raw_data = NULL;
    };

    // Go through each of the textures to be packed and load as surfaces.
    for (size_t i=0; i<surface_count; ++i) {
        const char* file_name = files[i].c_str();
        int w, h, bpp;
        raw_data[i] = stbi_load(file_name, &w, &h, &bpp, BYTES_PER_PIXEL);
        if (!raw_data[i]) {
            LOG_ERROR(ERR_MIN, "Failed to load atlas image file '%s'!", file_name);
            return;
        }

        int pitch = w * BYTES_PER_PIXEL;
        surfaces[i] = SDL_CreateRGBSurfaceWithFormatFrom(raw_data[i], w, h, BITS_PER_PIXEL, pitch, SURFACE_FORMAT);
        if (!surfaces[i]) {
            LOG_ERROR(ERR_MIN, "Failed to create atlas surface '%s'!", file_name);
            return;
        }

        // We need to set the blendmode to none because when we later make the
        // final atlas surface it will automatically filled with RGBA data of
        // all zeroes. So, if we had SDL_BLENDMODE_BLEND then the blit surface
        // calls would attempt to blend the semi-transparent pixels of each of
        // the surfaces with the black of the atlas surface -- leading to the
        // semi-transparent parts of the texture clips being slightly darker.
        SDL_SetSurfaceBlendMode(surfaces[i], SDL_BLENDMODE_NONE);
    }

    // Allocate memory for the necessary components used by the rect packer.
    int node_count = atlas_w;
    stbrp_node* nodes = cstd_malloc(stbrp_node, node_count);
    if (!nodes) {
        LOG_ERROR(ERR_MIN, "Failed to allocate atlas packing nodes!");
        return;
    }
    defer { cstd_free(nodes); nodes = NULL; };

    int rect_count = CAST(int, surface_count);
    stbrp_rect* rects = cstd_malloc(stbrp_rect, rect_count);
    if (!rects) {
        LOG_ERROR(ERR_MIN, "Failed to allocate atlas packing rects!");
        return;
    }
    defer { cstd_free(rects); rects = NULL; };

    // We need to store the size of each texture into the rects so that stb
    // can know the dimensions when packing the rects into a texture atlas.
    for (int i=0; i<rect_count; ++i) {
        rects[i].w = CAST(stbrp_coord, surfaces[i]->w);
        rects[i].h = CAST(stbrp_coord, surfaces[i]->h);
    }

    // Basic initialization needed to begin using the stb_rect_pack library.
    stbrp_context context;
    stbrp_init_target(&context, atlas_w,atlas_h, nodes, node_count);
    if (!stbrp_pack_rects(&context, rects, rect_count)) {
        LOG_ERROR(ERR_MIN, "Failed to pack texture atlas images!");
        return;
    }

    SDL_Surface* atlas_surface = SDL_CreateRGBSurfaceWithFormat(0, atlas_w,atlas_h, BITS_PER_PIXEL, SURFACE_FORMAT);
    if (!atlas_surface) {
        LOG_ERROR(ERR_MIN, "Failed to create final atlas surface! (%s)", SDL_GetError());
        return;
    }
    defer { SDL_FreeSurface(atlas_surface); atlas_surface = NULL; };

    std::string file_name(build_resource_string(_file_name));
    FILE* file = fopen(std::string(file_name + ".txt").c_str(), "w");
    if (!file) {
        LOG_ERROR(ERR_MIN, "Failed to create atlas lookup GON!");
        return;
    }
    defer { fclose(file); };

    fprintf(file, "texture \"%s\"\n", std::string(std::string(_file_name) + ".png").c_str());
    fprintf(file, "clips\n[\n");

    // Blit each of the individual surfaces to the final atlas surface and
    // cache the clip information for each texture in the lookup table.
    for (size_t i=0; i<surface_count; ++i) {
        SDL_Rect rect = { CAST(int, rects[i].x), CAST(int, rects[i].y), CAST(int, rects[i].w), CAST(int, rects[i].h) };
        if (SDL_BlitSurface(surfaces[i], NULL, atlas_surface, &rect) != 0) {
            LOG_ERROR(ERR_MIN, "Failed to blit texture to the atlas! (%s)", SDL_GetError());
            return;
        }

        constexpr int PADDING = 12; // Should also be updated in texture_pack!!!

        int x = rects[i].x +  PADDING;
        int y = rects[i].y +  PADDING;
        int w = rects[i].w - (PADDING * 2);
        int h = rects[i].h - (PADDING * 2);

        std::string id_str(strip_file_path_and_ext(files[i].c_str()));
        int id = std::stoi(id_str);
        if (id_str.find("-alt") != std::string::npos) { id += ALT_OFFSET; }

        fprintf(file, "{ id %d  clip [ %d %d %d %d ] }\n", id, x,y,w,h);
    }

    fprintf(file, "]\n");

    stbi_write_png(std::string(file_name + ".png").c_str(), atlas_w,atlas_h, BYTES_PER_PIXEL, atlas_surface->pixels, atlas_w*BYTES_PER_PIXEL);

    LOG_DEBUG("Created Texture Atlas: %s", strip_file_path(_file_name).c_str());
}
FILDEF void generate_texture_atlases ()
{
    if (main_event.type == SDL_KEYDOWN) {
        if (main_event.key.keysym.sym == SDLK_F11) {
            internal__generate_texture_atlas("textures/editor_icons/new_large", "../dev/editor_icons_padded/new_large/", TEXTURE_ATLAS_W_LARGE,TEXTURE_ATLAS_H_LARGE);
            internal__generate_texture_atlas("textures/editor_icons/new_small", "../dev/editor_icons_padded/new_small/", TEXTURE_ATLAS_W_SMALL,TEXTURE_ATLAS_H_SMALL);
            internal__generate_texture_atlas("textures/editor_icons/old_large", "../dev/editor_icons_padded/old_large/", TEXTURE_ATLAS_W_LARGE,TEXTURE_ATLAS_H_LARGE);
            internal__generate_texture_atlas("textures/editor_icons/old_small", "../dev/editor_icons_padded/old_small/", TEXTURE_ATLAS_W_SMALL,TEXTURE_ATLAS_H_SMALL);
        }
    }
}
#endif // DEBUG_BUILD
