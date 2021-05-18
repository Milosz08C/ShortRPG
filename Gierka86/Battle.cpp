#include "Battle.h"

Battle::Battle()
{
	font.loadFromFile("BebasNeue-Bold.ttf");
	dmgCount.setFont(font);
	dmgCount.setCharacterSize(60);
	dmgCount.setFillColor(sf::Color::Red);
	dmgCount.setStyle(sf::Text::Bold);
	dmgToHero.setFont(font);
	dmgToHero.setCharacterSize(60);
	dmgToHero.setFillColor(sf::Color::Red);
	dmgToHero.setStyle(sf::Text::Bold);
	Mana.setFont(font);
	Mana.setCharacterSize(40);
	Mana.setFillColor(sf::Color::Blue);
	Mana.setStyle(sf::Text::Bold);
}

void Battle::fight(Character& c1, Character& c2)
{
	if ((c1.getCharacter() == MAGE || c1.getCharacter() == KNIGHT) && c2.getCharacter() == ENEMY)
	{
		hero = &c1;
		enemy = &c2;
	}
	else
	{
		hero = &c2;
		enemy = &c1;
	}
	whoUsedSkill(hero, enemy);
	skillName = true;
}

void Battle::draw(sf::RenderTarget& win, sf::RenderStates state) const
{	
	if (dmgToHeroEx == true)
	{
		win.draw(dmgToHero, state);
	}

	if (textExist == true)
	{
		win.draw(dmgCount, state);
	}

	if (manaExist == true)
	{
		win.draw(Mana, state);
	}

	if (spriteExist == true)
	{
		win.draw(skillSprite,state);
	}

	if (closeEnough == true)
	{
		win.draw(PressE, state);
	}



	if (skillName == true)
	{
		win.draw(square);
		for (auto& s : spell)
		{
			win.draw(s, state);
		}
	}

	if (enemySkill == true)
	{
		win.draw(skillEnemy, state);
	}
}


bool Battle::isSomeoneDead(Character*hero, Character*enemy)
{
	return !hero->isAlive() || !enemy->isAlive();
}

Character *Battle::whoIsDead(Character& hero,Character& enemy)
{
	Character* hero1 = &hero;
	Character* enemy1 = &enemy;
	if(!hero1->isAlive())
	{
		return hero1;
	}
	if(!enemy1->isAlive())
	{
		return enemy1;
	}
	return nullptr;
}

void Battle::whoUsedSkill(Character* hero, Character* enemy)
{
	if (isSomeoneDead(hero, enemy) == false)
	{	
		if (pos == false)
		{
			if (hero->getCharacter() == MAGE)
			{
				posHero = hero->knigth.getPosition() - sf::Vector2f(250, 0);
				hero->setScale(posHero);
				posHero += sf::Vector2f(400, 0);
			}
			else if (hero->getCharacter() == KNIGHT)
			{
				posHero = hero->knigth.getPosition() - sf::Vector2f(250, 80);
				hero->setScale(posHero);
				posHero += sf::Vector2f(400, 80);
			}
			enemy->setScale(posHero);
			pos = true;
		}

		if (enemy->ifUsedSkill() == true && hero->ifUsedSkill() == false && enemySkill==false) //hero can use spell 
		{
			dmg=HerochooseSkill();
			if (delay == 1)
			{
				delay = 0;
			}
		}
		if (hero->ifUsedSkill() == true && enemy->isAlive() && enemy->ifUsedSkill() == false && spriteExist==false&& dash==false) //enemy can use spell
		{
			dmgFenemy = EnemyChooseSkill();
			enemySkill = true;
			if (hero->dodge() == true)
			{
				dmgToHero.setString("DODGE");
			}
			else
			{
				dmgToHero.setString("- " + std::to_string(dmgFenemy));	
			}
			dmgToHeroTextPos(hero);
		}
		spritePosition(hero, enemy);
		loadTexture(hero, enemy);
	}
	else
	{
		pos = false;
		hero->resetScale();
		enemy->resetScale();
	}
}

