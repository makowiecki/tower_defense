#include "Way.h"
#include "global-information.h"
#include <queue>

#include <iostream>
using namespace std;
#include <conio.h>

Way::Way(const Board& board):mValueParameter(-1)
{
	int width=board.getWidth();
	int height=board.getHeight();

	mWorkingBoard.reserve(width);

	for(int i=0; i < width; ++i)
	{
		mWorkingBoard.push_back(std::vector<int>(height));
	}
}

Way::~Way()
{
}

void Way::makeCopy(const Board& board)
{
	for(unsigned int i=0; i < mWorkingBoard.size(); ++i)
	{
		for(unsigned int j=0; j < mWorkingBoard[i].size(); ++j)
		{
			switch(board.getFieldType(i,j))// .getFieldID(i,j))
			{
				case FieldType::FIELD_EMPTY:
					mWorkingBoard[i][j]=0;
					break;
				case FieldType::FIELD_ENTER:
					mWorkingBoard[i][j]=1;
					break;
				case FieldType::FIELD_EXIT:
					mWorkingBoard[i][j]=2;
					mExitPosition.x=i;
					mExitPosition.y=j;
					break;
				default:
					mWorkingBoard[i][j]=9;
					break;
			}
		}
	}
}

void Way::fillStepsList(Monster& monster, int index)
{
	//while(!mStepsList.empty())
	//{
	//	mStepsList.pop();
	//}


	monster.addStep(mExitPosition);
	++mValueParameter;

	sf::Vector2i actualPosition(mExitPosition);

	while(mValueParameter != -1)
	{
		if(mWorkingBoard[actualPosition.x - 1][actualPosition.y] == mValueParameter)//left
		{
			actualPosition.x-=1;
			monster.addStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x + 1][actualPosition.y] == mValueParameter)//right
		{
			actualPosition.x+=1;
			monster.addStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x][actualPosition.y - 1] == mValueParameter)//up
		{
			actualPosition.y-=1;
			monster.addStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x][actualPosition.y + 1] == mValueParameter)//down
		{
			actualPosition.y+=1;
			monster.addStep(actualPosition);
		}
		++mValueParameter;
	}
}

bool Way::canFind(const Board& board, const sf::Vector2f& pixelsStartPosition)
{
	makeCopy(board);
	mValueParameter=-1;

	sf::Vector2i chosenFieldPosition(FieldManager::getInstance().getChosenFieldPosition());
	mWorkingBoard[chosenFieldPosition.x][chosenFieldPosition.y]=9;

	sf::Vector2u actualPosition(static_cast<unsigned>(pixelsStartPosition.x / gi::FIELD_WIDTH), static_cast<unsigned>(pixelsStartPosition.y / gi::FIELD_HEIGHT));
	mWorkingBoard[actualPosition.x][actualPosition.y]=mValueParameter;
	--mValueParameter;

	std::queue<sf::Vector2u> pointsList;

	pointsList.push(actualPosition);
	
	unsigned int pointsListSize=0;

	while(pointsList.size() != 0)
	{
		pointsListSize=pointsList.size();

		for(unsigned int i=0; i < pointsListSize; ++i)
		{
			actualPosition=pointsList.front();
			pointsList.pop();

			if(mWorkingBoard[actualPosition.x + 1][actualPosition.y] == 2)		// found exit on right field
			{
//fillStepsList(k);
				return true;
			}
			else if(mWorkingBoard[actualPosition.x + 1][actualPosition.y] == 0)	// right field
			{
				mWorkingBoard[actualPosition.x + 1][actualPosition.y]=mValueParameter;
				pointsList.push(sf::Vector2u(actualPosition.x + 1, actualPosition.y));
			}

			if(mWorkingBoard[actualPosition.x][actualPosition.y + 1] == 0)		// down field
			{
				mWorkingBoard[actualPosition.x][actualPosition.y + 1]=mValueParameter;
				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y + 1));
			}

			if(mWorkingBoard[actualPosition.x][actualPosition.y - 1] == 0)		// up field
			{
				mWorkingBoard[actualPosition.x][actualPosition.y - 1]=mValueParameter;
				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y - 1));
			}

			if(actualPosition.x > 1)
			{
				if(mWorkingBoard[actualPosition.x - 1][actualPosition.y] == 0)		// left field
				{
					mWorkingBoard[actualPosition.x - 1][actualPosition.y]=mValueParameter;
					pointsList.push(sf::Vector2u(actualPosition.x - 1, actualPosition.y));
				}
			}
		}
		--mValueParameter;
	}
	
	return false;
}

