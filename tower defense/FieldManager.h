#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include "all-fields.h"

class FieldManager
{
private:

	static FieldManager mManager;

	bool mSetToChange;
	FieldType mChosenFeldType;

public:
	FieldManager();
	~FieldManager();

	static FieldManager& getInstance();

	Field* createField(FieldType fieldType, int x, int y);
	Field* createField(FieldType fieldType, const sf::Vector2f& pos);

	void setFieldToChange(FieldType fieldType);
	bool isSetToChange();
	void discardChange();
	void changeField(Field*& desinationPtr);
};
#endif