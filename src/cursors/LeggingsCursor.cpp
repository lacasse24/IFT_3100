#include "LeggingsCursor.h"



LeggingsCursor::LeggingsCursor()
{
	image.load("./Img/cursors/legsplate.png");

}


LeggingsCursor::~LeggingsCursor()
{
	image.clear();
}

void LeggingsCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 20, (float)y + 20, 40, 40);
}