bool Way::findedWayInAll(MonstersList& monstersList, const Board& board)
{
	for(auto it=monstersList.mMonstersList.begin(); it != monstersList.mMonstersList.end(); ++it)
	{
		if(canFind(board, (*it)->getPosition()))
		{
			fillStepsList(**it, 0);
		}
		else
		{
			return false;
		}
	}
	return true;
}

void Way::fillGlobalStepsList(Board& board)
{
	board.addGlobalStep(mExitPosition);
	++mValueParameter;

	sf::Vector2i actualPosition(mExitPosition);

	while(mValueParameter != -1)
	{
		if(mWorkingBoard[actualPosition.x - 1][actualPosition.y] == mValueParameter)//left
		{
			actualPosition.x-=1;
			board.addGlobalStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x + 1][actualPosition.y] == mValueParameter)//right
		{
			actualPosition.x+=1;
			board.addGlobalStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x][actualPosition.y - 1] == mValueParameter)//up
		{
			actualPosition.y-=1;
			board.addGlobalStep(actualPosition);
		}
		else if(mWorkingBoard[actualPosition.x][actualPosition.y + 1] == mValueParameter)//down
		{
			actualPosition.y+=1;
			board.addGlobalStep(actualPosition);
		}
		++mValueParameter;
	}
}

//std::stack<sf::Vector2i> Way::getStepsList()
//{
//	return mStepsList;
//}

//int Way::getStepsNumber()const
//{
//	return mStepsList.size();
//}

/* just in case
bool GlobalWay::canFind(const std::vector<std::vector<Field*>>& board, unsigned int destinationX, unsigned int destinationY)
{
	std::vector<std::vector<int>> workBoard;

	workBoard.reserve(board.size());

	for(unsigned int i=0; i < board.size(); ++i)
	{
		workBoard.push_back(std::vector<int>(board[i].size()));
	}

	sf::Vector2u actualPosition;

	int tmpID;

	for(unsigned int i=0; i < workBoard.size(); ++i)
	{
		for(unsigned int j=0; j < workBoard[i].size(); ++j)
		{
			tmpID=board[i][j]->getID();

			if(i == destinationX && j == destinationY)
			{
				workBoard[i][j]=9;
			}
			else if(tmpID == 0)		//empty
			{
				workBoard[i][j]=0;
			}
			else if(tmpID == 1)		//enter
			{
				workBoard[i][j]=-1;
				actualPosition.x=i;
				actualPosition.y=j;
			}
			else if(tmpID == 2)		//exit
			{
				workBoard[i][j]=2;
			}
			else
			{
				workBoard[i][j]=9;
			}
		}
	}

	std::queue<sf::Vector2u> pointsList;

	pointsList.push(actualPosition);

	int k=-1;
	unsigned int pointsListSize=0;

	while(pointsList.size() != 0)
	{
		pointsListSize=pointsList.size();
		
		for(unsigned int i=0; i < pointsListSize; ++i)
		{
			actualPosition=pointsList.front();
			pointsList.pop();

			if(workBoard[actualPosition.x + 1][actualPosition.y] == 2)		// found exit on right field
			{
				return true;
			}
			else if(workBoard[actualPosition.x + 1][actualPosition.y] == 0)	// right field
			{
				workBoard[actualPosition.x + 1][actualPosition.y]=k;
				pointsList.push(sf::Vector2u(actualPosition.x + 1, actualPosition.y));
			}

			if(workBoard[actualPosition.x][actualPosition.y + 1] == 0)		// down field
			{
				workBoard[actualPosition.x][actualPosition.y + 1]=k;
				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y + 1));
			}
			
			if(workBoard[actualPosition.x][actualPosition.y - 1] == 0)		// up field
			{
				workBoard[actualPosition.x][actualPosition.y - 1]=k;
				pointsList.push(sf::Vector2u(actualPosition.x, actualPosition.y - 1));
			}

			if(actualPosition.x > 1)
			{
				if(workBoard[actualPosition.x - 1][actualPosition.y] == 0)		// left field
				{
					workBoard[actualPosition.x - 1][actualPosition.y]=k;
					pointsList.push(sf::Vector2u(actualPosition.x - 1, actualPosition.y));
				}
			}
		}
		
		--k;
	}
	return false;
}
*/