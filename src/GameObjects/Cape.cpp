#include "Cape.h"



Cape::Cape()
{
	Wearable::Wearable();
	_instance = ChildInstance::cape;
}

Cape::Cape(const std::string & meshpath)
{
	Wearable::Wearable(meshpath);
	_instance = ChildInstance::cape;
}


Cape::~Cape()
{
	
}
