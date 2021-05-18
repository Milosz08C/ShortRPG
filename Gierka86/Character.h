#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "Weapon.h"

enum Who{MAGE,KNIGHT,ENEMY};

class Character : public sf::Drawable
{
	int hp, mana, luck, strength, wisdom, lvl;	//stats points
	int baseHp, baseMana, baseLuck, baseStrength, baseWisdom;
	int currHp, currMana;	//current values of mana and health
	std::string name;
	Weapon* weapon;
	int random;
	bool usedSkill = false;
	bool armed; //variable which tells if character's stats were modified by weapon either not
	int exp=0;
public:

	int stop = 0; //uniemozliwa przechodzenie scian
	sf::Vector2f position; //zapisuje wektor ruchu 
	sf::Texture k;
	sf::Sprite knigth;
	Character(int, int, int, int, int,int, std::string, Weapon&);

	void draw(sf::RenderTarget& win, sf::RenderStates state) const override;
	void setHp(int); //beda ustawiac hp po np. wylaczeniu gry i wlaczeniu gry
	void setCurrentHp(int);
	void setMana(int);
	void setCurrentMana(int);
	void setLuck(int);
	void setStrength(int);
	void setWisdom(int);
	void setLvl(int);
	void setArmed(bool);
	void setUsedSkill(bool);
	void setName(const std::string);
	void setWeapon(Weapon&);

	int getHp();
	int getCurrentHp();
	int getMana();
	int getCurrentMana();
	int getLvl();
	int getLuck();
	int getStrength();
	int getWisdom();
	int getBaseHp();
	int getBaseMana();
	int getBaseLuck();
	int getBaseStrength();
	int getBaseWisdom();
	bool isArmed();
	bool isAlive();
	bool dodge();
	bool ifUsedSkill();
	std::string getName();
	Weapon getWeapon();

	void increaseHp(int);
	void increaseCurrentHp(int);
	void increaseMana(int);
	void increaseCurrentMana(int);
	bool decreaseCurrentMana(int);	//returns False if not enough mana, else substract proper value from mana
	void increaseLuck(int);
	void increaseStrength(int);
	void increaseWisdom(int);
	void increaseLvl(int);
	
	std::string getInfo();

	void addExp();
	int getExp();
	void addLvl();
	int resetExp();


	//-------------------LATER:--CREATE-WEAPON-CLASS---THEN:--MAKE-THIS-NON-VIRTUAL-----------------------//
	virtual void updateStats() = 0; //function which updates stat points by diffrent modifiers like weapon or buffs
	void disarm();
	virtual void changeWeapon(Weapon&) = 0;

	//--------------DEALING-DAMAGE----------------//
	virtual int skill1() = 0;
	virtual int skill2() = 0;
	virtual int skill3() = 0;
	virtual int skill4() = 0;

	//-------------GETTING-DAMAGE-----------------//
	virtual int getDmg(int&) = 0;	//modifies hp of user by int amount, returns hp after getting dmg
	void reset();

	//-------------------MOVE-----------------//
	virtual void move() = 0;
	virtual void run() = 0;

	//-------------------SCALE-----------------//
	virtual void setScale(sf::Vector2f&) = 0;
	virtual void resetScale() = 0;

	//------------WHO AM I?--------//
	virtual Who getCharacter() = 0;	
	
	virtual void changeTexture(int) = 0;
	virtual int getSkin() = 0;
};
