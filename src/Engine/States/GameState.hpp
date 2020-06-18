#pragma once

#include <SFML/Graphics.hpp>
#include "../StateMachine/State.hpp"
#include "../Game/Game.hpp"

namespace Stha
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _pauseButton;

		int turn;
		int gameState;
	};
}