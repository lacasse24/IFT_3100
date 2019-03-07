#pragma once
#include "GameObject.h"

class Wearable : public GameObject
{
public:
	Wearable();
	Wearable(const std::string &meshpath);
	virtual ~Wearable();
};
