#include <stdio.h>

<<<<<<< HEAD
#include <SCGUI/init.h>
#include <SCGUI/types.h>
#include <SCGUI/styles.h>
=======
>>>>>>> b4466d4e22a64588e8ff0888e08d2642ad533d84
#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/init.h>
#include <SCGUI/vector2.h>

int main() {
<<<<<<< HEAD
    scgui_init("SCGUI Application", 1200, 800);
    
    struct SCGUI_BUTTON button = scgui_new_button(vec_2(600, 400), 200, 100, "test");
    button.style = (SCGUI_BUTTON_STYLE) {
        .background_color = color(255, 0, 0)
    };
=======
	SCGUI_init("SCGUI Application", 1200, 800);
	struct SCGUI_Button button = SCGUI_Button_create(SCGUI_Vector2_create(600, 400), 200, 100, "test");
>>>>>>> b4466d4e22a64588e8ff0888e08d2642ad533d84

	while(app.running) {
		SCGUI_clear();
		SCGUI_Button_draw(button, CENTER);

		SCGUI_update(60);
	}

	SCGUI_destroy();
	return 0;
}
