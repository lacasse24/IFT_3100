#pragma once
#include <ofMain.h>
#include <string>
#include "Transform.h"

class GameObject
{
public:
	GameObject();

	explicit GameObject(Transform t);
	explicit GameObject(const std::string &meshpath);

	GameObject(Transform t, const std::string &meshpath);

	virtual ~GameObject();

	void draw();
	void setRenderMode(ofPolyRenderMode mode);

	//return a reference of the transforms to make its manipulation easier
	Transform& getTransform();

	//Method that load the mesh
	void loadMesh(const std::string &meshpath);

private:
	Transform _transform;
	ofMesh* _mesh;

	ofPolyRenderMode _renderMode;
	
};
