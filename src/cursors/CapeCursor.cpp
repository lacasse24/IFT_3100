#include "CapeCursor.h"

CapeCursor::CapeCursor()
{
	image.load("./Img/cursors/sword.png");

}


CapeCursor::~CapeCursor()
{
	image.clear();
}

void CapeCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 20, (float)y + 20, 40, 40);
}
