#include "Field.h"
#include "ResourceManager.h"


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

FieldType Field::getFieldType()const
{
	return mType;
}

sf::Vector2f Field::getPosition()const
{
	return mFieldSprite.getPosition();
}