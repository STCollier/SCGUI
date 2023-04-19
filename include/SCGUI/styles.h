#ifndef SCGUI_STYLES_H
#define SCGUI_STYLES_H

#include <SCGUI/types.h>

typedef struct {
    struct Color background_color;
    struct Color border_color;
    double border_size;
    char* font_family;
} SCGUI_BUTTON_STYLE;

#endif