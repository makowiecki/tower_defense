#include "Field.h"
#include "ResourceManager.h"


Field::Field(FieldType type, float x, float y):mType(type)
{
	switch(type)
	{
		case Field::ENTER:
			mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_ENTER));
			break;
		case Field::EXIT:
			mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EXIT));
			break;
		case Field::EMPTY:
			mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
			break;
		case Field::WALL:
			mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_WALL));
			break;
		case Field::TOWER:
			mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_TOWER));
			break;
		default:
			break;
	}

	mFieldSprite.setPosition(x, y);
}

Field::Field(const Field& origin):mType(origin.mType)
{
	mFieldSprite=origin.mFieldSprite;
}

Field::~Field()
{
}

Field& Field::operator=(const Field& origin)
{
	if(this == &origin) { return *this; }

	mFieldSprite=origin.mFieldSprite;
	mType=origin.mType;

	return *this;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mFieldSprite);
}

Field::FieldType Field::getType()const
{
	return mType;
}