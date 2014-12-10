#include <iostream>
using namespace std;
#include <string>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "global-information.h"

//=================================================



//=================================================
int main()
{
	sf::RenderWindow window(sf::VideoMode(gi::WINDOW_WIDTH, gi::WINDOW_HEIGHT), "michal");
	window.setFramerateLimit(gi::WINDOW_FRAMERATE_LIMIT);

	Game twGame;

	sf::Clock clock;
	float dt=0.0f;
	sf::Event myEvent;

	int klatki=0;
	float dt2=0.0f;

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
		dt2+=dt;
		twGame.update(window, dt);

		if(dt2 >= 1.0f)
		{
			window.setTitle(to_string(static_cast<float>(klatki) / dt2));
			dt2=0.0f;
			klatki=0;
		}

		clock.restart();

		window.clear(sf::Color(0, 125, 0));
		twGame.draw(window);
		window.display();

		++klatki;
	}

	return 0;
}
//=================================================
