#include "Weapon_Shop.h"

Weapon_Shop::Weapon_Shop(Character& h) : hero(&h)
{
	if (hero->getCharacter() == MAGE)
	{
		w[0].loadFromFile("staff.PNG");
		w[1].loadFromFile("betterStick.png");
		w[2].loadFromFile("OPstick.png");
		wands[0].setTexture(w[0]);
		wands[0].setOrigin(115, 65);
		wands[0].setScale(1.2, 1.6);
		wands[1].setScale(1.2, 1.6);
		wands[2].setScale(2, 3);
		wands[1].setTexture(w[1]);
		wands[1].setOrigin(94, 72);
		wands[2].setTexture(w[2]);
		wands[2].setOrigin(115, 92);
		text[0].setString("STICK");
		text[2].setString("BETTER STICK");
		text[4].setString("    EPIC WAND");
	}
	else if(hero->getCharacter()==KNIGHT)
	{
		w[0].loadFromFile("dagger.png");
		w[1].loadFromFile("swordWeapon.png");
		w[2].loadFromFile("axe.png");
		wands[0].setTexture(w[0]);
		wands[0].setOrigin(108, 24);
		wands[0].setScale(0.2, 0.4);

		wands[1].setTexture(w[1]);
		wands[1].setScale(0.6, 0.5);
		wands[1].setTexture(w[1]);
		wands[1].setOrigin(291, 91);	

		wands[2].setTexture(w[2]);
		wands[2].setScale(0.3, 0.22);
		wands[2].setOrigin(420, 7);
		text[0].setString("DAGGER");
		text[2].setString("       SWORD");
		text[4].setString("          AXE");
	}
	font.loadFromFile("BebasNeue-Bold.ttf");

	for (auto& b : back)
	{
		b.setFillColor(sf::Color::Black);
		b.setOutlineThickness(3);
		b.setOutlineColor(sf::Color::White);
		b.setSize(sf::Vector2f(200,200));
	}

	for (auto& t : text)
	{
		t.setFont(font);
		t.setFillColor(sf::Color::White);
		t.setStyle(sf::Text::Bold);
		t.setCharacterSize(40);
	}

	text[1].setString("2 LVL");
	text[3].setString("3 LVL");
	text[5].setString(" 5LVL");

	text[6].setCharacterSize(50);
	text[6].setString("TOO LOW LEVEL");
	text[6].setFillColor(sf::Color::Red);

	s.loadFromFile("shop.png");
	store.setTexture(s);
	store.setOrigin(412,134);
	store.setPosition(370,100);
	store.setScale(0.5,0.5);
}

void Weapon_Shop::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
	win.draw(store, state);
	if (isOpen == true)
	{
		for (int i = 0; i < 3; i++)
		{
			win.draw(back[i], state);
			win.draw(wands[i], state);
		}
		for (int i=0; i<6; i++)
		{
			win.draw(text[i], state);
		}
		if (showStat == true)
		{
			win.draw(weaponBack, state);
			for (auto& s : stats)
			{
				win.draw(s, state);
			}
			if (textExist == true)
			{
				win.draw(text[6], state);
			}
		}

		
	}

}

void Weapon_Shop::shop(sf::RenderWindow&win)
{

		//--------------------------------BLOCK LEFT-----------------------------------//
		if (((hero->knigth.getPosition().x < store.getPosition().x + 250 && hero->knigth.getPosition().x > store.getPosition().x + 240) && (hero->knigth.getPosition().y < store.getPosition().y + 280 && hero->knigth.getPosition().y > store.getPosition().y)) )
		{
			choice(win);
			isOpen = true;
			setPosition();
			hero->stop = 1;
		}
		
		//--------------------------------BLOCK RIGHT-----------------------------------//
		else if (((hero->knigth.getPosition().x < store.getPosition().x + 200 && hero->knigth.getPosition().x > store.getPosition().x) && (hero->knigth.getPosition().y < store.getPosition().y + 280 && hero->knigth.getPosition().y > store.getPosition().y)))
		{
			choice(win);
			isOpen = true;
			setPosition();
			hero->stop = 2;
		}
		
		//-------------------------------BLOCK DOWN------------------------------//
		else if (((hero->knigth.getPosition().y < store.getPosition().y + 290 && hero->knigth.getPosition().y > store.getPosition().y + 288) && (hero->knigth.getPosition().x < store.getPosition().x + 250 && hero->knigth.getPosition().x > store.getPosition().x)))
		{
			choice(win);
			isOpen = true;
			setPosition();
			hero->stop = 3;
		}
		
		//-------------------------------BLOCK UP------------------------------//
		else if (((hero->knigth.getPosition().y > store.getPosition().y-40 && hero->knigth.getPosition().y < store.getPosition().y + 20) && (hero->knigth.getPosition().x < store.getPosition().x + 250 && hero->knigth.getPosition().x > store.getPosition().x)))
		{
			choice(win);
			isOpen = true;
			setPosition();
			hero->stop = 4;
		}
		else
		{
			isOpen = false;
		}
}

