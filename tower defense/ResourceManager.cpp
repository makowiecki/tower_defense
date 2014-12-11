#include "ResourceManager.h"

#include <unordered_map>
using namespace std;

#include <cstdlib>	// only for exit() function
#include <conio.h>	// only for _getch() function


namespace // global variables definition
{
	std::string RESOURCE_DIRECTORY="Resources/";
}

/////////////////////////////////////////////////////////////////////////////
//	Class definition, to add new resource modyfy defoult constructor.
/////////////////////////////////////////////////////////////////////////////
namespace
{
#ifndef RESOURCE_KEEPER_CLASS
#define RESOURCE_KEEPER_CLASS

	class ResourceKeeper
	{
	private:

		static ResourceKeeper mKeeper;

		unordered_map<ResourceManager::Textures, sf::Texture> mTexturesMap;
		unordered_map<ResourceManager::Fonts, sf::Font> mFontsMap;

		ResourceKeeper();
		~ResourceKeeper() {};

		ResourceKeeper(const ResourceKeeper&);				// undefined
		ResourceKeeper& operator=(const ResourceKeeper&);	// undefined	

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
		if(!mTexturesMap[ResourceManager::FIELD_WALL].loadFromFile(RESOURCE_DIRECTORY + "Images/field-wall.png")) { _getch(); exit(-1); }
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
		auto it=GLOBAL_RESOURCE_KEEPER.mTexturesMap.begin();

		while(it->first != texture)
		{
			++it;
		}

		return it->second;
	}

	sf::Font& getFont(Fonts font)
	{
		auto it=GLOBAL_RESOURCE_KEEPER.mFontsMap.begin();

		while(it->first != font)
		{
			++it;
		}

		return it->second;
	}
} // namespace ResourceManager