#include "Cape.h"



Cape::Cape()
{

}

Cape::Cape(const std::string & meshpath)
{
	loadMesh(meshpath);
}


Cape::~Cape()
{
	Wearable::~Wearable();
}
