#pragma once

#include "Field.h"

class FieldWall:	public Field
{
public:
	FieldWall(int x, int y);
	FieldWall(const sf::Vector2f& pos);
	virtual ~FieldWall();

	void update(const sf::RenderWindow& window, float dt);
};

