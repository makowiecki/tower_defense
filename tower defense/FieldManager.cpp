#include "FieldManager.h"


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


void FieldManager::setFieldToChange(int id)
{
	mSetToChange=true;
	mChosenFieldID=id;
}

bool FieldManager::isSetToChange()
{
	return mSetToChange;
}

void FieldManager::changeField(Field*& desinationPtr)
{
	sf::Vector2f position(desinationPtr->getPosition());

	delete desinationPtr;

	desinationPtr=createField(mChosenFieldID, position);

	mSetToChange=false;
	mChosenFieldID=-1;
}