#pragma once
#include "cursor.h"
class LeggingsCursor:public Cursor
{
public:
	LeggingsCursor();
	~LeggingsCursor();
	ofImage image;
	void drawCursor();
};

