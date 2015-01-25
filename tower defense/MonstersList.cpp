#include "MonstersList.h"

#include "global-information.h"

MonstersList::MonstersList(const Board& board)
{
	mMonstersList.push_back(new Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), board));
}


MonstersList::~MonstersList()
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end(); ++it)
	{
		delete *it;
	}
}

void MonstersList::addMonster(/*MonsterType monsterType, */const Board& board)
{
	mMonstersList.push_back(new Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), board));
}

void MonstersList::update(const sf::RenderWindow& window, float dt, const Board& board)
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end();)
	{
		(*it)->update(window, dt, board);

		if((*it)->isExitReached())
		{
			it=mMonstersList.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void MonstersList::draw(sf::RenderWindow& window)
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end(); ++it)
	{
		window.draw(**it);
	}
}