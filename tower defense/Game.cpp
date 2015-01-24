#include "Game.h"

#include "global-information.h"
#include "FieldManager.h"

#include <iostream>
using namespace std;

Game::Game()
	:mBoard(gi::FIELDS_IN_ROW, gi::FIELDS_IN_COLUMN, gi::FIELD_WIDTH, gi::FIELD_HEIGHT)
{
	mEnemiesList.emplace_back(Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), mBoard));
}


Game::~Game()
{
}

void Game::update(const sf::RenderWindow& window, float dt)
{
	mBoard.updateAll(window, dt);

	for(auto it=mEnemiesList.begin(); it != mEnemiesList.end(); ++it)
	{
		it->update(window, dt, mBoard);
	}

	if(FieldManager::getInstance().isSetToChange())
	{
		mBoard.changeChosenField();
	}
}

void Game::draw(sf::RenderWindow& window)
{
	mBoard.drawAll(window);

	for(auto it=mEnemiesList.begin(); it != mEnemiesList.end(); ++it)
	{
		window.draw(*it);
	}
}