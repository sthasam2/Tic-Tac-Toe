#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../StateMachine/StateMachine.hpp"
#include "../AssetManager/AssetManager.hpp"
#include "../InputManager/InputManager.hpp"

namespace Stha
{
	//Custom Game object datatype
	struct GameData
	{
		// state manager
		StateMachine machine;
		// window object
		sf::RenderWindow window;
		// assets object
		AssetManager assets;
		// input object
		InputManager input;
	};

	//  Custom typedef for Game datatype
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		// Game Window init
		Game(int width, int height, std::string title);

	private:
		// Delta Time: Frame Rate Updater capped @60hz
		const float dt = 1.0f / 60.0f;

		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};

} // namespace Stha

// #endif