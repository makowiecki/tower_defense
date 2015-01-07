#include "FieldEmpty.h"
#include "ResourceManager.h"

#include "FieldManager.h"

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

void FieldEmpty::update(const sf::RenderWindow& window, float dt)
{
	sf::Vector2f mousePos(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

	if(mFieldSprite.getGlobalBounds().contains(mousePos))
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		{
			FieldManager::getInstance().setFieldToChange(3);
		}
	}
}