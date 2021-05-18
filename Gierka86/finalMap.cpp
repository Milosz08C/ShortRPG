#include "finalMap.h"
finalMap::finalMap()
{
	m.loadFromFile("finalMap.jpg");
	map.setTexture(m);
	map.setOrigin(1097, 1520);
	map.setPosition(1050, -1380);

	font.loadFromFile("BebasNeue-Bold.ttf");

	text.setFont(font);
	text.setString("press e to open");
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(600,-2780));
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(40);

	g.loadFromFile("grail.png");
	grail.setTexture(g);
	grail.setOrigin(291, 294);	
	grail.setPosition(700, -2780);
	grail.setScale(0.5, 0.5);

	l.loadFromFile("lastEnter.png");
	for (auto& s : lastExit)
	{
	s.setTexture(l);	
	s.setScale(2, 2);
	s.setOrigin(159, 240);
	}
	lastExit[0].setPosition(1150, -1350);
	lastExit[0].setRotation(180);

	lastExit[1].setRotation(270);
	lastExit[1].setPosition(-60, -2400);

}

void finalMap::draw(sf::RenderTarget& win, sf::RenderStates state) const
{	

	win.draw(map, state);
	if (chestOpen == true && isGrailTaken == false)
	{
		win.draw(text, state);
	}
	if (grailDraw == true && isGrailTaken==false)
	{
		win.draw(grail, state);
	}
	for (auto& s : lastExit)
	{
		win.draw(s);
	}
	
}

void finalMap::collision(Character& h)
{
	hero = &h;
	//-----------------------------------LEFT-------------------------------------//
	if (hero->knigth.getPosition().x < 80 && hero->knigth.getPosition().y>-2350)
	{
		hero->stop = 1;
	}
	
	if (hero->knigth.getPosition().x < 80 && hero->knigth.getPosition().y<-2470)
	{
		hero->stop = 1;
	}

	//--------------------------------RIGHT---------------------------------------//
	if (hero->knigth.getPosition().x > 1880)
	{
		hero->stop = 2;
	}

	//----------------------------TOP-------------------------------------------//
	if (hero->knigth.getPosition().y < -2820)
	{
		hero->stop = 3;
	}

	//---------------------------------DOWN-----------------------------------//
	if (hero->knigth.getPosition().y>-1500 && hero->knigth.getPosition().x>1200 )
	{
		hero->stop = 4;
	}
	if (hero->knigth.getPosition().y > -1500 && hero->knigth.getPosition().x < 1100)
	{
		hero->stop = 4;
	}
	
	treeCollision();
	chest();
}

