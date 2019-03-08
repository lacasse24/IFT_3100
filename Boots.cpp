#include "Boots.h"



Boots::Boots()
{
	Wearable::Wearable();
}

Boots::Boots(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
}


Boots::~Boots()
{
	Wearable::~Wearable();
}
