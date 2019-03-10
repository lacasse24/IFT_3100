#include "Character.h"



Character::Character() :
	_leftHand(nullptr), _rightHand(nullptr), _helmet(nullptr), _cape(nullptr), _armor(nullptr), _boots(nullptr),
	_lhTransform(Transform()), _rhTransform(Transform()),
	_hTransform(Transform()), _cTransform(Transform()), _aTransform(Transform()), _bTransform(Transform())
{
	GameObject::GameObject();
	_instance = ChildInstance::character;
}

Character::Character(const std::string &meshpath) :
	_leftHand(nullptr), _rightHand(nullptr), _helmet(nullptr), _cape(nullptr), _armor(nullptr), _boots(nullptr),
	_lhTransform(Transform()), _rhTransform(Transform()),
	_hTransform(Transform()), _cTransform(Transform()), _aTransform(Transform()), _bTransform(Transform())
{
	GameObject::GameObject(meshpath);
	_instance = ChildInstance::character;
}


Character::~Character()
{
	
}

void Character::setup()
{
	GameObject::setup();
	_lhTransform.parentTo(_transform.get());
	_rhTransform.parentTo(_transform.get());
	_hTransform.parentTo(_transform.get());
	_cTransform.parentTo(_transform.get());
	_aTransform.parentTo(_transform.get());
	_bTransform.parentTo(_transform.get());

	_lhTransform.setPosition(10, 1, 0);
	_rhTransform.setPosition(-10, 1, 0);
	_hTransform.setPosition(0, 2, 0);
	_cTransform.setPosition(0, 1, 0);
	_aTransform.setPosition(0, .5, 0);
	_bTransform.setPosition(0, -1, 0);
}

void Character::update()
{
	GameObject::update();
}

void Character::draw()
{
	GameObject::draw();
}

bool Character::canEquip(shared_ptr<GameObject> obj, float x, float y)
{
	if (obj == nullptr)
		return false;
	ChildInstance current = ChildInstance::null;
	float best = 43;
	float dist = 0;
	bool empty = true;

	dist = _lhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::holdable;
		empty = emptyLeftHand();
	}

	dist = _rhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::holdable;
		empty = emptyRightHand();
	}

	dist = _hTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::helmet;
		empty = emptyHelmet();
	}

	dist = _cTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::cape;
		empty = emptyCape();
	}

	dist = _aTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::armor;
		empty = emptyArmor();
	}

	dist = _bTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::boots;
		empty = emptyBoots();
	}

	return (obj->getInstance() == current) && empty;
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

bool Character::emptyLegging()
{
	return _legging == nullptr;
}

bool Character::emptyBoots()
{
	return _boots == nullptr;
}

bool Character::equip(shared_ptr<GameObject> go, float x, float y)
{
	if (!canEquip(go, x, y))
		return false;

	ChildInstance current = ChildInstance::null;
	float best = 43;
	float dist = 0;

	dist = _lhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::holdable;
	}

	dist = _rhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::holdable;
	}

	dist = _hTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::helmet;
	}

	dist = _cTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::cape;
	}

	dist = _aTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::armor;
	}

	dist = _bTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = ChildInstance::boots;
	}

	switch (current)
	{
	case 0:
		equipLeftHand(make_shared<Holdable>(*dynamic_cast<Holdable*>(go.get())));
	case 1:
		equipRightHand(make_shared<Holdable>(*dynamic_cast<Holdable*>(go.get())));
	case 2:
		equipHelmet(make_shared<Helmet>(*dynamic_cast<Helmet*>(go.get())));
	case 3:
		equipCape(make_shared<Cape>(*dynamic_cast<Cape*>(go.get())));
	case 4:
		equipArmor(make_shared<Armor>(*dynamic_cast<Armor*>(go.get())));
	case 5:
		equipBoots(make_shared<Boots>(*dynamic_cast<Boots*>(go.get())));
	default:
		return false;
	}

	return true;
}

//-----Equip to slot methods return true if the item is equiped false if it couldn't be-----
bool Character::equipLeftHand(std::shared_ptr<Holdable> holdable)
{
	if (!emptyLeftHand() && holdable != nullptr)
		return false;

	_leftHand = holdable;
	_leftHand->getTransform().parentTo(_lhTransform.get());

	return true;
}

bool Character::equipRightHand(std::shared_ptr<Holdable> holdable)
{
	if (!emptyRightHand() && holdable != nullptr)
		return false;

	_rightHand = holdable;
	_rightHand->getTransform().parentTo(_rhTransform.get());

	return true;
}

bool Character::equipHelmet(std::shared_ptr<Helmet> helmet)
{
	if (!emptyHelmet() && helmet != nullptr)
		return false;

	_helmet = helmet;
	_helmet->getTransform().parentTo(_hTransform.get());

	return true;
}

bool Character::equipCape(std::shared_ptr<Cape> cape)
{
	if (!emptyCape() && cape != nullptr)
		return false;

	_cape = cape;
	_cape->getTransform().parentTo(_cTransform.get());

	return true;
}

