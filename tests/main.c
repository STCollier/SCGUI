#include <stdio.h>

#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/init.h>
#include <SCGUI/vector2.h>

int main() {
	SCGUI_init("SCGUI Application", 1200, 800);
	struct SCGUI_Button button = SCGUI_Button_create(SCGUI_Vector2_create(600, 400), 200, 100, "test");

	while(app.running) {
		SCGUI_clear();
		SCGUI_Button_draw(button, CENTER);

		SCGUI_update(60);
	}

	SCGUI_destroy();
	return 0;
}
