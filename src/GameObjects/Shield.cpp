#include "Shield.h"



Shield::Shield()
{
	Holdable::Holdable();
	_instance = ChildInstance::shield;
}

Shield::Shield(const std::string & meshpath)
{
	Holdable::Holdable(meshpath);
	_instance = ChildInstance::shield;
}


Shield::~Shield()
{
	
}
