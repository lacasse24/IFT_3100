#pragma once
#include <ofMain.h>
#include <string>
#include "Transform.h"

class GameObject
{
public:
	GameObject();

	explicit GameObject(const std::string &meshpath);
	explicit GameObject(Transform t);

	GameObject(Transform t, const std::string &meshpath);

	virtual ~GameObject();

	//return a reference of the transforms to make its manipulation easier
	Transform& getTransform();

	//Method that load the mesh
	void loadMesh(const std::string &meshpath);

private:
	Transform _transform;
	ofMesh* _mesh;
	
};
