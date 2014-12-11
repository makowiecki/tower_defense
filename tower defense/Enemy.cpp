#include "Enemy.h"

#include "ResourceManager.h"
#include "global-information.h"

#include <iostream>
using namespace std;

Enemy::Enemy(int x, int y):mAggregateTime(0.0f)
{
	mEnemySprite.setTexture(ResourceManager::getTexture(ResourceManager::ENEMY_1));
	mEnemySprite.setOrigin(mEnemySprite.getGlobalBounds().height / 2, mEnemySprite.getGlobalBounds().width / 2);
	mEnemySprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}


Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mEnemySprite);
}

void Enemy::update(const sf::RenderWindow& window, float dt)
{
	mAggregateTime+=dt;

	if(mAggregateTime > 1.0f)
	{
		mEnemySprite.move(static_cast<float>(gi::FIELD_WIDTH), 0);
		mAggregateTime=0.0f;
	}
}