#include "Game_engine.h"
Game_engine::Game_engine()
{
	title=new Title_Page;
    que=new Quest;
    combat = new Battle;
    end = new endScreen;
    widok.setCenter(500, 500);
}

void Game_engine::debugDisplay()
{
    sf::RenderWindow win(sf::VideoMode(1000, 1000), "wub");
    sf::Event event;
    win.setFramerateLimit(120);
    hero = new Mage("Wikary", *new Stick());
    //hero = new Wikary("Wikary", *new Stick());
    /*hero->setHp(400);
    hero->setMana(400);
    hero->setCurrentHp(400);
    hero->setCurrentMana(400);
    hero->setLvl(5);*/
   // hero = new Wikary("Wikary", *new Knife());
    //hero->setHp(40);
    mine = new Mine;
    hero->knigth.setPosition(500, 500); 
    infEnemy = new Info;
   enemy.push_back(new Enemy(200, 10, 10, 50, 10, 10, "zbysiu", *new Knife()));
    enemy[enemy.size()-1]->knigth.setPosition(1000,-2100);
    enemy[enemy.size()-1]->changeTexture(3);
    hero->knigth.setPosition(1400, -1600);
    inf = new Info(*hero);
    shop = new Weapon_Shop(*hero);
    cav = new Cave;
    lastMap = new finalMap;
    change = 7;
    while (win.isOpen())
    {
       while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                win.close();
            }
        }
       if (change == 2)
       {
           win.setView(widok);
           if (againHere == false)
           {
               que->check(*hero);
           }
           if (againHere == true)
           {
               que->give(hero);
           }
           firstStage(win);
           isFirstExicist();
           hero->resetScale();
           hero->move();
           backGround->collision(*hero);
           win.draw(*hero);
           win.draw(*que);
       }
      if (change == 0)
       {
          win.clear(sf::Color::Black);
          mine->setView(*hero, win);
          mine->collision(*hero);
          hero->move();
          inf->infoStats(*hero);
          win.draw(*mine);
          win.draw(*hero);
          win.draw(*inf);
          shop->shop(win);
          if (mine->lastMap() && hero->getLvl()>=5)
          {
             change = 7;
          }
          if (enemy.size() > 0)
          {
              for (int i = 0; i < howManyMine; i++)
              {
                  win.draw(*enemy[i]);
                  win.draw(*combat);
                  start(1);
              }
          }
          win.draw(*shop);
       }

      if (change == 7)
      {
          win.clear(sf::Color::Black);
          hero->move();
          lastMap->collision(*hero);
          inf->infoStats(*hero);
          mine->setView(*hero, win);
          win.draw(*lastMap);
          win.draw(*hero);
          win.draw(*inf);
          if (enemy.size() > 0)
          {
              win.draw(*enemy[enemy.size() - 1]);
              win.draw(*combat);
              start(3);
          }
          if (lastMap->back() == true)
          {
              if (enemy.size() > 0)
              {
                  for (auto& e : enemy)
                  {
                      e->changeTexture(1);
                  }
              }
              change = 3;
          }
          if (enemy.size() == 0)
          {
              lastMap->open();
          }
          if (lastMap->taken() == true)
          {
              if (lastMap->backToBegin() == true)
              {
                  backGround = new Grass;
                  que = new Quest;
                  que->reset();
                  againHere = true;
                  hero->knigth.setPosition(940, 500);
                  change = 2;
              }
          }
      }
      if (change == 5)
      {
          win.clear(sf::Color::Black);
          //sf::Mouse::setPosition(sf::Vector2i(enemy[0]->knigth.getPosition()),win);
          combat->fight(*hero, *enemy[number]);
          infEnemy->infoStats(*enemy[number]);
          if (map == 1)
          {
              win.draw(*mine);
          }
          if (map == 2)
          {
              win.draw(*cav);
          }
          if (map == 3)
          {
              win.draw(*lastMap);
          }
          win.draw(*hero);
          inf->updateStats();
          infEnemy->updateStats();
          win.draw(*enemy[number]);
          win.draw(*infEnemy);
          win.draw(*combat);
          win.draw(*inf);
          win.draw(*infEnemy);
          if (combat->whoIsDead(*hero, *enemy[number]) == enemy[number])
          {
              inf->setFigth(false);
              infEnemy->setFigth(false);
              combat->reset(hero);
              hero->addExp();
              hero->addLvl();
              if (howMany > 0)
              {
                  howMany -= 1;
              }
              if (howManyMine > 0 && map == 1)
              {
                  howManyMine -= 1;
              }
              enemy.erase(enemy.begin() + number);

              if (howMany == 0)
              {
                  howMany = 0;
              }
              if (howManyMine == 0)
              {
                  howMany = 0;
              }
              number = 0;
              if (map == 1)
              {
                  change = 3;
              }
              if (map == 2)
              {
                  change = 6;
              }
          }
          else if (combat->whoIsDead(*hero, *enemy[number]) == hero)
          {

              end->setTexture(hero);
              change = 10;
          }
      }
      if (change == 10)
      {
          win.clear(sf::Color::Black);
          win.setView(widok);
          win.draw(*end);
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
          {
              reset(win);
          }
      }
    win.display();
    }
}

