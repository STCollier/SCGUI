#ifndef SCGUI_COLOR_H
#define SCGUI_COLOR_H

#include <stdint.h>

#define KEY_A SDL_SCANCODE_A
#define KEY_B SDL_SCANCODE_B
#define KEY_C SDL_SCANCODE_C
#define KEY_D SDL_SCANCODE_D
#define KEY_E SDL_SCANCODE_E
#define KEY_F SDL_SCANCODE_F
#define KEY_G SDL_SCANCODE_G
#define KEY_H SDL_SCANCODE_H
#define KEY_I SDL_SCANCODE_I
#define KEY_J SDL_SCANCODE_J
#define KEY_K SDL_SCANCODE_K
#define KEY_L SDL_SCANCODE_L
#define KEY_M SDL_SCANCODE_M
#define KEY_N SDL_SCANCODE_N
#define KEY_O SDL_SCANCODE_O
#define KEY_P SDL_SCANCODE_P
#define KEY_Q SDL_SCANCODE_Q
#define KEY_R SDL_SCANCODE_R
#define KEY_S SDL_SCANCODE_S
#define KEY_T SDL_SCANCODE_T
#define KEY_U SDL_SCANCODE_U
#define KEY_V SDL_SCANCODE_V
#define KEY_W SDL_SCANCODE_W
#define KEY_X SDL_SCANCODE_X
#define KEY_Y SDL_SCANCODE_Y
#define KEY_Z SDL_SCANCODE_Z

#define KEY_SPACE SDL_SCANCODE_SPACE
#define KEY_ENTER SDL_SCANCODE_RETURN

struct SCGUI_Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct SCGUI_Vector2 {
	int x;
	int y;
};

struct SCGUI_Color new_color(uint8_t red, uint8_t green, uint8_t blue);
void print_color(struct SCGUI_Color self);
struct SCGUI_Vector2 new_vec2(int x, int y);


#endif
