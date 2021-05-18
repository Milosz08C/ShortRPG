#pragma once
#include<SFML/Graphics.hpp>
#include"Character.h"
#include"Mage.h"
#include"Wikary.h"
class endScreen : public sf::Drawable
{
	sf::Texture m;
	sf::Sprite map;
	int which;
public:
	void setWhich(int);
	int getWhich();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void setTexture(Character*);
};

