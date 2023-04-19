#ifndef SCGUI_TYPES_H
#define SCGUI_TYPES_H

#include <stdint.h>

struct Vector2 {
	double x;
	double y;
};

struct Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct Color color(const uint8_t red, const uint8_t green, const uint8_t blue);
struct Vector2 vec_2(double x, double y);

#endif