#pragma once
#include "Holdable.h"
class Sword : public Holdable
{
public:
	Sword();
	Sword(const std::string &meshpath);
	virtual ~Sword();
};

