#include "Game.h"

#include "global-information.h"
#include "FieldManager.h"

#include <iostream>
using namespace std;

Game::Game()
	:mBoard(gi::FIELDS_IN_ROW, gi::FIELDS_IN_COLUMN, gi::FIELD_WIDTH, gi::FIELD_HEIGHT),
	mMonstersList(mBoard)
{
}


Game::~Game()
{
}

void Game::update(const sf::RenderWindow& window, float dt)
{
	mBoard.updateAll(window, dt);

	mMonstersList.update(window, dt, mBoard);

	if(FieldManager::getInstance().isSetToChange())
	{
		mBoard.changeChosenField();
	}
}

void Game::draw(sf::RenderWindow& window)
{
	mBoard.drawAll(window);

	mMonstersList.draw(window);
}