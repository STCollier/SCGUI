#ifndef SCGUI_COLOR_H
#define SCGUI_COLOR_H

#include <stdint.h>

struct SCGUI_Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct SCGUI_Vector2 {
	double x;
	double y;
};

struct SCGUI_Color new_color(uint8_t red, uint8_t green, uint8_t blue);
struct SCGUI_Vector2 new_vec2(double x, double y);


#endif
