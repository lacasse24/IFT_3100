#include "GameObject.h"



GameObject::GameObject() :
	_transform(Transform()), _mesh(ofxAssimpModelLoader()), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{}

GameObject::GameObject(Transform t) :
	_transform(t), _mesh(ofxAssimpModelLoader()), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{}

GameObject::GameObject(const std::string & meshpath) :
	_transform(Transform()), _mesh(ofxAssimpModelLoader()), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{
	loadModel(meshpath);
}

GameObject::GameObject(Transform t, const std::string & meshpath) :
	_transform(t), _mesh(ofxAssimpModelLoader()), _renderMode(ofPolyRenderMode::OF_MESH_FILL)
{
	loadModel(meshpath);
}


GameObject::~GameObject()
{}

void GameObject::setup()
{

}

void GameObject::update()
{

}

void GameObject::draw()
{
	std::vector<std::pair<float, aiVector3D> > rotations = _transform.getRotations();
	_mesh.setPosition(_transform.getPosition().x, _transform.getPosition().y, _transform.getPosition().z);
	_mesh.setScale(_transform.getScale().x, _transform.getScale().y, _transform.getScale().z);

	for (int i = 0; i < rotations.size(); i++)
	{
		_mesh.setRotation(i, rotations[i].first, rotations[i].second.x, rotations[i].second.y, rotations[i].second.z);
	}

	_mesh.draw(_renderMode);
}

void GameObject::draw(ofPolyRenderMode mode)
{
	ofDisableArbTex();
	ofPolyRenderMode current = _renderMode;
	_renderMode = mode;
	draw();
	_renderMode = current;
}

void GameObject::setRenderMode(ofPolyRenderMode mode)
{
	_renderMode = mode;
}

void GameObject::disableMaterials()
{
	_mesh.disableMaterials();
}

//-----parenting related methods-----
bool GameObject::parentTo(GameObject * go)
{
	return _transform.parentTo(go->getTransform().get());
}

void GameObject::removeParent()
{
	_transform.removeParent();
}

ChildInstance GameObject::getInstance()
{
	return _instance;
}

//-----get Transform-----
Transform & GameObject::getTransform()
{
	return _transform;
}

//-----Load mesh-----
void GameObject::loadModel(const std::string &meshpath)
{
	if (_mesh.loadModel(meshpath))
		ofLog() << "Model loaded successfully";
	else
		ofLog() << "Model load failed";
}
