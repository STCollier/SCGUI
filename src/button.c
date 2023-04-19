#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/init.h>
#include <SCGUI/vector2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct SCGUI_Button SCGUI_Button_create(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {
	struct SCGUI_Button button;
	button.position = SCGUI_Vector2_create(position.x, position.y);
	button.width = width;
	button.height = height;
	button.text = text;
	return button;
}

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
}
