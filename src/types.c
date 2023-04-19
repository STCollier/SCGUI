#include <SCGUI/types.h>
#include <stdint.h>

struct SCGUI_Color new_color(uint8_t red, uint8_t green, uint8_t blue) {
    struct SCGUI_Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

struct SCGUI_Vector2 new_vec2(double x, double y) {
    struct SCGUI_Vector2 vector2;

    vector2.x = x;
    vector2.y = y;

    return vector2;
}