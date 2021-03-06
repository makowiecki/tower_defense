#include "Way.h"
#include "global-information.h"
#include <queue>

Way::Way(const Board& board)
	:Way(board.getWidth(), board.getHeight())
{
}

Way::Way(int width, int height)
	:mValueParameter(-1)
{
	mWorkingBoard.reserve(width);

	for(int i = 0; i < width; ++i)
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
			switch(board.getFieldType(i,j))
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
	monster.emptyStepsList();

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

bool Way::foundWayInAll(MonstersList& monstersList, const Board& board)
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
	board.emptyGlobalStepsList();

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