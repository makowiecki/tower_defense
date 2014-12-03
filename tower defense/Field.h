#pragma once

#include <SFML\Graphics.hpp>

class Field:public sf::Drawable
{
protected:

	sf::Sprite mFieldSprite;
	int mID;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Field(int x, int y);
	virtual ~Field();

	virtual void update(const sf::RenderWindow& window, const sf::Event& pEvent, float dt)=0;
};