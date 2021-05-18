#include "Grass.h"

Grass::Grass()
{
    tloback.loadFromFile("grass.jpg");
    tlo.setTexture(tloback);
    tlo.setScale(1, 1.35);
}

void Grass::draw(sf::RenderTarget& win, sf::RenderStates state) const
{   

    win.draw(tlo, state);
}
   
void Grass::collision(Character& c)
{
    hero = &c;
    if (hero->knigth.getPosition().x-40< 0)
    {
        hero->stop = 1;
    }
    if ((hero->knigth.getPosition().x + 60 > 1000)&&((hero->knigth.getPosition().y <420)|| (hero->knigth.getPosition().y > 590)))
    {
        hero->stop = 2;
    }    
    if (hero->knigth.getPosition().y - 40 < 0)
    {
        hero->stop = 3;
    }
    if (hero->knigth.getPosition().y + 80 >1000)
    {
        hero->stop = 4;
    }
}