void Game_engine::display()
{
    sf::RenderWindow win(sf::VideoMode(1000, 1000), "wub");
    sf::Event event;
    win.setFramerateLimit(30);
    while (win.isOpen())
    {
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                win.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                reset(win);
            }
        }
       
        if (change == 0)
        {
            istitlexicst(win);
        }

        if (change == 1)
        {
            titleDelete(title);
            firstStage(win);
            que->setatBegin();
            win.draw(*que);
            que->setPos(*hero);
            win.draw(*hero);
            if (que->firstAnswer() == YUP)
            {
                que->reset();
                change = 2;
            }
            else if (que->firstAnswer() == NOPE)
            {
                change = 4;
            }
        }
        if (change == 2)
        { 
            win.setView(widok);
            if (againHere == false)
            {
                que->check(*hero);
            }
            else if (againHere == true)
            {
                if (que->give(hero))
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    {
                        end->setWhich(1);
                        end->setTexture(hero);
                        change = 10;
                    }
                }
            }
            firstStage(win);
            isFirstExicist();
            hero->resetScale();
            hero->move();  
            backGround->collision(*hero);
            win.draw(*hero);
            win.draw(*que);
        }
        if (change == 3)
        {
            win.clear(sf::Color::Black);
            grassDelete(backGround);
            questDelete(que); 
            mine->setView(*hero, win);
            mine->collision(*hero);
            hero->move();  
            inf->infoStats(*hero);
            inf->tutorial(hero);
            win.draw(*mine);
            win.draw(*hero);
            win.draw(*inf);
            shop->shop(win);
            if (mine->leave() == true)
            {
                newEnemies();
                if (enemy.size() > 0)
                {
                    for (auto& e : enemy)
                    {
                        e->changeTexture(2);
                    }
                }
                change = 6;
            }

            if (!mine->block() && mine->lastMap())
            {
                newFufu();
                enemy[enemy.size() - 1]->changeTexture(3);
                change = 7;
            }
            
            else if (mine->block())
            {

                inf->stop(true);
            }

            else
            {
                inf->stop(false);
            }
            

            if (enemy.size() > 0)
            {
                for (int i=0; i<howManyMine; i++)
                {
                    win.draw(*enemy[i]);
                    win.draw(*combat);
                    start(1);
                }
            }
            win.draw(*shop);
        }

        if (change == 6)
        {
            win.clear(sf::Color::Black);
            hero->move();
            cav->collision(hero);
            inf->infoStats(*hero);
            mine->setView(*hero, win);
            win.draw(*cav);
            win.draw(*hero);
            win.draw(*inf);
            if (enemy.size() > 0)
            {
                for (int i = howMany; i < enemy.size(); i++)
                {
                   win.draw(*enemy[i]);
                    win.draw(*combat);
                    start(2);
                }
            }
            if (cav->Leave(hero) == true)
            {
                if (enemy.size() > 0)
                {
                    for (auto& e : enemy)
                    {
                        e->changeTexture(1);
                    }
                }
                change = 3;
            }
        }

        if (change == 7)
        {
            win.clear(sf::Color::Black);
            hero->move();
            lastMap->collision(*hero);
            inf->infoStats(*hero);
            mine->setView(*hero, win);
            win.draw(*lastMap);
            win.draw(*hero);
            win.draw(*inf);
            if (enemy.size() > 0)
            {
               win.draw(*enemy[enemy.size()-1]);
               win.draw(*combat);
               start(3);      
            }
            if (lastMap->back() == true)
            {
                if (enemy.size() > 0)
                {
                    for (auto& e : enemy)
                    {
                        e->changeTexture(1);
                    }
                }
                change = 3;
            }
            if (enemy.size() == 0)
            {
                lastMap->open();
            }
            if (lastMap->taken() == true)
            {
                if (lastMap->backToBegin() == true)
                {
                    backGround = new Grass;
                    que = new Quest;
                    againHere = true;
                    que->reset();
                    hero->knigth.setPosition(940, 500);
                    change = 2;
                }
            }
        }

        if (change == 5)
        {
                win.clear(sf::Color::Black);
                combat->fight(*hero, *enemy[number]);
                infEnemy->infoStats(*enemy[number]);
                if (map == 1)
                {
                     win.draw(*mine);
                }
                if (map == 2)
                {
                    win.draw(*cav);
                }
                if (map == 3)
                {
                    win.draw(*lastMap);
                }
                win.draw(*hero);
                inf->updateStats();
                infEnemy->updateStats();
                win.draw(*enemy[number]);
                win.draw(*infEnemy);
                win.draw(*combat);
                win.draw(*inf);
                win.draw(*infEnemy);
                if (combat->whoIsDead(*hero, *enemy[number]) == enemy[number])
                {
                    inf->setFigth(false);
                    infEnemy->setFigth(false);
                    combat->reset(hero);
                    hero->addExp();
                    hero->addLvl();  
                    if (howMany > 0)
                    {
                        howMany -= 1;
                    }
                    if (howManyMine > 0 && map == 1)
                    {
                        howManyMine -= 1;
                    }
                    enemy.erase(enemy.begin() + number);

                    if (howMany == 0)
                    {
                        howMany = 0;
                    }
                    if (howManyMine == 0)
                    {
                        howMany = 0;
                    }
                    number = 0;
                    if (map == 1)
                    {
                        change = 3;
                    }
                    if (map == 2)
                    {
                        change = 6;
                    }
                    if (map == 3)
                    {
                        change = 7;
                    }
                }
               
                else if (combat->whoIsDead(*hero, *enemy[number]) == hero)
                {                   
                    end->setWhich(0);
                    end->setTexture(hero);
                    change = 10;
                }
        }

        if (change == 10)
        {
            win.clear(sf::Color::Black);
            win.setView(widok);
            win.draw(*end);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                reset(win);
            }
        }

        if (change == 4)
        {
            que->coward();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                reset(win);
            }
            win.draw(*que);
        }
        win.display();
    }

}

