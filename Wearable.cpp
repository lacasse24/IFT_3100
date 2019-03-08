#include "Wearable.h"



Wearable::Wearable()
{
	GameObject::GameObject();
}

Wearable::Wearable(const std::string & meshpath)
{
	GameObject::GameObject(meshpath);
}


Wearable::~Wearable()
{
	GameObject::~GameObject();
}
