#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

struct SCGUI_Button scgui_new_button(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {
	struct SCGUI_Button button;

	button.position = new_vec2(position.x, position.y);
	button.width = width;
	button.height = height;
	button.text = text;

	return button;
}


void scgui_draw_button(struct SCGUI_Button self, enum SCGUI_Alignment alignment) {
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
