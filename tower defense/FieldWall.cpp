#include "FieldWall.h"
#include "ResourceManager.h"

#include "global-information.h"

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

	if(isCorner())
	{
		static int howManyCorners = 0;

		mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL_CORNER));
		
		sf::IntRect subTexture(0, 0, gi::FIELD_WIDTH, gi::FIELD_HEIGHT); // always 4 corners

		subTexture.top = gi::FIELD_HEIGHT * howManyCorners++;

		mFieldSprite.setTextureRect(subTexture);
	}
	else if(getPosition().x == 0 || getPosition().x == gi::WINDOW_WIDTH - gi::FIELD_WIDTH) //vertical walls
	{
		mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL_VERTICAL));
		mFieldSprite.setTextureRect(sf::IntRect(0, getPosition().x == 0 ? 0 : gi::FIELD_HEIGHT, gi::FIELD_WIDTH, gi::FIELD_HEIGHT));
	}
	else if(getPosition().y == 0 || getPosition().y == gi::WINDOW_HEIGHT - gi::FIELD_HEIGHT) //horizontal walls
	{
		mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL_HORIZONTAL));
		mFieldSprite.setTextureRect(sf::IntRect(0, getPosition().y == 0 ? 0 : gi::FIELD_HEIGHT, gi::FIELD_WIDTH, gi::FIELD_HEIGHT));
	}
	else //wall in the middle
	{
		mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL_MIDDLE));
	}
}

void FieldWall::update(const sf::RenderWindow& window, float dt)
{

}