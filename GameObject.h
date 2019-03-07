#pragma once
#include <ofMain.h>
#include <ofxAssimpModelLoader.h>
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

	bool parentTo(GameObject* go);
	void removeParent();

	//return a reference of the transforms to make its manipulation easier
	Transform& getTransform();

	//Method that load the mesh
	void loadModel(const std::string &meshpath);

protected:
	Transform _transform;
	ofxAssimpModelLoader* _mesh;

	ofPolyRenderMode _renderMode;
	
};
