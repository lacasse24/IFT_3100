#include "Transform.h"



Transform::Transform()
{

}


Transform::~Transform()
{

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
	return _position;
}

aiVector3D Transform::getRotation() const
{
	return _rotation;
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
