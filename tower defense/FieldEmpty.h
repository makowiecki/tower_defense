#pragma once

#include "Field.h"

class FieldEmpty:	public Field
{
public:
	FieldEmpty(int x, int y);
	FieldEmpty(const sf::Vector2f& pos);
	virtual ~FieldEmpty();

	void update(const sf::RenderWindow& window, float dt);
};

