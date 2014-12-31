#pragma once

#include "Field.h"

class FieldWall:	public Field
{
private:

	friend class FieldManager;

	FieldWall(int x, int y);
	FieldWall(const sf::Vector2f& pos);

	virtual void init();

public:
	virtual ~FieldWall();

	FieldWall(const FieldWall& origin)=delete;
	FieldWall operator=(const FieldWall& origin)=delete;

	void update(const sf::RenderWindow& window, float dt);
};

