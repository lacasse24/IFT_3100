#include "Transform.h"



Transform::Transform() :
	_position(aiVector3D(0)), _rotation(aiVector3D(0)), _scale(aiVector3D(1)),
	_parent(nullptr), _childs(std::list<Transform*>())
{}

Transform::Transform(aiVector3D pos, aiVector3D rot, aiVector3D sca) :
	_position(pos), _rotation(rot), _scale(sca),
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

void Transform::translate(aiVector3D pos)
{
	_position += pos;
}

void Transform::rotate(aiVector3D rot, float a)
{
	aiQuaternion q = aiQuaternion(rot, a);
	q.Rotate(_rotation);
}

void Transform::scale(aiVector3D sca)
{
	scale(sca.x, sca.y, sca.z);
}

void Transform::translate(float x, float y, float z)
{
	translate(aiVector3D(x, y, z));
}

void Transform::rotate(float x, float y, float z, float a)
{
	aiQuaternion q = aiQuaternion(aiVector3D(x, y, z), a);
	q.Rotate(_rotation);
}

void Transform::scale(float x, float y, float z)
{
	_scale.x *= x;
	_scale.y *= y;
	_scale.z *= z;
}

aiVector3D Transform::getPosition() const
{
	auto pos = _position;
	pos += _parent->getPosition();
	return pos;
}

aiVector3D Transform::getRotation() const
{
	auto rot = _rotation;
	rot += _parent->getRotation();
	return rot;
}

aiVector3D Transform::getScale() const
{
	return _scale;
}

void Transform::setPosition(aiVector3D pos)
{
	_position = pos;
}

void Transform::setRotation(aiVector3D rot)
{
	_rotation = rot;
}

void Transform::setScale(aiVector3D sca)
{
	_scale = sca;
}

void Transform::setPosition(float x, float y, float z)
{
	_position = aiVector3D(x, y, z);
}

void Transform::setRotation(float x, float y, float z)
{
	_rotation = aiVector3D(x, y, z);
}

void Transform::setScale(float x, float y, float z)
{
	_scale = aiVector3D(x, y, z);
}

void Transform::resetTransform()
{
	_position = aiVector3D(0);
	_rotation = aiVector3D(0);
	_scale = aiVector3D(1);
}

//Parenting related methods

void Transform::parentTo(Transform* parent)
{
	if (hasParent())
		return;

	_parent = parent;
	_parent->_addChild(this);

	_position = aiVector3D(0);
	_rotation = aiVector3D(0);
}

void Transform::removeParent()
{
	_position += _parent->getPosition();
	_rotation += _parent->getRotation();

	_parent->_removeChild(this);
	_parent = nullptr;
}

bool Transform::hasParent()
{
	return _parent != nullptr;
}

bool Transform::hasChild()
{
	return _childs.empty();
}

int Transform::childCount()
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

void Transform::_addChild(Transform* child)
{
	_childs.push_back(child);
}

void Transform::_removeChild(Transform* child)
{
	if (!_isDeleting)
		_childs.remove(child);
}
