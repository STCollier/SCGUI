#ifndef SCGUI_INIT_H
#define SCGUI_INIT_H

#include <SDL2/SDL.h>
#include <limits.h>
#include <stdbool.h>

#include <SCGUI/types.h>

struct SCGUI_App {
	SDL_Renderer* renderer;
	char* title;
	int width;
	int height;
	bool resizeable;
	bool running;
	struct SCGUI_Vector2 mouse_pos;
};

struct SCGUI_Input {
	char keys[CHAR_MAX - CHAR_MIN + 1];
};

void scgui_init(char* title, int width, int height);
void scgui_clear();
void scgui_update(int rate);
void scgui_destroy();

extern struct SCGUI_App app;
extern struct SCGUI_Input input;

#endif
