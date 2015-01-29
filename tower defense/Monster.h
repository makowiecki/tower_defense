#pragma once

#include <SFML\Graphics.hpp>
#include <stack>
//#include "Way.h"
//#include "Board.h"

class Monster:	public sf::Drawable
{
protected:

	sf::Sprite mMonsterSprite;
	std::stack<sf::Vector2i> mStepsList;
	//Way mWay;
	//Type mType;
	float mAggregateTime;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Monster(int pX, int pY, std::stack<sf::Vector2i>& stepsList /*, const Board& board*/);
	virtual ~Monster();

	bool isExitReached()const;

	void addStep(const sf::Vector2i& step);

	sf::Vector2f getPosition()const;

	virtual void update(const sf::RenderWindow& window, float dt/*, const Board& board*/);
};

