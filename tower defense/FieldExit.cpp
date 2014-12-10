#include "FieldExit.h"
#include "ResourceManager.h"

FieldExit::FieldExit(int x, int y):Field(x, y)
{
	mID=2;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EXIT));
}


FieldExit::~FieldExit()
{
}


void FieldExit::update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board)
{

}