#pragma once

#include <SFML\Graphics.hpp>
#include "Board.h"

#include <list>
#include "Monster.h"

class Game
{
private:

	Board mBoard;

	std::list<Monster> mEnemiesList;

	//EnemiesList
	//Way??

public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

