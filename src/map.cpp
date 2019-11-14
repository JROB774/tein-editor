// CSV parsing taken from here: https://stackoverflow.com/a/30338543
FILDEF std::vector<std::vector<std::string>> internal__read_csv (std::istream& in)
{
    enum class CSVState {
        UnquotedField,
        QuotedField,
        QuotedQuote
    };
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof()) {
        std::getline(in, row);
        if (in.bad() || in.fail()) {
            break;
        }
        CSVState state = CSVState::UnquotedField;
        std::vector<std::string> fields {""};
        size_t i = 0; // index of the current field
        for (char c : row) {
            switch (state) {
                case CSVState::UnquotedField:
                    switch (c) {
                        case ',': // end of field
                                  fields.push_back(""); i++;
                                  break;
                        case '"': state = CSVState::QuotedField;
                                  break;
                        default:  fields[i].push_back(c);
                                  break; }
                    break;
                case CSVState::QuotedField:
                    switch (c) {
                        case '"': state = CSVState::QuotedQuote;
                                  break;
                        default:  fields[i].push_back(c);
                                  break; }
                    break;
                case CSVState::QuotedQuote:
                    switch (c) {
                        case ',': // , after closing quote
                                  fields.push_back(""); i++;
                                  state = CSVState::UnquotedField;
                                  break;
                        case '"': // "" -> "
                                  fields[i].push_back('"');
                                  state = CSVState::QuotedField;
                                  break;
                        default:  // end of quote
                                  state = CSVState::UnquotedField;
                                  break; }
                    break;
            }
        }
        table.push_back(fields);
    }
    return table;
}

FILDEF bool internal__load_map (Tab& _tab, std::istream&& _stream)
{
    // Convert raw CSV values into our internal map format.
    auto csv = internal__read_csv(_stream);
    for (int iy=0; iy<CAST(int, csv.size()); ++iy) {
        const auto& row = csv.at(iy);
        for (int ix=0; ix<CAST(int, row.size()); ++ix) {
            const auto& field = row.at(ix);
            if (!field.empty()) {
                _tab.map.push_back({ ix,iy, field });
            }
        }
    }

    return true;
}

FILDEF bool internal__save_map (const Tab& _tab, FILE* _file)
{
    // If the map is empty just save an empty file.
    if (_tab.map.empty()) { return true; }

    int x = get_map_x_pos (_tab.map);
    int y = get_map_y_pos (_tab.map);
    int w = get_map_width (_tab.map);
    int h = get_map_height(_tab.map);

    // Write out the CSV formatted fields for the map.
    for (int iy=y; iy<h; ++iy) {
        for (int ix=x; ix<w; ++ix) {
            for (auto& node: _tab.map) {
                if (node.x == ix && node.y == iy) {
                    std::string txt(node.lvl);
                    if (_tab.map_node_info.active && (node.x == _tab.map_node_info.active->x && node.y == _tab.map_node_info.active->y)) {
                        txt = _tab.map_node_info.cached_lvl_text;
                    }
                    // Need to wrap in quotes if it contains a comma.
                    if (txt.find(',') == std::string::npos) {
                        fprintf(_file, "%s", txt.c_str());
                    } else {
                        fprintf(_file, "\"%s\"", txt.c_str());
                    }
                    break;
                }
            }
            if (ix != (w-1)) {
                fprintf(_file, ",");
            }
        }
        fprintf(_file, "\n");
    }

    return true;
}

STDDEF bool load_map (Tab& _tab, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.

    if (!does_file_exist(_file_name)) {
        LOG_ERROR(ERR_MED, "CSV file '%s' does not exist!", _file_name);
        return false;
    }

    return internal__load_map(_tab, std::ifstream(_file_name));
}

STDDEF bool save_map (const Tab& _tab, const char* _file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.

    FILE* file = fopen(_file_name, "wb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to save level file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    return internal__save_map(_tab, file);
}

STDDEF bool load_restore_map (Tab& _tab, const char* _file_name)
{
    std::string data(read_entire_file_str(_file_name));

    // Read until the null-terminator to get the name of the map.
    std::string map_name;
    for (auto c: data) {
        if (c) { map_name += c; continue; }
        break;
    }

    // Set the name of the map for the tab we are loading into.
    _tab.name = map_name;

    return internal__load_map(_tab, std::istringstream(data.substr(map_name.length()+1)));
}

STDDEF bool save_restore_map (const Tab& _tab, const char* _file_name)
{
    FILE* file = fopen(_file_name, "wb");
    if (!file) {
        LOG_ERROR(ERR_MED, "Failed to save restore file '%s'!", _file_name);
        return false;
    }
    defer { fclose(file); };

    // Write the name of the map + null-terminator for later restoration.
    if (_tab.name.empty()) {
        char null_terminator = '\0';
        fwrite(&null_terminator, sizeof(char), 1, file);
    } else {
        const char* name = _tab.name.c_str();
        fwrite(name, sizeof(char), strlen(name)+1, file);
    }

    return internal__save_map(_tab, file);
}

FILDEF int get_map_x_pos (const Map& _map)
{
    if (_map.empty()) { return 0; }
    int min_x = INT_MAX;
    for (auto node: _map) {
        min_x = std::min(node.x, min_x);
    }
    return min_x;
}
FILDEF int get_map_y_pos (const Map& _map)
{
    if (_map.empty()) { return 0; }
    int min_y = INT_MAX;
    for (auto node: _map) {
        min_y = std::min(node.y, min_y);
    }
    return min_y;
}

FILDEF int get_map_width (const Map& _map)
{
    if (_map.empty()) { return 1; }
    int min_x = INT_MAX, max_x = INT_MIN;
    for (auto node: _map) {
        min_x = std::min(node.x, min_x);
        max_x = std::max(node.x, max_x);
    }
    return abs(max_x-min_x)+1;
}
FILDEF int get_map_height (const Map& _map)
{
    if (_map.empty()) { return 1; }
    int min_y = INT_MAX, max_y = INT_MIN;
    for (auto node: _map) {
        min_y = std::min(node.y, min_y);
        max_y = std::max(node.y, max_y);
    }
    return abs(max_y-min_y)+1;
}
