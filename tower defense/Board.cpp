#include "Board.h"

#include "Way.h"

Board::Board(int width, int height, int fieldWidth, int fieldHeight):mFieldManager(FieldManager::getInstance())
{
	mBoard.reserve(width);

	for(int i=0; i < width; ++i)
	{
		mBoard.push_back(std::vector<Field*>(height));
	}

	for(int i=0; i < width; ++i)
	{
		for(int j=0; j < height; ++j)
		{
			if(i == 0 && j == height / 2)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_ENTER, i*fieldWidth, j*fieldHeight);
			}
			else if(i == width - 1 && j == height / 2)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_EXIT, i*fieldWidth, j*fieldHeight);
			}
			else if(i == 0 || i == width - 1)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_WALL, i*fieldWidth, j*fieldHeight);
			}
			else if(j == 0 || j == height - 1)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_WALL, i*fieldWidth, j*fieldHeight);
			}
			else
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_EMPTY, i*fieldWidth, j*fieldHeight);
			}
		}
	}
}

Board::~Board()
{
	for(unsigned int i=0; i < mBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mBoard[i].size(); ++j)
		{
			delete mBoard[i][j];
		}
	}
}

int Board::getWidth()const
{
	return mBoard.size();
}

int Board::getHeight()const
{
	return mBoard[0].size();
}

sf::Vector2i Board::getSize()const
{
	return sf::Vector2i(getHeight(), getWidth());
}

int Board::getFieldID(int pX, int pY)const
{
	return mBoard[pX][pY]->getID();
}

void Board::changeChosenField()
{
	mFieldManager.changeField(mBoard[mFieldManager.getChosenFieldPosition().x][mFieldManager.getChosenFieldPosition().y]);
}

void Board::updateAll(const sf::RenderWindow& window, float dt)
{
	for(unsigned int i=0; i < mBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mBoard[i].size(); ++j)
		{
			mBoard[i][j]->update(window, dt);
		}
	}
}

void Board::drawAll(sf::RenderWindow& window)
{
	for(unsigned int i=0; i < mBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mBoard[i].size(); ++j)
		{
			window.draw(*mBoard[i][j]);
		}
	}
}