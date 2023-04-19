#include <SCGUI/color.h>
#include <SCGUI/style.h>

struct SCGUI_Style SCGUI_Style_create(const struct SCGUI_Color backgroundColor, char* fontFamily, const int fontSize, const struct SCGUI_Color fontColor) {
	struct SCGUI_Style style;
	style.backgroundColor = backgroundColor;
	style.fontFamily = fontFamily;
	style.fontSize = fontSize;
	style.fontColor = fontColor;
	return style;
}
