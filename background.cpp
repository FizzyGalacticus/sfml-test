#include "background.h"

#include <iostream>
using std::cout;
using std::endl;

Background::Background() :
_animatedWaterSprite(sf::seconds(0.09), false, true),
_waterRects{
		IntRect(2,247,464,60),
		IntRect(469,247,464,60),
		IntRect(936,247,464,60),
		IntRect(1403,247,464,60),
		IntRect(1870,247,464,60),
		IntRect(2337,247,464,60),
		IntRect(2804,247,464,60),
		IntRect(3271,247,464,60)
	}
{
	this->_texture = make_shared<Texture>();
	this->_mainSprite = make_shared<Sprite>();

	if(!(this->_texture->loadFromFile("sprites/background.png"))) {
		if(this->getDebugging())
			cout << "Could not load background texture..." << endl;
	}
	else {
		if(this->getDebugging())
			cout << "Background texture loaded." << endl;

		this->_mainSprite->setTexture(*(this->_texture));
		this->_mainSprite->setTextureRect(IntRect(2,3,464,224));

		this->_waterAnimation.setSpriteSheet(*(this->_texture));

		for(auto rect : this->_waterRects)
			this->_waterAnimation.addFrame(rect);

		this->_animatedWaterSprite.setPosition(sf::Vector2f(0,164));
		this->_animatedWaterSprite.play(this->_waterAnimation);
	}
}

void Background::update(RenderWindow * window, sf::Time clock) {
	this->_animatedWaterSprite.update(clock);
	window->draw(*(this->_mainSprite));
	window->draw(this->_animatedWaterSprite);
}