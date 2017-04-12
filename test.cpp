#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main(int argc, char const *argv[])
{
	sf::RenderWindow renderWindow(sf::VideoMode(640,480), "SFML Demo");
	sf::Event event;
	sf::Color color(sf::Color::Red);

	sf::Clock clock;

	srand(time(NULL));

	std::uniform_int_distribution<int> randomColorRange(0,255);
	std::random_device rd;
	std::mt19937 randomNumbers(rd());

	while(renderWindow.isOpen()) {
		while(renderWindow.pollEvent(event)) {
			if(event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
				color.r = 0;
		}
		else color.r = randomColorRange(randomNumbers);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
				color.g = 0;
		}
		else color.g = randomColorRange(randomNumbers);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
				color.b = 0;
		}
		else color.b = randomColorRange(randomNumbers);

		std::cout << "Elapsed time in microsecodns:" << clock.getElapsedTime().asMicroseconds() << std::endl;
		clock.restart();

		renderWindow.clear(color);
		renderWindow.display();

	}

	return 0;
}