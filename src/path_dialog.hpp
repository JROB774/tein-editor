#pragma once

GLOBAL const std::string DEFAULT_GAME_PATH = "C:/Program Files (x86)/Steam/steamapps/common/theendisnigh/";
GLOBAL const std::string EXECUTABLE_NAME = "TheEndIsNigh.exe";

FILDEF void open_path   ();
FILDEF void do_path     ();
FILDEF void okay_path   ();
FILDEF void cancel_path ();

FILDEF void handle_path_events ();