int Battle::EnemyChooseSkill()
{	
		changeSkill = (std::rand() % 4) + 1;
		if (changeSkill == 1)
		{

			hero->setUsedSkill(false);
			if (enemy->getSkin() == 1)
			{
				s.loadFromFile("ezQ.jpg");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(598, 591);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}
			
			if (enemy->getSkin() == 2)
			{
				s.loadFromFile("head.png");
				isHead = true;
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1.4, 1.4);
				skillEnemy.setOrigin(160, 160);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}

			if (enemy->getSkin() == 3)
			{
				s.loadFromFile("bear.png");
				isHead = true;
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(150, 156);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}
			
			return enemy->skill1();
		}
	
		else if (changeSkill == 2)
		{
			hero->setUsedSkill(false);
			if (enemy->getSkin()==1)
			{
				s.loadFromFile("morgQ.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(260, 100);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}
			if (enemy->getSkin() == 2)
			{
				s.loadFromFile("arrow.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(344, 249);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}

			if (enemy->getSkin() == 3)
			{
				s.loadFromFile("bear4s.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(0.5, 0.5);
				skillEnemy.setOrigin(183, 256);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}


			return enemy->skill2();
		}
		else if (changeSkill == 3)
		{
			hero->setUsedSkill(false);
			if (enemy->getSkin()==1)
			{
				s.loadFromFile("stone.png");
				skillEnemy.setTexture(s);	
				skillEnemy.setOrigin(302, 226);
				skillEnemy.setScale(0.25, 0.25);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}
			if (enemy->getSkin() == 2)
			{
				s.loadFromFile("wlocznia.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(456, 554);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}
			if (enemy->getSkin() == 3)
			{
				s.loadFromFile("bear3.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(59, 56);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}

			return enemy->skill3();
		}
		else if (changeSkill == 4)
		{
			hero->setUsedSkill(false);
			if (enemy->getSkin()==1)
			{
				s.loadFromFile("drop.png");
				skillEnemy.setTexture(s);
				skillEnemy.setOrigin(406, 1166);
				skillEnemy.setScale(0.4, 0.4);
				skillEnemy.setPosition(enemy->knigth.getPosition() - sf::Vector2f(0, 40));
			}
			if (enemy->getSkin() == 2)
			{
				s.loadFromFile("bone.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(2, 2);
				skillEnemy.setOrigin(256, 282);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}

			if (enemy->getSkin() == 3)
			{
				s.loadFromFile("leaf.png");
				skillEnemy.setTexture(s);
				skillEnemy.setScale(1, 1);
				skillEnemy.setOrigin(131, 169);
				skillEnemy.setPosition(enemy->knigth.getPosition() + sf::Vector2f(0, 20));
			}

			return enemy->skill4();
		}

}

int Battle::HerochooseSkill()
{
				//--------------FIRST SKILL----------------//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) &&hero->getCurrentMana()>=60)
	{
		if (hero->getCharacter() == MAGE)
		{
			s.loadFromFile("fireball.png");		
			skillSprite.setTexture(s);
			skillSprite.setOrigin(260, 191);
			skillSprite.setPosition(hero->knigth.getPosition() + sf::Vector2f(0, 50));
		}
		else
		{
			s.loadFromFile("sword.png");
			skillSprite.setTexture(s);
			skillSprite.setOrigin(1000, 0);
			skillSprite.scale(0.4, 0.4);
			skillSprite.setPosition(hero->knigth.getPosition() + sf::Vector2f(0, 0));
		}
		spriteExist = true;
		dmg = hero->skill1();
		enemy->setUsedSkill(false);
		manaExist = false;
		if (enemy->dodge() == true)
		{
			dmgCount.setString("DODGE");
			dmgTextPos(enemy);
		}
		else
		{
			dmgCount.setString("- " + std::to_string(dmg));
			dmgTextPos(enemy);
		}
		dmgCount.setFillColor(sf::Color::Red);
		return dmg;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && hero->getCurrentMana() < 60) 
	{
		Mana.setString("NOT ENOUGH MANA");
		Mana.setPosition(hero->knigth.getPosition() - sf::Vector2f(60, 0));
		manaExist = true;
	}

			//--------------------SECOND SKILL---------------------//

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)&& hero->getCurrentMana() >= 29)
	{	
		s.loadFromFile("frozenball.png");
		if (hero->getCharacter() == MAGE)
		{
			s.loadFromFile("frozenball.png");
			skillSprite.setTexture(s);
			skillSprite.setOrigin(381,215);
			isShuriken = true;
			skillSprite.setPosition(hero->knigth.getPosition() + sf::Vector2f(0, 50));
		}
		else
		{
			s.loadFromFile("shuriken.png");
			isShuriken = true;
			skillSprite.setTexture(s);
			skillSprite.setOrigin(1200, 1200);
			skillSprite.scale(0.05, 0.05);
			skillSprite.setPosition(hero->knigth.getPosition() + sf::Vector2f(-100, 50));
		}
		spriteExist = true;
		dmg = hero->skill2();
		enemy->setUsedSkill(false);
		manaExist = false;
		if (enemy->dodge() == true)
		{
			dmgCount.setString("DODGE");
			dmgTextPos(enemy);
		}
		else
		{
			dmgCount.setString("- " + std::to_string(dmg));
			dmgTextPos(enemy);
		}
		dmgCount.setFillColor(sf::Color::Red);
		return dmg;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && hero->getCurrentMana() < 29)
	{
		Mana.setString("NOT ENOUGH MANA");
		Mana.setPosition(hero->knigth.getPosition() - sf::Vector2f(60, 0));
		manaExist = true;
	}

			//-----------------------------THIRD SKILL-----------------------//

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		dmg = hero->skill3();
		enemy->setUsedSkill(false);
		manaExist = false;
		startPos = hero->knigth.getPosition();
		if (hero->getCharacter() == KNIGHT)
		{
			dash=true;
		}
		if (hero->getCharacter() == MAGE)
		{		
			s.loadFromFile("AAmag.png");
			skillSprite.setTexture(s);
			skillSprite.setOrigin(200, 200);
			skillSprite.setPosition(hero->knigth.getPosition() + sf::Vector2f(0, 50));
			spriteExist = true;
		}
		if (enemy->dodge() == true)
		{
			dmgCount.setString("DODGE");
			dmgTextPos(enemy);
		}
		else if(enemy->dodge()==false)
		{
			dmgCount.setString("- " + std::to_string(dmg));

			dmgTextPos(enemy);
		}
		dmgCount.setFillColor(sf::Color::Red);
		return dmg;
	}

	//-----------------FORTH SKILL--------------------------------//

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)&& hero->getCurrentMana() >= 15)
	{
		hero->skill4();
		if (hero->getCharacter() == MAGE)
		{
			
			dmg =(hero->getWisdom()/2)+10;
					
		}
		else
		{
			dmg = hero->getStrength()/2;
		}

		enemy->setUsedSkill(false);
		manaExist = false;
		delay = 1;
		dmgCount.setString("+ " + std::to_string(dmg));
		dmgCount.setFillColor(sf::Color::Green);
		dmgTextPos(hero);
		textExist = true;
		return 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && hero->getCurrentMana() < 15)
	{
		Mana.setString("NOT ENOUGH MANA");
		Mana.setPosition(hero->knigth.getPosition() - sf::Vector2f(60, 0));
		manaExist = true;
	}
}

void Battle::loadTexture(Character* hero, Character* enemy)
{
	if (texturePos == false)
	{
		square.setFillColor(sf::Color(103, 152, 152));
		square.setOutlineThickness(3);
		square.setOutlineColor(sf::Color::Black);
		square.setSize(sf::Vector2f(620, 150));
		if (hero->getCharacter() == MAGE)
		{
			spell[0].setString("1: FIREBALL  60");
			spell[1].setString("2: SNOW  29");
			spell[2].setString("3: ATTACK");
			spell[3].setString("4: HEAL+"+std::to_string((hero->getWisdom()/2)+10)+"HP  15");
		}

		if (hero->getCharacter() == KNIGHT)
		{
			spell[0].setString("1: THROW SWORD  60");
			spell[1].setString("2: SHURIKEN  29");
			spell[2].setString("3: DASH"); 
			spell[3].setString("4: HEAL+"+std::to_string(hero->getStrength()/2)+"HP  15");
		}

		for (auto& s : spell)
		{
			s.setFont(font);
			s.setCharacterSize(40);
			s.setFillColor(sf::Color(31, 46, 46));
			s.setStyle(sf::Text::Bold);

		}

		for (int i = 0, j = 0; i < 2 && j < 400; i++, j += 350)
		{
			spell[i].setPosition(hero->knigth.getPosition() + sf::Vector2f(40 + j, 300));
		}

		for (int i = 2, j = 0; i < 4 && j < 400; i++, j += 350)
		{
			spell[i].setPosition(hero->knigth.getPosition() + sf::Vector2f(40 + j, 400));
		}
		square.setPosition(spell[0].getPosition() - sf::Vector2f(30, 0));
		texturePos = true;
	}

}

void Battle::rotate()
{
	if (skillEnemy.getPosition().x > hero->knigth.getPosition().x && isHead == true)
	{
		skillEnemy.setRotation(rotateDegree);
		rotateDegree -= 10;
	}

	if (skillSprite.getPosition().x < enemy->knigth.getPosition().x && isShuriken==true)
	{
		skillSprite.setRotation(rotateDegree);	
		rotateDegree += 10;		
	}
}

void Battle::spritePosition(Character*hero, Character* enemy)
{

	if (enemySkill == true)
	{
		skillEnemy.move(-18.f, 0.f);// skillSprite.move(sf::Vector2f(-18.f, 0.f)); do gry. Do testow 4
		rotate();
		if (skillEnemy.getPosition().x < hero->knigth.getPosition().x)
		{
			test12 = 1;
			dmgToHeroEx = true;
			hero->getDmg(dmgFenemy);
			skillEnemy.setRotation(0);
			enemySkill = false;
			isHead = false;
			skillEnemy.setPosition(0, 0);

		}
	}

	if (dash == true)
	{
		hero->knigth.move(14.f, 0.f);
		if (hero->knigth.getPosition().x > enemy->knigth.getPosition().x)
		{
			hero->knigth.move(0.f, 0.f);
			hero->knigth.setPosition(startPos);
			enemy->getDmg(dmg);
			textExist = true;
			dash = false;
		}

	}
	if (spriteExist == true)
	{
		skillSprite.move(sf::Vector2f(18.f, 0.f)); //skillSprite.move(sf::Vector2f(18.f, 0.f)); do gry. Do testow 4
		rotate();
		if (skillSprite.getPosition().x > enemy->knigth.getPosition().x)
		{
			skillSprite.setScale(1, 1);
			skillSprite.setRotation(0);
			skillSprite.setPosition(0, 0);
			enemy->getDmg(dmg);
			textExist = true;
			isShuriken = false;
			spriteExist = false;
		}
	}

	if (textExist == true)
	{
		dmgCount.move(sf::Vector2f(0, -7.f)); //dmgCount.move(sf::Vector2f(0, -7.f));
		if (dmgCount.getPosition().y < enemy->knigth.getPosition().y-200)
		{
			textExist = false;
		}
	}
	if (dmgToHeroEx == true)
	{
		dmgToHero.move(sf::Vector2f(0, -7.f)); //dmgToHero.move(sf::Vector2f(0, -7.f));
		if (dmgToHero.getPosition().y < enemy->knigth.getPosition().y - 200)
		{
			dmgToHeroEx = false;
		}
	}
}

void Battle::dmgTextPos(Character* enemy)
{	
	dmgCount.setPosition(enemy->knigth.getPosition() - sf::Vector2f(40, 0));
	
}

void Battle::dmgToHeroTextPos(Character* hero)
{	
	dmgToHero.setPosition(hero->knigth.getPosition() + sf::Vector2f(80, 0));
}

void Battle::pressePos(std::vector<Character*>enemy,int i)
{
	PressE.setFont(font);
	PressE.setCharacterSize(80);
	PressE.setFillColor(sf::Color::Red);
	PressE.setStyle(sf::Text::Bold);
	PressE.setPosition(enemy[i]->knigth.getPosition() + sf::Vector2f(0, 40));
	PressE.setString("PRESS E TO FIGHT");
}

bool Battle::setClose(bool s)
{
	closeEnough = s;
	return closeEnough;
}

void Battle::reset(Character*hero)
{
	dmg = 0;
	dmgFenemy = 0;
	rotateDegree = 0;
	skillSprite.setPosition(0,0); 
	manaExist = false;
	dmgToHeroEx = false;
	textExist = false;
	spriteExist = false;
	texturePos = false;
	dash = false;;
	pos = false;
	texturePos = false;
	enemySkill = false;
	skillName = false;
	hero->setUsedSkill(false);
	hero->reset();
	hero->resetScale();
}