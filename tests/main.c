#include <stdio.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/button.h>

int main() {
    scgui_init("SCGUI Application", 1200, 800);
    struct SCGUI_BUTTON button = scgui_new_button(vec_2(600, 400), 200, 100, "test");

    while(app.running) {
        scgui_clear();
        scgui_draw_button(button, CENTER);

        scgui_update(60);
    }

    scgui_destroy();
    return 0;
}