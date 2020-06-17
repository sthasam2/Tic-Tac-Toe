#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(360, 480), "SFML Check");
	while (window.isOpen())
	{
		sf::Event event;

		// sf::CircleShape shape(window.getSize().x / 2);
		// shape.setFillColor(sf::Color::White);

		sf::Sprite shape;

		sf::Texture texture;
		if (!texture.loadFromFile("./sfmlCheck.png"))
		{
			std::cout << "ERROR\n";
		}
		else
		{
			texture.loadFromFile("./sfmlCheck.png");
			texture.setSmooth(true);
			shape.setTexture(texture);
		}

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	// return EXIT_SUCCESS;
}