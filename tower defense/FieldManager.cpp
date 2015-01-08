#include "FieldManager.h"

#include "global-information.h"

FieldManager FieldManager::mManager;

FieldManager::FieldManager():mSetToChange(false), mChosenFeldType(FIELD_NONE)
{
}


FieldManager::~FieldManager()
{
}

FieldManager& FieldManager::getInstance()
{
	return mManager;
}

Field* FieldManager::createField(FieldType feldType, int x, int y)
{
	switch(feldType)
	{
		case FIELD_NONE:
			return nullptr;
			break;
		case FIELD_EMPTY:
			return new FieldEmpty(x, y);
			break;
		case FIELD_ENTER:
			return new FieldEnter(x, y);
			break;
		case FIELD_EXIT:
			return new FieldExit(x, y);
			break;
		case FIELD_WALL:
			return new FieldWall(x, y);
			break;
		//case
		default:
			break;
	}
	return nullptr;
}


Field* FieldManager::createField(FieldType feldType, const sf::Vector2f& pos)
	{
	return createField(feldType, static_cast<int>(pos.x), static_cast<int>(pos.y));
}


void FieldManager::setFieldToChange(FieldType feldType, const sf::Vector2f& pixelsPosition)
{
	mSetToChange=true;
	mChosenFeldType=feldType;
	mOnBoardPosition.x=static_cast<int>(pixelsPosition.x / gi::FIELD_WIDTH);
	mOnBoardPosition.y=static_cast<int>(pixelsPosition.y / gi::FIELD_HEIGHT);
}

bool FieldManager::isSetToChange()const
{
	return mSetToChange;
}

void FieldManager::discardChange()
{
	mSetToChange=false;
	mChosenFeldType=FIELD_NONE;
}

const sf::Vector2i& FieldManager::getChosenFieldPosition()const
{
	return mOnBoardPosition;
}

void FieldManager::changeField(Field*& desinationPtr)
{
	sf::Vector2f position(desinationPtr->getPosition());

	delete desinationPtr;

	desinationPtr=createField(mChosenFeldType, position);

	mSetToChange=false;
	mChosenFeldType=FIELD_NONE;
}