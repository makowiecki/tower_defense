#pragma once

#include "Field.h"

class FieldEnter:	public Field
{
private:

	friend class FieldManager;

	float mAggregateTime;

	FieldEnter(int x, int y);
	FieldEnter(const sf::Vector2f& pos);

	virtual void init();

public:
	virtual ~FieldEnter();

	FieldEnter(const FieldEnter& origin)=delete;
	FieldEnter operator=(const FieldEnter& origin)=delete;

	void update(const sf::RenderWindow& window, float dt);
};