void Game_engine::istitlexicst(sf::RenderWindow& win)
{
    if (titleExcist==true)
    {
        title->sprawdzaj(win);
        title->zoom(win);
        win.draw(*title);
        if (title->koniec(win) == 1)
        {           
            hero = new Wikary("Wikary", *new Knife()); 
            inf = new Info(*hero);
            shop = new Weapon_Shop(*hero);
            change = 1;  
        }
        if (title->koniec(win) == 2)
        {  
            hero = new Mage("Wikary", *new Stick());
            inf = new Info(*hero);
            shop = new Weapon_Shop(*hero);
            change = 1;
          
        }
    }
}

void Game_engine::firstStage(sf::RenderWindow& win)
{
    if (grassExcist == false)
    {
        backGround=new Grass;
        grassExcist = true;
    }
    win.draw(*backGround);
}

void Game_engine::isFirstExicist()
{
        if (hero->knigth.getPosition().x > 940 && hero->knigth.getPosition().y > 380&& hero->knigth.getPosition().y < 600 && grassExcist==true)
        {
            hero->knigth.setPosition(0, 500);
            mine = new Mine;
            infEnemy = new Info;
            enemy.push_back(new Enemy(150, 10, 10, 70, 10, 10, "zbysiu", *new Knife()));
            enemy.push_back(new Enemy(180, 10, 10, 65, 10, 10, "zdzisiu", *new Knife()));
            enemy.push_back(new Enemy(120, 10, 10, 50, 10, 10, "zenek", *new Knife()));
            enemy.push_back(new Enemy(120, 10, 10, 50, 10, 10, "Stasiu", *new Knife()));
            for (auto& e : enemy)
            {
                e->changeTexture(1);
            }
            enemy[0]->knigth.setPosition(1400, 100);
            enemy[1]->knigth.setPosition(1400, 900);
            enemy[2]->knigth.setPosition(900, 700);
            enemy[3]->knigth.setPosition(1000, 100);
            infEnemy = new Info;
            change = 3;
        }   
}

