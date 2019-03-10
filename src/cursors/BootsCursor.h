#pragma once
#include "Cursor.h"
class BootsCursor:public Cursor
{
public:
	ofImage image;
	BootsCursor();
	~BootsCursor();
	void drawCursor();
};

