#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

enum choice{YUP,NOPE,W8};

class Quest : public sf::Drawable
{
	sf::Texture Magtext;
	
	sf::Texture cloud;
	sf::Sprite chat;
	Character* hero;
	sf::Font font;
	sf::Text text[2];
	sf::Texture coco;
	sf::Sprite cowa;
	int change = 0;
	sf::Text end;

	sf::Texture d;
	sf::Sprite dym;

public:
	sf::Sprite Magq;
	Quest();
	void draw(sf::RenderTarget&, sf::RenderStates)const override;
	choice firstAnswer();
	void setPos(Character&);
	void setatBegin();
	void reset();
	void check(Character&);
	bool give(Character*);
	void coward();
};


