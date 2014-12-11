#include "Game.h"

#include "global-information.h"

#include <iostream>
using namespace std;

Game::Game()
	:mBoard(gi::FIELDS_IN_ROW, gi::FIELDS_IN_COLUMN, gi::FIELD_WIDTH, gi::FIELD_HEIGHT)
{
}


Game::~Game()
{
}

void Game::update(const sf::RenderWindow& window, float dt)
{
	mBoard.updateAll(window, dt);
}

void Game::draw(sf::RenderWindow& window)
{
	mBoard.drawAll(window);
}