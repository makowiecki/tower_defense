#pragma once

#include <SFML\Graphics.hpp>
#include "Way.h"
#include "Board.h"

class Enemy:	public sf::Drawable
{
protected:

	sf::Sprite mEnemySprite;
	Way mWay;
	//int mID;
	float mAggregateTime;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Enemy(int pX, int pY, const Board& board);
	virtual ~Enemy();

	virtual void update(const sf::RenderWindow& window, float dt, const Board& board);
};

