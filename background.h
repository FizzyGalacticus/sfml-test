#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include "gameobject.h"

#include "AnimatedSprite.hpp"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::IntRect;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

class Background : public GameObject {
	public:
		Background();
		void update(RenderWindow * window, sf::Time clock);

	private:
		shared_ptr<Texture> _texture;
		shared_ptr<Sprite> _mainSprite;
		AnimatedSprite _animatedWaterSprite;
		Animation _waterAnimation;
		vector<IntRect> _waterRects;
};

#endif