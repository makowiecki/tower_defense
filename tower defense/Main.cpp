#include <iostream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "global-information.h"

//=================================================



//=================================================
int main()
{
	sf::RenderWindow window(sf::VideoMode(gi::WINDOW_WIDTH, gi::WINDOW_HEIGHT), "michal");

	Game twGame;

	sf::Clock clock;
	float dt=0.0f;
	sf::Event myEvent;

	while(window.isOpen())
	{
		if(window.pollEvent(myEvent))
		{
			if(myEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		dt=clock.getElapsedTime().asSeconds();
		twGame.update(window, dt);
		clock.restart();

		window.clear(sf::Color(0, 125, 0));
		twGame.draw(window);
		window.display();

	}

	return 0;
}
//=================================================
