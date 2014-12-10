#pragma once

#include <SFML\Graphics.hpp>

#include <iostream>
using namespace std;

class Field:public sf::Drawable
{
protected:

	sf::Sprite mFieldSprite;
	int mID;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Field(int x, int y);
	Field(const sf::Vector2f& pos);
	virtual ~Field();

	int getID()const;

	sf::Vector2f getPosition()const;

	virtual void update(const sf::RenderWindow& window, float dt, const std::vector<std::vector<Field*>>& board)=0;
};