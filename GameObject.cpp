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
	const std::vector<std::pair<float, aiVector3D> > rotations = _transform.getRotations();
	_mesh->setPosition(_transform.getPosition().x, _transform.getPosition().y, _transform.getPosition().z);
	_mesh->setScale(_transform.getScale().x, _transform.getScale().y, _transform.getScale().z);

	for (int i = 0; i < rotations.size(); i++)
	{
		_mesh->setRotation(i, rotations[i].first, rotations[i].second.x, rotations[i].second.y, rotations[i].second.z);
	}

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
	if (_mesh->loadModel(meshpath))
		ofLog() << "Mesh loaded successfully";
	else
		ofLog() << "Mesh load failed";
}
