#pragma once
#include<SFML/Graphics.hpp>
#include "Character.h"
class Grass : public sf::Drawable
{
	sf::Texture tloback;
	sf::Sprite tlo;
	Character* hero;

public:
	Grass();
	void collision(Character&);
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

