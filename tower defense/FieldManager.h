#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include "all-fields.h"

class FieldManager
{
private:

	static FieldManager mManager;

	bool mSetToChange;
	int mChosenFieldID;

public:
	FieldManager();
	~FieldManager();

	static FieldManager& getInstance();

	Field* createField(int id, int x, int y);
	Field* createField(int id, const sf::Vector2f& pos);

	void setFieldToChange(int id);
	bool isSetToChange();
	void changeField(Field*& desinationPtr);

};
#endif