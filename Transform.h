#pragma once

#include <vector3.h>
#include <quaternion.h>
#include <list>

class Transform
{
public:
	Transform();
	Transform(aiVector3D pos, aiVector3D rot, aiVector3D sca);
	~Transform();

	//Transformation modification methods using a vector3
	void translate(aiVector3D pos);
	void rotate(aiVector3D rot, float a);
	void scale(aiVector3D sca);

	//Transformation modification methods overload using x, y, z
	void translate(float x, float y, float z);
	void rotate(float x, float y, float z, float a);
	void scale(float x, float y, float z);

	//Getters
	aiVector3D getPosition() const;
	aiVector3D getRotation() const;
	aiVector3D getScale() const;

	//Setters using a vector3
	void setPosition(aiVector3D pos);
	void setRotation(aiVector3D rot);
	void setScale(aiVector3D sca);

	//Setter using x, y, z
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);

	void resetTransform();

	//Parenting related methods
	void parentTo(Transform* parent);
	void removeParent();

	bool hasParent();
	bool hasChild();
	int childCount();

	Transform getParent();
	Transform getTopParent();

private:
	aiVector3D _position;
	//TODO revised the rotation calculation
	aiVector3D _rotation;
	aiVector3D _scale;

	Transform* _parent;
	std::list<Transform*> _childs;

	//Parenting related private methods
	void _addChild(Transform* child);
	void _removeChild(Transform* child);

	bool _isDeleting = false;
};

