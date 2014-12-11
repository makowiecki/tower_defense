#pragma once

#include <SFML\Graphics.hpp>
#include "Board.h"

#include <list>
#include "Enemy.h"

class Game
{
private:

	Board mBoard;

	std::list<Enemy> mEnemiesList;

	//EnemiesList
	//Way??

public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

