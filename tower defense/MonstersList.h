#pragma once

#include "Monster.h"
#include <list>
//#include "Way.h"
//#include "Board.h"

class MonstersList
{
private:

	friend class Way;

	std::list<Monster*> mMonstersList;

public:
	MonstersList(/*const Board& board*/);
	~MonstersList();

	MonstersList(const MonstersList& origin)=delete;
	MonstersList operator=(const MonstersList& origin)=delete;

	void addMonster(/*MonsterType monsterType, */ std::stack<sf::Vector2i>& monsterStepsList/*const Board& board*/);

	int getMonstersCount()const;

	sf::Vector2f getMonsterPosition(int i);

	void update(const sf::RenderWindow& window, float dt/*, const Board& board*/);
	void draw(sf::RenderWindow& window);
};

