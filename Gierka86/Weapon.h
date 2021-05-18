#pragma once
class Weapon
{
	int mana, wisdom, hp, strength, luck;	//staty broni

public:
	Weapon(int, int, int, int, int);

	int getMana();
	int getWisdom();
	int getHp();
	int getStrength();
	int getLuck();

	void setMana(int);
	void setWisdom(int);
	void setHp(int);
	void setStrength(int);
	void setLuck(int);
};

