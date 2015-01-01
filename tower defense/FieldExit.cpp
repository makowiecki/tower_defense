#include "FieldExit.h"
#include "ResourceManager.h"

FieldExit::FieldExit(int x, int y):Field(x, y)
{
	init();
}

FieldExit::FieldExit(const sf::Vector2f& pos):Field(pos)
{
	init();
}

FieldExit::~FieldExit()
{
}

void FieldExit::init()
{
	mType=FieldType::FIELD_EXIT;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EXIT));
}

void FieldExit::update(const sf::RenderWindow& window, float dt)
{

}