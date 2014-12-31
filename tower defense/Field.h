#pragma once

#include <SFML\Graphics.hpp>

#include <iostream>
using namespace std;

enum FieldType { FIELD_NONE, FIELD_EMPTY, FIELD_ENTER, FIELD_EXIT, FIELD_WALL };

class Field:public sf::Drawable
{
private:
	
	friend class FieldManager;

protected:

	sf::Sprite mFieldSprite;
	FieldType mType;

	Field(int x, int y);
	Field(const sf::Vector2f& pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

	virtual void init()=0;

public:
	
	virtual ~Field();

	FieldType getFieldType()const;

	sf::Vector2f getPosition()const;

	virtual void update(const sf::RenderWindow& window, float dt)=0;
};