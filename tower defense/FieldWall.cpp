#include "FieldWall.h"
#include "ResourceManager.h"

FieldWall::FieldWall(int x, int y):Field(x, y)
{
	mID=3;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL));
}

FieldWall::FieldWall(const sf::Vector2f& pos):Field(pos)
{
	mID=3;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL));
}

FieldWall::~FieldWall()
{
}

void FieldWall::update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board)
{

}