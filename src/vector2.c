#include <SCGUI/vector2.h>

struct SCGUI_Vector2 SCGUI_Vector2_create(const double x, const double y) {
	struct SCGUI_Vector2 vector2;
	vector2.x = x;
	vector2.y = y;
	return vector2;
}
