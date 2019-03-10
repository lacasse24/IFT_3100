#pragma once
#include "cursor.h"
class HelmetCursor:public Cursor
{
public:
	HelmetCursor();
	~HelmetCursor();
	ofImage image;
	void drawCursor();
};

