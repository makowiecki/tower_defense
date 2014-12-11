#pragma once

#include <SFML\Graphics.hpp>
#include "Board.h"

class Game
{
private:

	Board mBoard;

	//EnemiesList
	//Way??

public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

