#include "Helmet.h"



Helmet::Helmet()
{
	Wearable::Wearable();
	_instance = ChildInstance::helmet;
}

Helmet::Helmet(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
	_instance = ChildInstance::helmet;
}


Helmet::~Helmet()
{
	
}
