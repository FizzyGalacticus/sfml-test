#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include "gameobject.h"

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
		Background(shared_ptr<Texture> texture);
		~Background();
		void update(RenderWindow * window, const uint64_t & milliseconds);

	private:
		shared_ptr<Texture> _texture;
		shared_ptr<Sprite> _mainSprite;
		shared_ptr<Sprite> _waterSprite;
		vector<IntRect> _waterRects;
		unsigned int _waterIndex;
};

#endif