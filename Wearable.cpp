#include "Wearable.h"



Wearable::Wearable()
{
	GameObject::GameObject();
	_instance = ChildInstance::wearable;
}

Wearable::Wearable(const std::string & meshpath)
{
	GameObject::GameObject(meshpath);
	_instance = ChildInstance::wearable;
}


Wearable::~Wearable()
{

}
