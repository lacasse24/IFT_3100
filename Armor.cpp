#include "Armor.h"



Armor::Armor()
{

}

Armor::Armor(const std::string & meshpath)
{
	loadModel(meshpath);
}


Armor::~Armor()
{
	Wearable::~Wearable();
}
