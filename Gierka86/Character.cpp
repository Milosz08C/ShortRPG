#include "Character.h"
#include "Mage.h"
#include <iostream>

Character::Character(int hp, int mana, int luck, int strength, int wisdom, int lvl, std::string name, Weapon& w) {
	this->hp = hp;
	this->mana = mana;
	this->luck = luck;
	this->strength = strength;
	this->wisdom = wisdom;
	this->name = name;
	this->currHp = hp;
	this->currMana = mana;
	this->lvl = lvl;
	this->baseHp = hp;
	this->baseMana = mana;
	this->baseLuck = luck;
	this->baseStrength = strength;
	this->baseWisdom = wisdom;
	this->armed = false;	//after initialising, character is always unarmed
	
	weapon = &w;
}
int Character::getHp() { return hp; }

int Character::getLvl() { return lvl; }

bool Character::ifUsedSkill() { return usedSkill; }

void Character::setUsedSkill(bool a) {
	usedSkill = a; 
}

int Character::getMana() { return mana; }

int Character::getLuck() { return luck; }

std::string Character::getName() { return name; }

int Character::getStrength() { return strength; }

int Character::getWisdom() { return wisdom; }

int Character::getCurrentHp() { return currHp; }

int Character::getCurrentMana() { return currMana; }

int Character::getBaseHp() { return baseHp; }

int Character::getBaseMana() { return baseMana; }

int Character::getBaseLuck() { return baseLuck; }

int Character::getBaseWisdom() { return baseWisdom; }

int Character::getBaseStrength() { return baseStrength; }

Weapon Character::getWeapon() { return *weapon; }

bool Character::isArmed() { return armed; }

void Character::setHp(int hp) { this->hp = hp; }

void Character::setCurrentHp(int hp) { this->currHp = hp; }

void Character::setCurrentMana(int ma) { this->currMana = ma; }

void Character::setLvl(int lv) { this->lvl = lv; }

void Character::setMana(int ma) { this->mana = ma; }

void Character::setLuck(int lu) { this->luck = lu; }

void Character::setStrength(int str) { this->strength = str; }

void Character::setWeapon(Weapon& w) { this->weapon = &w; }

void Character::setWisdom(int wis) { this->wisdom = wis; }

void Character::setName(std::string na) { this->name = na; }

void Character::setArmed(bool ar) { this->armed = ar; }

bool Character::isAlive()
{
	if (currHp > 0)
	{
		return true;
	}
	return false; 
}

bool Character::dodge() 
{	
	 srand(time(0));
	 int l = getLuck();
	 random = rand() % 101 + 0;
	if (l > random)
	{
		return true;
	}
	return false;
}

void Character::increaseHp(int add)
{
	hp += add;
}

void Character::increaseCurrentHp(int add)
{
	if (currHp + add >= hp)
	{
		currHp = hp;
	}
	else
	{
		currHp += add;
	}	

}

void Character::increaseCurrentMana(int add)
{
	if (currMana + add > mana)
	{
		currMana = mana;
	}
	else
	{
		currMana += add;
	}
}

bool Character::decreaseCurrentMana(int sub)
{
	if (sub <= getCurrentMana())
	{
		currMana -= sub;
		return true;
	}
	else if (sub > getCurrentMana())
	{
		return false;
	}
 
}

void Character::increaseMana(int add)
{
	mana += add;
}

void Character::increaseLuck(int add)
{
	luck += add;
}

void Character::increaseWisdom(int add)
{
	wisdom += add;
}

void Character::increaseStrength(int add)
{
	strength += add;
}

void Character::increaseLvl(int add)
{
	lvl += add;
}

void Character::addExp()
{
	exp += 50;
}

int Character::getExp()
{
	return exp;
}

int Character::resetExp()
{
	exp = 0;
	return exp;
}

void Character::addLvl()
{
	if (getExp() == 100)
	{
		resetExp();
		increaseLvl(1);
	}
}

void Character::disarm()
{
	setHp(getHp() - weapon->getHp());
	setMana(getMana() - weapon->getMana());
	setLuck(getLuck() - weapon->getLuck());
	setWisdom(getWisdom() - weapon->getWisdom());
	setStrength(getStrength() - weapon->getStrength());
	setArmed(false);
}

std::string Character::getInfo() {
	return "Name: " + getName() +"HP: " + std::to_string(getCurrentHp()) + "MANA: " + std::to_string(getCurrentMana()) + "Luck: " + std::to_string(getLuck()) +
		"Strength: " + std::to_string(getStrength()) + "Wisdom: " + std::to_string(getWisdom());
}

void Character::reset()
{
	currHp = getHp();
	currMana = getMana();
}

void Character::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
	win.draw(knigth, state);
}







