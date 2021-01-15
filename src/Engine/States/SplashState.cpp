#pragma once

#include <iostream>
#include <sstream>

#include "../../DEFINITIONS.hpp"
#include "SplashState.hpp"
#include "MainMenuState.hpp"

namespace Stha
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{
	}

	void SplashState::Init()
	{
		// loading data asset
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

		// settiung background sprite
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		// sysytem event object
		sf::Event event;

		// Only one input during this state- close window. thus checking event through comkparision
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close(); //closing the window
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_TIMEOUT)
		{
			// Switch to Main Menu
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		//clear screen every frame, here it clears to certain color- red
		this->_data->window.clear(sf::Color::Red);

		//after clearing it draws a texture
		this->_data->window.draw(this->_background);

		// sets the draw to window
		this->_data->window.display();
	}
} // namespace Stha
