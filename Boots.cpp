#include "Boots.h"



Boots::Boots()
{

}

Boots::Boots(const std::string & meshpath)
{
	loadModel(meshpath);
}


Boots::~Boots()
{
	Wearable::~Wearable();
}
