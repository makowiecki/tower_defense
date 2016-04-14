#include "Field.h"
#include "ResourceManager.h"

#include "global-information.h"

Field::Field(int x, int y)
{
	mFieldSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

Field::Field(const sf::Vector2f& pos)
{
	mFieldSprite.setPosition(pos);
}

Field::~Field()
{
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mFieldSprite);
}

bool Field::isCorner()const
{
	return (getPosition().x == 0 && (getPosition().y == 0 || getPosition().y == gi::WINDOW_HEIGHT - gi::FIELD_HEIGHT) ||
			getPosition().x == gi::WINDOW_WIDTH - gi::FIELD_WIDTH && (getPosition().y == 0 || getPosition().y == gi::WINDOW_HEIGHT - gi::FIELD_HEIGHT));
}

FieldType Field::getFieldType()const
{
	return mType;
}

sf::Vector2f Field::getPosition()const
{
	return mFieldSprite.getPosition();
}