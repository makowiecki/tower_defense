#pragma once

#include <SFML\Graphics.hpp>

namespace ResourceManager
{
	enum Textures { FIELD_EMPTY, FIELD_WALL, TEXTURES_NUMBER };
	enum Fonts { FONT_1, FONTS_NUMBER };

	////
	///	\brief Returns one of the chosen Texture
	///
	///	Typica use:
	///
	///	sf::Sprite.setTexture(ResourceManager::getTexture(ResourceManager::TEXTURE_1));
	///
	///	\return Reference to sf::Texture.
	////
	sf::Texture& getTexture(Textures texture);

	////
	///	\brief Returns one of the chosen Font.
	///
	///	Typica use:
	///
	///	sf::Text.setFont(ResourceManager::getFont(ResourceManager::FONT_1));
	///
	///	\return Reference to sf::Font.
	////
	sf::Font& getFont(Fonts font);
}