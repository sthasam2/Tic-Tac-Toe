#pragma once

#include <iostream>
#include <sstream>

#include "MainMenuState.hpp"
#include "../../DEFINITIONS.hpp"

namespace Stha
{
	/**
	 * Main Menu State constructor with reference to gamedata ptr
	 */
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	/**
	 * Ininitializer
	 */
	void MainMenuState::Init()
	{
		// Loading Assets
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		// Setting Assets
		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		// Positioning Assets

		// Position Coordinates
		// Play Button
		float playX = ((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2));
		float playY = ((SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));
		// Play Button Outer
		float playOuterX = ((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2));
		float playOuterY = ((SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));
		// Title
		float titleX = ((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2));
		float titleY = (this->_title.getGlobalBounds().height * 0.1);

		// Setting Coordinates for Positioning
		this->_playButton.setPosition(playX, playY);
		this->_playButtonOuter.setPosition(playOuterX, playOuterY);
		this->_title.setPosition(titleX, titleY);
	}

	/**
	 * Handle Input
	 */
	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			// Close window
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// Play Button
			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				//Game Screen
				std::cout << "Go to Game Screen\n";
			}
		}
	}

	/**
	 * Update variable
	 * 
	 * @param dt - updater delta
	 */
	void MainMenuState::Update(float dt)
	{
		//No update since it is single state
	}

	/**
		 * Draw all assets and states on screen
		 * 
		 * @param : float dt
		*/
	void MainMenuState::Draw(float dt)
	{
		// clear existing window
		this->_data->window.clear(sf::Color::Cyan);

		// Draw assets on window
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_playButtonOuter);
		this->_data->window.draw(this->_title);

		//display
		this->_data->window.display();
	}
} // namespace Stha