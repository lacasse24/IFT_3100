#pragma once
#include "GameObject.h"
#include "Holdable.h"
#include "Wearable.h"

class Character : public GameObject
{
public:
	Character();
	virtual ~Character();

private:
	Holdable _lefthand;
	Holdable _righthand;

	Wearable _helmet;
	Wearable _cape;
	Wearable _armor;
	Wearable _boots;
};

