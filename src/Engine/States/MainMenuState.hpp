// #ifndef MainMenuState_hpp
// #define MainMenuState_hpp

#pragma once

#include <SFML/Graphics.hpp>
#include "../StateMachine/State.hpp"
#include "../Game/Game.hpp"

namespace Stha
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _playButton;

		sf::Sprite _playButtonOuter;

		sf::Sprite _title;
	};
} // namespace Stha

// #endif