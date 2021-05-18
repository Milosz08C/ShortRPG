#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
class Mine : public sf::Drawable
{
	sf::Texture tloback[4];
	sf::Sprite tlo[4];
	Character* hero;
	sf::View widok;
	sf::Texture e;
	sf::Sprite exit;
	sf::Texture l;
	sf::Sprite lastExit;
public:
	void setView(Character&,sf::RenderWindow&);
	Mine();
	void collision(Character&);
	bool block();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	bool leave();
	bool lastMap();
};

