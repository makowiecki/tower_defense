#include "MonstersList.h"

#include "global-information.h"

MonstersList::MonstersList(/*const Board& board*/)
{
	//mMonstersList.push_back(new Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2)/*, board*/));
}


MonstersList::~MonstersList()
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end(); ++it)
	{
		delete *it;
	}
}

void MonstersList::addMonster(/*MonsterType monsterType, */std::stack<sf::Vector2i>& monsterStepsList/*const Board& board*/)
{
	mMonstersList.push_back(new Monster(25, 25 + 50 * (gi::FIELDS_IN_COLUMN / 2), monsterStepsList/*, board*/));
}

int MonstersList::getMonstersCount()const
{
	return mMonstersList.size();
}

sf::Vector2f MonstersList::getMonsterPosition(int i)
{
	return (*mMonstersList.begin())->getPosition();
}

void MonstersList::update(const sf::RenderWindow& window, float dt/*, const Board& board*/)
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end();)
	{
		(*it)->update(window, dt/*, board*/);

		if((*it)->isExitReached())
		{
			it=mMonstersList.erase(it);
		}
		else
		{
			++it;
		}
	}

	static float mAggregateTime=0.0;
	mAggregateTime+=dt;

	if(mAggregateTime > 1.5f)
	{
		//addMonster();
		mAggregateTime=0.0f;
	}
}

void MonstersList::draw(sf::RenderWindow& window)
{
	for(auto it=mMonstersList.begin(); it != mMonstersList.end(); ++it)
	{
		window.draw(**it);
	}
}