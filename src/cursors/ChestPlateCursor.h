#pragma once
#include "cursor.h"
class ChestPlateCursor:public Cursor
{
public:
	ChestPlateCursor();
	~ChestPlateCursor();
	ofImage image;
	void drawCursor();
};

