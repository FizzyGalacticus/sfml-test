#include "drawable.h"

#include "constants.h"

b2World Drawable::_world = b2World(b2Vec2(0,GRAVITY));

Drawable::Drawable() :
_bodyDef(new b2BodyDef()),
_shape(new b2PolygonShape()),
_fixture(new b2FixtureDef()) {
	this->init();
}

Drawable::~Drawable() {
	Drawable::_world.DestroyBody(this->_body);
}

void Drawable::init() {
	this->_bodyDef->type = b2_dynamicBody;
	this->_bodyDef->position.Set(200*P2M,GROUND_LEVEL*P2M);

	this->_shape->SetAsBox(23,25);

	this->_fixture->shape = this->_shape;
	this->_fixture->density = -1.0f;
	this->_fixture->friction = 0.1f;

	this->_body = Drawable::_world.CreateBody(this->_bodyDef);
	this->_body->CreateFixture(this->_fixture);
}

b2World & Drawable::getWorld() {
	return this->_world;
}


b2Body * Drawable::getBody() {
	return this->_body;
}

void Drawable::step() {
	this->_world.Step(BOX_TIMESTEP,5,5);
}