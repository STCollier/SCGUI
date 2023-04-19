#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/init.h>
#include <SCGUI/vector2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stdbool.h>

#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>
=======
>>>>>>> b4466d4e22a64588e8ff0888e08d2642ad533d84

struct SCGUI_Button SCGUI_Button_create(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {
	struct SCGUI_Button button;
	button.position = SCGUI_Vector2_create(position.x, position.y);
	button.width = width;
	button.height = height;
	button.text = text;
	return button;
}

<<<<<<< HEAD

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
=======
void SCGUI_Button_draw(const struct SCGUI_Button button, const enum SCGUI_Alignment alignment) {
	switch (alignment) {
		case SCGUI_ALIGNMENT_LEFT:
			button.area = (SDL_Rect){
				button.position.x,
				button.position.y,
				button.width,
				button.height
			};
			break;
		case SCGUI_ALIGNMENT_RIGHT:
			button.area = (SDL_Rect){
				button.position.x - button.width,
				button.position.y,
				button.width,
				button.height
			};
			break;
		case SCGUI_ALIGNMENT_CENTER:
			button.area = (SDL_Rect){
				button.position.x - button.width / 2,
				button.position.y - button.height / 2,
				button.width,
				button.height
			};
			break;
	}

	SDL_SetRenderDrawColor(SCGUI_app.renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(SCGUI_app.renderer, &button.area);
>>>>>>> b4466d4e22a64588e8ff0888e08d2642ad533d84
}
