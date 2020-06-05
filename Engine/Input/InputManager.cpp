#include "InputManager.hpp"

namespace Stha
{
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
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
	}

	// gets mouse position
	sf::Vector2i GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
} // namespace Stha