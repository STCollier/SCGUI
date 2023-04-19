#ifndef SCGUI_BUTTON_H
#define SCGUI_BUTTON_H

#include <SDL2/SDL.h>
#include <SCGUI/styles.h>

struct SCGUI_Button {
	struct SCGUI_Vector2 position;
	SDL_Rect area;
	double width;
	double height;
	char* text;
	SCGUI_ButtonStyle style;
};

enum SCGUI_Alignment {
	LEFT,
	RIGHT,
	CENTER
};


struct SCGUI_Button scgui_new_button(struct SCGUI_Vector2 position, double width, double height, char* text);
void scgui_draw_button(struct SCGUI_Button button, enum SCGUI_Alignment alignment);

#endif
