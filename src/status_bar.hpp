#pragma once

GLOBAL constexpr float STATUS_BAR_INNER_PAD =  6.0f;
GLOBAL constexpr float STATUS_BAR_HEIGHT    = 20.0f;

INLDEF void push_status_bar_message (const char* _fmt, ...);
FILDEF void do_status_bar           ();
