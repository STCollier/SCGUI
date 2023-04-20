#include <stdio.h>

#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
#include <SCGUI/button.h>

int main() {

    scgui_init("SCGUI Window", 1200, 800);

    struct SCGUI_Button button = scgui_new_button(new_vec2(600, 400), 200, 100, "Button");
    button.style = (SCGUI_ButtonStyle) {
        .background_color = new_color(220, 220, 220),
        .font_family = "res/Roboto-Regular.ttf",
        .font_size = 36,
        .font_color = new_color(0, 0, 0),
    };

    scgui_set_style(button);



    while(app.running) {
        scgui_clear();

        scgui_draw_button(button, CENTER);

		scgui_update(60);
	}

	scgui_destroy();
    
	return 0;
}