void finalMap::treeCollision()
{
	//----------------------------RIGHT TREE---------------------------------------//
	//----------------------LEFT-------------------------//
	if (hero->knigth.getPosition().x < 1700 && hero->knigth.getPosition().x>1690 && hero->knigth.getPosition().y < -2300 && hero->knigth.getPosition().y > -2800)
	{
		hero->stop = 1;
	}
	//---------------------RIGHT----------------------//
	if (hero->knigth.getPosition().x > 1340 && hero->knigth.getPosition().x < 1360 && hero->knigth.getPosition().y < -2300 && hero->knigth.getPosition().y > -2800)
	{
		hero->stop = 2;
	}

	//-------------------BOT-----------------------//
	if (hero->knigth.getPosition().y < -2260 && hero->knigth.getPosition().y > -2280 && hero->knigth.getPosition().x > 1360 && hero->knigth.getPosition().x < 1690)
	{
		hero->stop = 3;
	}

	//-------------------TOP-----------------------//
	if (hero->knigth.getPosition().y > -2740 && hero->knigth.getPosition().y < -2720 && hero->knigth.getPosition().x > 1360 && hero->knigth.getPosition().x < 1690)
	{
		hero->stop = 4;
	}

	//----------------------------MIDDLE TREE--------------------------------------//
	//--------------------------LEFT----------------------//
	if (hero->knigth.getPosition().x < 1200 && hero->knigth.getPosition().x > 1180 && hero->knigth.getPosition().y > -2700 && hero->knigth.getPosition().y < -2200)
	{
		hero->stop = 1;
	}
	//---------------------RIGHT------------------------//
	if (hero->knigth.getPosition().x > 680  && hero->knigth.getPosition().x <690 && hero->knigth.getPosition().y > -2700 && hero->knigth.getPosition().y < -2200)
	{
		hero->stop = 2;
	}
	//----------------------BOT-------------------------//
	if (hero->knigth.getPosition().y < -2180 && hero->knigth.getPosition().y > -2200 && hero->knigth.getPosition().x > 690 && hero->knigth.getPosition().x < 1180)
	{
		hero->stop = 3;
	}
	//----------------------TOP-------------------------//
	if (hero->knigth.getPosition().y > -2720 && hero->knigth.getPosition().y < -2700 && hero->knigth.getPosition().x > 690 && hero->knigth.getPosition().x < 1180)
	{
		hero->stop = 4;
	}

	//--------------------------------LEFT TREE----------------------------------//
	//------------------------------LEFT-------------------------//
	if (hero->knigth.getPosition().x < 540 && hero->knigth.getPosition().x > 530 && hero->knigth.getPosition().y < -2380 && hero->knigth.getPosition().y > -2840)
	{
		hero->stop = 1;
	}
	
	//---------------------RIGHT----------------------//
	if (hero->knigth.getPosition().x > 140 && hero->knigth.getPosition().x < 150 && hero->knigth.getPosition().y < -2380 && hero->knigth.getPosition().y > -2840)
	{
		hero->stop = 2;
	}
	
	//-------------------BOT-----------------------//
	if (hero->knigth.getPosition().y < -2340 && hero->knigth.getPosition().y > -2350 && hero->knigth.getPosition().x > 150 && hero->knigth.getPosition().x < 530)
	{
		hero->stop = 3;
	}

	//-------------------TOP-----------------------//
	if (hero->knigth.getPosition().y > -2800 && hero->knigth.getPosition().y < -2720 && hero->knigth.getPosition().x > 150 && hero->knigth.getPosition().x < 530)
	{
		hero->stop = 4;
	}

}

void finalMap::chest()
{
	if (hero->knigth.getPosition().x < 820 && hero->knigth.getPosition().x > 780 && hero->knigth.getPosition().y >-2900 && hero->knigth.getPosition().y < -2700)
	{
		hero->stop = 1;
		chestOpen = true;
	}

	else if (hero->knigth.getPosition().x > 600  && hero->knigth.getPosition().x < 640 && hero->knigth.getPosition().y >-2900 && hero->knigth.getPosition().y < -2700)
	{
		hero->stop = 2;
		chestOpen = true;
	}

	else if (hero->knigth.getPosition().x > 640 && hero->knigth.getPosition().x < 780 && hero->knigth.getPosition().y >-2700 && hero->knigth.getPosition().y < -2680)
	{
		hero->stop = 3;
		chestOpen = true;
	}

	else
	{
		chestOpen = false;
	}
}
void finalMap::open()
{
	if (chestOpen == true && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		grailDraw = true;
		chestOpen = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		grailDraw = false;
		isGrailTaken = true;
	}
}
bool finalMap::back()
{
	if (hero->knigth.getPosition().x < 1200 && hero->knigth.getPosition().x>1100 && hero->knigth.getPosition().y>-1400)
	{
		return true;
	}
	return false;
}

bool finalMap::backToBegin()
{
	if (hero->knigth.getPosition().x < 80 && hero->knigth.getPosition().y < -2350 && hero->knigth.getPosition().y > -2470)
	{
		return true;
	}
	return false;
}

bool finalMap::taken()
{
	return isGrailTaken;
}

