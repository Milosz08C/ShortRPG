#include "endScreen.h"

void endScreen::draw(sf::RenderTarget&win,sf::RenderStates state) const
{
	win.draw(map, state);
}

void endScreen::setTexture(Character* hero)
{
	if (getWhich() == 0)
	{
		if (hero->getCharacter() == MAGE)
		{
			m.loadFromFile("magDead.png");
			map.setTexture(m);
			map.setOrigin(922, 665);
			map.setScale(0.8, 0.9);
			map.setPosition(500, 500);
		}
		else if (hero->getCharacter() == KNIGHT)
		{
			m.loadFromFile("wikaryDead.png");
			map.setTexture(m);
			map.setOrigin(922, 665);
			map.setScale(0.8, 0.9);
			map.setPosition(500, 500);
		}
	}

	else if (getWhich() == 1)
	{
		m.loadFromFile("win.png");
		map.setTexture(m);
		map.setOrigin(828, 390);
		map.setScale(0.8, 0.9);
		map.setPosition(500, 500);
	}
}

void endScreen::setWhich(int x)
{
	which = x;
}

int endScreen::getWhich()
{
	return which;
}