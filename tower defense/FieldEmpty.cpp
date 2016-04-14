#include "FieldEmpty.h"
#include "ResourceManager.h"
#include "global-information.h"

#include <random>

#include "FieldManager.h"

FieldEmpty::FieldEmpty(int x, int y):Field(x,y)
{
	init();
}

FieldEmpty::FieldEmpty(const sf::Vector2f& pos):Field(pos)
{
	init();
}

FieldEmpty::~FieldEmpty()
{
}

void FieldEmpty::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	Field::draw(target, states);
	if(mDrawFrame)
	{
		target.draw(mFrame, states);
	}
}


void FieldEmpty::init()
{
	mType=FieldType::FIELD_EMPTY;
	mFieldSprite.setTexture(ResourceManager::getTexture(ResourceManager::FIELD_EMPTY));
	
	sf::IntRect subTexture(0, 0, gi::FIELD_WIDTH, gi::FIELD_HEIGHT);

	int howManySubTextures = mFieldSprite.getTexture()->getSize().y / gi::FIELD_HEIGHT;

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(0, howManySubTextures - 1);

	subTexture.top = distribution(generator) * gi::FIELD_HEIGHT;

	mFieldSprite.setTextureRect(subTexture);

	mDrawFrame = false;
	mFrame.setSize(sf::Vector2f(gi::FIELD_WIDTH - 2.f, gi::FIELD_HEIGHT - 2.f));
	mFrame.setPosition(getPosition().x - 1.f, getPosition().y - 1.f);

	mFrame.setFillColor(sf::Color::Transparent);
	mFrame.setOutlineColor(sf::Color::White);
	mFrame.setOutlineThickness(1.f);
}

void FieldEmpty::update(const sf::RenderWindow& window, float dt)
{
	sf::Vector2f mousePos(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

	if(mFieldSprite.getGlobalBounds().contains(mousePos))
	{
		mDrawFrame = true;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		{
			FieldManager::getInstance().setFieldToChange(FieldType::FIELD_WALL, getPosition());
		}
	}
	else
	{
		mDrawFrame = false;
	}
}