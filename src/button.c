#include <SCGUI/alignment.h>
#include <SCGUI/app.h>
#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/style.h>
#include <SCGUI/vector2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

struct SCGUI_Button SCGUI_Button_create(char* text, const struct SCGUI_Vector2 size, const struct SCGUI_App app, const struct SCGUI_Vector2 position) {
	struct SCGUI_Button button;
	button.text = text;
	button.size = size;
	button.position = position;
	button.style = SCGUI_Style_create(SCGUI_Color_create(200, 200, 200), 12, "res/Roboto-Regular.ttf", SCGUI_Color_create(0, 0, 0));

	TTF_Font* font = TTF_OpenFont(button.style.fontFamily, button.style.fontSize);
	if (font == NULL) {
		fprintf(stderr, "Failed to load TTF font %s\n", button.style.fontFamily);
		exit(EXIT_FAILURE);
	}
	button.surfaceText = TTF_RenderText_Solid(font, button.text, (SDL_Color){
		button.style.fontColor.red,
		button.style.fontColor.green,
		button.style.fontColor.blue,
		255
	});
	button.texture = SDL_CreateTextureFromSurface(app.renderer, surfaceText);
	
	return button;
}

void SCGUI_Button_draw(const struct SCGUI_Button button, const struct SCGUI_App app, const enum SCGUI_Alignment alignment) {
	switch (alignment) {
		case SCGUI_ALIGNMENT_RIGHT:
			button.area = (SDL_Rect){
				button.position.x,
				button.position.y,
				button.size.x,
				button.size.y
			};
			break;
		case SCGUI_ALIGNMENT_LEFT:
			button.area = (SDL_Rect){
				button.position.x - button.size.x,
				button.position.y,
				button.size.x,
				button.size.y
			};
			break;
		case SCGUI_ALIGNMENT_CENTER:
			button.area = (SDL_Rect){
				button.position.x - button.size.x / 2,
				button.position.y - button.height / 2,
				button.size.x,
				button.size.y
			};
			break;
	}
	SDL_SetRenderDrawColor(app.renderer, button.style.backgroundColor.red, button.style.backgroundColor.green, button.style.backgroundColor.blue, 255);
	SDL_RenderFillRect(app.renderer, &button.area);
	SDL_RenderCopy(app.renderer, button.texture, NULL, &button.area);
}

void SCGUI_Button_destroy(const struct SCGUI_Button button) {
	SDL_FreeSurface(button.surface);
	SDL_DestroyTexture(button.texture);
}
