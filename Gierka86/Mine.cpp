#include "Mine.h"

Mine::Mine()
{
    tloback[0].loadFromFile("MINE.jpg");
    tlo[0].setTexture(tloback[0]);
    tlo[0].setScale(1.4, 1.5);
    tlo[0].setPosition(306, 0);

    tloback[1].loadFromFile("MINEenter.png");
    tlo[1].setTexture(tloback[1]);
    tlo[1].setPosition(sf::Vector2f(-540, -160));
    tlo[1].setScale(1.2, 1.8);

    tloback[2].loadFromFile("MINEup.png");
    tlo[2].setTexture(tloback[2]);
    tlo[2].setPosition(sf::Vector2f(130, -1038));
    tlo[2].setScale(2, 1.8);
    tlo[3].setTexture(tloback[2]);
    tlo[3].setPosition(sf::Vector2f(130, -1700));
    tlo[3].setScale(2, 1.8);

    e.loadFromFile("MINEexit.png");
    exit.setTexture(e);
    exit.setOrigin(158,461);
    exit.setScale(2, 4);
    exit.setPosition(1650,600);
    
    l.loadFromFile("lastEnter.png");
    lastExit.setTexture(l);
    lastExit.setOrigin(159, 240);
    lastExit.setPosition(1150, -1350);

    //fufu the sloth
}

void Mine::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    for (auto& t : tlo)
    {
        win.draw(t, state);
    }
    win.draw(lastExit);
    win.draw(exit);
}

void Mine::collision(Character& c)
{
    hero = &c;
    //----------------------FIRE-------------------//
    //-----------RIGHT SIDE----------//
    if (hero->knigth.getPosition().x - 40 < 1180 && hero->knigth.getPosition().x - 40 > 1160 && hero->knigth.getPosition().y<620 && hero->knigth.getPosition().y > 340)
    {
        hero->stop = 1;
    }
    //---------LEFT SIDE------//
    if (hero->knigth.getPosition().x - 40 < 870 && hero->knigth.getPosition().x - 40 > 850 && hero->knigth.getPosition().y < 620 && hero->knigth.getPosition().y > 340)
    {
        hero->stop = 2;
    }
    //---------BOTTOM------//
    if (hero->knigth.getPosition().x - 40 < 1180 && hero->knigth.getPosition().x - 40 > 870 &&hero->knigth.getPosition().y < 620 && hero->knigth.getPosition().y > 600)
    {
        hero->stop = 3;
    }
    //-----------TOP-----//
    if (hero->knigth.getPosition().x - 40 < 1180 && hero->knigth.getPosition().x - 40 > 870 && hero->knigth.getPosition().y > 300 && hero->knigth.getPosition().y < 320)
    {
        hero->stop = 4;
    }
    //----------------------FIRST TUNEL COLLISION-------------------//
    //------------LEFT WALL---------//
    if (hero->knigth.getPosition().x  < -90 )
    {
        hero->stop = 1;
    }
    //------------TOP-----//
    if (hero->knigth.getPosition().y > 440 && hero->knigth.getPosition().y <450 && (hero->knigth.getPosition().x >-100 && hero->knigth.getPosition().x < 400) )
    {
        hero->stop = 3;
    }
    //------------BOT-----//
    if (hero->knigth.getPosition().y > 520 && hero->knigth.getPosition().y < 550&&(hero->knigth.getPosition().x - 40 > -180 && hero->knigth.getPosition().x < 400))
    {
        hero->stop = 4;
    }
    //----------------------SECOND TUNEL COLLISION-------------------//
    //------------LEFT WALL---------//
    if (hero->knigth.getPosition().x >1080 && hero->knigth.getPosition().x <1100 && (hero->knigth.getPosition().y > -1400 && hero->knigth.getPosition().y < 0))
    {
        hero->stop = 1;
    }
    //----------------RIGHT WALL---------//
    if (hero->knigth.getPosition().x >1200 && hero->knigth.getPosition().x <1210 && (hero->knigth.getPosition().y > -1400 && hero->knigth.getPosition().y < 0))
    {
        hero->stop = 2;
    }
    //------------------------------------ROOM--------------------------------//
    //--------------------LEFT---------------//
    if (hero->knigth.getPosition().x < 370 && hero->knigth.getPosition().x > 350&& hero->knigth.getPosition().y <450 && hero->knigth.getPosition().y > 0)
    {
        hero->stop = 1;
    }
    if (hero->knigth.getPosition().x < 370 && hero->knigth.getPosition().x > 350 && hero->knigth.getPosition().y > 550 && hero->knigth.getPosition().y < 1100)
    {
        hero->stop = 1;
    }
    //---------------------RIGHT--------------------//
    if (hero->knigth.getPosition().x > 1650 && hero->knigth.getPosition().x < 1670&& hero->knigth.getPosition().y < 600 && hero->knigth.getPosition().y >0)
    {
        hero->stop = 2;
    }
    if (hero->knigth.getPosition().x < 1670 && hero->knigth.getPosition().x > 1650 && hero->knigth.getPosition().y > 800 && hero->knigth.getPosition().y < 1100)
    {
        hero->stop = 2;
    }
    //-----------------TOP------------------//
    if (hero->knigth.getPosition().y > 10 && hero->knigth.getPosition().y <30 && hero->knigth.getPosition().x > 370 && hero->knigth.getPosition().x < 1100)
    {
        hero->stop = 3;
    }
    if (hero->knigth.getPosition().y > 10 && hero->knigth.getPosition().y < 30 && hero->knigth.getPosition().x < 1700 && hero->knigth.getPosition().x >1200)
    {
        hero->stop = 3;
    }
    //-----------------BOT------------------//
    if (hero->knigth.getPosition().y > 1000 && hero->knigth.getPosition().y < 1030 && hero->knigth.getPosition().x > 370 && hero->knigth.getPosition().x < 1700)
    {
        hero->stop = 4;
    }
}

bool Mine::leave()
{
    if (hero->knigth.getPosition().x > 1650 && hero->knigth.getPosition().y > 600 && hero->knigth.getPosition().y < 800)
    {
        return true;
    }
    return false;
}

bool Mine::lastMap()
{
    if (hero->knigth.getPosition().y < -1400)
    {
        return true;
    }
    return false;
}

void Mine::setView(Character& h,sf::RenderWindow&win)
{
    hero = &h;
    if (widok.getCenter() != hero->knigth.getPosition() )
    {
        widok.setCenter(hero->knigth.getPosition());
    }
   win.setView(widok);
}

bool Mine::block()
{
    if (hero->knigth.getPosition().y < -1350 && hero->getLvl() < 5)
    {
        hero->stop = 3;
        return true;
    }
    return false;
}