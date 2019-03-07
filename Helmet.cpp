#include "Helmet.h"



Helmet::Helmet()
{

}

Helmet::Helmet(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Helmet::~Helmet()
{
	Wearable::~Wearable();
}
