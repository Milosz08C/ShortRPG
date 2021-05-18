#pragma once
#include <SFML/Graphics.hpp>
class Title_Page : public sf::Drawable
{
	sf::Texture lol;
	sf::Texture tloback;
	sf::Texture m;
	sf::Sprite tlo;
	sf::Sprite woj;
	sf::Sprite mag;
	sf::Text tytul;
	sf::Text start;

	sf::Text hero[2];
	sf::Font font;
	sf::Text choice;
	int wybor = 0;
public:
	Title_Page();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	int sprawdzaj(sf::RenderWindow&);
	void zoom(sf::RenderWindow&);
	int koniec(sf::RenderWindow&);
};

