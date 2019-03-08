#include "Armor.h"



Armor::Armor()
{
	Wearable::Wearable();
}

Armor::Armor(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
}


Armor::~Armor()
{
	
}
