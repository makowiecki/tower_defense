#include "Game.h"

#include "global-information.h"
#include "FieldWall.h"
#include "FieldEmpty.h"
#include "FieldEnter.h"
#include "FieldExit.h"

#include <iostream>
using namespace std;

Game::Game()
{
	mBoard.reserve(gi::FIELDS_IN_ROW);
	
	for(unsigned int i=0; i < gi::FIELDS_IN_ROW; ++i)
	{
		mBoard.push_back(std::vector<Field*>(gi::FIELDS_IN_COLUMN));
	}
	
	for(unsigned int i=0; i < gi::FIELDS_IN_ROW; ++i)
	{
		for(unsigned int j=0; j < gi::FIELDS_IN_COLUMN; ++j)
		{
			if(i == 0 && j == gi::FIELDS_IN_COLUMN / 2)
			{
				mBoard[i][j]=new FieldEnter(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);
			}
			else if(i == gi::FIELDS_IN_ROW - 1 && j == gi::FIELDS_IN_COLUMN / 2)
			{
				mBoard[i][j]=new FieldExit(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);
			}
			else if(i == 0 || i == gi::FIELDS_IN_ROW - 1)
			{
				mBoard[i][j]=new FieldWall(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);
			}
			else if(j == 0 || j == gi::FIELDS_IN_COLUMN - 1)
			{
				mBoard[i][j]=new FieldWall(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);
			}
			else
			{
				mBoard[i][j]=new FieldEmpty(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);
			}
		}
	}
}


Game::~Game()
{
	for(unsigned int i=0; i < gi::FIELDS_IN_ROW; ++i)
	{
		for(unsigned int j=0; j < gi::FIELDS_IN_COLUMN; ++j)
		{
			delete mBoard[i][j];
		}
	}
}

void Game::update(const sf::RenderWindow& window, float dt)
{
	for(unsigned int i=0; i < gi::FIELDS_IN_ROW; ++i)
	{
		for(unsigned int j=0; j < gi::FIELDS_IN_COLUMN; ++j)
		{
			mBoard[i][j]->update(window, dt);
		}
	}
}

void Game::draw(sf::RenderWindow& window)
{
	for(unsigned int i=0; i < gi::FIELDS_IN_ROW; ++i)
	{
		for(unsigned int j=0; j < gi::FIELDS_IN_COLUMN; ++j)
		{
			window.draw(*mBoard[i][j]);
		}
	}
}