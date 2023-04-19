#ifndef SCGUI_HEADER_BUTTON
#	define SCGUI_HEADER_BUTTON

#	include <SCGUI/color.h>
#	include <SCGUI/vector2.h>
#	include <SDL2/SDL.h>

struct SCGUI_ButtonStyle {
	struct SCGUI_Color backgroundColor;
	struct SCGUI_Color borderCoolor;
	double borderSize;
	char* fontFamily;
};

struct SCGUI_Button {
	struct SCGUI_Vector2 position;
	SDL_Rect area;
	double width;
	double height;
	char* text;
	struct SCGUI_ButtonStyle style;
};

enum SCGUI_Alignment {
	SCGUI_ALIGNMENT_LEFT,
	SCGUI_ALIGNMENT_RIGHT,
	SCGUI_ALIGNMENT_CENTER
};

struct SCGUI_Button SCGUI_Button_create(struct SCGUI_Vector2 position, double width, double height, char* text);

void SCGUI_Button_draw(struct SCGUI_Button button, enum SCGUI_Alignment alignment);

#endif
