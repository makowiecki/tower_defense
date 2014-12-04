#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Field.h"

class Game
{
private:

	std::vector<std::vector<Field*>> mBoard;

	//EnemiesList
	//Way??

public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

