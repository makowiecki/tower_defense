#pragma once

#include "Field.h"

class FieldEmpty:	public Field
{
private:

	friend class FieldManager;

	sf::RectangleShape mFrame;
	bool mDrawFrame;

	FieldEmpty(int x, int y);
	FieldEmpty(const sf::Vector2f& pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void init();

public:
	virtual ~FieldEmpty();

	FieldEmpty(const FieldEmpty& origin)=delete;
	FieldEmpty operator=(const FieldEmpty& origin)=delete;

	void update(const sf::RenderWindow& window, float dt);
};

