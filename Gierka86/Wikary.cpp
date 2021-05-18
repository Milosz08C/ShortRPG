#include "Wikary.h"

Wikary::Wikary(const std::string name, Weapon& stick) : Character(120, 100, 10, 30, 40, 1, name, stick) { k.loadFromFile("czlowiekTyl.png"); knigth.setTexture(k); knigth.setOrigin(60, 40); knigth.setPosition(500, 500); knigth.setScale(2, 2);
}

Wikary::Wikary(const std::string name) : Character(120, 100, 10, 30, 40, 1, name, s1) { k.loadFromFile("czlowiekTyl.png"); knigth.setTexture(k); knigth.setOrigin(60, 40); knigth.setPosition(500, 500); knigth.setScale(2, 2);
}



int Wikary::skill1() //throw sword
{
	if (ifUsedSkill() == false)
	{
		if (decreaseCurrentMana(60))
		{
			setUsedSkill(true);
			return getStrength() + 30;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}


int Wikary::skill2() //shuriken
{
	if (ifUsedSkill() == false)
	{
		if (decreaseCurrentMana(29))
		{
			setUsedSkill(true);
			return getStrength() + 8;
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

int Wikary::skill3() //dash
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getStrength();
	}
	else
	{
		return 0;
	}
}

int Wikary::skill4() //supp heal
{
	if (ifUsedSkill() == false)
	{
		if (decreaseCurrentMana(15))
		{
			increaseCurrentHp(getStrength()/2);
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

int Wikary::getDmg(int& boom)
{
	if (dodge() == false)
	{
		increaseCurrentHp(-boom);
	}
	else if (dodge() == true)
	{
		increaseCurrentHp(0);
	}
	return boom;
}

void Wikary::updateStats()
{
	//later in armUP() function
	if (!isArmed()) {	//changes stats only if were not changed before
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

void Wikary::changeWeapon(Weapon& roz)
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

void Wikary::move()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && stop != 1)
	{
	
		knigth.move(sf::Vector2f(-6.5f, 0.f));
		k.loadFromFile("czlowiekLewo.png");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && stop != 2)
	{	
		knigth.move(sf::Vector2f(6.5f, 0.f));
		k.loadFromFile("czlowiekPrawo.jpg");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) && stop != 3)
	{
		knigth.move(sf::Vector2f(0.f, -6.5f));
		k.loadFromFile("czlowiekTyl.png");
		knigth.setTexture(k);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && stop != 4)
	{
		knigth.move(sf::Vector2f(0.f, 6.5f));
		k.loadFromFile("czlowiekPrzod.png");
		knigth.setTexture(k);
	}
	run();
}

void Wikary::run()
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


void Wikary::setScale(sf::Vector2f& x)
{
	k.loadFromFile("czlowiekPrawo.jpg");
	knigth.setTexture(k);
	knigth.setScale(5, 5);
	knigth.setPosition(x);
}

void Wikary::resetScale()
{
	knigth.setScale(2, 2);
}

Who Wikary::getCharacter()
{
	return KNIGHT;
}


void Wikary::changeTexture(int c)
{

}

int Wikary::getSkin()
{
	return 0;
}