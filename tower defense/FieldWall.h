#pragma once

#include "Field.h"

class FieldWall:	public Field
{
public:
	FieldWall(int x, int y);
	virtual ~FieldWall();

	void update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board);
};

