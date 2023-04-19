#include <stdio.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

int main() {
    scgui_init("SCGUI Application", 1200, 800);
    
    struct SCGUI_BUTTON button = scgui_new_button(vec_2(600, 400), 200, 100, "test");
    button.style = (SCGUI_BUTTON_STYLE) {
        .background_color = color(255, 0, 0)
    };

    while(app.running) {
        scgui_clear();
        scgui_draw_button(button, CENTER);

        scgui_update(60);
    }

    scgui_destroy();
    return 0;
}