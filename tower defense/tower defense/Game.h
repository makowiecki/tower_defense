#pragma once

#include <SFML\Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, const sf::Event& pEvent, float dt);
	void draw(sf::RenderWindow& window);
};

