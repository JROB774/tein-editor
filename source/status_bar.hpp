#pragma once

GLOBAL constexpr float STATUS_BAR_INNER_PAD =  6;
GLOBAL constexpr float STATUS_BAR_HEIGHT    = 20;

INLDEF void push_status_bar_message (const char* fmt, ...);
FILDEF void do_status_bar           ();
