#ifndef HEADER_SCGUI_APP
#	define HEADER_SCGUI_APP

#	include <SCGUI/input.h>
#	include <SCGUI/vector2.h>
#	include <SDL2/SDL.h>
#	include <stdbool.h>

struct SCGUI_App {
	char* title;
	struct SCGUI_Vector2 size;
	SDL_Renderer* renderer;
	SDL_Window* window;
	bool resizeable;
	bool running;
	struct SCGUI_Input input;
};

struct SCGUI_App SCGUI_App_create(char* title, struct SCGUI_Vector2 size);

void SCGUI_App_clear(struct SCGUI_App app);

void SCGUI_App_update(struct SCGUI_App& app, int rate);

void SCGUI_App_destroy(struct SCGUI_App app);

#endif
