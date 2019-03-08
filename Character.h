#pragma once
#include <memory>

#include "GameObject.h"
#include "Holdable.h"
#include "Wearable.h"

#include "Helmet.h"
#include "Cape.h"
#include "Armor.h"
#include "Legging.h"
#include "Boots.h"

class Character : public GameObject
{
public:
	Character();
	Character(const std::string &meshpath);
	virtual ~Character();

	//Empty slot verification methods, return true if empty false else
	bool emptyLeftHand();
	bool emptyRightHand();

	bool emptyHelmet();
	bool emptyCape();
	bool emptyArmor();
	bool emptyLegging();
	bool emptyBoots();

	//Equip to slot methods, return true if the item is equiped false if it couldn't be
	bool equipLeftHand(std::shared_ptr<Holdable> holdable);
	bool equipRightHand(std::shared_ptr<Holdable> holdable);

	bool equipHelmet(std::shared_ptr<Helmet> helmet);
	bool equipCape(std::shared_ptr<Cape> cape);
	bool equipArmor(std::shared_ptr<Armor> armor);
	bool equipLegging(std::shared_ptr<Legging> legging);
	bool equipBoots(std::shared_ptr<Boots> boots);

	//Unequip slot methods, return the equiped item that has been removed, and a nullptr if there where none
	std::shared_ptr<Holdable> unequipLeftHand();
	std::shared_ptr<Holdable> unequipRightHand();

	std::shared_ptr<Helmet> unequipHelmet();
	std::shared_ptr<Cape> unequipCape();
	std::shared_ptr<Armor> unequipArmor();
	std::shared_ptr<Legging> unequipLegging();
	std::shared_ptr<Boots> unequipBoots();

	//Swap slot methods, return the equiped item if any and equip the given item
	std::shared_ptr<Holdable> swapLeftHand(std::shared_ptr<Holdable> holdable);
	std::shared_ptr<Holdable> swapRightHand(std::shared_ptr<Holdable> holdable);

	std::shared_ptr<Helmet> swapHelmet(std::shared_ptr<Helmet> helmet);
	std::shared_ptr<Cape> swapCape(std::shared_ptr<Cape> cape);
	std::shared_ptr<Armor> swapArmor(std::shared_ptr<Armor> armor);
	std::shared_ptr<Legging> swapLegging(std::shared_ptr<Legging> legging);
	std::shared_ptr<Boots> swapBoots(std::shared_ptr<Boots> boots);

private:
	std::shared_ptr<Holdable> _leftHand;
	Transform _lhTransform;

	std::shared_ptr<Holdable> _rightHand;
	Transform _rhTransform;


	std::shared_ptr<Helmet> _helmet;
	Transform _hTransform;

	std::shared_ptr<Cape> _cape;
	Transform _cTransform;

	std::shared_ptr<Armor> _armor;
	Transform _aTransform;

	std::shared_ptr<Legging> _legging;
	Transform _lTransform;

	std::shared_ptr<Boots> _boots;
	Transform _bTransform;
};

