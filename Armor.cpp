#include "Armor.h"



Armor::Armor()
{
	Wearable::Wearable();
	_instance = ChildInstance::armor;
}

Armor::Armor(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
	_instance = ChildInstance::armor;
}


Armor::~Armor()
{
	
}