void Weapon_Shop::setPosition()
{
	wands[0].setPosition(store.getPosition()-sf::Vector2f(0,250));
	back[0].setPosition(wands[0].getPosition()-sf::Vector2f(40,0));
	text[0].setPosition(back[0].getPosition()+sf::Vector2f(40,80));
	text[1].setPosition(text[0].getPosition() + sf::Vector2f(0, 40));


	wands[1].setPosition(store.getPosition() - sf::Vector2f(-200, 250));
	back[1].setPosition(wands[1].getPosition() - sf::Vector2f(40, 0));
	text[2].setPosition(back[1].getPosition() + sf::Vector2f(0, 80));
	text[3].setPosition(text[2].getPosition() + sf::Vector2f(60, 40));


	wands[2].setPosition(store.getPosition() - sf::Vector2f(-400, 250));
	back[2].setPosition(wands[2].getPosition() - sf::Vector2f(40, 0));
	text[4].setPosition(back[2].getPosition() + sf::Vector2f(0, 80));
	text[5].setPosition(text[4].getPosition() + sf::Vector2f(60, 40));
}

void Weapon_Shop::choice(sf::RenderWindow& win)
{
	if ((sf::Mouse::getPosition(win).x > back[0].getPosition().x-100 && sf::Mouse::getPosition(win).x < back[0].getPosition().x+80) && (sf::Mouse::getPosition(win).y > back[0].getPosition().y+300 && sf::Mouse::getPosition(win).y < back[0].getPosition().y + 500) && isOpen==true)
	{
		if (hero->getCharacter() == MAGE)
		{
			WeaponInfo(&hero->getWeapon(), new Staff);
		}
		if (hero->getCharacter() == KNIGHT)
		{
			WeaponInfo(&hero->getWeapon(), new Dagger);
		}
		showStat = true;
		change = 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&hero->getLvl() >= 2)
		{
			if (hero->getCharacter() == MAGE)
			{
				hero->changeWeapon(*new Staff);
			}
			if (hero->getCharacter() == KNIGHT)
			{
				hero->changeWeapon(*new Dagger);
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hero->getLvl() < 2)
		{
			text[6].setPosition(back[0].getPosition()+sf::Vector2f(0,100));
			textExist = true;
		}
	}
	
	else
	{
		showStat = false;
	}
	
	if ((sf::Mouse::getPosition(win).x > back[1].getPosition().x - 100 && sf::Mouse::getPosition(win).x < back[1].getPosition().x + 80) && (sf::Mouse::getPosition(win).y > back[1].getPosition().y + 300 && sf::Mouse::getPosition(win).y < back[1].getPosition().y + 500) && isOpen == true)
	{
		if (hero->getCharacter() == MAGE)
		{
			WeaponInfo(&hero->getWeapon(), new Scepter);
		}
		if (hero->getCharacter() == KNIGHT)
		{
			WeaponInfo(&hero->getWeapon(), new Sword);
		}
		showStat = true;
		change = 2;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hero->getLvl() >= 3)
		{

			if (hero->getCharacter() == MAGE)
			{
				hero->changeWeapon(*new Scepter);
			}
			if (hero->getCharacter() == KNIGHT)
			{
				hero->changeWeapon(*new Sword);
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hero->getLvl() < 3)
		{
			text[6].setPosition(back[1].getPosition() + sf::Vector2f(0, 100));
			textExist = true;
		}
	}

	if ((sf::Mouse::getPosition(win).x > back[2].getPosition().x - 100 && sf::Mouse::getPosition(win).x < back[2].getPosition().x + 80) && (sf::Mouse::getPosition(win).y > back[2].getPosition().y + 300 && sf::Mouse::getPosition(win).y < back[2].getPosition().y + 500) && isOpen == true)
	{

		if (hero->getCharacter() == MAGE)
		{
			WeaponInfo(&hero->getWeapon(), new OPstick);
		}
		if (hero->getCharacter() == KNIGHT)
		{
			WeaponInfo(&hero->getWeapon(), new Axe);
		}
		showStat = true;
		change = 3;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hero->getLvl() >= 5)
		{

			if (hero->getCharacter() == MAGE)
			{
				hero->changeWeapon(*new OPstick);
			}
			if (hero->getCharacter() == KNIGHT)
			{
				hero->changeWeapon(*new Axe);
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hero->getLvl() < 5)
		{
			text[6].setPosition(back[2].getPosition() + sf::Vector2f(0, 100));
			textExist = true;
		}
	}
	textMove();

}

