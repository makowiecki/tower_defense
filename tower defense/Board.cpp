#include "Board.h"

Board::Board(int width, int height, int fieldWidth, int fieldHeight):mFieldManager(FieldManager::getInstance())
{
	mBoard.reserve(width);

	for(int i=0; i < width; ++i)
	{
		mBoard.push_back(std::vector<FiledPtr>(height));
	}

	for(int i=0; i < width; ++i)
	{
		for(int j=0; j < height; ++j)
		{
			if(i == 0 && j == height / 2)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_ENTER, i*fieldWidth, j*fieldHeight);
				mEnterFieldPosition=mBoard[i][j]->getPosition();
			}
			else if(i == width - 1 && j == height / 2)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_EXIT, i*fieldWidth, j*fieldHeight);
				mExitFieldPosition=mBoard[i][j]->getPosition();
			}
			else if(i == 0 || i == width - 1)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_WALL, i*fieldWidth, j*fieldHeight);
			}
			else if(j == 0 || j == height - 1)
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_WALL, i*fieldWidth, j*fieldHeight);
			}
			else
			{
				mBoard[i][j]=mFieldManager.createField(FieldType::FIELD_EMPTY, i*fieldWidth, j*fieldHeight);
			}
		}
	}
}

Board::~Board()
{
}

int Board::getWidth()const
{
	return mBoard.size();
}

int Board::getHeight()const
{
	return mBoard[0].size();
}

sf::Vector2i Board::getSize()const
{
	return sf::Vector2i(getHeight(), getWidth());
}

sf::Vector2f Board::getEnterFieldPosition()const
{
	return mEnterFieldPosition;
}

sf::Vector2f Board::getExitFieldPosition()const
{
	return mExitFieldPosition;
}

void Board::addGlobalStep(const sf::Vector2i& step)
{
	mGlobalStepsList.push(sf::Vector2i(step));
}

void Board::emptyGlobalStepsList()
{
	while(!mGlobalStepsList.empty())
	{
		mGlobalStepsList.pop();
	}
}

FieldType Board::getFieldType(unsigned int pX, unsigned int pY)const
{
	if((pX >= 0 || pX <= mBoard.size()) && (pY >= 0 || pY <= mBoard[0].size()))
	{
		return mBoard[pX][pY]->getFieldType();
	}
	return FieldType::FIELD_NONE;
}

void Board::changeChosenField()
{
	mFieldManager.changeField(mBoard[mFieldManager.getChosenFieldPosition().x][mFieldManager.getChosenFieldPosition().y]);
}

void Board::updateAll(const sf::RenderWindow& window, float dt, MonstersList& monstersList)
{
	for_each(mBoard.begin(), mBoard.end(), [&window, dt](const vector<FiledPtr>& row)
	{
		for_each(row.begin(), row.end(), [&window, dt](const FiledPtr& ptr){ ptr->update(window, dt); });
	});

	//TMP:
	if(/*monsterManager.issettoadd()*/true)
	{
		static bool raz = true;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			if(raz)
			{
				monstersList.addMonster(mGlobalStepsList);
				raz = false;
			}
		}
		else
		{
			raz = true;
		}
	}
	//END_OF_TMP
}

void Board::drawAll(sf::RenderWindow& window)
{
	for_each(mBoard.begin(), mBoard.end(), [&window](const vector<FiledPtr>& row)
	{
		for_each(row.begin(), row.end(), [&window](const FiledPtr& ptr){ window.draw(*ptr); });
	});
}