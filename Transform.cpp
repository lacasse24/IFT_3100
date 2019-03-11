#include "Transform.h"



Transform::Transform() :
	_position(aiVector3D(0)), _rotations(std::vector< std::pair<float, aiVector3D> >()), _scale(aiVector3D(1)),
	_parent(nullptr), _childs(std::list<Transform*>())
{}

Transform::Transform(aiVector3D pos, const std::vector< std::pair<float, aiVector3D> > &rot, aiVector3D sca) :
	_position(pos), _rotations(rot), _scale(sca),
	_parent(nullptr), _childs(std::list<Transform*>())
{}


Transform::~Transform()
{
	_isDeleting = true;
	for (std::list<Transform *>::iterator it = _childs.begin(); it != _childs.end(); /*it is updated in the loop itself*/)
	{
		(*it)->removeParent();
		it = _childs.erase(it);
	}
}

float Transform::getDistFrom(aiVector3D pos)
{
	int x = pos.x, y = pos.y, z = pos.z;
	ofVec3f vector = ofVec3f(x, y, z);
	ofVec3f point = ofVec3f(_position.x, _position.y, _position.z);
	float resultat = (point - vector.scale(point.dot(vector))).length();
}

float Transform::getDistFrom(float x, float y, float z)
{
	return getDistFrom(aiVector3D(x, y, z));
}

//-----Rotation augmentation related methods-----
void Transform::addRotation(std::pair<float, aiVector3D> rotation)
{
	_rotations.push_back(rotation);
}

void Transform::addRotation(float angle, aiVector3D rot)
{
	_rotations.push_back(std::pair<float, aiVector3D>(angle, rot));
}

void Transform::addRotation(float angle, float x, float y, float z)
{
	_rotations.push_back(std::pair<float, aiVector3D>(angle, aiVector3D(x, y, z)));
}

void Transform::addRotations(const std::vector<std::pair<float, aiVector3D>>& rotations)
{
	for (int i = 0; i < rotations.size(); i++)
	{
		_rotations.push_back(rotations[i]);
	}
}

//-----Transformation modification methods using a vector3-----
void Transform::translate(aiVector3D pos)
{
	_position += pos;
}

void Transform::scale(aiVector3D sca)
{
	scale(sca.x, sca.y, sca.z);
}

//-----Transformation modification methods overload using x, y, z-----
void Transform::translate(float x, float y, float z)
{
	translate(aiVector3D(x, y, z));
}

void Transform::rotate(int which, float a)
{
	if (which >= _rotations.size() && which < 0)
		return;
	_rotations[which].first += a;
}

void Transform::scale(float x, float y, float z)
{
	_scale.x *= x;
	_scale.y *= y;
	_scale.z *= z;
}

//-----Getters-----
Transform * Transform::get()
{
	return this;
}

aiVector3D Transform::getPosition() const
{
	auto pos = _position;
	if (hasParent())
		pos += _parent->getPosition();
	return pos;
}

std::vector< std::pair<float, aiVector3D> > Transform::getRotations() const
{
	std::vector< std::pair<float, aiVector3D> > rotations;

	if (hasParent())
		rotations = _parent->getRotations();
	else
		rotations = std::vector< std::pair<float, aiVector3D> >();

	for (int i = 0; i < _rotations.size(); i++)
	{
		rotations.push_back(_rotations[i]);
	}
	return rotations;
}

aiVector3D Transform::getScale() const
{
	return _scale;
}

//-----Setters using a vector3-----
void Transform::setPosition(aiVector3D pos)
{
	_position = pos;
}

void Transform::setRotation(int which, float angle, aiVector3D rot)
{
	if (which >= _rotations.size() && which < 0)
		return;
	_rotations[which] = std::pair<float, aiVector3D>(angle, rot);
}

void Transform::setScale(aiVector3D sca)
{
	_scale = sca;
}

//-----Setter using x, y, z-----
void Transform::setPosition(float x, float y, float z)
{
	_position = aiVector3D(x, y, z);
}

void Transform::setRotation(int which, float angle, float x, float y, float z)
{
	if (which >= _rotations.size() && which < 0)
		return;
	_rotations[which] = std::pair<float, aiVector3D>(angle, aiVector3D(x, y, z));
}

void Transform::setScale(float x, float y, float z)
{
	_scale = aiVector3D(x, y, z);
}

//-----Reset Method-----
void Transform::resetTransform()
{
	_position = aiVector3D(0);
	_rotations.clear();
	_scale = aiVector3D(1);
}

//-----Parenting related methods-----
bool Transform::parentTo(Transform* parent)
{
	if (hasParent() || parent == this)
		return false;

	_parent = parent;
	_parent->_addChild(this);

	_position = aiVector3D(0);
	_rotations.clear();

	return true;
}

void Transform::removeParent()
{
	if (!hasParent())
		return;

	std::vector< std::pair<float, aiVector3D> > rotations = _rotations;
	_position += _parent->getPosition();
	_rotations = _parent->getRotations();
	addRotations(rotations);

	_parent->_removeChild(this);
	_parent = nullptr;
}

bool Transform::hasParent() const
{
	return _parent != nullptr;
}

bool Transform::hasChild() const
{
	return _childs.empty();
}

int Transform::childCount() const
{
	return _childs.size();
}

Transform Transform::getParent()
{
	return *_parent;
}

Transform Transform::getTopParent()
{
	if (hasParent())
		return _parent->getTopParent();
	else
		return *this;
}

//----Parenting related private methods-----
void Transform::_addChild(Transform* child)
{
	_childs.push_back(child);
}

void Transform::_removeChild(Transform* child)
{
	if (!_isDeleting)
		_childs.remove(child);
}
