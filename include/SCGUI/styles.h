#ifndef SCGUI_STYLES_H
#define SCGUI_STYLES_H

#include <SCGUI/types.h>

typedef struct {
    struct SCGUI_Color background_color;
    char* font_family;
    int font_size;
    struct SCGUI_Color font_color;
} SCGUI_ButtonStyle;

#endif