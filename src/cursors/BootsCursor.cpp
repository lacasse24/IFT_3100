#include "BootsCursor.h"



BootsCursor::BootsCursor()
{
	image.load("./Img/cursors/boots.png");
}


BootsCursor::~BootsCursor()
{
	image.clear();
}

void BootsCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 20, (float)y + 20, 40, 40);
}
