#include "Game.h"

#include "global-information.h"
#include "Wall.h"

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
			mBoard[i][j]=new Wall(i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT);

			//			if(i == 0 && j == gi::FIELDS_IN_COLUMN / 2)
			//			{
			//				mFieldsList.emplace_back(Field(Field::ENTER, i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT));
			//			}
			//			else if(i == gi::FIELDS_IN_ROW - 1 && j == gi::FIELDS_IN_COLUMN / 2)
			//			{
			//				mFieldsList.emplace_back(Field(Field::EXIT, i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT));
			//			}
			//			else if(i == 0 || i == gi::FIELDS_IN_ROW - 1)
			//			{
			//				mFieldsList.emplace_back(Field(Field::WALL, i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT));
			//			}
			//			else if(j == 0 || j == gi::FIELDS_IN_COLUMN - 1)
			//			{
			//				mFieldsList.emplace_back(Field(Field::WALL, i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT));
			//			}
			//			else
			//			{
			//				mFieldsList.emplace_back(Field(Field::EMPTY, i*gi::FIELD_WIDTH, j*gi::FIELD_HEIGHT));
			//			}
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