void Game_engine::newEnemies()
{
    if (areAlive == false)
    {
        enemy.push_back(new Enemy(250, 10, 10, 70, 10, 10, "zbysiu", *new Sword()));
        enemy.push_back(new Enemy(250, 10, 10, 70, 10, 10, "zdzisiu", *new Knife()));
        enemy.push_back(new Enemy(200, 10, 10, 70, 10, 10, "zenek", *new Knife()));
        enemy.push_back(new Enemy(200, 10, 10, 70, 10, 10, "Stasiu", *new Knife()));
        enemy[howMany]->knigth.setPosition(3000, 1000);
        enemy[howMany+1]->knigth.setPosition(2600, 500);
        enemy[howMany+2]->knigth.setPosition(3000, 600);
        enemy[howMany+3]->knigth.setPosition(2000, 300);
        cav = new Cave;
    }
    areAlive = true;
}

void Game_engine::newFufu()
{
    if (fufuAlive == false)
    {
        enemy.push_back(new Enemy(340, 10, 10, 70, 10, 10, "FUFU", *new Knife()));
        enemy[enemy.size()-1]->knigth.setPosition(1000, -2100);
        lastMap = new finalMap;
    }
    fufuAlive = true;
}

void Game_engine::titleDelete(Title_Page* t)
{
    if (titleExcist == true)
    {
        delete t;
    }
    titleExcist = false;
}

void Game_engine::grassDelete(Grass* g)
{
    if (grassExcist == true)
    {
        delete g;
    }
    grassExcist = false;
}

void Game_engine::questDelete(Quest* q)
{
    if (questExcist == true)
    {
        delete q;
    }
    questExcist = false;
}


bool Game_engine::closeEnough()
{
    if (enemy.size() > 0)
    {
        for (int i = 0; i < enemy.size(); i++)
        {
            if (hero->knigth.getPosition().x > (enemy[i]->knigth.getPosition().x - 100) && hero->knigth.getPosition().x < (enemy[i]->knigth.getPosition().x + 100) && hero->knigth.getPosition().y>(enemy[i]->knigth.getPosition().y-100) && hero->knigth.getPosition().y < (enemy[i]->knigth.getPosition().y + 100))
            {
                number = i;
                return true;
            }
            else
            {
                combat->setClose(false);
            }
        }
    }
}

void Game_engine::start(int m)
{
    if (closeEnough() == true)
    {
        combat->setClose(true);
        combat->pressePos(enemy,number);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            inf->setFigth(true);
            infEnemy->setFigth(true);
            combat->setClose(false);
            map = m;
            change = 5;
        }
    }
}

void Game_engine::reset(sf::RenderWindow& win)
{   
    enemy.clear();
    questDelete(que);
    grassDelete(backGround);
    titleDelete(title);
    widok.setCenter(500, 500);
    areAlive = false;
    win.setView(widok);
    fufuAlive = false;
    againHere = false;
    howMany = 4;
    howManyMine = 4;
    if (areAlive == true)
    {
        areAlive = false;
    }
    if (titleExcist == false)
    {
        title = new Title_Page;
        titleExcist = true;
    }
    if (questExcist == false)
    {
        que = new Quest;
        questExcist = true;
    }
    delete combat;
    combat = new Battle;
    change = 0;
}

/*
    sf::VertexArray line(sf::LinesStrip);
    linia.append(sf::Vector2f{ 3,3 });
    linia.append(sf::Vector2f{ 3,797 });
    linia.append(sf::Vector2f{ 797,797 });
    linia.append(sf::Vector2f{ 797,3 });
    linia.append(sf::Vector2f{ 3,3 });
*/