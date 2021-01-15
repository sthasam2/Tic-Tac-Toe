#pragma once

#include <iostream>
#include <sstream>

#include "PauseState.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "../../DEFINITIONS.hpp"

namespace Stha
{
	/**
	 * Pause State constructor with reference to gamedata ptr
	 */
	PauseState::PauseState(GameDataRef data) : _data(data)
	{
	}

	/**
	 * Ininitializer
	 */
	void PauseState::Init()
	{
		// Loading Assets
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		// Setting Assets
		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		// Positioning Assets

		// Position Coordinates
		// Resume Button
		float resumeX = ((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2));
		float resumeY = ((this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		// HOME BUTTON
		float homeX = ((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2));
		float homeY = ((this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));

		// Setting Coordinates for Positioning
		this->_resumeButton.setPosition(resumeX, resumeY);
		this->_homeButton.setPosition(homeX, homeY);
	}

	/**
	 * Handle Input
	 */
	void PauseState::HandleInput()
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
			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch to Game Screen after removing pause state screen by popping top state
				this->_data->machine.RemoveState();

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
	void PauseState::Update(float dt)
	{
		//No update since it is single state
	}

	/**
	 * Draw all assets and states on screen
	 * 
	 * @param : float dt
	*/
	void PauseState::Draw(float dt)
	{
		// clear existing window
		this->_data->window.clear(sf::Color::Green);

		// Draw assets on window
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		//display
		this->_data->window.display();
	}
} // namespace Stha