#include <SCGUI/color.h>
#include <stdint.h>

struct SCGUI_Color SCGUI_Color_create(const uint8_t red, const uint8_t green, const uint8_t blue) {
	struct SCGUI_Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
}
