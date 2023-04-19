#ifndef HEADER_SCGUI_INPUT
#	define HEADER_SCGUI_INPUT

#	include <limits.h>
#	include <stdbool.h>

struct SCGUI_Input {
	bool keys[CHAR_MAX - CHAR_MIN + 1];
};

#endif
