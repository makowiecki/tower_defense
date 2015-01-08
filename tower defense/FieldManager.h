#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include "all-fields.h"

class FieldManager
{
private:

	static FieldManager mManager;

	bool mSetToChange;
	FieldType mChosenFieldType;
	sf::Vector2i mOnBoardPosition;

	FieldManager();
	~FieldManager();

	FieldManager(const FieldManager& origin)=delete;
	FieldManager operator=(const FieldManager& origin)=delete;

public:

	static FieldManager& getInstance();

	Field* createField(FieldType fieldType, int x, int y);
	Field* createField(FieldType fieldType, const sf::Vector2f& pos);

	void setFieldToChange(FieldType fieldType, const sf::Vector2f& pixelsPosition);
	bool isSetToChange()const;
	void discardChange();
	const sf::Vector2i& getChosenFieldPosition()const;
	void changeField(Field*& desinationPtr);
};
#endif