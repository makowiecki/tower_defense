#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include "all-fields.h"

class FieldManager
{
private:

	static FieldManager mManager;

	bool mSetToChange;
	int mChosenFieldID;
	sf::Vector2i mOnBoardPosition;

public:
	FieldManager();
	~FieldManager();

	static FieldManager& getInstance();

	Field* createField(int id, int x, int y);
	Field* createField(int id, const sf::Vector2f& pos);

	void setFieldToChange(int id, const sf::Vector2f& pixelsPosition);
	bool isSetToChange()const;
	void discardChange();
	const sf::Vector2i& getChosenFieldPosition()const;
	void changeField(Field*& desinationPtr);

};
#endif