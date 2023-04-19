#include <SCGUI/types.h>
#include <stdint.h>

struct Color color(const uint8_t red, const uint8_t green, const uint8_t blue) {
	struct Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

struct Vector2 vec_2(double x, double y) {
    struct Vector2 self;

    self.x = x;
    self.y = y;

    return self;
}