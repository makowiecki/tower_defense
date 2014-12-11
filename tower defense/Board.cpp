#include "Board.h"

#include "Way.h"

Board::Board(int width, int height, int fieldWidith, int fieldHeight):mFieldManager(FieldManager::getInstance())
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
				mBoard[i][j]=new FieldEnter(i*fieldWidith, j*fieldHeight);
			}
			else if(i == width - 1 && j == height / 2)
			{
				mBoard[i][j]=new FieldExit(i*fieldWidith, j*fieldHeight);
			}
			else if(i == 0 || i == width - 1)
			{
				mBoard[i][j]=new FieldWall(i*fieldWidith, j*fieldHeight);
			}
			else if(j == 0 || j == height - 1)
			{
				mBoard[i][j]=new FieldWall(i*fieldWidith, j*fieldHeight);
			}
			else
			{
				mBoard[i][j]=new FieldEmpty(i*fieldWidith, j*fieldHeight);
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

void Board::updateAll(const sf::RenderWindow& window, float dt)
{
	for(unsigned int i=0; i < mBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mBoard[i].size(); ++j)
		{
			mBoard[i][j]->update(window, dt);

			if(mFieldManager.isSetToChange())
			{
				if(findWay(mBoard, (int)mBoard[i][j]->getPosition().x / 50, (int)mBoard[i][j]->getPosition().y / 50))
				{
					cout << "TRUE" << endl;
					mFieldManager.changeField(mBoard[i][j]);
				}
				else
				{
					mFieldManager.discardChange();
					cout << "FALSE" << endl;
				}
			}
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