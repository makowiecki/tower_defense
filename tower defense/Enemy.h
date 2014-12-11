#pragma once

#include <SFML\Graphics.hpp>

class Enemy:	public sf::Drawable
{
protected:

	sf::Sprite mEnemySprite;
	//int mID;
	float mAggregateTime;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	virtual void update(const sf::RenderWindow& window, float dt);
};