void Weapon_Shop::WeaponInfo(Weapon* now, Weapon* future)
{
	weaponBack.setSize(sf::Vector2f(160, 180));
	weaponBack.setFillColor(sf::Color(140, 140, 140));
	weaponBack.setOutlineThickness(3);
	weaponBack.setOutlineColor(sf::Color(38, 38, 38));

	for (int i = 0, j = 10; i < 5 && j < 50; i++, j -= 30)
	{
		stats[i].setFont(font);
		stats[i].setFillColor(sf::Color(38, 38, 38));
		stats[i].setStyle(sf::Text::Bold);
		if (change == 1)
		{
			stats[i].setPosition(back[0].getPosition() - sf::Vector2f(-70, -200 + j));
		}
		
		else if (change == 2)
		{
			stats[i].setPosition(back[1].getPosition() - sf::Vector2f(-70, -200 + j));
		}
		
		else if (change == 3)
		{
			stats[i].setPosition(back[2].getPosition() - sf::Vector2f(-70, -200 + j));
		}

		stats[i].setCharacterSize(30);
	}
	
	weaponBack.setPosition(stats[0].getPosition() - sf::Vector2f(0, 20));
	
	//--------------------HP------------------------------//
	if (future->getHp() - now->getHp() >= 0)
	{
		stats[0].setString("HP: +" + std::to_string(future->getHp() - now->getHp()));
	}
	
	else if (future->getHp() - now->getHp() < 0)
	{
		stats[0].setString("HP: " + std::to_string(future->getHp() - now->getHp()));
	}

	//-------------------------MANA----------------------//

	if (future->getMana() - now->getMana() >= 0)
	{
		stats[1].setString("MANA: +" + std::to_string(future->getMana() - now->getMana()));
	}

	else if (future->getMana() - now->getMana() < 0)
	{
		stats[1].setString("MANA: " + std::to_string(future->getMana() - now->getMana()));
	}

	//----------------------WISDOM------------------//

	if (future->getWisdom() - now->getWisdom() >= 0)
	{
		stats[2].setString("WISDOM: +" + std::to_string(future->getWisdom() - now->getWisdom()));
	}

	else if (future->getWisdom() - now->getWisdom() < 0)
	{
		stats[2].setString("WISDOM: " + std::to_string(future->getWisdom() - now->getWisdom()));
	}

	//-----------------STREGTH-----------------//

	if (future->getStrength() - now->getStrength() >= 0)
	{
		stats[3].setString("STRENGTH: +" + std::to_string(future->getStrength() - now->getStrength()));
	}

	else if (future->getStrength() - now->getStrength() < 0)
	{
		stats[3].setString("STRENGTH: " + std::to_string(future->getStrength() - now->getStrength()));
	}

	//-----------------LUCK---------------//
	if (future->getLuck() - now->getLuck() >= 0)
	{
		stats[4].setString("LUCK: +" + std::to_string(future->getLuck() - now->getLuck()));
	}

	else if (future->getLuck() - now->getLuck() < 0)
	{
		stats[4].setString("LUCK: " + std::to_string(future->getLuck() - now->getLuck()));
	}


}

void Weapon_Shop::textMove()
{
	if (textExist == true)
	{
		text[6].move(0.f,-2.f);
		if (text[6].getPosition().y < (back[0].getPosition().y -50))
		{
			textExist = false;
		}
	}
}

/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		if (change == 2)
		{
			isOpen = false;
			change = 0;
			return false;
		}
		else
		{
			isOpen = true;
			setPosition();
			choice(win);
			if (change == 0 || change == 1)
			{
				change += 1;
			}
			return true;
		}
	}
*/