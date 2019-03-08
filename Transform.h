#pragma once

#include <vector3.h>
#include <quaternion.h>
#include <vector>
#include <list>
#include <utility>

class Transform
{
public:
	Transform();
	Transform(aiVector3D pos, const std::vector< std::pair<float, aiVector3D> > &rot, aiVector3D sca);
	~Transform();

	//Rotation augmentation related methods
	void addRotation(std::pair<float, aiVector3D> rotation);
	void addRotation(float angle, aiVector3D rot);
	void addRotation(float angle, float x, float y, float z);

	void addRotations(const std::vector<std::pair<float, aiVector3D>> &rotations);

	//Transformation modification methods using a vector3
	void translate(aiVector3D pos);
	void scale(aiVector3D sca);

	//Transformation modification methods overload using x, y, z
	void translate(float x, float y, float z);
	void rotate(int which, float a);
	void scale(float x, float y, float z);

	//Getters
	Transform* get();

	aiVector3D getPosition() const;
	std::vector< std::pair<float, aiVector3D> > getRotations() const;
	aiVector3D getScale() const;

	//Setters using a vector3
	void setPosition(aiVector3D pos);
	void setRotation(int which, float angle, aiVector3D rot);
	void setScale(aiVector3D sca);

	//Setter using x, y, z
	void setPosition(float x, float y, float z);
	void setRotation(int which, float angle, float x, float y, float z);
	void setScale(float x, float y, float z);

	//Reset Method
	void resetTransform();

	//Parenting related methods
	bool parentTo(Transform* parent);
	void removeParent();

	bool hasParent() const;
	bool hasChild() const;
	int childCount() const;

	Transform getParent();
	Transform getTopParent();

private:
	aiVector3D _position;
	std::vector<std::pair<float, aiVector3D>> _rotations;
	aiVector3D _scale;

	Transform* _parent;
	std::list<Transform*> _childs;

	//Parenting related private methods
	void _addChild(Transform* child);
	void _removeChild(Transform* child);

	bool _isDeleting = false;
};

