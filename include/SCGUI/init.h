#ifndef SCGUI_INIT_H
#define SCGUI_INIT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

struct SCGUI_APP {
    SDL_Renderer *renderer;
    char* title;
    int width;
    int height;
    bool resizeable;
    bool running;
};

struct SCGUI_INPUT {
    int keys[256];
};

void scgui_init(char* title, int width, int height);
void scgui_clear();
void scgui_update(int rate);
void scgui_destroy();

extern struct SCGUI_APP app; 
extern struct SCGUI_INPUT input;

#endif