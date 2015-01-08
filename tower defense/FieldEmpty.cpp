#include "FieldEmpty.h"
#include "ResourceManager.h"

#include "FieldManager.h"

FieldEmpty::FieldEmpty(int x, int y):Field(x,y)
{
	init();
}

FieldEmpty::FieldEmpty(const sf::Vector2f& pos):Field(pos)
{
	init();
}

FieldEmpty::~FieldEmpty()
{
}

void FieldEmpty::init()
{
	mType=FieldType::FIELD_EMPTY;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
}

void FieldEmpty::update(const sf::RenderWindow& window, float dt)
{
	sf::Vector2f mousePos(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

	if(mFieldSprite.getGlobalBounds().contains(mousePos))
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		{
			FieldManager::getInstance().setFieldToChange(FieldType::FIELD_WALL, getPosition());
		}
	}
}