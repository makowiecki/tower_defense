#ifndef WAY_H
#define WAY_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <stack>
#include "Board.h"

class Way
{
private:

	std::vector<std::vector<int>> mWorkingBoard;
	std::stack<sf::Vector2i> mStepsList;
	sf::Vector2i mExitPosition;

	void makeCopy(const Board& board);
	void fillStepsList(int k);

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

	sf::Vector2i getNextStep();

	int getStepsNumber()const;
};

#endif