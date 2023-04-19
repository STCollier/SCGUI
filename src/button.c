#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

#include <SCGUI/init.h>

struct SCGUI_BUTTON scgui_new_button(struct Vector2 position, double width, double height, char* text) {
    struct SCGUI_BUTTON self;

    self.position = vec_2(position.x, position.y);

    self.width = width;
    self.height = height;
    self.text = text;

    return self;
}


void scgui_draw_button(struct SCGUI_BUTTON self, enum SCGUI_ALIGNMENT alignment) {
    switch(alignment) {
        case LEFT:
            self.area = (SDL_Rect) {self.position.x, self.position.y, self.width, self.height};
            break;
        case RIGHT:
            self.area = (SDL_Rect) {self.position.x-self.width, self.position.y, self.width, self.height};
            break;
        case CENTER:
            self.area = (SDL_Rect) {self.position.x-self.width/2, self.position.y-self.height/2, self.width, self.height};
            break;
    }

    SDL_SetRenderDrawColor(app.renderer, 
        self.style.background_color.red, 
        self.style.background_color.green, 
        self.style.background_color.blue,
        255
    );
    SDL_RenderFillRect(app.renderer, &self.area);
}

