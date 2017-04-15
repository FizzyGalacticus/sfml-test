#include "player.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player() :
_runningRects{
		IntRect(0,150,46,50),
		IntRect(46,150,46,50),
		IntRect(92,150,46,50),
		IntRect(138,150,46,50),
		IntRect(184,150,46,50),
		IntRect(230,150,46,50),
		IntRect(276,150,46,50),
		IntRect(322,150,46,50)
	},
_jumpingRects{
		IntRect(322,0,46,50),
		IntRect(276,0,46,50)
	},
_runningIndex(0),
_jumpingIndex(0),
_jumping(false),
_running(false),
_stopping(false)
{
	this->_texture = make_shared<Texture>();
	this->_mainSprite = make_shared<Sprite>();

	if(!(this->_texture->loadFromFile("sprites/player.png"))) {
		if(this->getDebugging())
			cout << "Could not load player texture..." << endl;
	}
	else {
		if(this->getDebugging())
			cout << "Player texture loaded." << endl;

		this->_mainSprite->setTexture(*(this->_texture));
		this->_mainSprite->setTextureRect(IntRect(0,0,46,50));
		this->_mainSprite->setPosition(Vector2f(200,GROUND_LEVEL));
		this->_mainSprite->setOrigin(23,0);
	}
}

void Player::update(RenderWindow * window, const uint64_t & milliseconds) {
	if(this->getTimeSinceLastUpdate(milliseconds) > 55) {
		sf::Vector2u windowSize = window->getSize();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->_jumping) { //Walking left
			
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !this->_jumping) { //Walking right
			
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Crouch
			
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->_jumping) { //Jump
			
		}
		else { //Standing still
			
		}

		this->setLastUpdate(milliseconds);
	}

	window->draw(*(this->_mainSprite));
}
