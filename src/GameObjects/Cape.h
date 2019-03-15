#pragma once
#include "Wearable.h"
class Cape : public Wearable
{
public:
	Cape();
	Cape(const std::string &meshpath);
	virtual ~Cape();
};

