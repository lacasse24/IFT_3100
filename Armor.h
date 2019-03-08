#pragma once
#include "Wearable.h"
class Armor : public Wearable
{
public:
	Armor();
	Armor(const std::string &meshpath);
	virtual ~Armor();
};

