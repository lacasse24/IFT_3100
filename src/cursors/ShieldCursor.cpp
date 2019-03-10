#include "ShieldCursor.h"


ShieldCursor::ShieldCursor()
{
	image.load("./Img/cursors/shield.png");

}

ShieldCursor::~ShieldCursor()
{
	image.clear();
}
void ShieldCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 20, (float)y + 20, 40, 40);
}

