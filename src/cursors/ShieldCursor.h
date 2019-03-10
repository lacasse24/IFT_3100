#include "cursor.h"
#pragma once
class ShieldCursor:public Cursor
{
public:
	ShieldCursor();
	~ShieldCursor();
	ofImage image;
	void drawCursor();
};

