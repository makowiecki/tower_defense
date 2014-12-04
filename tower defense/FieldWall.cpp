#include "FieldWall.h"
#include "ResourceManager.h"
#include "global-information.h"

#include <iostream>
using namespace std;

FieldWall::FieldWall(int x, int y):Field(x, y)
{
	mID=3;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL));
}

FieldWall::~FieldWall()
{
}

void FieldWall::update(const sf::RenderWindow& window, float dt)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2f tmpMousePos(sf::Mouse::getPosition(window));
		if(mFieldSprite.getGlobalBounds().contains(tmpMousePos))
		{
			cout << mFieldSprite.getPosition().x / gi::FIELD_HEIGHT << " | " << mFieldSprite.getPosition().y / gi::FIELD_HEIGHT << endl;
		}
	}
}