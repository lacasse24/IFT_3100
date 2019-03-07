#include "Cape.h"



Cape::Cape()
{

}

Cape::Cape(const std::string & meshpath)
{
	loadModel(meshpath);
}


Cape::~Cape()
{
	Wearable::~Wearable();
}
