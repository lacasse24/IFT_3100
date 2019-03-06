#pragma once
#include <ofMain.h>
#include "Transform.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();



private:
	Transform _transform;
	ofMesh* _mesh;
	
};

