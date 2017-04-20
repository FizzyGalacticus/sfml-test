#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

#include "constants.h"
#include "gameobject.h"
#include "background.h"
#include "player.h"
#include "soundhandler.h"

#include <iostream>
using std::cout;
using std::endl;

#include <Thor/Animations.hpp>

#include <string>
using std::string;

int main(int argc, char const *argv[])
{
	if(GameObject::getDebugging())
		cout << "Debugging mode on" << endl;
	else
		cout << "Debugging mode off" << endl;

	sf::RenderWindow renderWindow(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "SFML Test");
	sf::Event event;
	sf::Color color(sf::Color::Red);

	Background gameBackground;
	Player player;
	SoundHandler sound;

	sf::Clock clock;

	srand(time(NULL));

	std::uniform_int_distribution<int> randomColorRange(0,255);
	std::random_device rd;
	std::mt19937 randomNumbers(rd());

	/**************************************/
	// sf::IntRect rect1(0,150,46,50);
	// sf::IntRect rect2(46,150,46,50);
	// sf::IntRect rect3(92,150,46,50);
	// sf::IntRect rect4(138,150,46,50);
	// sf::IntRect rect5(184,150,46,50);
	// sf::IntRect rect6(230,150,46,50);
	// sf::IntRect rect7(276,150,46,50);
	// sf::IntRect rect8(322,150,46,50);

	// thor::FrameAnimation runAnimation;
	// runAnimation.addFrame(1.f, rect1);
	// runAnimation.addFrame(1.f, rect2);
	// runAnimation.addFrame(1.f, rect3);
	// runAnimation.addFrame(1.f, rect4);
	// runAnimation.addFrame(1.f, rect5);
	// runAnimation.addFrame(1.f, rect6);
	// runAnimation.addFrame(1.f, rect7);
	// runAnimation.addFrame(1.f, rect8);

	// sf::Sprite runSprite;
	// float progress = 0.f;
	// runAnimation(runSprite, progress);

	// thor::Animator<sf::Sprite, std::string> animator;
	// animator.addAnimation("run", runSprite, sf::seconds(1.f));
	/**************************************/

	renderWindow.setMouseCursorVisible(false);

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

		sf::Time deltaTime = clock.restart();
		renderWindow.clear(color);
		GameObject::updateAll(&renderWindow, deltaTime);
		renderWindow.display();
	}

	return 0;
}