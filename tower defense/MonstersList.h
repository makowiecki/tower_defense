#pragma once

#include "Monster.h"
#include <list>
#include "Board.h"

class MonstersList
{
private:

	std::list<Monster*> mMonstersList;

public:
	MonstersList(const Board& board);
	~MonstersList();

	MonstersList(const MonstersList& origin)=delete;
	MonstersList operator=(const MonstersList& origin)=delete;

	void addMonster(/*MonsterType monsterType, */const Board& board);

	void update(const sf::RenderWindow& window, float dt, const Board& board);
	void draw(sf::RenderWindow& window);
};

