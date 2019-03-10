#pragma once
#include "cursor.h"

class CapeCursor:public Cursor
{
public:
	CapeCursor();
	~CapeCursor();
	ofImage image;
	void drawCursor();
};

