#include "ResourceManager.h"

#include <map>
using namespace std;

#include <cstdlib>	// only for exit() function
#include <conio.h>	// only for _getch() function


namespace // global variables definition
{
	std::string RESOURCE_DIRECTORY="Resources/";
}

/////////////////////////////////////////////////////////////////////////////
//	Class definition, to add new resource modyfy default constructor.
/////////////////////////////////////////////////////////////////////////////
namespace
{
#ifndef RESOURCE_KEEPER_CLASS
#define RESOURCE_KEEPER_CLASS

	class ResourceKeeper
	{
	private:

		static ResourceKeeper mKeeper;

		map<ResourceManager::Textures, sf::Texture> mTexturesMap;
		map<ResourceManager::Fonts, sf::Font> mFontsMap;

		ResourceKeeper();
		~ResourceKeeper() {};

		ResourceKeeper(const ResourceKeeper&)=delete;
		ResourceKeeper& operator=(const ResourceKeeper&)=delete;

	public:

		static ResourceKeeper& getInstance();

		friend sf::Texture& ResourceManager::getTexture(ResourceManager::Textures texture);
		friend sf::Font& ResourceManager::getFont(ResourceManager::Fonts font);
	};
#endif

	ResourceKeeper::ResourceKeeper()
	{
		if(!mTexturesMap[ResourceManager::FIELD_ENTER].loadFromFile(RESOURCE_DIRECTORY + "Images/field-enter.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_EXIT].loadFromFile(RESOURCE_DIRECTORY + "Images/field-exit.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_EMPTY].loadFromFile(RESOURCE_DIRECTORY + "Images/field-empty.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_WALL_VERTICAL].loadFromFile(RESOURCE_DIRECTORY + "Images/field-wall-vertical.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_WALL_HORIZONTAL].loadFromFile(RESOURCE_DIRECTORY + "Images/field-wall-horizontal.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_WALL_CORNER].loadFromFile(RESOURCE_DIRECTORY + "Images/field-wall-corner.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::FIELD_WALL_MIDDLE].loadFromFile(RESOURCE_DIRECTORY + "Images/field-wall-middle.png")) { _getch(); exit(-1); }
		if(!mTexturesMap[ResourceManager::ENEMY_1].loadFromFile(RESOURCE_DIRECTORY + "Images/enemy1.png")) { _getch(); exit(-1); }


		if(!mFontsMap[ResourceManager::FONT_1].loadFromFile(RESOURCE_DIRECTORY + "Fonts/font1.otf")) { _getch(); exit(-1); }
	}

	ResourceKeeper& ResourceKeeper::getInstance()
	{
		return mKeeper;
	}

	ResourceKeeper ResourceKeeper::mKeeper;
}
/////////////////////////////////////////////////////////////////////////////
//	End of class definition.
/////////////////////////////////////////////////////////////////////////////

namespace // global variable
{
	ResourceKeeper& GLOBAL_RESOURCE_KEEPER=ResourceKeeper::getInstance();
}

namespace ResourceManager
{
	sf::Texture& getTexture(Textures texture)
	{
		return GLOBAL_RESOURCE_KEEPER.mTexturesMap.find(texture)->second; //must find becouse everything is added in ctor
	}

	sf::Font& getFont(Fonts font)
	{
		return GLOBAL_RESOURCE_KEEPER.mFontsMap.find(font)->second; //must find becouse everything is added in ctor
	}
} // namespace ResourceManager