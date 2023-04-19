#include <SCGUI/alignment.h>
#include <SCGUI/app.h>
#include <SCGUI/button.h>
#include <SCGUI/color.h>
#include <SCGUI/style.h>
#include <SCGUI/vector2.h>
#include <stdio.h>

int main() {
	struct SCGUI_App app = SCGUI_App_create("SCGUI WIndow", SCGUI_Vector2_create(1200, 800));

	struct SCGUI_Button button = SCGUI_Button_create("test", SCGUI_Vector2_create(200, 100), app, SCGUI_Vector2_create(600, 400));
	button.style = SCGUI_Style_create(SCGUI_Color_create(220, 220, 220), "res/Roboto-Regular.ttf", 12, SCGUI_Color_create(0, 0, 0));

	while (app.running) {
		SCGUI_App_clear(app);
		SCGUI_Button_draw(button, app, SCGUI_ALIGNMENT_CENTER);
		SCGUI_App_update(app, 60);
	}

	SCGUI_App_destroy(app);
}
