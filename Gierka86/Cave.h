#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Mage.h"
#include "Wikary.h"
class Cave : public sf::Drawable
{
	sf::Texture c;
	sf::Sprite enter;
	sf::Texture d;
	sf::Sprite map;
public:
	bool Leave(Character*);
	void collision(Character*);
	Cave();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

