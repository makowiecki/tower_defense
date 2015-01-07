#include "FieldManager.h"

#include "global-information.h"

FieldManager FieldManager::mManager;

FieldManager::FieldManager():mSetToChange(false), mChosenFieldID(-1)
{
}


FieldManager::~FieldManager()
{
}

FieldManager& FieldManager::getInstance()
{
	return mManager;
}

Field* FieldManager::createField(int id, int x, int y)
{
	switch(id)
	{
		case 0:
			return new FieldEmpty(x, y);
		case 1:
			return new FieldEnter(x, y);
		case 2:
			return new FieldExit(x, y);
		case 3:
			return new FieldWall(x, y);
		//case 4:
			//towers
	}
	return nullptr;
}


Field* FieldManager::createField(int id, const sf::Vector2f& pos)
{
	switch(id)
	{
		case 0:
			return new FieldEmpty(pos);
		case 1:
			return new FieldEnter(pos);
		case 2:
			return new FieldExit(pos);
		case 3:
			return new FieldWall(pos);
		//case 4:
			//towers
	}
	return nullptr;
}


void FieldManager::setFieldToChange(int id, const sf::Vector2f& pixelsPosition)
{
	mSetToChange=true;
	mChosenFieldID=id;
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
}

const sf::Vector2i& FieldManager::getChosenFieldPosition()const
{
	return mOnBoardPosition;
}

void FieldManager::changeField(Field*& desinationPtr)
{
	sf::Vector2f position(desinationPtr->getPosition());

	delete desinationPtr;

	desinationPtr=createField(mChosenFieldID, position);

	mSetToChange=false;
	mChosenFieldID=-1;
}