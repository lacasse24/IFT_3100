#include "Boots.h"



Boots::Boots()
{
	Wearable::Wearable();
	_instance = ChildInstance::boots;
}

Boots::Boots(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
	_instance = ChildInstance::boots;
}


Boots::~Boots()
{
	
}
