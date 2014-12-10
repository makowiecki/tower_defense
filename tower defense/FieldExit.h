#pragma once
#include "Field.h"

class FieldExit:	public Field
{
public:
	FieldExit(int x, int y);
	virtual ~FieldExit();

	void update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board);
};

