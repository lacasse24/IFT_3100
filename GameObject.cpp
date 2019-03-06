#include "GameObject.h"



GameObject::GameObject() :
	_transform(), _mesh(nullptr)
{}

GameObject::GameObject(const std::string & meshpath) :
	_transform()
{
	loadMesh(meshpath);
}

GameObject::GameObject(Transform t) :
	_transform(t)
{}

GameObject::GameObject(Transform t, const std::string & meshpath) :
	_transform(t)
{
	loadMesh(meshpath);
}


GameObject::~GameObject()
{
	delete _mesh;
}

Transform & GameObject::getTransform()
{
	return _transform;
}

void GameObject::loadMesh(const std::string &meshpath)
{
	_mesh->load(meshpath);
}
