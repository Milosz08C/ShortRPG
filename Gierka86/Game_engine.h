#pragma once
#include "Title_Page.h"
#include "Character.h"
#include "Mage.h"
#include "Wikary.h"
#include"Scepter.h"
#include "Grass.h"
#include "Mine.h"
#include "Quest.h"
#include "Battle.h"
#include "Info.h"
#include"Enemy.h"
#include "Weapon_Shop.h"
#include "Cave.h"
#include "finalMap.h"
#include "endScreen.h"
class Game_engine
{
	sf::View widok;
	Title_Page* title;
	Grass*backGround;
	Mine* mine;
	Weapon_Shop* shop;
	void istitlexicst(sf::RenderWindow& win);
	int change = 0; //1: tittle screen,  2: Grass,  3:Mine,  4:Coward screen,  5:Battle,  6: Cave (2nd mine)
	Character* hero;
	std::vector<Character*> enemy;
	Quest* que;
	void reset(sf::RenderWindow&);
	void firstStage(sf::RenderWindow&);
	void isFirstExicist(); 
	Battle* combat;
	Info* inf;
	Info* infEnemy;
	Cave* cav;
	finalMap* lastMap;
	int map;
	endScreen* end;
	//------------DESTRUCTORS--------//
	bool titleExcist = true;
	void titleDelete(Title_Page*);
	bool grassExcist = false;
	void grassDelete(Grass*);
	bool questExcist = true;
	void questDelete(Quest*);
	bool closeEnough();
	void start(int);
	void newEnemies();
	void newFufu();
	bool fufuAlive = false;

	bool againHere = false;


	int number;
	int howMany = 4;
	int howManyMine = 4;
	bool areAlive = false;
public:

	Game_engine();
	void debugDisplay();
	void display();
};

