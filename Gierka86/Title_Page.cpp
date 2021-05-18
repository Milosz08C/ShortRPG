#include "Title_Page.h"
Title_Page::Title_Page()
{
    tloback.loadFromFile("las2.png");
    lol.loadFromFile("czlowiekPrzod.png");
    m.loadFromFile("magPrzod.png");

    tlo.setTexture(tloback);
    tlo.setScale(1, 2);

    woj.setTexture(lol);
    woj.setOrigin(60, 20);
    woj.setPosition(200, 680);
    woj.setScale(4, 4);

    mag.setTexture(m);
    mag.setOrigin(40, 50);
    mag.setScale(8, 8);
    mag.setPosition(700, 720);

    font.loadFromFile("BebasNeue-Bold.ttf");

    hero[0].setFont(font);
    hero[0].setString("KNIGHT");
    hero[0].setCharacterSize(80);
    hero[0].setFillColor(sf::Color::Black);
    hero[0].setStyle(sf::Text::Bold);
    hero[0].setPosition(woj.getPosition() - sf::Vector2f(60, 80));

    hero[1].setFont(font);
    hero[1].setString("MAGE");
    hero[1].setCharacterSize(80);
    hero[1].setFillColor(sf::Color::Black);
    hero[1].setStyle(sf::Text::Bold);
    hero[1].setPosition(mag.getPosition() - sf::Vector2f(10, 100));

    choice.setFont(font);
    choice.setString("CHOOSE YOUR HERO");
    choice.setCharacterSize(100);
    choice.setFillColor(sf::Color::Black);
    choice.setStyle(sf::Text::Bold);
    choice.setPosition(200, 400);

    tytul.setFont(font);
    tytul.setString("HERO IS BORN");
    tytul.setCharacterSize(100);
    tytul.setFillColor(sf::Color(51, 51, 0));
    tytul.setStyle(sf::Text::Bold);
    tytul.setPosition(300, 300);

    start.setFont(font);
    start.setString("START");
    start.setCharacterSize(100);
    start.setFillColor(sf::Color::Black);
    start.setStyle(sf::Text::Bold);
    start.setPosition(400, 500);
}

void Title_Page::zoom(sf::RenderWindow& win)
{
    if (wybor == 1)
    {
        mag.setScale(8, 8);
        woj.setScale(4, 4);
        for (int i = 0; i < 200; i++)
        {
            for (int j = 0; j < 200; j++)
            {
                if (sf::Mouse::getPosition(win) == sf::Vector2i(mag.getPosition() + sf::Vector2f(i, j)))
                {
                    mag.setScale(10, 10);
                }
                if (sf::Mouse::getPosition(win) == sf::Vector2i(woj.getPosition() + sf::Vector2f(i, j)))
                {
                    woj.setScale(5, 5);
                }
            }
        }
    }
}

void Title_Page::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    win.draw(tlo, state);
    if (wybor == 0)
    {
        win.draw(tytul, state);
        win.draw(start, state);
    }
    else
    {
        win.draw(choice, state);
        win.draw(woj, state);
        win.draw(mag, state);
        win.draw(hero[0], state);
        win.draw(hero[1], state);
    }
}



int Title_Page::sprawdzaj(sf::RenderWindow& win)
{
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (((sf::Mouse::getPosition(win) == sf::Vector2i(start.getPosition() + sf::Vector2f(i, j))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))||sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                return wybor = 1;
            }
        }
    }
}

int Title_Page::koniec(sf::RenderWindow& win)
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if ((sf::Mouse::getPosition(win) == sf::Vector2i(woj.getPosition() + sf::Vector2f(i, j))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                return 1;
            }
            if ((sf::Mouse::getPosition(win) == sf::Vector2i(mag.getPosition() + sf::Vector2f(i, j))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                return 2;
            }
        }
    }
}

