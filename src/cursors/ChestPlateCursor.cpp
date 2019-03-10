#include "ChestPlateCursor.h"



ChestPlateCursor::ChestPlateCursor()
{
	image.load("./Img/cursors/chestplate.png");

}


ChestPlateCursor::~ChestPlateCursor()
{
	image.clear();
}
void ChestPlateCursor::drawCursor()
{
	int x = Cursor::positionx;
	int y = Cursor::positiony;
	image.draw((float)x - 20, (float)y + 20, 40, 40);
}
