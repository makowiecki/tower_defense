#include "Field.h"
#include "ResourceManager.h"


Field::Field(int x, int y)
{
	mFieldSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

Field::~Field()
{
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mFieldSprite);
}

int Field::getID()const
{
	return mID;
}