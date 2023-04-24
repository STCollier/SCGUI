#include <SCGUI/types.h>
#include <stdio.h>
#include <stdint.h>

struct SCGUI_Color new_color(uint8_t red, uint8_t green, uint8_t blue) {
    struct SCGUI_Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

struct SCGUI_Vector2 new_vec2(int x, int y) {
    struct SCGUI_Vector2 vector2;

    vector2.x = x;
    vector2.y = y;

    return vector2;
}

void print_color(struct SCGUI_Color self) {
	printf("R: %u G: %u B: %u\n", self.red, self.green, self.blue);
}