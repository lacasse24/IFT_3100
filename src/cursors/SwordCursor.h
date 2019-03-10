#pragma once
#include "cursor.h"

class SwordCursor :public Cursor
{
public:
	SwordCursor();
	~SwordCursor();
	ofImage image;
	void drawCursor();
};

