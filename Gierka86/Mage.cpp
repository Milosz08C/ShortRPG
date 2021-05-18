#include "Mage.h"
#include <iostream>

Mage::Mage(const std::string name, Weapon& stick) : Character(100, 100, 10, 20, 40, 1, name, stick) { k.loadFromFile("magTyl.png"); knigth.setTexture(k); knigth.setOrigin(50, 60); knigth.setPosition(500, 500); knigth.setScale(3,3);
}
Mage::Mage(const std::string name) : Character(100, 100, 10, 20, 40, 1, name, s1) { k.loadFromFile("magTyl.png"); knigth.setTexture(k); knigth.setOrigin(50, 60); knigth.setPosition(500, 500); knigth.setScale(3, 3); }



int Mage::skill1() //fire ball
{
	if (ifUsedSkill()==false)
	{
		if (decreaseCurrentMana(60))
		{
			setUsedSkill(true);
			return getWisdom() + 30;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int Mage::skill2() // frozen ball, returns dmg dealt
{
	if ( ifUsedSkill() == false)
	{
		if (decreaseCurrentMana(29))
		{
			setUsedSkill(true);
			return getWisdom() + 8;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Mage::skill3() //AA
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getWisdom();
	}
	else
	{
		return 0;
	}
}

int Mage::skill4() //supp heal
{
	if (ifUsedSkill() == false)
	{	
		if (decreaseCurrentMana(15))
		{
			increaseCurrentHp((getWisdom()/2)+10);
			setUsedSkill(true);	
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Mage::getDmg(int& boom)
{
	if (dodge() == false)
	{
		increaseCurrentHp(-boom);
	}
	if(dodge() == true)
	{
		increaseCurrentHp(0);
	}
	return boom;
}

void Mage::updateStats()
{
	//later in armUP() function
	if (!isArmed()) 
	{	//changes stats only if were not changed before
		increaseHp(getWeapon().getHp());
		increaseMana(getWeapon().getMana());
		increaseWisdom(getWeapon().getWisdom());
		increaseStrength(getWeapon().getStrength());
		increaseLuck(getWeapon().getLuck());
		increaseCurrentHp(getWeapon().getHp());
		increaseCurrentMana(getWeapon().getMana());
		setArmed(true);	//after changing stats with weapon, character becomes armed
	}
}

void Mage::changeWeapon(Weapon& roz)
{
	//
	if (!isArmed())
	{
		setWeapon(roz);
		updateStats();
		setArmed(true);
	}
	else
	{
		disarm();
		setWeapon(roz);
		updateStats();	
		setArmed(true);
	}

}

void Mage::move()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))&& stop!=1)
	{
		position = sf::Vector2f((-6.5f), 0.f);
		knigth.move(position);
		k.loadFromFile("magLewo.png");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))&& stop!=2)
	{	
		position = sf::Vector2f((6.5f), 0.f);
		knigth.move(position);
		k.loadFromFile("magPrawo.png");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && stop!=3)
	{
		position = sf::Vector2f(0.f, -6.5f);
		knigth.move(position);
		k.loadFromFile("magTyl.png");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&stop!=4)
	{
		position = sf::Vector2f(0.f, 6.5f);
		knigth.move(position);
		k.loadFromFile("magPrzod.png");
		knigth.setTexture(k);
	}
	run();
}

void Mage::run()
{
	switch (stop)
	{
	case 1:
		if (position != sf::Vector2f(-6.5f, 0.f))
		{
			stop = 0;
		}
		break;
	case 2:
		if (position != sf::Vector2f(6.5f, 0.f))
		{
			stop = 0;
		}
		break;
	case 3:
		if (position != sf::Vector2f(0.f, -6.5f))
		{
			stop = 0;
		}
		break;
	case 4:
		if (position != sf::Vector2f(0.f, 6.5f))
		{
			stop = 0;
		}
		break;
	}
}

void Mage::setScale(sf::Vector2f&x)
{
	knigth.setScale(10, 10);
	k.loadFromFile("magPrawo.png");
	knigth.setTexture(k);
	knigth.setPosition(x); //200,420
}

void Mage::resetScale()
{
	knigth.setScale(3, 3);
}

Who Mage::getCharacter()
{
	return MAGE;
}

void Mage::changeTexture(int c)
{
	
}

int Mage::getSkin()
{
	return 0;
}