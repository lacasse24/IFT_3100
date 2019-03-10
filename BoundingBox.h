#pragma once
#include <ofMain.h>
#include "GameObject.h"
#include "Character.h"

class BoundingBox : public GameObject
{
public:
	BoundingBox();
	//~BoundingBox();

	void CalculateDelimitations(ofxAssimpModelLoader Mesh);
	void draw(GameObject obj);

private:
	float MinX, MaxX, MinY, MaxY, MinZ, MaxZ;
	ofBoxPrimitive _BoundBox;
};

//BoundingBox::~BoundingBox(){}