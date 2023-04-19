#ifndef HEADER_SCGUI_STYLE
#	define HEADER_SCGUI_STYLE

#	include <SCGUI/color.h>

struct SCGUI_Style {
	struct SCGUI_Color backgroundColor;
	char* fontFamily;
	int fontSize;
	struct SCGUI_Color fontColor;
};

struct SCGUI_Style SCGUI_Style_create(struct SCGUI_Color backgroundColor, char* fontFamily, int fontSize, struct SCGUI_Color fontColor);

#endif
