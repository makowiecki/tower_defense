#pragma once

#include "Monster.h"
#include <list>

class MonstersList
{
private:
	//TODO: think how to change this:
	friend class Way;

	std::list<Monster*> mMonstersList;

public:
	MonstersList();
	~MonstersList();

	MonstersList(const MonstersList& origin)=delete;
	MonstersList operator=(const MonstersList& origin)=delete;

	void addMonster(std::stack<sf::Vector2i>& monsterStepsList);

	void update(const sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
};

