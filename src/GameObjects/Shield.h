#pragma once
#include "Holdable.h"
class Shield : public Holdable
{
public:
	Shield();
	Shield(const std::string &meshpath);
	virtual ~Shield();
};

