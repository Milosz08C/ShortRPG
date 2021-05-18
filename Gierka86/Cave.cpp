#include "Cave.h"

Cave::Cave()
{
	c.loadFromFile("caveEnter.png");
	enter.setTexture(c);
	enter.setOrigin(89,489);
	enter.setPosition(1300, 850);
	enter.setScale(4, 6);
	d.loadFromFile("cave.png");
	map.setTexture(d);
	map.setPosition(1600, 90);
	map.setScale(0.8, 0.8);
}

void Cave::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
	win.draw(map, state);
	win.draw(enter, state);
}

void Cave::collision(Character*hero)
{
	//----------------LEFT----------------------//
	if (hero->knigth.getPosition().x < 1680 &&hero->knigth.getPosition().y>120 && hero->knigth.getPosition().y < 780)
	{
		hero->stop = 1;
	}
	if (hero->knigth.getPosition().x < 1680 && hero->knigth.getPosition().y>980 && hero->knigth.getPosition().y < 1200)
	{
		hero->stop = 1;
	}
	//----------------RIGHT----------------------//
	if (hero->knigth.getPosition().x > 3170)
	{
		hero->stop = 2;
	}	
	//----------------UP----------------------//
	if (hero->knigth.getPosition().y < 120)
	{
		hero->stop = 3;
	}
	//----------------DOWN----------------------//
	if (hero->knigth.getPosition().y > 1200)
	{
		hero->stop = 4;
	}
}

bool Cave::Leave(Character*hero)
{
	if (hero->knigth.getPosition().x < 1680 && hero->knigth.getPosition().y>780 && hero->knigth.getPosition().y < 980)
	{
		return true;
	}
	return false;
}
