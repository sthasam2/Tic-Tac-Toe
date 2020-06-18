#pragma once

#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../../DEFINITIONS.hpp"

#include <iostream>

namespace Stha
{
	/**
	 *  GAMESTATE CONSTRUCTOR POINTS TO GAMEDATA OBJECT
	 */
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}

	/** 
	 * Initialize Game State
	 */
	void GameState::Init()
	{
		// GAME STATES - PLAYING
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		// LOADING TEXTURE
		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);

		// SETTING TEXTURES
		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

		// POSITIONING PAUSE BUTTON
		float pauseX = (this->_data->window.getSize().x - _pauseButton.getLocalBounds().width);
		float pauseY = _pauseButton.getPosition().y;

		_pauseButton.setPosition(pauseX, pauseY);
	}

	/**
	 *  Gamestate Input Handler
	 */
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			// CHECK WINDOW CLOSE EVENT
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// CHECK GAME PAUSE PRESS EVENT
			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				// PAUSE
				// this->_data->machine.AddState(StateRef(new PauseState(_data)), false); // false because we are only pausing so we need to return back on resume
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), false);
			}
		}
	}

	/**
	 * Update variable
	 * 
	 * @param dt - updater delta
	 */
	void GameState::Update(float dt)
	{
	}

	/**
	 * Draw all assets and states on screen
	 * 
	 * @param : float dt
	*/
	void GameState::Draw(float dt)
	{
		// CLEAR SCREEN
		this->_data->window.clear(sf::Color::Magenta);
		// DRAW
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pauseButton);
		// DISPLAY
		this->_data->window.display();
	}
} // namespace Stha