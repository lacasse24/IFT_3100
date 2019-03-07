#include "Wearable.h"



Wearable::Wearable()
{

}

Wearable::Wearable(const std::string & meshpath)
{
	loadModel(meshpath);
}


Wearable::~Wearable()
{
	GameObject::~GameObject();
}
