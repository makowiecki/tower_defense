#include "FieldEnter.h"
#include "ResourceManager.h"

FieldEnter::FieldEnter(int x, int y):Field(x, y), mAggregateTime(0.0f)
{
	mID=1;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_ENTER));
}


FieldEnter::~FieldEnter()
{
}

void FieldEnter::update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board)
{
	
}