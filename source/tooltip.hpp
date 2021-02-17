#pragma once

STDDEF void set_current_tooltip   (std::string name, std::string desc = "");
FILDEF void do_tooltip            ();
FILDEF void handle_tooltip_events ();
