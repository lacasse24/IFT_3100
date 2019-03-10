#include "Holdable.h"



Holdable::Holdable()
{
	GameObject::GameObject();
	_instance = ChildInstance::holdable;
}

Holdable::Holdable(const std::string & meshpath)
{
	GameObject::GameObject(meshpath);
	_instance = ChildInstance::holdable;
}


Holdable::~Holdable()
{
	
}
