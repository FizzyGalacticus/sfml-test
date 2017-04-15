#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "constants.h"
#include "drawable.h"

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

class Player : public Drawable {
	public:
		Player();
		void update(RenderWindow * window, const uint64_t & milliseconds);
		
	private:
		shared_ptr<Texture> _texture;
		shared_ptr<Sprite> _mainSprite;
		vector<IntRect> _runningRects;
		vector<IntRect> _jumpingRects;
		unsigned int _runningIndex;
		unsigned int _jumpingIndex;
		bool _jumping;
		bool _running;
		bool _stopping;
};

#endif