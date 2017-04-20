#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "constants.h"

#include "gameobject.h"

#include "AnimatedSprite.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::IntRect;
using sf::Vector2f;

#include <vector>
using std::vector;

class Player : public GameObject {
	public:
		Player();
		void update(RenderWindow * window, sf::Time clock);
		const bool isJumping() const;
		const bool isRunning() const;
		const bool isAttacking() const;
		const bool isCrouching() const;
		
	private:
		void flipSprite();

		shared_ptr<Texture> _texture;
		AnimatedSprite _mainSprite;
		const vector<IntRect> _runningRects;
		const vector<IntRect> _jumpingRects;
		const vector<IntRect> _attackingRects;
		Animation _idleAnimation;
		Animation _runningAnimation;
		Animation _jumpingAnimation;
		Animation _attackingAnimation;
		Animation _crouchingAnimation;
		Animation * _currentAnimation;
		bool _direction;
};

#endif