#include "player.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player() :
_mainSprite(sf::seconds(0.09), false, true),
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
		IntRect(276,0,46,50)
	},
_attackingRects {
	IntRect(92,0,46,50),
	IntRect(138,0,46,50),
	IntRect(184,0,46,50),
	IntRect(230,0,46,50)
},
_direction(true)
{
	this->_texture = make_shared<Texture>();

	if(!(this->_texture->loadFromFile("sprites/player.png"))) {
		if(this->getDebugging())
			cout << "Could not load player texture..." << endl;
	}
	else {
		if(this->getDebugging())
			cout << "Player texture loaded." << endl;

		this->_idleAnimation.setSpriteSheet(*(this->_texture));
		this->_idleAnimation.addFrame(IntRect(0,0,46,50));

		this->_runningAnimation.setSpriteSheet(*(this->_texture));
		for(auto rect : this->_runningRects)
			this->_runningAnimation.addFrame(rect);

		this->_jumpingAnimation.setSpriteSheet(*(this->_texture));
		for(auto rect : this->_jumpingRects)
			this->_jumpingAnimation.addFrame(rect);

		this->_attackingAnimation.setSpriteSheet(*(this->_texture));
		for(auto rect : this->_attackingRects)
			this->_attackingAnimation.addFrame(rect);

		this->_crouchingAnimation.setSpriteSheet(*(this->_texture));
		this->_crouchingAnimation.addFrame(IntRect(46,0,46,50));

		this->_currentAnimation = &this->_idleAnimation;

		this->_mainSprite.setPosition(sf::Vector2f(WINDOW_WIDTH/2,GROUND_LEVEL));
		this->_mainSprite.play(*(this->_currentAnimation));
	}
}

void Player::update(RenderWindow * window, sf::Time clock) {
	sf::Vector2u windowSize = window->getSize();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !(this->isAttacking())) { //Attacking
		this->_currentAnimation = &this->_attackingAnimation;
		this->_mainSprite.setLooped(false);
		this->_mainSprite.play(*(this->_currentAnimation));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !(this->isAttacking())) { //Running left
		if(this->_direction) {
			this->flipSprite();
		}

		if(!(this->isRunning())) {
			this->_currentAnimation = &this->_runningAnimation;
			this->_mainSprite.play(*(this->_currentAnimation));
		}

		Vector2f position = this->_mainSprite.getPosition();

		if(position.x > 23)
			this->_mainSprite.setPosition(Vector2f(position.x-VELOCITY_X*windowSize.x, position.y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !(this->isAttacking())) { //Running right
		if(!this->_direction) {
			this->flipSprite();
		}

		if(!(this->isRunning())) {
			this->_currentAnimation = &this->_runningAnimation;
			this->_mainSprite.play(*(this->_currentAnimation));
		}

		Vector2f position = this->_mainSprite.getPosition();

		if(position.x < (WINDOW_WIDTH - 23))
			this->_mainSprite.setPosition(Vector2f(position.x+VELOCITY_X*windowSize.x, position.y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !(this->isJumping() || this->isAttacking())) { //Crouch
		this->_currentAnimation = &this->_crouchingAnimation;
		this->_mainSprite.play(*(this->_currentAnimation));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Jump
		if(!(this->isJumping())) {
			this->_currentAnimation = &this->_jumpingAnimation;
			this->_mainSprite.play(*(this->_currentAnimation));
			this->_mainSprite.setLooped(false);
		}
	}
	else { //Standing still
		if(this->isRunning() || this->isJumping() || this->isCrouching() || 
			(this->isAttacking() && !this->_mainSprite.isPlaying())) {
			this->_currentAnimation = &this->_idleAnimation;
			this->_mainSprite.play(*(this->_currentAnimation));
			this->_mainSprite.setLooped(true);
		}
	}

	this->GameObject::update(window, clock);

	this->_mainSprite.update(clock);
	window->draw(this->_mainSprite);
}

const bool Player::isJumping() const {
	return (this->_currentAnimation == (&this->_jumpingAnimation));
}

const bool Player::isRunning() const {
	return (this->_currentAnimation == (&this->_runningAnimation));
}

const bool Player::isAttacking() const {
	return (this->_currentAnimation == (&this->_attackingAnimation));
}

const bool Player::isCrouching() const {
	return (this->_currentAnimation == (&this->_crouchingAnimation));
}

void Player::flipSprite() {
	Vector2f currentScale = this->_mainSprite.getScale();
	Vector2f currentPosition = this->_mainSprite.getPosition();
	this->_mainSprite.setScale(currentScale.x*-1,1);
	this->_direction = !this->_direction;
	this->_mainSprite.setPosition(currentPosition.x+46*(this->_direction ? -1:1), currentPosition.y);
}