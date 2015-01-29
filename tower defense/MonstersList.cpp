#include "MonstersList.h"

#include "global-information.h"

MonstersList::MonstersList()
{
}

MonstersList::~MonstersList()
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end(); ++it)
	{
		delete *it;
	}
}

void MonstersList::addMonster(std::stack<sf::Vector2i>& monsterStepsList)
{
	mMonstersList.push_back(new Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), monsterStepsList));
}

void MonstersList::update(const sf::RenderWindow& window, float dt)
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end();)
	{
		(*it)->update(window, dt);

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