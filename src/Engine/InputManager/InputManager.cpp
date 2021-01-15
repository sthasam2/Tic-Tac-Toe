#pragma once

#include "InputManager.hpp"

namespace Stha
{
	/**
	 * Checks input on a sprite
	 * 
	 * @param object	- the sprite object
	 * @param button	- Mouse input button click event
	 * @param window	- the app window instance
	 */
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		// checks input
		if (sf::Mouse::isButtonPressed(button))
		{
			// gets position of click (x,y, rectangleWidth, rectangleHeight)
			sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			//checks collision by comparing clicks
			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}

	// gets mouse position
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
} // namespace Stha