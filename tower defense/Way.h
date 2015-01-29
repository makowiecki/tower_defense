#ifndef WAY_H
#define WAY_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "MonstersList.h"
#include <stack>
#include "Board.h"

class Way
{
private:

	std::vector<std::vector<int>> mWorkingBoard;
	//std::stack<sf::Vector2i> mStepsList;
	sf::Vector2i mExitPosition;
	int mValueParameter;

	void makeCopy(const Board& board);
	void fillStepsList(Monster& monster, int index);

public:
	Way(const Board& board);
	~Way();

	////
	///
	///	\brief Check whether can find way if player will block chosen Field on board.
	///
	///	\return True if can find way, false if cannot find way while chosen Filed will be blocked.
	////
	bool canFind(const Board& board, const sf::Vector2f& pixelsStartPosition);

	bool findedWayInAll(MonstersList& monstersList, const Board& board);

	void fillGlobalStepsList(Board& board);

	//std::stack<sf::Vector2i> getStepsList();

	//int getStepsNumber()const;
};

#endif