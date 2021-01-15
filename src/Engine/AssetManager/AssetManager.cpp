#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

namespace Stha
{
	// TEXTURES

	/**
	 * Function for managing Assets - Textures
	 * 
	 * @param name 		- string to denote the name of the asset
	 * @param fileName 	string to denote the file name including the location of said file
    */
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	/**
	 * Function to get texture asset
	 * 
	 * @param name - name of the texture asset
	 * @return _textures.at(name) - the texture asset of name
	 */
	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	// FONTS

	/**
	 * Function for managing Assets - Fonts
	 * 


	 * @param name - string to denote the name of the asset
	 * @param fileName string to denote the file name including the location of said file
    */
	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	/**
	 * Function to get texture asset
	 * 
	 * @param name - name of the texture asset
	 * @return _fonts.at(name) - the font with param 'name'
	 */
	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
} // namespace Stha