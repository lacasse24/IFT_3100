#include "Holdable.h"



Holdable::Holdable()
{

}

Holdable::Holdable(const std::string & meshpath)
{
	loadModel(meshpath);
}


Holdable::~Holdable()
{
	GameObject::~GameObject();
}
