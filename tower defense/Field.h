#pragma once

#include <SFML\Graphics.hpp>

class Field:public sf::Drawable
{
public:

	enum FieldType { ENTER, EXIT, EMPTY, WALL, TOWER };

private:

	sf::Sprite mFieldSprite;
	FieldType mType;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Field(FieldType type, float x, float y);
	Field(const Field& origin);
	~Field();

	Field& operator=(const Field& origin);

	FieldType getType()const;
};

