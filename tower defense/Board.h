#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "all-fields.h"
#include "FieldManager.h"

class Board
{
private:

	std::vector<std::vector<Field*>> mBoard;

	FieldManager& mFieldManager;

public:
	Board(int widith, int height, int fieldWidith, int fieldHeight);
	~Board();

	void updateAll(const sf::RenderWindow& window, float dt);
	void drawAll(sf::RenderWindow& window);
};

#endif