#include "Enemy.h"

Enemy::Enemy() : Character(50, 50, 50, 50, 50, 1, "Zbigniew", w1) {setUsedSkill(true); }

Enemy::Enemy(int hp, int mana, int luck, int strength, int wisdom, int lvl, std::string name, Weapon& w) : Character(hp, mana, luck, strength, wisdom, lvl, name, w) {
	 setUsedSkill(true);
}

void Enemy::updateStats()
{

}

int Enemy::skill1()
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getStrength()+10;
	}
	else
	{
		return 0;
	}

}

int Enemy::skill2()
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getStrength()-10;
	}
	else
	{
		return 0;
	}

}

int Enemy::skill3()
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getStrength()-20;
	}
	else
	{
		return 0;
	}

}

int Enemy::skill4()
{
	if (ifUsedSkill() == false)
	{
		setUsedSkill(true);
		return getStrength()-40;
	}
	else
	{
		return 0;
	}

}

int Enemy::getDmg(int& boom)
{
	if (dodge() == false)
	{
		increaseCurrentHp(-boom);
	}
	if (dodge() == true)
	{
		increaseCurrentHp(0);
	}
	return boom;
}

void Enemy::changeWeapon(Weapon& roz)
{
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

void Enemy::move()
{

}

void Enemy::run()
{

}

void Enemy::changeTexture(int c)
{	
	if (c == 1)
	{
		k.loadFromFile("enemy1.png");
		knigth.setTexture(k); 
		knigth.setOrigin(50, 60);
		knigth.setScale(3, 3);
		scale = 1;
		skin= 1;
	}

	if (c == 2)
	{
		k.loadFromFile("skeleton.png");
		knigth.setTexture(k);
		knigth.setScale(0.5, 0.5);
		knigth.setOrigin(385, 451);
		scale = 2;
		skin=2;
	}

	if (c == 3)
	{
		k.loadFromFile("fufu.png");
		knigth.setTexture(k);
		knigth.setScale(1, 1);
		knigth.setOrigin(210, 151);
		scale = 3;
		skin = 3;
	}

}

int Enemy::getSkin()
{
	return skin;
}

void Enemy::setScale(sf::Vector2f&x)
{
	if (scale == 1)
	{
		knigth.setScale(10, 10);
	
	}
	if (scale == 2)
	{
		knigth.setScale(2,2);
	}
	if (scale == 3)
	{
		knigth.setScale(2, 2);
	}
	knigth.setPosition(x);
}

void Enemy::resetScale()
{
	if (scale == 1)
	{
		knigth.setScale(3, 3);

	}
	if (scale == 2)
	{
		knigth.setScale(0.5, 0.5);

	}
	if (scale == 3)
	{
		knigth.setScale(1, 1);
	}

}

Who Enemy::getCharacter()
{
	return ENEMY;
}