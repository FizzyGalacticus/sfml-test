#include "background.h"

#include <iostream>
using std::cout;
using std::endl;

Background::Background() :
_waterIndex(0)
{
	this->_texture = make_shared<Texture>();

	if(!this->_texture->loadFromFile("sprites/background.png"))
		cout << "Could not load background texture..." << endl;
	else
		cout << "Background texture loaded." << endl;

	this->_waterRects = {
		IntRect(2,247,464,60),
		IntRect(469,247,464,60),
		IntRect(936,247,464,60),
		IntRect(1403,247,464,60),
		IntRect(1870,247,464,60),
		IntRect(2337,247,464,60),
		IntRect(2804,247,464,60),
		IntRect(3271,247,464,60)
	};


	this->_mainSprite = make_shared<Sprite>();
	this->_waterSprite = make_shared<Sprite>();

	this->_waterSprite->setTexture(*(this->_texture));
	this->_waterSprite->setTextureRect((this->_waterRects[this->_waterIndex]));
	this->_waterSprite->setPosition(sf::Vector2f(0,164));
}

Background::Background(shared_ptr<Texture> texture) : 
_texture(texture),
_waterRects{
		IntRect(2,247,464,60),
		IntRect(469,247,464,60),
		IntRect(936,247,464,60),
		IntRect(1403,247,464,60),
		IntRect(1870,247,464,60),
		IntRect(2337,247,464,60),
		IntRect(2804,247,464,60),
		IntRect(3271,247,464,60)
	},
_waterIndex(0)
{
	this->_mainSprite = make_shared<Sprite>();
	this->_waterSprite = make_shared<Sprite>();

	this->_waterSprite->setTexture(*(this->_texture));
	this->_waterSprite->setTextureRect((this->_waterRects[this->_waterIndex]));
	this->_waterSprite->setPosition(sf::Vector2f(0,164));
}

Background::~Background() {

}

void Background::update(RenderWindow & window, const uint64_t & milliseconds) {
	// if(this->getTimeSinceLastUpdate(milliseconds) > 2) {
	// 	this->_waterIndex = (this->_waterIndex < this->_waterRects.size()-1 ? this->_waterIndex+1:0);
	// 	this->_waterSprite->setTextureRect((this->_waterRects[this->_waterIndex]));
	// 	this->setLastUpdate(milliseconds);
	// }

	window.draw(*(this->_mainSprite));
	window.draw(*(this->_waterSprite));
}