#include "SFML/Graphics.hpp"
#include "HealthBar.h"
void testWindow()//template
{
	int maxHealth1 = 100;
	int curHealth1 = 100;
	int maxHealth2 = 100;
	int curHealth2 = 100;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "simple Test");
	HealthBar hb(curHealth1, maxHealth1, sf::Vector2f(10, 10));
	HealthBar hb2(curHealth2, maxHealth2, sf::Vector2f(790, 10), true, HealthBar::Right);
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Left)
				{
					curHealth1 -= 2;
				}
				if (e.key.code == sf::Keyboard::Right)
				{
					curHealth2 -= 2;
				}
				if (e.key.code == sf::Keyboard::R)
				{
					hb.toggleText();
					hb2.toggleText();
				}
				if (e.key.code == sf::Keyboard::E)
				{
					curHealth1 = maxHealth1;
				}
			}
		}
		//hb.UpdateHealth();
		//hb2.UpdateHealth();
		window.clear(sf::Color::White);
		//draw here
		window.draw(hb);
		window.draw(hb2);
		window.display();
	}
}

int main()
{
	testWindow();
	return 0;
}