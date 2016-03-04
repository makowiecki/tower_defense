#include "FieldManager.h"

#include "global-information.h"

FieldManager FieldManager::mManager;

FieldManager::FieldManager():mSetToChange(false), mChosenFieldType(FIELD_NONE)
{
}


FieldManager::~FieldManager()
{
}

FieldManager& FieldManager::getInstance()
{
	return mManager;
}

std::unique_ptr<Field> FieldManager::createField(FieldType fieldType, int x, int y)
{
	switch(fieldType)
	{
		case FIELD_NONE:
			return nullptr;
			break;
		case FIELD_EMPTY:
			//return std::make_unique<FieldEmpty>(x, y);
			return std::unique_ptr<Field>(new FieldEmpty(x, y));
			break;
		case FIELD_ENTER:
			//return std::make_unique<FieldEnter>(x, y);
			return std::unique_ptr<Field>(new FieldEnter(x, y));
			break;
		case FIELD_EXIT:
			//return std::make_unique<FieldExit>(x, y);
			return std::unique_ptr<Field>(new FieldExit(x, y));
			break;
		case FIELD_WALL:
			//return std::make_unique<FieldWall>(x, y);
			return std::unique_ptr<Field>(new FieldWall(x, y));
			break;
		//case
		default:
			break;
	}
	return nullptr;
}


std::unique_ptr<Field> FieldManager::createField(FieldType fieldType, const sf::Vector2f& pos)
{
	return createField(fieldType, static_cast<int>(pos.x), static_cast<int>(pos.y));
}


void FieldManager::setFieldToChange(FieldType fieldType, const sf::Vector2f& pixelsPosition)
{
	mSetToChange=true;
	mChosenFieldType=fieldType;
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
	mChosenFieldType=FIELD_NONE;
}

const sf::Vector2i& FieldManager::getChosenFieldPosition()const
{
	return mOnBoardPosition;
}

void FieldManager::changeField(std::unique_ptr<Field>& desinationPtr)
{
	desinationPtr = std::move(createField(mChosenFieldType, desinationPtr->getPosition()));

	mSetToChange=false;
	mChosenFieldType=FIELD_NONE;
}