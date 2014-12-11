#include "Way.h"

#include <queue>


Way::Way()
{}


Way::~Way()
{}


bool findWay(const std::vector<std::vector<Field*>>& board, unsigned int destinationX, unsigned int destinationY)
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

	while(true)
	{
		pointsListSize=pointsList.size();
		
		for(unsigned int i=0; i < pointsListSize; ++i)
		{
			actualPosition=pointsList.front();
			pointsList.pop();

			if(workBoard[actualPosition.x + 1][actualPosition.y] == 2)		// found exit right field
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

		if(pointsList.size() == 0)	// cannot find any next point
		{
			return false;
		}
		
		--k;
	}
	return false;
}