#pragma once
#include "GameObject.h"
#include "Holdable.h"
#include "Wearable.h"

#include "Helmet.h"
#include "Cape.h"
#include "Armor.h"
#include "Boots.h"

class Character : public GameObject
{
public:
	Character();
	virtual ~Character();

private:
	Holdable _lefthand;
	Transform _lhTransform;

	Holdable _righthand;
	Transform _rhTransform;


	Helmet _helmet;
	Transform _hTransfrom;

	Cape _cape;
	Transform _cTransform;

	Armor _armor;
	Transform _aTransform;

	Boots _boots;
	Transform _bTransform;
};

