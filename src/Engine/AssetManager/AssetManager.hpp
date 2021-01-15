#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Stha
{
	class AssetManager
	{
	public:
		AssetManager() {}  //constructor
		~AssetManager() {} //destructor

		void LoadTexture(std::string name, std::string fileName); // Load the Texture
		sf::Texture &GetTexture(std::string name);				  // Get the texture

		void LoadFont(std::string name, std::string fileName); // Load the Font
		sf::Font &GetFont(std::string name);				   // Get the Font

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	}; //class AssetManager
} // namespace Stha