#ifndef SCGUI_HEADER_INIT
#	define SCGUI_HEADER_INIT

#	include <SDL2/SDL.h>
#	include <limits.h>
#	include <stdbool.h>

struct SCGUI_App {
	SDL_Renderer* renderer;
	char* title;
	int width;
	int height;
	bool resizeable;
	bool running;
};

struct SCGUI_Input {
	char keys[CHAR_MAX - CHAR_MIN + 1];
};

void SCGUI_init(char* title, int width, int height);

void SCGUI_clear();

void SCGUI_update(int rate);

void SCGUI_destroy();

extern struct SCGUI_App SCGUI_app;

<<<<<<< HEAD
extern struct SCGUI_APP app;
extern struct SCGUI_INPUT input;
=======
extern struct SCGUI_Input SCGUI_input;
>>>>>>> b4466d4e22a64588e8ff0888e08d2642ad533d84

#endif
