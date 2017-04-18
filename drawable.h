#ifndef __MOVEABLEOBJECT_H_
#define __MOVEABLEOBJECT_H_

#include "constants.h"
#include "gameobject.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <SFML/Graphics.hpp>
using sf::Texture;
using sf::Sprite;

#include <Box2D/Box2D.h>

class Drawable : public GameObject {
	public:
		Drawable();
		~Drawable();

	protected:
		b2World & getWorld();
		b2Body * getBody();

		const b2Vec2 getPosition() const;
		void setPosition(const b2Vec2 & newPos);

		void step();
		
	private:
		static b2World _world;

		void init();

		shared_ptr<Texture> _texture;
		shared_ptr<Sprite> _mainSprite;
		b2BodyDef * _bodyDef;
		b2Body * _body;
		b2FixtureDef * _fixture;
		b2PolygonShape * _shape;
};

#endif