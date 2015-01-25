#include "Monster.h"

#include "ResourceManager.h"
#include "FieldManager.h"
#include "global-information.h"

#include <iostream>
using namespace std;

Monster::Monster(int pX, int pY, const Board& board):mWay(board), mAggregateTime(0.0f)
{
	mMonsterSprite.setTexture(ResourceManager::getTexture(ResourceManager::ENEMY_1));
	mMonsterSprite.setOrigin(mMonsterSprite.getGlobalBounds().height / 2, mMonsterSprite.getGlobalBounds().width / 2);
	mMonsterSprite.setPosition(static_cast<float>(pX), static_cast<float>(pY));

	mWay.canFind(board, mMonsterSprite.getPosition());
}


Monster::~Monster()
{
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mMonsterSprite);
}

bool Monster::isExitReached()const
{
	return mWay.getStepsNumber() == 0 ? true : false;
}

void Monster::update(const sf::RenderWindow& window, float dt, const Board& board)
{
	if(FieldManager::getInstance().isSetToChange())
	{
		if(!mWay.canFind(board, mMonsterSprite.getPosition()))
		{
			FieldManager::getInstance().discardChange();
		}
	}

	mAggregateTime+=dt;

	if(mAggregateTime > 1.0f)
	{
		sf::Vector2i nextStep;

		if(mWay.getStepsNumber() != 0)
		{
			nextStep=mWay.getNextStep();
		}
		else
		{
			return;
		}
		sf::Vector2f nextPosition;

		nextPosition.x=static_cast<float>(nextStep.x*gi::FIELD_WIDTH + 25);
		nextPosition.y=static_cast<float>(nextStep.y*gi::FIELD_HEIGHT + 25);

		mMonsterSprite.setPosition(nextPosition);
		mAggregateTime=0.0f;
	}
}