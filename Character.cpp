#include "Character.h"



Character::Character() :
	_leftHand(nullptr), _rightHand(nullptr), _helmet(nullptr), _cape(nullptr), _armor(nullptr), _boots(nullptr),
	_lhTransform(), _rhTransform(), _hTransform(), _cTransform(), _aTransform(), _bTransform()
{

}

Character::Character(const std::string &meshpath) :
	_leftHand(nullptr), _rightHand(nullptr), _helmet(nullptr), _cape(nullptr), _armor(nullptr), _boots(nullptr),
	_lhTransform(), _rhTransform(), _hTransform(), _cTransform(), _aTransform(), _bTransform()
{
	loadMesh(meshpath);
}


Character::~Character()
{
	GameObject::~GameObject();
}

//-----Empty slot verification methods return true if empty false else-----
bool Character::emptyLeftHand()
{
	return _leftHand == nullptr;
}

bool Character::emptyRightHand()
{
	return _rightHand == nullptr;
}

bool Character::emptyHelmet()
{
	return _helmet == nullptr;
}

bool Character::emptyCape()
{
	return _cape == nullptr;
}

bool Character::emptyArmor()
{
	return _armor == nullptr;
}

bool Character::emptyBoots()
{
	return _boots == nullptr;
}

//-----Equip to slot methods return true if the item is equiped false if it couldn't be-----
bool Character::equipLeftHand(std::shared_ptr<Holdable> holdable)
{
	if (!emptyLeftHand())
		return false;

	_leftHand = holdable;
	_leftHand.get()->getTransform().parentTo(_lhTransform.get());

	return true;
}

bool Character::equipRightHand(std::shared_ptr<Holdable> holdable)
{
	if (!emptyRightHand())
		return false;

	_rightHand = holdable;
	_rightHand.get()->getTransform().parentTo(_rhTransform.get());

	return true;
}

bool Character::equipHelmet(std::shared_ptr<Helmet> helmet)
{
	if (!emptyHelmet())
		return false;

	_helmet = helmet;
	_helmet.get()->getTransform().parentTo(_hTransform.get());

	return true;
}

bool Character::equipCape(std::shared_ptr<Cape> cape)
{
	if (!emptyCape())
		return false;

	_cape = cape;
	_cape.get()->getTransform().parentTo(_cTransform.get());

	return true;
}

bool Character::equipArmor(std::shared_ptr<Armor> armor)
{
	if (!emptyArmor())
		return false;

	_armor = armor;
	_armor.get()->getTransform().parentTo(_aTransform.get());

	return true;
}

bool Character::equipBoots(std::shared_ptr<Boots> boots)
{
	if (!emptyBoots())
		return false;

	_boots = boots;
	_boots.get()->getTransform().parentTo(_bTransform.get());

	return true;
}

//-----Unequip slot methods return the equiped item that has been removed, and a nullptr if there where none-----
std::shared_ptr<Holdable> Character::unequipLeftHand()
{
	if (emptyLeftHand())
		return std::shared_ptr<Holdable>();

	auto tmp = _leftHand;
	_leftHand.get()->getTransform().removeParent();
	_leftHand = nullptr;

	return tmp;
}

std::shared_ptr<Holdable> Character::unequipRightHand()
{
	if (emptyRightHand())
		return std::shared_ptr<Holdable>();

	auto tmp = _rightHand;
	_rightHand.get()->getTransform().removeParent();
	_rightHand = nullptr;

	return tmp;
}

std::shared_ptr<Helmet> Character::unequipHelmet()
{
	if (emptyHelmet())
		return std::shared_ptr<Helmet>();

	auto tmp = _helmet;
	_helmet.get()->getTransform().removeParent();
	_helmet = nullptr;

	return tmp;
}

std::shared_ptr<Cape> Character::unequipCape()
{
	if (emptyCape())
		return std::shared_ptr<Cape>();

	auto tmp = _cape;
	_cape.get()->getTransform().removeParent();
	_cape = nullptr;

	return tmp;
}

std::shared_ptr<Armor> Character::unequipArmor()
{
	if (emptyArmor())
		return std::shared_ptr<Armor>();

	auto tmp = _armor;
	_armor.get()->getTransform().removeParent();
	_armor = nullptr;

	return tmp;
}

std::shared_ptr<Boots> Character::unequipBoots()
{
	if (emptyBoots())
		return std::shared_ptr<Boots>();

	auto tmp = _boots;
	_boots.get()->getTransform().removeParent();
	_boots = nullptr;

	return tmp;
}
