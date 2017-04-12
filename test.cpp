#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

#include "gameobject.h"
#include "background.h"

int main(int argc, char const *argv[])
{
	sf::RenderWindow renderWindow(sf::VideoMode(464,224), "SFML Demo");
	sf::Event event;
	sf::Color color(sf::Color::Red);

	sf::Texture backgroundTexture;
	if(!backgroundTexture.loadFromFile("sprites/background.png"));

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect(sf::IntRect(2,3,464,224));

	std::vector<sf::IntRect> waterRects = {
		sf::IntRect(2,247,464,60),
		sf::IntRect(469,247,464,60),
		sf::IntRect(936,247,464,60),
		sf::IntRect(1403,247,464,60),
		sf::IntRect(1870,247,464,60),
		sf::IntRect(2337,247,464,60),
		sf::IntRect(2804,247,464,60),
		sf::IntRect(3271,247,464,60)
	};

	unsigned int waterIndex = 0;

	sf::Sprite backgroundWaterSprite;
	backgroundWaterSprite.setTexture(backgroundTexture);
	backgroundWaterSprite.setTextureRect(waterRects[waterIndex]);
	backgroundWaterSprite.setPosition(sf::Vector2f(0,164));

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

		// if(clock.getElapsedTime().asMicroseconds() % 100000 == 0) {

		// }

		if(clock.getElapsedTime().asMicroseconds() > 60000) {
			// if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			// 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
			// 		sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
			// 		color.r = 0;
			// }
			// else color.r = (color.r+randomColorRange(randomNumbers) % 255);//randomColorRange(randomNumbers);

			// if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			// 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
			// 		sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
			// 		color.g = 0;
			// }
			// else color.g = (color.g+randomColorRange(randomNumbers) % 255);//randomColorRange(randomNumbers);

			// if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			// 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
			// 		sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
			// 		color.b = 0;
			// }
			// else color.b = (color.b+randomColorRange(randomNumbers) % 255);//randomColorRange(randomNumbers);

			waterIndex = (waterIndex < waterRects.size()-1 ? waterIndex+1:0);
			backgroundWaterSprite.setTextureRect(waterRects[waterIndex]);

			clock.restart();
		}

		renderWindow.clear(color);
		renderWindow.draw(backgroundSprite);
		renderWindow.draw(backgroundWaterSprite);
		renderWindow.display();

	}

	return 0;
}