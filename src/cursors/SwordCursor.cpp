#include "SwordCursor.h"



SwordCursor::SwordCursor()
{
	image.load("./Img/cursors/sword.png");
}

SwordCursor::~SwordCursor()
{
	image.clear();
}

void SwordCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;

	image.draw((float)x - 10, (float)y -7, 40, 40);
}




