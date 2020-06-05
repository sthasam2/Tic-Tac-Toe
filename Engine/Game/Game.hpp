#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Assets/AssetManager.hpp"
#include "../Input/InputManager.hpp"
#include "../State/StateMachine.hpp"

namespace Stha
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		// Frame Rate Update 60hz
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};

} // namespace Stha
