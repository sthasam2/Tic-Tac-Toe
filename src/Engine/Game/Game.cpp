#include "Game.hpp"
#include "../States/SplashState.hpp"

namespace Stha
{
	/**
	 * App window manager
	 * 
	 * @param width 	- the width of app window
	 * @param height 	- the height of app window
	 * @param title 	- the text shown in title bar of app window
	 */
	Game::Game(int width, int height, std::string title)
	{
		// create window instance using sfml
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		// First State - Splash Screen
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		// App runtime manager
		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
} // namespace Stha