#include <stdio.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

int main() {

    scgui_init("SCGUI Window", 1200, 800);

    struct SCGUI_Button button = scgui_new_button(new_vec2(600, 400), 200, 100, "Button");

    while(app.running) {
        scgui_clear();

        scgui_draw_button(&button, CENTER);

        printf("Hovered: %d\n", button.state.hovered);

		scgui_update(60);
	}

	scgui_destroy();
    
	return 0;
}
