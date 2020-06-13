#ifndef SplashState_hpp
#define SplashState_hpp

// #pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/StateMachine/State.hpp"
#include "../Engine/Game/Game.hpp"

namespace Stha
{
	class SplashState : public State
	{
	public:
		// reference to game data pointer
		SplashState(GameDataRef data);

		// Initialize Splash state
		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	}; //class  SplashState
} // namespace Stha

#endif