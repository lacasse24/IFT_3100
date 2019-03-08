#pragma once
#include "Wearable.h"
class Boots : public Wearable
{
public:
	Boots();
	Boots(const std::string &meshpath);
	virtual ~Boots();
};

