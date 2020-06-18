#pragma once

#include <iostream>
#include <sstream>

#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "../../DEFINITIONS.hpp"

namespace Stha
{
	/**
	 * Game Over State constructor with reference to gamedata ptr
	 */
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	/**
	 * Ininitializer
	 */
	void GameOverState::Init()
	{
		// Loading Assets
		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		// Setting Assets
		this->_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		// Positioning Assets

		// Position Coordinates
		// Resume Button
		float retryX = ((this->_data->window.getSize().x / 2) - (this->_retryButton.getLocalBounds().width / 2));
		float retryY = ((this->_data->window.getSize().y / 3) - (this->_retryButton.getLocalBounds().height / 2));
		// HOME BUTTON
		float homeX = ((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2));
		float homeY = ((this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));

		// Setting Coordinates for Positioning
		this->_retryButton.setPosition(retryX, retryY);
		this->_homeButton.setPosition(homeX, homeY);
	}

	/**
	 * Handle Input
	 */
	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			// Close window
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// Resume Button
			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch to Game Screen after removing pause state screen by popping top state
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);

				// this way it returns to the second to the top state ie the previous game state
			}

			// Resume Button
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				// Remove pause state screen by popping top state
				this->_data->machine.RemoveState();

				// Switch to Main Menu Screen byb replacing penultimate Game Screen
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	/**
	 * Update variable
	 * 
	 * @param dt - updater delta
	 */
	void GameOverState::Update(float dt)
	{
		//No update since it is single state
	}

	/**
	 * Draw all assets and states on screen
	 * 
	 * @param : float dt
	*/
	void GameOverState::Draw(float dt)
	{
		// clear existing window
		this->_data->window.clear(sf::Color::Black);

		// Draw assets on window
		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_homeButton);

		//display
		this->_data->window.display();
	}
} // namespace Stha