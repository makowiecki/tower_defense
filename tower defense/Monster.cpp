#include "Monster.h"

#include "ResourceManager.h"
#include "FieldManager.h"
#include "global-information.h"

Monster::Monster(int pX, int pY, std::stack<sf::Vector2i>& stepsList)
	:mStepsList(stepsList),
	mAggregateTime(0.0f)
{
	mMonsterSprite.setTexture(ResourceManager::getTexture(ResourceManager::ENEMY_1));
	mMonsterSprite.setOrigin(mMonsterSprite.getGlobalBounds().height / 2, mMonsterSprite.getGlobalBounds().width / 2);
	mMonsterSprite.setPosition(static_cast<float>(pX), static_cast<float>(pY));
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
		sf::Vector2i nextStep;

		if(mStepsList.size() != 0)
		{
			nextStep=mStepsList.top();
			mStepsList.pop();
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