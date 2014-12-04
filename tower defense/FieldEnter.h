#pragma once
#include "Field.h"

class FieldEnter:	public Field
{
private:

	float mAggregateTime;

public:
	FieldEnter(int x, int y);
	virtual ~FieldEnter();

	void update(const sf::RenderWindow& window, float dt);
};

