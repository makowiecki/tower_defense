#include "FieldWall.h"
#include "ResourceManager.h"
#include "global-information.h"

FieldWall::FieldWall(int x, int y):Field(x, y)
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