FILDEF void push_editor_event (Editor_Event _event, void* _data1, void* _data2)
{
    SDL_Event event;
    SDL_zero(event);

    event.type           = SDL_USEREVENT;
    event.user.type      = SDL_USEREVENT;
    event.user.timestamp = SDL_GetTicks();
    event.user.code      = _event;
    event.user.data1     = _data1;
    event.user.data2     = _data2;

    SDL_PushEvent(&event);
}
