#include "GameObject.h"



GameObject::GameObject() :
	_transform(), _mesh(nullptr), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{}

GameObject::GameObject(Transform t) :
	_transform(t), _mesh(nullptr), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{}

GameObject::GameObject(const std::string & meshpath) :
	_transform(), _mesh(nullptr), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{
	loadMesh(meshpath);
}

GameObject::GameObject(Transform t, const std::string & meshpath) :
	_transform(t), _mesh(nullptr), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{
	loadMesh(meshpath);
}


GameObject::~GameObject()
{
	delete _mesh;
}

void GameObject::draw()
{
	_mesh->draw(_renderMode);
}

void GameObject::setRenderMode(ofPolyRenderMode mode)
{
	_renderMode = mode;
}

Transform & GameObject::getTransform()
{
	return _transform;
}

void GameObject::loadMesh(const std::string &meshpath)
{
	_mesh->load(meshpath);
}
