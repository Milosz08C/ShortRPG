#pragma once
#include<SFML/Graphics.hpp>
#include "Character.h"
#include "Weapon.h"
#include "Knife.h"

class Wikary : public Character
{
	Knife* s = new Knife(0, 0, 0);     
	Knife s1 = *s;
public:

	void changeTexture(int) override;
	Wikary(const std::string name, Weapon&);
	Wikary(const std::string name);

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

