#include "FieldWall.h"
#include "ResourceManager.h"

FieldWall::FieldWall(int x, int y):Field(x, y)
{
	init();
}

FieldWall::FieldWall(const sf::Vector2f& pos):Field(pos)
{
	init();
}

FieldWall::~FieldWall()
{
}

void FieldWall::init()
{
	mType=FieldType::FIELD_WALL;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL));
}

void FieldWall::update(const sf::RenderWindow& window, float dt)
{

}