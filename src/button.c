#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

static struct {
    TTF_Font* font;
    SDL_Surface* surface_text;
    SDL_Texture* text;
    SDL_Rect text_area;
    int text_width, text_height;
} private;


struct SCGUI_Button scgui_new_button(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {
	struct SCGUI_Button button;

	button.position = new_vec2(position.x, position.y);
	button.width = width;
	button.height = height;
	button.text = text;

	return button;
}


void scgui_set_style(struct SCGUI_Button self) {
    //Default behavior
    self.style = (SCGUI_ButtonStyle) {
        .background_color = self.style.background_color,
        .font_color = self.style.font_color,
        .font_family = self.style.font_family == NULL || strlen(self.style.font_family) == 0 ? "res/Roboto-Regular.ttf" : self.style.font_family,
        .font_size = self.style.font_size
    };

    private.font = TTF_OpenFont(self.style.font_family, self.style.font_size);
    if (private.font == NULL) {
        fprintf(stderr, "Failed to load TTF font %s!\n", self.style.font_family);
        exit(EXIT_FAILURE);
    }

    if(!TTF_SizeText(private.font, self.text, &private.text_width, &private.text_height)) {
        printf("width=%d height=%d\n", private.text_width, private.text_height);
    }

    private.surface_text = TTF_RenderText_Blended(private.font, self.text, (SDL_Color) {self.style.font_color.red, self.style.font_color.green, self.style.font_color.blue, 255}); 
    private.text = SDL_CreateTextureFromSurface(app.renderer, private.surface_text);

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

    private.text_area = (SDL_Rect) {
        self.position.x-private.text_width/2, 
        self.position.y-private.text_height/2,
        private.text_width,
        private.text_height
    };


    SDL_RenderFillRect(app.renderer, &self.area);
    SDL_RenderCopy(app.renderer, private.text, NULL, &private.text_area);
}

void scgui_destroy_button() {
    SDL_FreeSurface(private.surface_text);
    SDL_DestroyTexture(private.text);
}