#pragma once

#include <SFML\Graphics.hpp>
#include <stack>

class Monster:	public sf::Drawable
{
protected:

	enum Direction { LEFT, RIGHT, UP, DOWN };

	sf::Sprite mMonsterSprite;
	std::stack<sf::Vector2i> mStepsList;
	float mAggregateTime;
	Direction mDirection;
	float mSpeed;
	sf::Vector2i mNextStep;
	sf::Vector2i mPreviousStep;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void setDirection();
	void moveToDirection(float dt);

public:
	Monster(int pX, int pY, std::stack<sf::Vector2i>& stepsList);
	virtual ~Monster();

	bool isExitReached()const;

	void addStep(const sf::Vector2i& step);

	void emptyStepsList();

	sf::Vector2f getPosition()const;

	virtual void update(const sf::RenderWindow& window, float dt);
};

