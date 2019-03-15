#pragma once
#include "Wearable.h"
class Legging : public Wearable
{
public:
	Legging();
	Legging(const std::string &meshpath);
	virtual ~Legging();
};

