#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "FieldManager.h"

class Board
{
private:

	std::vector<std::vector<Field*>> mBoard;

	FieldManager& mFieldManager;

public:
	Board(int width, int height, int fieldWidth, int fieldHeight);
	~Board();

	int getWidth()const;
	int getHeight()const;
	sf::Vector2i getSize()const;

	FieldType getFieldType(int pX, int pY)const;

	void changeChosenField();

	void updateAll(const sf::RenderWindow& window, float dt);
	void drawAll(sf::RenderWindow& window);
};

#endif