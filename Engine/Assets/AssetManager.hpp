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

		// Load the Texture
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		// Load the Font
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	}; //class AssetManager
} // namespace Stha