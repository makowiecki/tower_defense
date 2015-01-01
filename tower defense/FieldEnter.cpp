#include "FieldEnter.h"
#include "ResourceManager.h"

FieldEnter::FieldEnter(int x, int y):Field(x, y), mAggregateTime(0.0f)
{
	init();
}

FieldEnter::FieldEnter(const sf::Vector2f& pos):Field(pos)
{
	init();
}

FieldEnter::~FieldEnter()
{
}

void FieldEnter::init()
{
	mType=FieldType::FIELD_ENTER;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_ENTER));
}

void FieldEnter::update(const sf::RenderWindow& window, float dt)
{
	
}