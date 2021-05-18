/*#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Knife.h"

class Knight : public Character
{
	Knife* s = new Knife(0, 0, 0); //zw chcesz cos z avon?       
	Knife s1 = *s;
public:
	Knight(const std::string name, Weapon&);
	Knight(const std::string name);

	int skill1() override;
	int skill2() override;
	int skill3() override;
	int skill4() override;

	void updateStats() override;

	void changeWeapon(Weapon&) override;

	int getDmg(int&) override;
};
#include "Knight.h"

Knight::Knight(const std::string name, Weapon& stick) : Character(100, 100, 10, 20, 40, 1, name, stick) {}
Knight::Knight(const std::string name) : Character(100, 100, 10, 20, 40, 1, name, s1) {}

int Knight::skill1() //rape the bitch by your hand
{
	if (decreaseCurrentMana(50))
	{
		return getWisdom() + getStrength() * 2 + 30;
	}
	return 0;
}

int Knight::skill2() // frozen ball, returns dmg dealt
{
	if (decreaseCurrentMana(29))
	{
		return getWisdom() + 8;
	}
	return 0;
}

int Knight::skill3() //fire ball, returns dmg dealt
{
	if (decreaseCurrentMana(30))
	{
		return getWisdom() + 9;
	}
	return 0;
}

int Knight::skill4() //supp heal, returns hp after heal, if not enough mana returns 0
{
	if (decreaseCurrentMana(15))
	{
		increaseCurrentHp(10);
		return getCurrentHp();
	}
	return 0;
}

int Knight::getDmg(int& boom)
{
	increaseCurrentHp(-boom);
	return boom;
}

void Knight::updateStats()
{
	//later in armUP() function
	if (!isArmed()) {	//changes stats only if were not changed before
		increaseHp(getWeapon().getHp());
		increaseMana(getWeapon().getMana());
		increaseWisdom(getWeapon().getWisdom());
		increaseStrength(getWeapon().getStrength());
		increaseLuck(getWeapon().getLuck());

		increaseCurrentHp(getWeapon().getHp());
		increaseCurrentMana(getWeapon().getMana());
		setArmed(true);	//after changing stats with weapon, character becomes armed
	}
}

void Knight::changeWeapon(Weapon& roz)
{
	//
	if (!isArmed())
	{
		setWeapon(roz);
		setArmed(true);
	}
	else
	{
		disarm();
		setWeapon(roz);
		setArmed(true);
	}

}*/