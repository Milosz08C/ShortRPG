#include "Info.h"

Info::Info(Character&h) : hero(&h){ font.loadFromFile("BebasNeue-Bold.ttf"); }
Info::Info(){ font.loadFromFile("BebasNeue-Bold.ttf"); }


void Info::draw(sf::RenderTarget& win, sf::RenderStates state)const
{
	if (info == true)
	{
		win.draw(back, state);
		for (auto& s : stats)
		{
			win.draw(s, state);
		}
	}

	if (fight == true)
	{
		for (auto& g : graphicStats)
		{
			win.draw(g, state);
		}
		for (auto& t : graphicText)
		{
			win.draw(t, state);
		}
	}

	if (tutOpen == true)
	{
		win.draw(tutBack, state);
		for (auto& t : tut)
		{
			win.draw(t, state);
		}

	}
	if (lowLvl == true)
	{
		win.draw(stopText, state);
	}
}


void Info::getInfoSFML(Character*)
{
	back.setSize(sf::Vector2f(180, 260));
	back.setFillColor(sf::Color(140, 140, 140));
	back.setOutlineThickness(3);
	back.setOutlineColor(sf::Color(38, 38, 38));
	back.setOrigin(sf::Vector2f(90, 100));
	back.setPosition(hero->knigth.getPosition() - sf::Vector2f(0, 140));

	stats[0].setString("Name: " + hero->getName());
	stats[1].setString("HP: " + std::to_string(hero->getCurrentHp()));
	stats[2].setString("MANA: " + std::to_string(hero->getCurrentMana()));
	stats[3].setString("Luck: " + std::to_string(hero->getLuck()));
	stats[4].setString("Strength: " + std::to_string(hero->getStrength()));
	stats[5].setString("Wisdom: " + std::to_string(hero->getWisdom()));
	stats[6].setString("LVL: " + std::to_string(hero->getLvl()));
	stats[7].setString("EXP: " + std::to_string(hero->getExp()));

	for (int i = 0, j = 10; i < 8 && j < 80; i++, j -= 30)
	{
		stats[i].setFont(font);
		stats[i].setFillColor(sf::Color(38, 38, 38));
		stats[i].setStyle(sf::Text::Bold);
		stats[i].setPosition(hero->knigth.getPosition() - sf::Vector2f(70, 220 + j));
		stats[i].setCharacterSize(30);
	}
}

void Info::infoStats(Character& h)
{
	hero = &h;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) 
	{	
			if (change == 2)
			{
				info = false;
				change = 0;
			}
			else
			{
				info = true;
				hero->updateStats();
				getInfoSFML(hero);
				if (change == 0 || change == 1)
				{
					change += 1;

				}
			}
	}
}

void Info::stop(bool m)
{
	stopText.setFont(font);
	stopText.setFont(font);
	stopText.setFillColor(sf::Color::Red);
	stopText.setStyle(sf::Text::Bold);
	stopText.setPosition(hero->knigth.getPosition() - sf::Vector2f(100, 220));
	stopText.setCharacterSize(100);
	stopText.setString("YOU NEED 5LVL!");
	lowLvl=m;
}

void Info::updateStats()
{


	//---------------------HP------------//
	hero->updateStats();
	graphicStats[0].setPosition(hero->knigth.getPosition()-sf::Vector2f(80,200));
	graphicStats[0].setSize(sf::Vector2f(hero->getHp(), 20));
	graphicStats[0].setFillColor(sf::Color::Black);
	graphicStats[0].setOutlineThickness(3);
	graphicStats[0].setOutlineColor(sf::Color::White);
	graphicStats[1].setPosition(hero->knigth.getPosition() - sf::Vector2f(80, 200));
	graphicStats[1].setSize(sf::Vector2f(hero->getCurrentHp(), 20));
	graphicStats[1].setFillColor(sf::Color::Red);
	
	graphicText[0].setFont(font);
	graphicText[0].setFillColor(sf::Color::White);
	graphicText[0].setStyle(sf::Text::Bold);
	graphicText[0].setPosition(graphicStats[0].getPosition()+sf::Vector2f((hero->getHp()-40),-10));
	graphicText[0].setString(std::to_string(hero->getCurrentHp()));
	graphicText[0].setCharacterSize(30);

	graphicText[1].setFont(font);
	graphicText[1].setFillColor(sf::Color::White);
	graphicText[1].setStyle(sf::Text::Bold);
	graphicText[1].setPosition(graphicStats[0].getPosition() + sf::Vector2f(0, -10));
	graphicText[1].setString("HP");
	graphicText[1].setCharacterSize(30);

	//--------------------MANA----------//
	if (hero->getCharacter() != ENEMY)
	{
		graphicStats[2].setPosition(hero->knigth.getPosition() - sf::Vector2f(80, 170));
		graphicStats[2].setSize(sf::Vector2f(hero->getMana(), 20));
		graphicStats[2].setFillColor(sf::Color::Black);
		graphicStats[2].setOutlineThickness(3);
		graphicStats[2].setOutlineColor(sf::Color::White);
		graphicStats[3].setPosition(hero->knigth.getPosition() - sf::Vector2f(80, 170));
		graphicStats[3].setSize(sf::Vector2f(hero->getCurrentMana(), 20));
		graphicStats[3].setFillColor(sf::Color::Blue);

		graphicText[2].setFont(font);
		graphicText[2].setFillColor(sf::Color::White);
		graphicText[2].setStyle(sf::Text::Bold);
		graphicText[2].setPosition(graphicStats[2].getPosition() + sf::Vector2f((hero->getMana() - 40), -10));
		graphicText[2].setString(std::to_string(hero->getCurrentMana()));
		graphicText[2].setCharacterSize(30);

		graphicText[3].setFont(font);
		graphicText[3].setFillColor(sf::Color::White);
		graphicText[3].setStyle(sf::Text::Bold);
		graphicText[3].setPosition(graphicStats[2].getPosition() + sf::Vector2f(0, -10));
		graphicText[3].setString("MANA");
		graphicText[3].setCharacterSize(30);
	}
}
//Greetings wanderer!!!!!
//Press 'I' to show and close statistics 
//You can find a shop in left upper corner
//Have fun!
//Press enter to close 
void Info::tutorial(Character*h)
{
	tutBack.setSize(sf::Vector2f(500, 180));
	tutBack.setFillColor(sf::Color(140, 140, 140));
	tutBack.setOutlineThickness(3);
	tutBack.setOutlineColor(sf::Color(38, 38, 38));
	tutBack.setOrigin(200,200);
	tutBack.setPosition(h->knigth.getPosition());

	tut[0].setString("			Greetings wanderer!!!!!");
	tut[1].setString("Press 'I' to show and close statistics ");
	tut[2].setString("You can find a shop in left upper corner");
	tut[3].setString("						Have fun!");
	tut[4].setString("		Press enter to close");

	for (int i = 0, j = 5; i < 5 && j < 50; i++, j -= 30)
	{
		tut[i].setFont(font);
		tut[i].setFillColor(sf::Color(38, 38, 38));
		tut[i].setStyle(sf::Text::Bold);
		tut[i].setPosition(h->knigth.getPosition() - sf::Vector2f(160, 200 + j));
		tut[i].setCharacterSize(30);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		tutOpen = false;
	}
}

bool Info::setFigth(bool a)
{
	fight = a;
	return fight;
}