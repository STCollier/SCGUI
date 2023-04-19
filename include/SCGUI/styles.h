#ifndef SCGUI_STYLES_H
#define SCGUI_STYLES_H

#include <SCGUI/types.h>

typedef struct {
    struct SCGUI_Color background_color;
    struct SCGUI_Color border_color;
    double border_size;
    char* font_family;
} SCGUI_ButtonStyle;

#endif