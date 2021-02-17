FILDEF bool internal__create_texture_atlas (Texture_Atlas& atlas, GonObject gon)
{
    std::string texture_file(gon["texture"].String());
    if (!load_texture_resource(texture_file, atlas.texture))
    {
        LOG_ERROR(ERR_MIN, "Failed to load texture atlas image!");
        return false;
    }

    for (const auto& obj: gon["clips"].children_array)
    {
        s32   id        = std::stoi(obj["id"].String());
        auto& clip_data = obj["clip"].children_array;
        quad clip
        {
        CAST(float, clip_data[0].Number()),
        CAST(float, clip_data[1].Number()),
        CAST(float, clip_data[2].Number()),
        CAST(float, clip_data[3].Number())
        };
        atlas.clips.insert(std::pair<s32, quad>(id, clip));
    }

    return true;
}

FILDEF bool load_texture_atlas_from_file (Texture_Atlas& atlas, std::string file_name)
{
    file_name = make_path_absolute(file_name);
    return internal__create_texture_atlas(atlas, GonObject::Load(file_name));
}
FILDEF bool load_texture_atlas_from_data (Texture_Atlas& atlas, const std::vector<u8>& file_data)
{
    std::string buffer(file_data.begin(), file_data.end());
    return internal__create_texture_atlas(atlas, GonObject::LoadFromBuffer(buffer));
}

FILDEF void free_texture_atlas (Texture_Atlas& atlas)
{
    free_texture(atlas.texture);
    atlas.clips.clear();
}

FILDEF quad& get_atlas_clip (Texture_Atlas& atlas, s32 key)
{
    return atlas.clips[key];
}
