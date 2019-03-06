#pragma once

#include <vector3.h>

class Transform
{
public:
	Transform();
	~Transform();

private:
	aiVector3D _position;
	aiVector3D _rotation;
	aiVector3D _scale;

};

