#include "Weapon.h"

Weapon::Weapon(int mana, int wisdom, int hp, int strength, int luck)
{
	this->hp = hp;
	this->wisdom = wisdom;
	this->mana = mana;
	this->strength = strength;
	this->luck = luck;
}

int Weapon::getHp() { return hp; }
int Weapon::getMana() { return mana; }
int Weapon::getWisdom() { return wisdom; }
int Weapon::getStrength() { return strength; }
int Weapon::getLuck() { return luck; }

void Weapon::setHp(int hp) { this->hp = hp; }
void Weapon::setMana(int ma) { this->mana = ma; }
void Weapon::setWisdom(int wi) { this->wisdom = wi; }
void Weapon::setStrength(int wi) { this->strength = wi; }
void Weapon::setLuck(int wi) { this->luck = wi; }
