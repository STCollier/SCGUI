#include <SCGUI/init.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct SCGUI_App SCGUI_app;
struct SCGUI_Input SCGUI_input;

// Private application details to intilize window (user does not need to see these variables)
static struct {
	SDL_Window* window;
	SDL_Event event;
	bool closeRequested;
} details;

void SCGUI_init(char* title, const int width, const int height) {
	SCGUI_app.title = title;
	SCGUI_app.width = width;
	SCGUI_app.height = height;
	SCGUI_app.resizeable = false;
	SCGUI_app.running = !details.closeRequested;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) {
		fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	const int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if ((IMG_Init(flags) & flags) != flags) {
		fprintf(stderr, "Error initializing SDL_image (PNG & JPG): %s\n", IMG_GetError());
		exit(EXIT_FAILURE);
	}
 	
	if (TTF_Init()) {
		printf("Error intilizing SDL_ttf: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	details.window = SDL_CreateWindow(SCGUI_app.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCGUI_app.width, SCGUI_app.height, SCGUI_app.resizeable);
	if (!details.window) {
		fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError()); 
		SDL_Quit(); 
		exit(EXIT_FAILURE);
	}

	SCGUI_app.renderer = SDL_CreateRenderer(details.window, -1, (Uint32)SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!SCGUI_app.renderer) {
		fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(details.window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}

void SCGUI_clear() {
	SDL_SetRenderDrawColor(SCGUI_app.renderer, 255, 255, 255, 255);
	SDL_RenderClear(SCGUI_app.renderer);
}

void SCGUI_update(const int rate) {
	while (SDL_PollEvent(&details.event))
		switch (details.event.type) {
			case SDL_QUIT:
				details.closeRequested = true;
				SCGUI_app.running = false;
				break;
			case SDL_KEYDOWN:
				SCGUI_input.keys[details.event.key.keysym.scancode] = true;
				break;
			case SDL_KEYUP:
				SCGUI_input.keys[details.event.key.keysym.scancode] = false;
				break;
		}
	SDL_RenderPresent(SCGUI_app.renderer);
	SDL_Delay(1000 / rate);
}

void SCGUI_destroy() {
	SDL_DestroyRenderer(SCGUI_app.renderer);
	SDL_DestroyWindow(details.window);
	SDL_Quit();
}
