#include "Quest.h"

Quest::Quest()
{
    Magtext.loadFromFile("magQuest.png");
    Magq.setTexture(Magtext);

    cloud.loadFromFile("dymek.png");
    chat.setTexture(cloud);

    font.loadFromFile("BebasNeue-Bold.ttf");

    end.setFont(font);
    end.setStyle(sf::Text::Bold);
    end.setString("Press 'e' to return the hoily grail");
    end.setCharacterSize(40);
    end.setFillColor(sf::Color::Red);

    d.loadFromFile("dymekEnd.png");
    dym.setTexture(d);
    dym.setScale(0.6, 0.6);
    dym.setPosition(570, -50);
}


void Quest::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    if (change == 0)
    {
        win.draw(chat, state);
        win.draw(Magq, state);
        for (auto& t : text)
        {
            win.draw(t, state);
        }
    }
    if (change == 1)
    {
        win.draw(Magq, state);
    }
    if (change == 2)
    {
        win.draw(chat, state);
        win.draw(Magq, state);
    }
    if (change == 3)
    {
        win.draw(cowa,state);
        for (auto& t : text)
        {
            win.draw(t, state);
        }
    }
    if (change == 4)
    {
        win.draw(end, state);
        win.draw(Magq, state);
        win.draw(dym, state);
    }
}

choice Quest::firstAnswer()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        return YUP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        return NOPE;
    }
    else
        return W8;
}

void Quest::setPos(Character& h)
{
    hero = &h;
    sf::Vector2f pos(200, 420);
    hero->setScale(pos);
}

void Quest::setatBegin()
{
   
    Magq.setPosition(400, 200);
    chat.setScale(2, 2);
    chat.setPosition(-100, -380);

    for (auto& t : text)
    {
        t.setFont(font);
        t.setFillColor(sf::Color::Black);
        t.setStyle(sf::Text::Bold);
    }

    text[0].setString("ARE YOU STRONG ENOUGH TO HANDLE IT?");
    text[0].setCharacterSize(60);
    text[0].setPosition(100, 700);
    text[1].setString("YES [Y]                               NOPE [N]");
    text[1].setCharacterSize(80);
    text[1].setPosition(100, 790);
}

void Quest::reset()
{
    Magq.setPosition(680, 100);
    Magq.setScale(0.4, 0.4);
    cloud.loadFromFile("dymek2.png");
    chat.setTexture(cloud);
    chat.setScale(0.6, 0.6);
    chat.setPosition(570, -50);
    change = 1;
}

void Quest::check(Character& h)
{
    hero = &h;
    if ((hero->knigth.getPosition().y < 300 && hero->knigth.getPosition().y > 80)&& (hero->knigth.getPosition().x < 800 && hero->knigth.getPosition().x > 600) )
    {
        change = 2;
    }
    else
    {
        change = 1;
    }
}

bool Quest::give(Character* hero)
{
    if ((hero->knigth.getPosition().y < 300 && hero->knigth.getPosition().y > 80) && (hero->knigth.getPosition().x < 800 && hero->knigth.getPosition().x > 600))
    {
        end.setPosition(Magq.getPosition()-sf::Vector2f(200,75));
       change = 4;
       return true;
    }
    else
    {
        change = 1;
        return false;
    }
}

void Quest::coward()
{
    coco.loadFromFile("coward.jpg");
    cowa.setTexture(coco);
    cowa.setScale(2, 4);
    for (auto& t : text)
    {
        t.setFont(font);
        t.setFillColor(sf::Color::Magenta);
        t.setStyle(sf::Text::Bold);
    }
    text[0].setString("CO-CO-COWARD!!!!");
    text[0].setCharacterSize(180);
    text[0].setPosition(0, 400); 
    text[1].setString("PRESS 'R' AND TRY AGAIN");
    text[1].setCharacterSize(100);
    text[1].setPosition(100, 600);
    change = 3;
}

/*
lata temu zgubilem tam swiety gral
, wielu smialkow probowalo go dla mnie odzyskac, lecz nie podolalo, twoim zadaniem jest go odnalezc, powodzenia'
*/

/*
'Hello Wikary. Years ago I lost there my holy Graal. So many bravehearts was trying to give it back to me, but they cannot handle it. Now it's your turn. Good luck'  
*/