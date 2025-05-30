// window.h
#ifndef WINDOW_H
#define WINDOW_H

extern SDL_Window* window;
extern SDL_GLContext* context;

int window_init();
void window_destroy();
void window_title_set(const char *text);
int window_is_running();

#endif