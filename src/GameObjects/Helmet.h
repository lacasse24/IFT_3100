#pragma once
#include "Wearable.h"
class Helmet : public Wearable
{
public:
	Helmet();
	Helmet(const std::string &meshpath);
	virtual ~Helmet();
};

