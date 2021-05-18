#pragma once
#include<SFML/Graphics.hpp>
#include "Character.h"
#include "Weapon.h"
#include "Stick.h"

class Mage : public Character
{
	Stick* s = new Stick(0, 0, 0);
	Stick s1 = *s;
public:
	void changeTexture(int) override;
	Mage(const std::string name, Weapon&);
	Mage(const std::string name);

	int skill1() override;
	int skill2() override;
	int skill3() override;
	int skill4() override;

	void updateStats() override;

	void changeWeapon(Weapon&) override;

	int getDmg(int&) override;

	void move() override;
	void run() override;

	void setScale(sf::Vector2f&) override;
	void resetScale() override;
	Who getCharacter();

	int getSkin() override;
};
