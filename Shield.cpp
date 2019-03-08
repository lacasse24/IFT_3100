#include "Shield.h"



Shield::Shield()
{
	Holdable::Holdable();
}

Shield::Shield(const std::string & meshpath)
{
	Holdable::Holdable(meshpath);
}


Shield::~Shield()
{
	Holdable::~Holdable();
}
