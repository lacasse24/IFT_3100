#include "Sword.h"



Sword::Sword()
{
	Holdable::Holdable();
}

Sword::Sword(const std::string & meshpath)
{
	Holdable::Holdable(meshpath);
}


Sword::~Sword()
{
	Holdable::~Holdable();
}
