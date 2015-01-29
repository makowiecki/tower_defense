#pragma once

#include <SFML\Graphics.hpp>
#include "Board.h"
#include "MonstersList.h"
#include "Way.h"

class Game
{
private:

	Board mBoard;
	MonstersList mMonstersList;
	Way mMonstersWays;

public:
	Game();
	~Game();

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

