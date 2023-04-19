#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SCGUI/init.h>

struct SCGUI_APP app;
struct SCGUI_INPUT input;

struct SCGUI_DETAILS {
    SDL_Window *window;
    SDL_Event event;
    bool close_requested;
};

//Private application details to intilize window (user does not need to see these variables)
static struct SCGUI_DETAILS details;

static void handle_input() {
    while (SDL_PollEvent(&details.event)) {
        if (details.event.type == SDL_QUIT) {
            details.close_requested = true;
            app.running = false;
        }

        if (details.event.type == SDL_KEYDOWN) {
            input.keys[details.event.key.keysym.scancode] = true;
        }

        if (details.event.type == SDL_KEYUP) {
            input.keys[details.event.key.keysym.scancode] = false;
        }
    }
}

void scgui_init(char* title, int width, int height) {
    app.title = title;
    app.width = width;
    app.height = height;
    app.resizeable = false;
    app.running = !details.close_requested;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags) {
        fprintf(stderr, "Error initializing SDL_image (PNG & JPG): %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
 	
    if (TTF_Init() != 0) {
        printf("Error intilizing SDL_ttf: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    details.window = SDL_CreateWindow(app.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, app.width, app.height, app.resizeable);
    if (!details.window) {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError()); 
        SDL_Quit(); 
        exit(EXIT_FAILURE);
    }

    app.renderer = SDL_CreateRenderer(details.window, -1, (Uint32) SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!app.renderer) {
        fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(details.window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void scgui_clear() {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
    SDL_RenderClear(app.renderer);
}

void scgui_update(int rate) {
    handle_input();

    SDL_RenderPresent(app.renderer);
    SDL_Delay(1000/rate);
}

void scgui_destroy() {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(details.window);
    SDL_Quit();
}