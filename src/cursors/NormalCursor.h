#pragma once
#include "cursor.h"
class NormalCursor :public Cursor
{
public:
	NormalCursor();
	~NormalCursor();
	ofImage image;
	void drawCursor();
};

