#pragma once
#include "Character.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

class Battle : public sf::Drawable
{
	int changeSkill=0;
	int dmg = 0;
	int dmgFenemy = 0;
	Character* enemy;
	Character* hero;
	float rotateDegree = 0;
	bool isShuriken = false;
	void whoUsedSkill(Character*, Character*);
	bool isSomeoneDead(Character*, Character*);
	sf::Text spell[4];
	sf::Font font;
	sf::Text dmgCount;
	sf::Text dmgToHero;
	sf::Text Mana;
	sf::Text PressE;
	sf::RectangleShape square;
	sf::Texture s;
	sf::Sprite skillSprite;
	sf::Sprite skillEnemy;
	void rotate();
	void spritePosition(Character*, Character* );
	bool spriteExist=false;
	bool textExist=false;
	bool dmgToHeroEx = false;
	bool manaExist = false;
	bool enemySkill = false;
	void dmgTextPos(Character*);
	void dmgToHeroTextPos(Character*);
	int delay = 0;
	int HerochooseSkill();
	int EnemyChooseSkill();
	sf::Vector2f posHero;
	bool pos = false;
	bool dash=false;
	bool texturePos = false;
	sf::Vector2f startPos;	
	bool closeEnough = false;
	int test12 = 0;
	bool skillName = false;
	bool isHead = false;
public:	
	void pressePos(std::vector<Character*>,int );

	bool setClose(bool);
	void reset(Character*);
	Battle();
	void fight(Character&, Character&);
	void loadTexture(Character*, Character*);
	void draw(sf::RenderTarget& win, sf::RenderStates state) const override;
	Character* whoIsDead(Character&,Character&);

};

