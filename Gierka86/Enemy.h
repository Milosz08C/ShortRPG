#pragma once
#include "Character.h"
#include "Weapon.h"
class Enemy : public Character
{
	Weapon* w = new Weapon(0, 0, 0, 0, 0);
	Weapon w1 = *w;
	int scale;
	int skin;
public:
	void changeTexture(int) override;
	Enemy();
	Enemy(int, int, int, int, int, int, std::string, Weapon&);
	void updateStats() override;
	int skill1() override;
	int skill2() override;
	int skill3() override;
	int skill4() override;
	int getDmg(int&) override;
	void changeWeapon(Weapon&) override;
	void move() override;

	void run() override;

	void setScale(sf::Vector2f&) override;
	void resetScale() override;

	 Who getCharacter();
	 int getSkin() override;
};
