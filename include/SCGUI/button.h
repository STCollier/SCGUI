#ifndef SCGUI_BUTTON_H
#define SCGUI_BUTTON_H

#include <SDL2/SDL.h>
#include <SCGUI/styles.h>

struct SCGUI_BUTTON {
    struct Vector2 position;
    SDL_Rect area;
    double width;
    double height;
    char* text;
    SCGUI_BUTTON_STYLE style;
};

enum SCGUI_ALIGNMENT {
    LEFT,
    RIGHT,
    CENTER
};

struct SCGUI_BUTTON scgui_new_button(struct Vector2 position, double width, double height, char* text);
void scgui_draw_button(struct SCGUI_BUTTON self, enum SCGUI_ALIGNMENT alignment);

#endif