#include "Armor.h"



Armor::Armor()
{

}

Armor::Armor(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Armor::~Armor()
{
	Wearable::~Wearable();
}
