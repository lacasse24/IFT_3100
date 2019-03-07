#include "Boots.h"



Boots::Boots()
{

}

Boots::Boots(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Boots::~Boots()
{
	Wearable::~Wearable();
}
