#include "Sword.h"



Sword::Sword()
{
	Holdable::Holdable();
	_instance = ChildInstance::sword;
}

Sword::Sword(const std::string & meshpath)
{
	Holdable::Holdable(meshpath);
	_instance = ChildInstance::sword;
}


Sword::~Sword()
{
	
}
