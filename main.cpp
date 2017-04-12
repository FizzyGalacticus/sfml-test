#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

#include "gameobject.h"
#include "background.h"
#include "player.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	if(GameObject::getDebugging())
		cout << "Debugging mode on" << endl;
	else
		cout << "Debugging mode off" << endl;

	sf::RenderWindow renderWindow(sf::VideoMode(464,224), "SFML Test");
	sf::Event event;
	sf::Color color(sf::Color::Red);

	Background gameBackground;
	Player player;

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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
				renderWindow.close();
		}

		renderWindow.clear(color);
		GameObject::updateAll(&renderWindow, clock.getElapsedTime().asMilliseconds());
		renderWindow.display();

	}

	return 0;
}