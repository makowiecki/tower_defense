#include "Enemy.h"

#include "ResourceManager.h"
#include "FieldManager.h"
#include "global-information.h"

#include <iostream>
using namespace std;

Enemy::Enemy(int pX, int pY, const Board& board):mWay(board), mAggregateTime(0.0f)
{
	mEnemySprite.setTexture(ResourceManager::getTexture(ResourceManager::ENEMY_1));
	mEnemySprite.setOrigin(mEnemySprite.getGlobalBounds().height / 2, mEnemySprite.getGlobalBounds().width / 2);
	mEnemySprite.setPosition(static_cast<float>(pX), static_cast<float>(pY));
}


Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mEnemySprite);
}

void Enemy::update(const sf::RenderWindow& window, float dt, const Board& board)
{
	if(!mWay.canFind(board, mEnemySprite.getPosition()))
	{
		FieldManager::getInstance().discardChange();
	}

	mAggregateTime+=dt;

	if(mAggregateTime > 1.0f)
	{
		sf::Vector2f nextPosition;
		sf::Vector2i nextStep=mWay.getNextStep();

		nextPosition.x=static_cast<float>(nextStep.x*gi::FIELD_WIDTH + 25);
		nextPosition.y=static_cast<float>(nextStep.y*gi::FIELD_HEIGHT + 25);

		mEnemySprite.setPosition(nextPosition);
		mAggregateTime=0.0f;
	}
}