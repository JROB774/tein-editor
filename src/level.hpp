#pragma once

GLOBAL constexpr float DEFAULT_LEVEL_WIDTH  = 54.00f;
GLOBAL constexpr float DEFAULT_LEVEL_HEIGHT = 32.00f;
// These are stored as ints because they are only used by new/resize dialogs.
GLOBAL constexpr int   MINIMUM_LEVEL_WIDTH  = 54;
GLOBAL constexpr int   MINIMUM_LEVEL_HEIGHT = 32;
GLOBAL constexpr int   MAXIMUM_LEVEL_WIDTH  = 2840;
GLOBAL constexpr int   MAXIMUM_LEVEL_HEIGHT = 2840;

typedef u32 Level_Layer;
typedef s32 Tile_ID;

GLOBAL constexpr Level_Layer LEVEL_LAYER_TAG     = 0;
GLOBAL constexpr Level_Layer LEVEL_LAYER_OVERLAY = 1;
GLOBAL constexpr Level_Layer LEVEL_LAYER_ACTIVE  = 2; // Combo of Basic and Entity.
GLOBAL constexpr Level_Layer LEVEL_LAYER_BACK1   = 3;
GLOBAL constexpr Level_Layer LEVEL_LAYER_BACK2   = 4;
GLOBAL constexpr Level_Layer LEVEL_LAYER_TOTAL   = 5;

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

STDDEF bool load_level         (      Level&   _level, const char* _file_name);
STDDEF bool save_level         (const Level&   _level, const char* _file_name);

// A custom file format. Exactly the same as the default level format except
// the first part of the file until zero is the name of the level. This is
// done so that the name of the file can also be restored when the editor
// is loaded again after a fatal failure occurs and restore files are saved.

struct Level_Tab;

STDDEF bool load_restore_level (      Level_Tab& _tab, const char* _file_name);
STDDEF bool save_restore_level (const Level_Tab& _tab, const char* _file_name);


FILDEF bool create_blank_level (Level& _level, int _w=CAST(int, DEFAULT_LEVEL_WIDTH), int _h=CAST(int, DEFAULT_LEVEL_HEIGHT));
