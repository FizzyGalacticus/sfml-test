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

	},
_runningIndex(0),
_jumpingIndex(0),
_direction(0),
_jumping(false)
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

	this->setMaxAcceleration(0.1);
	this->setMaxVelocity(3);
}

void Player::update(RenderWindow * window, const uint64_t & milliseconds) {
	if(this->getTimeSinceLastUpdate(milliseconds) >= 40) {
		this->move(milliseconds);
	}

	if(this->getTimeSinceLastUpdate(milliseconds) > 55) {
		sf::Vector2u windowSize = window->getSize();

		const Vector2f & currentAcceleration = this->getAcceleration();
		const Vector2f & currentVelocity     = this->getVelocity();

		if(this->_position.y >= GROUND_LEVEL) {
			this->_position.y = GROUND_LEVEL;
			this->setAcceleration(currentAcceleration.x, 0);
			this->_jumping = false;
		}

		this->_mainSprite->setPosition(this->_position);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Walking left
			if(this->_direction != 1) {
				this->_mainSprite->scale(-1,1);
				this->_direction = 1;
			}

			this->_mainSprite->setTextureRect(this->_runningRects[this->_runningIndex]);
			this->_runningIndex = (this->_runningIndex < this->_runningRects.size()-1 ? this->_runningIndex+1:0);

			this->setAcceleration(-0.05f, currentAcceleration.y);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //Walking right
			if(this->_direction == 1) {
				this->_mainSprite->scale(-1,1);
				this->_direction = 0;
			}

			this->_mainSprite->setTextureRect(this->_runningRects[this->_runningIndex]);
			this->_runningIndex = (this->_runningIndex < this->_runningRects.size()-1 ? this->_runningIndex+1:0);

			this->setAcceleration(0.05f, currentAcceleration.y);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->_position.y == GROUND_LEVEL) { //Crouch
			this->_mainSprite->setTextureRect(IntRect(46,0,46,50));
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->_jumping) { //Jump
			this->setAcceleration(currentAcceleration.x, -0.05f);
			this->_jumping = true;
		}
		else {
			this->_runningIndex = 0;
			this->_jumpingIndex = 0;
			this->_mainSprite->setTextureRect(IntRect(0,0,46,50));
		}

		this->setLastUpdate(milliseconds);
	}

	window->draw(*(this->_mainSprite));
}
