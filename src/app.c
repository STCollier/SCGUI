#include <SCGUI/app.h>
#include <SCGUI/vector2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void SCGUI_App_create(char* title, const struct SCGUI_Vector2 size) {
	struct SCGUI_App app;
	app.title = title;
	app.size = size;
	app.resizeable = false;
	app.running = true;

	if (STD_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) {
		fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
	if ((IMG_INIT(flags) & flags) != flags) {
		fprintf(stderr, "Error initializing SDL_image (PNG & JPG): %s\n", IMG_GetError());
		exit(EXIT_FAILURE);
	}

	if (TTF_Init()) {
		printf("Error initializing SDL_ttf: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	app.window = SDL_CreateWindow(app.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, app.size.x, app.size.y, app.resizeable);
	if (!app.window) {
		fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	app.renderer = SDL_CreateRenderer(app.window, -1, (Uint32)SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!app.renderer) {
		fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(app.window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}

void SCGUI_App_clear(const struct SCGUI_App app) {
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
	SDL_RenderClear(app.renderer);
}

void SCGUI_App_update(struct SCGUI_App& app, const int rate) {
	SDL_Event event;
	while (SDL_PollEvent(&event))
		switch (event.type) {
			case SDL_QUIT:
				app.running = false;
				break;
			case SDL_KEYDOWN:
				app.input.keys[event.key.keysym.scancode] = true;
				break;
			case SDL_KEYUP:
				app.input.keys[event.key.keysym.scancode] = false;
				break;
		}
	SDL_RenderPresent(app.renderer);
	SDL_Delay(1000 / rate);
}

void SCGUI_App_destroy(const struct SCGUI_App app) {
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}
