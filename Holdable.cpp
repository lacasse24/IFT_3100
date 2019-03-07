#include "Holdable.h"



Holdable::Holdable()
{

}

Holdable::Holdable(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Holdable::~Holdable()
{
	GameObject::~GameObject();
}
