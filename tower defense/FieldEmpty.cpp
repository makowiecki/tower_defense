#include "FieldEmpty.h"
#include "ResourceManager.h"

FieldEmpty::FieldEmpty(int x, int y):Field(x,y)
{
	mID=0;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
}

FieldEmpty::FieldEmpty(const sf::Vector2f& pos):Field(pos)
{
	mID=0;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
}

FieldEmpty::~FieldEmpty()
{
}

void FieldEmpty::update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board)
{

}