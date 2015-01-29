#ifndef WAY_H
#define WAY_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "MonstersList.h"
#include "Monster.h"
#include "Board.h"

class Way
{
private:

	std::vector<std::vector<int>> mWorkingBoard;
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

	//TODO: think about rename:
	bool findedWayInAll(MonstersList& monstersList, const Board& board);

	void fillGlobalStepsList(Board& board);
};

#endif