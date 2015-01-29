#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <stack>
#include "FieldManager.h"
#include "MonstersList.h"

class Board
{
private:

	std::vector<std::vector<Field*>> mBoard;
	FieldManager& mFieldManager;

	sf::Vector2f mEnterFieldPosition;
	sf::Vector2f mExitFieldPosition;

	std::stack < sf::Vector2i> mGlobalStepsList;


	//bool canFindGlobalWay();

public:
	Board(int width, int height, int fieldWidth, int fieldHeight);
	~Board();

	int getWidth()const;
	int getHeight()const;
	sf::Vector2i getSize()const;

	sf::Vector2f getEnterFieldPosition()const;
	sf::Vector2f getExitFieldPosition()const;

	void addGlobalStep(const sf::Vector2i& step);

	FieldType getFieldType(int pX, int pY)const;

	void changeChosenField();

	void updateAll(const sf::RenderWindow& window, float dt, MonstersList& monstersList);
	void drawAll(sf::RenderWindow& window);
};

#endif