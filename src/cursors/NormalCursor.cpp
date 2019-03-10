#include "NormalCursor.h"



NormalCursor::NormalCursor()
{
	image.load("./Img/cursors/normal.png");
}


NormalCursor::~NormalCursor()
{
	image.clear();
}

void NormalCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x-10, (float)y-7, 40, 40);
}