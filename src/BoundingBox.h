#pragma once
#include <ofMain.h>
#include "GameObjects/GameObject.h"
#include "GameObjects/Character.h"

class BoundingBox : public GameObject
{
public:
	BoundingBox();
	//~BoundingBox();

	ofBoxPrimitive CalculateDelimitations(ofxAssimpModelLoader Mesh, ofBoxPrimitive BoundBox);
	ofBoxPrimitive draw(GameObject obj);

private:
	float MinX, MaxX, MinY, MaxY, MinZ, MaxZ;
	ofBoxPrimitive _BoundBox;
};

//BoundingBox::~BoundingBox(){}