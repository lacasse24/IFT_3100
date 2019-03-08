#include "Holdable.h"



Holdable::Holdable()
{
	GameObject::GameObject();
}

Holdable::Holdable(const std::string & meshpath)
{
	GameObject::GameObject(meshpath);
}


Holdable::~Holdable()
{
	
}
