#pragma once

#include <SFML\Graphics.hpp>

namespace ResourceManager
{
enum Textures { FIELD_ENTER, FIELD_EXIT, FIELD_EMPTY, FIELD_WALL_CORNER, FIELD_WALL_VERTICAL, FIELD_WALL_HORIZONTAL, FIELD_WALL_MIDDLE, ENEMY_1 };
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