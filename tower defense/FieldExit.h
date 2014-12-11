#pragma once

#include "Field.h"

class FieldExit:	public Field
{
public:
	FieldExit(int x, int y);
	FieldExit(const sf::Vector2f& pos);
	virtual ~FieldExit();

	void update(const sf::RenderWindow& window, float dt);
};

