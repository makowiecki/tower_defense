#pragma once

#include <SFML\Graphics.hpp>
#include "Way.h"
#include "Board.h"

class Monster:	public sf::Drawable
{
protected:

	sf::Sprite mMonsterSprite;
	Way mWay;
	//Type mType;
	float mAggregateTime;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Monster(int pX, int pY, const Board& board);
	virtual ~Monster();

	bool isExitReached()const;

	virtual void update(const sf::RenderWindow& window, float dt, const Board& board);
};

