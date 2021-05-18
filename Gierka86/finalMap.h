#pragma once
#include<SFML/Graphics.hpp>
#include "Character.h"
#include "Mage.h"
#include "Wikary.h"
class finalMap : public sf::Drawable
{
	sf::Texture m;
	sf::Sprite map;
	Character* hero;

	sf::Texture g;
	sf::Sprite grail;

	sf::Texture l;
	sf::Sprite lastExit[2];
	sf::Font font;
	sf::Text text;

	void treeCollision();
	void chest();
	bool chestOpen = false;
	bool grailDraw = false;
	bool isGrailTaken = false;

	int block = 0;

public:	
	void open();
	bool back();
	bool backToBegin();
	void collision(Character&);
	bool taken();
	finalMap();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

