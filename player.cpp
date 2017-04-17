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
_direction(true)
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
	this->step();
	b2Body * body   = this->getBody();
	b2Vec2 position = body->GetPosition();

	this->_mainSprite->setPosition(Vector2f(position.x*M2P, position.y*M2P));
	this->_mainSprite->setRotation(body->GetAngle()*R2D);

	if(this->getTimeSinceLastUpdate(milliseconds) > 55) {
		sf::Vector2u windowSize = window->getSize();

		if(this->_running) {
			this->_runningIndex = (this->_runningIndex < this->_runningRects.size()-1 ? this->_runningIndex+1:0);
			this->_mainSprite->setTextureRect(this->_runningRects[this->_runningIndex]);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->_running) { //Running left
			if(this->_direction) {
				this->_mainSprite->setScale(-1,1);
				this->_direction = false;
			}
			this->_running = true;
			body->SetTransform(b2Vec2(position.x-(7.0*P2M),position.y), body->GetAngle());
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !this->_running) { //Running right
			if(!this->_direction) {
				this->_mainSprite->setScale(1,1);
				this->_direction = true;
			}
			this->_running = true;
			body->SetTransform(b2Vec2(position.x+(7.0*P2M),position.y), body->GetAngle());
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !this->_jumping) { //Crouch
			this->_mainSprite->setTextureRect(IntRect(46,0,46,50));
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->_jumping) { //Jump
			body->ApplyForce(b2Vec2(0,60000.0f), body->GetWorldCenter(), true);
		}
		else { //Standing still
			if(this->_running) {
				this->_running = false;
				body->SetLinearVelocity(b2Vec2(0,0));
			}
			else 
				this->_mainSprite->setTextureRect(IntRect(0,0,46,50));
		}

		this->setLastUpdate(milliseconds);
	}

	window->draw(*(this->_mainSprite));
}
