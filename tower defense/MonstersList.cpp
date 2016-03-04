#include "MonstersList.h"

#include "global-information.h"

#include <algorithm>

MonstersList::MonstersList()
{
}

MonstersList::~MonstersList()
{
}

void MonstersList::addMonster(std::stack<sf::Vector2i>& monsterStepsList)
{
	mMonstersList.push_back(std::make_unique<Monster>(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), monsterStepsList));
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
	std::for_each(mMonstersList.begin(), mMonstersList.end(), [&window](const std::unique_ptr<Monster> &ptr){ window.draw(*ptr); });
}