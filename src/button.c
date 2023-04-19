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

static struct {
    TTF_Font* font;
    SDL_Surface* surface_text;
    SDL_Texture* text;
} private;

struct SCGUI_Button scgui_new_button(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {
	struct SCGUI_Button button;

    //Default behavior
    button.style = (SCGUI_ButtonStyle) {
        .background_color = new_color(200, 200, 200),
        .font_family = "res/Roboto-Regular.ttf",
        .font_size = 12,
        .font_color = new_color(0, 0, 0)
    };


	button.position = new_vec2(position.x, position.y);
	button.width = width;
	button.height = height;
	button.text = text;

    private.font = TTF_OpenFont(button.style.font_family, button.style.font_size);
    if (private.font == NULL) {
        fprintf(stderr, "Failed to load TTF font %s!", button.style.font_family);
        exit(EXIT_FAILURE);
    }

    private.surface_text = TTF_RenderText_Solid(private.font, button.text, (SDL_Color) {button.style.font_color.red, button.style.font_color.green, button.style.font_color.blue, 255}); 
    private.text = SDL_CreateTextureFromSurface(app.renderer, private.surface_text);

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
    SDL_RenderCopy(app.renderer, private.text, NULL, &self.area);
}

void scgui_destroy_button() {
    SDL_FreeSurface(private.surface_text);
    SDL_DestroyTexture(private.text);
}