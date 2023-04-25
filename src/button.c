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


static bool button_hovered(SDL_Rect area, int x, int y) {
    if (x >= area.x && x <= area.x + area.w && y >= area.y && y <= area.y + area.h) {
        return true;
    }

    return false;
}

static SCGUI_ButtonStyle default_style;


struct SCGUI_Button scgui_new_button(const struct SCGUI_Vector2 position, const double width, const double height, char* text) {

    //Initilize default values
    struct SCGUI_Button button = {
        .position = new_vec2(position.x, position.y),
        .width = width,
        .height = height,
        .text = text,

        .state = {  
            .clicked = false,
            .hovered = false
        },

        .style = {
            .background_color = new_color(0, 0, 0),
            .font_color = new_color(0, 0, 0),
            .font_family = "res/Roboto.ttf",
            .font_size = 24,

            .hover = {
                .background_color = new_color(0, 0, 0),
                .font_color = new_color(0, 0, 0),
                .font_family = "res/Roboto.ttf",
                .font_size = 24,
            }
        }
    };

    return button;
}

void scgui_set_style(struct SCGUI_Button *self) {
    self->style = (SCGUI_ButtonStyle) {
        .background_color = self->style.background_color,
        .font_color = self->style.font_color,
        .font_family = self->style.font_family == NULL ? "res/Roboto.ttf" : self->style.font_family,
        .font_size = self->style.font_size == 0 ? 24 : self->style.font_size,

        .hover = {
            .background_color = self->style.hover.background_color,
            .font_color = self->style.hover.font_color,
            .font_family = self->style.hover.font_family == NULL ? "res/Roboto.ttf" : self->style.hover.font_family,
            .font_size = self->style.font_size == 0 ? 24 : self->style.hover.font_size,
        }
    };

    default_style = (SCGUI_ButtonStyle) {
        .background_color = self->style.background_color,
        .font_color = self->style.font_color,
        .font_family = self->style.font_family == NULL ? "res/Roboto.ttf" : self->style.font_family,
        .font_size = self->style.font_size == 0 ? 24 : self->style.font_size,
    };
}

static void set_hovered(struct SCGUI_Button *self) {
    self->state.hovered = true;

    self->style.background_color = self->style.hover.background_color;
    self->style.font_color = self->style.hover.font_color;
    self->style.font_family = self->style.hover.font_family == NULL ? "res/Roboto.ttf" : self->style.hover.font_family;
    self->style.font_size = self->style.font_size == 0 ? 24 : self->style.hover.font_size;
}

static void set_default(struct SCGUI_Button *self) {
    self->state.hovered = false;

    self->style.background_color = default_style.background_color;
    self->style.font_color = default_style.font_color;
    self->style.font_family = default_style.font_family == NULL ? "res/Roboto.ttf" : default_style.font_family;
    self->style.font_size = default_style.font_size == 0 ? 24 : default_style.font_size; 
}


void scgui_draw_button(struct SCGUI_Button *self, enum SCGUI_Alignment alignment) {

    switch(alignment) {
        case LEFT:
            self->area = (SDL_Rect) {self->position.x, self->position.y, self->width, self->height};
            break;
        case RIGHT: 
            self->area = (SDL_Rect) {self->position.x-self->width, self->position.y, self->width, self->height};
            break;
        case CENTER:
            self->area = (SDL_Rect) {self->position.x-self->width/2, self->position.y-self->height/2, self->width, self->height};
            break;
    }

    //printf("Hovered: %s\nColor: (%d, %d, %d)\n\n", self->state.hovered ? "true" : "false", self->style.background_color.red, self->style.background_color.green, self->style.background_color.blue);

    if (button_hovered(self->area, app.mouse_pos.x, app.mouse_pos.y)) {
        set_hovered(self);


        private.font = TTF_OpenFont(self->style.font_family, self->style.font_size);
        if (private.font == NULL) {
            fprintf(stderr, "Failed to load TTF font %s!\n", self->style.font_family);
            exit(EXIT_FAILURE);
        }



        TTF_SizeText(private.font, self->text, &private.text_width, &private.text_height); //Get text size

        private.surface_text = TTF_RenderText_Blended(private.font, self->text, (SDL_Color) {self->style.font_color.red, self->style.font_color.green, self->style.font_color.blue, 255}); 
        private.text = SDL_CreateTextureFromSurface(app.renderer, private.surface_text);

        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
    } else {
        set_default(self);
        scgui_set_style(self);

        private.font = TTF_OpenFont(self->style.font_family, self->style.font_size);
        if (private.font == NULL) {
            fprintf(stderr, "Failed to load TTF font %s!\n", self->style.font_family);
            exit(EXIT_FAILURE);
        }

        TTF_SizeText(private.font, self->text, &private.text_width, &private.text_height);

        private.surface_text = TTF_RenderText_Blended(private.font, self->text, (SDL_Color) {self->style.font_color.red, self->style.font_color.green, self->style.font_color.blue, 255}); 
        private.text = SDL_CreateTextureFromSurface(app.renderer, private.surface_text);

        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }

    SDL_SetRenderDrawColor(app.renderer,
        self->style.background_color.red, 
        self->style.background_color.green, 
        self->style.background_color.blue,
        255
    );

    private.text_area = (SDL_Rect) {
        self->position.x-private.text_width/2, 
        self->position.y-private.text_height/2,
        private.text_width,
        private.text_height
    };


    SDL_RenderFillRect(app.renderer, &self->area);
    SDL_RenderCopy(app.renderer, private.text, NULL, &private.text_area);
}

void scgui_destroy_button() {
    SDL_FreeSurface(private.surface_text);
    SDL_DestroyTexture(private.text);
}