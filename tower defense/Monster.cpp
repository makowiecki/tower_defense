#include "Monster.h"

#include "ResourceManager.h"
#include "FieldManager.h"
#include "global-information.h"


#include <iostream>
using namespace std;
#include <conio.h>

Monster::Monster(int pX, int pY, std::stack<sf::Vector2i>& stepsList)
	:mStepsList(stepsList),
	mAggregateTime(0.0f),
	mDirection(Direction::RIGHT),
	mSpeed(50.0f)
{
	mMonsterSprite.setTexture(ResourceManager::getTexture(ResourceManager::ENEMY_1));
	mMonsterSprite.setOrigin(mMonsterSprite.getGlobalBounds().height / 2, mMonsterSprite.getGlobalBounds().width / 2);
	mMonsterSprite.setPosition(static_cast<float>(pX), static_cast<float>(pY));
	
	mNextStep=mStepsList.top();
	mStepsList.pop();
	mPreviousStep.x=pX / gi::FIELD_WIDTH;
	mPreviousStep.y=pY / gi::FIELD_HEIGHT;
	
	setDirection();
}

Monster::~Monster()
{
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mMonsterSprite);
}

void Monster::setDirection()
{
	//sf::Vector2i nextPosition;
	//sf::Vector2i monsterPosition=static_cast<sf::Vector2i>(mMonsterSprite.getPosition());

	//nextPosition.x=(nextStep.x*gi::FIELD_WIDTH + 25);
	//nextPosition.y=(nextStep.y*gi::FIELD_HEIGHT + 25);


	cout << "ns.x= " << mNextStep.x << " | ps.x= " << mPreviousStep.x << " || ns.y= " << mNextStep.y << " | ps.y= " << mPreviousStep.y << endl;
	//_getch();

	if(mNextStep.x > mPreviousStep.x)
	{
		mDirection=Direction::RIGHT;
	}
	else if(mNextStep.x < mPreviousStep.x)
	{
		mDirection=Direction::LEFT;
	}
	else if(mNextStep.y > mPreviousStep.y)
	{
		mDirection=Direction::DOWN;
	}
	else if(mNextStep.y < mPreviousStep.y)
	{
		mDirection=Direction::UP;
	}
}

void Monster::moveToDirection(float dt)
{
	switch(mDirection)
	{
		case Direction::LEFT:
			mMonsterSprite.move(-mSpeed*dt, 0);
			break;
		case Direction::RIGHT:
			mMonsterSprite.move(mSpeed*dt, 0);
			break;
		case Direction::UP:
			mMonsterSprite.move(0, -mSpeed*dt);
			break;
		case Direction::DOWN:
			mMonsterSprite.move(0, mSpeed*dt);
			break;
		default:
			break;
	}
}

bool Monster::isExitReached()const
{
	return mStepsList.size() == 0 ? true : false;
}

sf::Vector2f Monster::getPosition()const
{
	return mMonsterSprite.getPosition();
}

void Monster::addStep(const sf::Vector2i& step)
{
	mStepsList.push(sf::Vector2i(step));
}

void Monster::emptyStepsList()
{
	while(!mStepsList.empty())
	{
		mStepsList.pop();
	}
}

void Monster::update(const sf::RenderWindow& window, float dt)
{
	mAggregateTime+=dt;
	
	if(mAggregateTime > 1.0f)
	{
		if(mStepsList.size() != 0)
		{
			mPreviousStep=mNextStep;

			mNextStep=mStepsList.top();
			mStepsList.pop();
		}
		else
		{
			return;
		}

		setDirection();
		mAggregateTime=0.0f;
	}
	moveToDirection(dt);
}