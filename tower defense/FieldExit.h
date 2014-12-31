#pragma once

#include "Field.h"

class FieldExit:	public Field
{
private:

	friend class FieldManager;

	FieldExit(int x, int y);
	FieldExit(const sf::Vector2f& pos);

	virtual void init();

public:
	virtual ~FieldExit();

	FieldExit(const FieldExit& origin)=delete;
	FieldExit operator=(const FieldExit& origin)=delete;

	void update(const sf::RenderWindow& window, float dt);
};

