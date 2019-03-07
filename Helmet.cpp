#include "Helmet.h"



Helmet::Helmet()
{

}

Helmet::Helmet(const std::string & meshpath)
{
	loadModel(meshpath);
}


Helmet::~Helmet()
{
	Wearable::~Wearable();
}
