
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Character.h"
#include"Weapon.h"
#include"Stick.h"
#include"Scepter.h"
#include "Mage.h"
#include "Enemy.h"
#include "Game_engine.h"
#include "Battle.h"


int main()
{
	
	Character* c1 = new Wikary("Juliusz", *new Knife());
	Character* c2 = new Mage("Wikary");
	Character* en = new Enemy(100,10,10,10,10,10,"zbysiu",*new Knife());	//enemy Zbysiu

	en->changeTexture(2);
	int x = 1000;
	c1->getDmg(x);
	std::cout << c1->isAlive();

	//bat->fight(*c2, *en);
	//NAPRAW HEAL'A

	//x = en->skill1();
	//std::cout << x;

	Game_engine game;

	//game.debugDisplay();
	game.display();
	//std::cout << w.dodge() << std::endl;
	//c1->updateStats();
	//std::cout << c1->getInfo() << std::endl;
	//c1->changeWeapon(*new Scepter());
	//c1->updateStats();
	//std::cout << c1->getInfo() << std::endl;

	/*std::cout<<"PRZED ATAKIEM " << c1->getInfo() << std::endl;
	 
	

	//bysiu atakuje julka
	
	int x = 2;
	//bat.whoUsedSkill();
	std::cout<<"PO PIERWSZYM ATAKU " << c1->getInfo() << std::endl;
	if (x == 2)
	{
		c2->skill2();
		bat.whoUsedSkill(x);
	}
	std::cout<<"PO DRUGIM ATAKU " << c1->getInfo() << std::endl;*/

	/*c2->updateStats();
	std::cout << c2->getInfo() << std::endl;*/


/*	Battle* b = new Battle(*c1, *c2);
	b->whoUsedSkill();
	c2->updateStats();
	std::cout<< c1->getInfo()<<std::endl;
	int dmg = c2->skill1();
	c1->getDmg(dmg);
	b->whoUsedSkill();
	b->whoIsDead();
	std::cout << c1->getInfo();
	int dmg1 = c2->skill1();
	b->whoUsedSkill();
	c1->getDmg(dmg1);
	std::cout<<c1->getInfo();*/
}