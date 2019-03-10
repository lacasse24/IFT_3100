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

	virtual void setup();
	virtual void update();
	virtual void draw();

	bool canEquip(shared_ptr<GameObject> obj, float x, float y);

	//Empty slot verification methods, return true if empty false else
	bool emptyLeftHand();
	bool emptyRightHand();

	bool emptyHelmet();
	bool emptyCape();
	bool emptyArmor();
	bool emptyLegging();
	bool emptyBoots();

	//Equip to slot methods, return true if the item is equiped false if it couldn't be
	bool equip(shared_ptr<GameObject> go, float x, float y);

	bool equipLeftHand(std::shared_ptr<Holdable> holdable);
	bool equipRightHand(std::shared_ptr <Holdable> holdable);

	bool equipHelmet(std::shared_ptr<Helmet> helmet);
	bool equipCape(std::shared_ptr<Cape> cape);
	bool equipArmor(std::shared_ptr<Armor> armor);
	bool equipLegging(std::shared_ptr<Legging> legging);
	bool equipBoots(std::shared_ptr<Boots> boots);

	//Unequip slot methods, return the equiped item that has been removed, and a nullptr if there where none
	std::shared_ptr<GameObject> unequip(float x, float y);

	std::shared_ptr<GameObject> unequipLeftHand();
	std::shared_ptr<GameObject> unequipRightHand();

	std::shared_ptr<GameObject> unequipHelmet();
	std::shared_ptr<GameObject> unequipCape();
	std::shared_ptr<GameObject> unequipArmor();
	std::shared_ptr<GameObject> unequipLegging();
	std::shared_ptr<GameObject> unequipBoots();

	//Swap slot methods, return the equiped item if any and equip the given item
	std::shared_ptr<GameObject> swap(shared_ptr<GameObject> go, float x, float y);

	std::shared_ptr<GameObject> swapLeftHand(std::shared_ptr<Holdable> holdable);
	std::shared_ptr<GameObject> swapRightHand(std::shared_ptr<Holdable> holdable);

	std::shared_ptr<GameObject> swapHelmet(std::shared_ptr<Helmet> helmet);
	std::shared_ptr<GameObject> swapCape(std::shared_ptr<Cape> cape);
	std::shared_ptr<GameObject> swapArmor(std::shared_ptr<Armor> armor);
	std::shared_ptr<GameObject> swapLegging(std::shared_ptr<Legging> legging);
	std::shared_ptr<GameObject> swapBoots(std::shared_ptr<Boots> boots);

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

