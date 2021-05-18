#pragma once
#include"Character.h"
#include "Weapon.h"
#include "Staff.h"
#include"Stick.h"
#include"Scepter.h"
#include"OPstick.h"
#include"Dagger.h"
#include"Knife.h"
#include"Sword.h"
#include"Axe.h"
class Weapon_Shop : public sf::Drawable
{
	Character* hero;
	sf::Texture s;
	sf::Sprite store;
	sf::Texture w[3];
	sf::Sprite wands[3];
	sf::RectangleShape back[3];
	sf::Font font;
	sf::Text text[7];
	void setPosition();
	bool isOpen;
	int change = 0;	
	void choice(sf::RenderWindow&);
	sf::RectangleShape weaponBack;
	sf::Text stats[5];
	void WeaponInfo(Weapon*,Weapon*);
	bool showStat = false;
	bool textExist = false;
	void textMove();
public:
	Weapon_Shop(Character&);
	void draw(sf::RenderTarget&, sf::RenderStates)const override;
	void shop(sf::RenderWindow&);
};

