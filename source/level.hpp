#pragma once

GLOBAL constexpr float DEFAULT_LEVEL_WIDTH  = 54;
GLOBAL constexpr float DEFAULT_LEVEL_HEIGHT = 32;
GLOBAL constexpr int   MINIMUM_LEVEL_WIDTH  = 1;
GLOBAL constexpr int   MINIMUM_LEVEL_HEIGHT = 1;
GLOBAL constexpr int   MAXIMUM_LEVEL_WIDTH  = 5400;
GLOBAL constexpr int   MAXIMUM_LEVEL_HEIGHT = 3200;

typedef u32 Level_Layer;

GLOBAL constexpr Level_Layer LEVEL_LAYER_TAG     = 0;
GLOBAL constexpr Level_Layer LEVEL_LAYER_OVERLAY = 1;
GLOBAL constexpr Level_Layer LEVEL_LAYER_ACTIVE  = 2; // Combo of Basic and Entity.
GLOBAL constexpr Level_Layer LEVEL_LAYER_BACK1   = 3;
GLOBAL constexpr Level_Layer LEVEL_LAYER_BACK2   = 4;
GLOBAL constexpr Level_Layer LEVEL_LAYER_TOTAL   = 5;

typedef s32 Tile_ID;

struct Level_Header
{
    s32 version;
    s32 width;
    s32 height;
    s32 layers;
};

typedef std::array<std::vector<Tile_ID>, LEVEL_LAYER_TOTAL> Level_Data;

struct Level
{
    Level_Header header;
    Level_Data data;
};

STDDEF bool load_level         (      Level& level, std::string file_name);
STDDEF bool save_level         (const Level& level, std::string file_name);

// A custom file format. Exactly the same as the default level format except
// the first part of the file until zero is the name of the level. This is
// done so that the name of the file can also be restored when the editor
// is loaded again after a fatal failure occurs and restore files are saved.

struct Tab; // Defined in <editor.hpp>

STDDEF bool load_restore_level (      Tab&   tab,   std::string file_name);
STDDEF bool save_restore_level (const Tab&   tab,   std::string file_name);



FILDEF bool create_blank_level (Level& level, int w = DEFAULT_LEVEL_WIDTH,
                                              int h = DEFAULT_LEVEL_HEIGHT);
