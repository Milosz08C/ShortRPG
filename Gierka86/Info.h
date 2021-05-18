#pragma once
#include "Character.h"

class Info : public sf::Drawable
{
	Character* hero;
	sf::View widok;
	int change = 0;
	void getInfoSFML(Character*);
	sf::Text stats[8];
	sf::Text tut[5];
	sf::Font font;
	sf::RectangleShape back;
	sf::RectangleShape graphicStats[4];
	sf::RectangleShape backEnemy;
	sf::RectangleShape tutBack;
	bool info = false;
	bool fight = false;
	sf::Text graphicText[4];	
	bool tutOpen = true;
	sf::Text stopText;
	bool lowLvl = false;
public:
	bool setFigth(bool);
	void tutorial(Character*);
	Info();
	void stop(bool);
	Info(Character&);
	void updateStats();
	void draw(sf::RenderTarget&, sf::RenderStates state)const override;
	void infoStats(Character&);
};

