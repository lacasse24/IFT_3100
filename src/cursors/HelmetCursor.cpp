#include "HelmetCursor.h"



HelmetCursor::HelmetCursor()
{
	image.load("./Img/cursors/helmet.png");

}


HelmetCursor::~HelmetCursor()
{
	image.clear();
}

void HelmetCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 10, (float)y-7, 40, 40);
}