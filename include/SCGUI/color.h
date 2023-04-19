#ifndef HEADER_SCGUI_COLOR
#	define HEADER_SCGUI_COLOR

#	include <stdint.h>

struct SCGUI_Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct SCGUI_Color SCGUI_Color_create(uint8_t red, uint8_t green, uint8_t blue);

#endif
