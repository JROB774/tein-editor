#pragma once

enum Editor_Event: u32
{
    EDITOR_EVENT_UI_REDRAW,
    EDITOR_EVENT_BACKUP_LEVEL,
    EDITOR_EVENT_HOTLOAD,
    EDITOR_EVENT_COOLDOWN,
    EDITOR_EVENT_BLINK_CURSOR,
    EDITOR_EVENT_GPAK_PROGRESS,
    EDITOR_EVENT_SHOW_TOOLTIP,
};

FILDEF void push_editor_event (Editor_Event _event,
                               void* _data1 = NULL,
                               void* _data2 = NULL);
