#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include <memory>
#include "all-fields.h"

// should be an observer-builder pattern
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

	std::unique_ptr<Field> createField(FieldType fieldType, int x, int y);
	std::unique_ptr<Field> createField(FieldType fieldType, const sf::Vector2f& pos);

	void setFieldToChange(FieldType fieldType, const sf::Vector2f& pixelsPosition);
	bool isSetToChange()const;
	void discardChange();
	const sf::Vector2i& getChosenFieldPosition()const;
	void changeField(std::unique_ptr<Field>& desinationPtr);
};
#endif