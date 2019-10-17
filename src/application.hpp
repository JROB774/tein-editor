#pragma once

#include "utility.hpp"
#include "debug.hpp"
#include "error.hpp"
#include "custom_events.hpp"
#include "window.hpp"
#include "cursor.hpp"
#include "key_bindings.hpp"
#include "settings.hpp"
#include "texture.hpp"
#include "texture_atlas.hpp"
#include "texture_pack.hpp"
#include "font.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "resource_manager.hpp"
#include "user_interface.hpp"
#include "level.hpp"
#include "gpak.hpp"
#include "hotbar.hpp"
#include "toolbar.hpp"
#include "tooltip.hpp"
#include "tile_panel.hpp"
#include "layer_panel.hpp"
#include "control_panel.hpp"
#include "new_dialog.hpp"
#include "resize_dialog.hpp"
#include "level_editor.hpp"
#include "tab_bar.hpp"
#include "status_bar.hpp"
#include "color_picker.hpp"
#include "preferences_menu.hpp"
#include "about.hpp"

GLOBAL constexpr int EDITOR_MAJOR = 1;
GLOBAL constexpr int EDITOR_MINOR = 0;
GLOBAL constexpr int EDITOR_PATCH = 0;

FILDEF void init_editor (int _argc, char** _argv);
FILDEF void quit_editor ();

FILDEF void do_editor   ();

FILDEF bool handle_editor_events ();
