#pragma once

#include <SFML/Graphics.hpp>
#include "../StateMachine/State.hpp"
#include "../Game/Game.hpp"

namespace Stha
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		// sf::Sprite _background;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;
	};
} // namespace Stha