#ifndef HEADER_SCGUI_BUTTON
#	define HEADER_SCGUI_BUTTON

#	include <SCGUI/alignment.h>
#	include <SCGUI/app.h>
#	include <SCGUI/style.h>
#	include <SCGUI/vector2.h>
#	include <SDL2/SDL.h>

struct SCGUI_Button {
	char* text;
	struct SCGUI_Vector2 size;
	struct SCGUI_Vector2 position;
	SDL_Rect area;
	struct SCGUI_Style style;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

struct SCGUI_Button SCGUI_Button_create(char* text, struct SCGUI_Vector2 size, struct SCGUI_App app, struct SCGUI_Vector2 position);

void SCGUI_Buton_draw(struct SCGUI_Button button, struct SCGUI_App app, enum SCGUI_Alignment alignment);

void SCGUI_Button_destroy(struct SCGUI_Button button);

#endif
