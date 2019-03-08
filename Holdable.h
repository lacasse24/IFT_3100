#pragma once
#include "GameObject.h"

class Holdable : public GameObject
{
public:
	Holdable();
	Holdable(const std::string &meshpath);
	virtual ~Holdable();
};