bool Character::equipArmor(std::shared_ptr<Armor> armor)
{
	if (!emptyArmor() && armor != nullptr)
		return false;

	_armor = armor;
	_armor->getTransform().parentTo(_aTransform.get());

	return true;
}

bool Character::equipLegging(std::shared_ptr<Legging> legging)
{
	if (!emptyLegging() && legging != nullptr)
		return false;

	_legging = legging;
	_legging->getTransform().parentTo(_lTransform.get());

	return true;
}

bool Character::equipBoots(std::shared_ptr<Boots> boots)
{
	if (!emptyBoots() && boots != nullptr)
		return false;

	_boots = boots;
	_boots->getTransform().parentTo(_bTransform.get());

	return true;
}

std::shared_ptr<GameObject> Character::unequip(float x, float y)
{
	shared_ptr<GameObject> unequiped = nullptr;
	int current = -1;
	float best = 43;
	float dist = 0;

	dist = _lhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 0;
	}

	dist = _rhTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 1;
	}

	dist = _hTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 2;
	}

	dist = _cTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 3;
	}

	dist = _aTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 4;
	}

	dist = _bTransform.getDistFrom(x, y, 0);
	if (dist < best)
	{
		best = dist;
		current = 5;
	}

	switch (current)
	{
	case 0:
		return unequipLeftHand();
	case 1:
		return unequipRightHand();
	case 2:
		return unequipHelmet();
	case 3:
		return unequipCape();
	case 4:
		return unequipArmor();
	case 5:
		return unequipBoots();
	default:
		return unequiped;
	}
}

//-----Unequip slot methods return the equiped item that has been removed, and a nullptr if there where none-----
std::shared_ptr<GameObject> Character::unequipLeftHand()
{
	if (emptyLeftHand())
		return std::shared_ptr<Holdable>();

	auto tmp = _leftHand;
	_leftHand.get()->getTransform().removeParent();
	_leftHand = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipRightHand()
{
	if (emptyRightHand())
		return std::shared_ptr<Holdable>();

	auto tmp = _rightHand;
	_rightHand.get()->getTransform().removeParent();
	_rightHand = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipHelmet()
{
	if (emptyHelmet())
		return std::shared_ptr<Helmet>();

	auto tmp = _helmet;
	_helmet.get()->getTransform().removeParent();
	_helmet = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipCape()
{
	if (emptyCape())
		return std::shared_ptr<Cape>();

	auto tmp = _cape;
	_cape.get()->getTransform().removeParent();
	_cape = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipArmor()
{
	if (emptyArmor())
		return std::shared_ptr<Armor>();

	auto tmp = _armor;
	_armor.get()->getTransform().removeParent();
	_armor = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipLegging()
{
	if (emptyLegging())
		return std::shared_ptr<Legging>();

	auto tmp = _legging;
	_legging.get()->getTransform().removeParent();
	_legging = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::unequipBoots()
{
	if (emptyBoots())
		return std::shared_ptr<Boots>();

	auto tmp = _boots;
	_boots.get()->getTransform().removeParent();
	_boots = nullptr;

	return tmp;
}

std::shared_ptr<GameObject> Character::swap(shared_ptr<GameObject> go, float x, float y)
{
	std::shared_ptr<GameObject> item = unequip(x, y);
	equip(go, x, y);
	return item;
}

//-----Swap slot methods, return the equiped item if any and equip the given item-----
std::shared_ptr<GameObject> Character::swapLeftHand(std::shared_ptr<Holdable> holdable)
{
	std::shared_ptr<GameObject> item = unequipLeftHand();
	equipLeftHand(holdable);
	return item;
}

std::shared_ptr<GameObject> Character::swapRightHand(std::shared_ptr<Holdable> holdable)
{
	std::shared_ptr<GameObject> item = unequipRightHand();
	equipRightHand(holdable);
	return item;
}

std::shared_ptr<GameObject> Character::swapHelmet(std::shared_ptr<Helmet> helmet)
{
	std::shared_ptr<GameObject> item = unequipHelmet();
	equipHelmet(helmet);
	return item;
}

std::shared_ptr<GameObject> Character::swapCape(std::shared_ptr<Cape> cape)
{
	std::shared_ptr<GameObject> item = unequipCape();
	equipCape(cape);
	return item;
}

std::shared_ptr<GameObject> Character::swapArmor(std::shared_ptr<Armor> armor)
{
	std::shared_ptr<GameObject> item = unequipArmor();
	equipArmor(armor);
	return item;
}

std::shared_ptr<GameObject> Character::swapLegging(std::shared_ptr<Legging> legging)
{
	std::shared_ptr<GameObject> item = unequipLegging();
	equipLegging(legging);
	return item;
}

std::shared_ptr<GameObject> Character::swapBoots(std::shared_ptr<Boots> boots)
{
	std::shared_ptr<GameObject> item = unequipBoots();
	equipBoots(boots);
	return item;
}

