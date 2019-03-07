#include "Wearable.h"



Wearable::Wearable()
{

}

Wearable::Wearable(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Wearable::~Wearable()
{
	GameObject::~GameObject();
}
