#include "FieldEmpty.h"
#include "ResourceManager.h"

FieldEmpty::FieldEmpty(int x, int y):Field(x,y)
{
	mID=0;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
}


FieldEmpty::~FieldEmpty()
{}

void FieldEmpty::update(const sf::RenderWindow& window, float dt)
{

}