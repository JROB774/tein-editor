#pragma once

struct Map_Node
{
    int x;
    int y;

    std::string lvl;
};

typedef std::vector<Map_Node> Map;

STDDEF bool load_map         (      Tab& _tab, const char* _file_name);
STDDEF bool save_map         (const Tab& _tab, const char* _file_name);

// A custom file format. Exactly the same as the default world format except
// the first part of the file until zero is the name of the level. This is
// done so that the name of the file can also be restored when the editor
// is loaded again after a fatal failure occurs and restore files are saved.

// Defined in editor.hpp
struct Tab;

STDDEF bool load_restore_map (      Tab& _tab, const char* _file_name);
STDDEF bool save_restore_map (const Tab& _tab, const char* _file_name);



FILDEF int get_map_x_pos  (const Map& _map);
FILDEF int get_map_y_pos  (const Map& _map);
FILDEF int get_map_width  (const Map& _map);
FILDEF int get_map_height (const Map& _map);
