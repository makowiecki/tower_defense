#include "Board.h"

#include <queue>

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
				mEnterFieldPosition=mBoard[i][j]->getPosition();
			}
			else if(i == width - 1 && j == height / 2)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_EXIT, i*fieldWidth, j*fieldHeight);
				mExitFieldPosition=mBoard[i][j]->getPosition();
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

//bool Board::canFindGlobalWay()
//{
//	std::vector<std::vector<int>> workingBoard;
//
//	workingBoard.reserve(mBoard.size());
//
//	for(unsigned int i=0; i < mBoard.size(); ++i)
//	{
//		workingBoard.push_back(std::vector<int>(mBoard[i].size()));
//	}
//
//	sf::Vector2u actualPosition;
//
//	for(unsigned int i=0; i < workingBoard.size(); ++i)
//	{
//		for(unsigned int j=0; j < workingBoard[i].size(); ++j)
//		{
//			switch(mBoard[i][j]->getFieldType())
//			{
//				case FieldType::FIELD_EMPTY:
//					workingBoard[i][j]=0;
//					break;
//				case FieldType::FIELD_ENTER:
//					workingBoard[i][j]=-1;
//					actualPosition.x=i;
//					actualPosition.y=j;
//					break;
//				case FieldType::FIELD_EXIT:
//					workingBoard[i][j]=2;
//					break;
//				default:
//					workingBoard[i][j]=9;
//					break;
//			}
//		}
//	}
//	workingBoard[mFieldManager.getChosenFieldPosition().x][mFieldManager.getChosenFieldPosition().y]=9;
//
//	std::queue<sf::Vector2u> pointsList;
//
//	pointsList.push(actualPosition);
//
//	int k=-2;
//	unsigned int pointsListSize=0;
//
//	while(pointsList.size() != 0)
//	{
//		pointsListSize=pointsList.size();
//
//		for(unsigned int i=0; i < pointsListSize; ++i)
//		{
//			actualPosition=pointsList.front();
//			pointsList.pop();
//
//			if(workingBoard[actualPosition.x + 1][actualPosition.y] == 2)		// found exit on right field
//			{
//				return true;
//			}
//			else if(workingBoard[actualPosition.x + 1][actualPosition.y] == 0)	// right field
//			{
//				workingBoard[actualPosition.x + 1][actualPosition.y]=k;
//				pointsList.push(sf::Vector2u(actualPosition.x + 1, actualPosition.y));
//			}
//
//			if(workingBoard[actualPosition.x][actualPosition.y + 1] == 0)		// down field
//			{
//				workingBoard[actualPosition.x][actualPosition.y + 1]=k;
//				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y + 1));
//			}
//
//			if(workingBoard[actualPosition.x][actualPosition.y - 1] == 0)		// up field
//			{
//				workingBoard[actualPosition.x][actualPosition.y - 1]=k;
//				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y - 1));
//			}
//
//			if(actualPosition.x > 1)
//			{
//				if(workingBoard[actualPosition.x - 1][actualPosition.y] == 0)		// left field
//				{
//					workingBoard[actualPosition.x - 1][actualPosition.y]=k;
//					pointsList.push(sf::Vector2u(actualPosition.x - 1, actualPosition.y));
//				}
//			}
//		}
//
//		--k;
//	}
//	return false;
//}

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

sf::Vector2f Board::getEnterFieldPosition()const
{
	return mEnterFieldPosition;
}

sf::Vector2f Board::getExitFieldPosition()const
{
	return mExitFieldPosition;
}

void Board::addGlobalStep(const sf::Vector2i& step)
{
	mGlobalStepsList.push(sf::Vector2i(step));
}

FieldType Board::getFieldType(int pX, int pY)const
{
	return mBoard[pX][pY]->getFieldType();
}

void Board::changeChosenField()
{
	mFieldManager.changeField(mBoard[mFieldManager.getChosenFieldPosition().x][mFieldManager.getChosenFieldPosition().y]);
}

void Board::updateAll(const sf::RenderWindow& window, float dt, MonstersList& monstersList)
{
	for(unsigned int i=0; i < mBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mBoard[i].size(); ++j)
		{
			mBoard[i][j]->update(window, dt);
		}
	}

	if(/*monsterManager.issettoadd()*/true)
	{
		static bool raz=true;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			if(raz)
			{
				monstersList.addMonster(mGlobalStepsList);
				raz=false;
			}
		}
		else
		{
			raz=true;
		}
	}

	//if(mFieldManager.isSetToChange())
	//{
	//	if(!canFindGlobalWay())
	//	{
	//		mFieldManager.discardChange();
	//	}
	//}
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