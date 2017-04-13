#include "moveableobject.h"

#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

MoveableObject::MoveableObject() :
_velocity(0.f, 0.f),
_acceleration(0.f,0.f),
_maxVelocity(1.f),
_maxAcceleration(1.f)
{

}

const Vector2f & MoveableObject::getVelocity() const {
	return this->_velocity;
}

void MoveableObject::setVelocity(const Vector2f & velocity) {
	this->_velocity = velocity;
}

void MoveableObject::setVelocity(const float & x, const float & y) {
	this->_velocity.x = x;
	this->_velocity.y = y;
}

const bool MoveableObject::hasVelocity() const {
	return (this->_velocity.x != 0 || this->_velocity.y != 0);
}

void MoveableObject::setMaxVelocity(const float & maxVelocity) {
	this->_maxVelocity = maxVelocity;
}

const float & MoveableObject::getMaxVelocity() {
	return this->_maxVelocity;
}

const Vector2f & MoveableObject::getAcceleration() const {
	return this->_acceleration;
}

void MoveableObject::setAcceleration(const Vector2f & acceleration) {
	this->_acceleration = acceleration;
}

void MoveableObject::setAcceleration(const float & x, const float & y) {
	this->_acceleration.x = x;
	this->_acceleration.y = y;
}

const bool MoveableObject::hasAcceleration() const {
	return (this->_acceleration.x != 0 || this->_acceleration.y != 0);
}

void MoveableObject::setMaxAcceleration(const float & maxAcceleration) {
	this->_maxAcceleration = maxAcceleration;
}

const float & MoveableObject::getMaxAcceleration() {
	return this->_maxAcceleration;
}

void MoveableObject::move(const uint64_t & milliseconds) {
	const uint64_t timeSinceLastUpdate = this->getTimeSinceLastUpdate(milliseconds);
	int time                           = (timeSinceLastUpdate / 40);
	bool signOfAccelerationX           = this->getSignOfFloat(this->_acceleration.x);

	if(this->_acceleration.y > this->_maxAcceleration)
		this->_acceleration.y = this->_maxAcceleration;
	else if(this->_acceleration.y < -1*this->_maxAcceleration)
		this->_acceleration.y = -1*this->_maxAcceleration;

	if(this->_acceleration.x > this->_maxAcceleration)
		this->_acceleration.x = this->_maxAcceleration;
	else if(this->_acceleration.x < -1*this->_maxAcceleration)
		this->_acceleration.x = -1*this->_maxAcceleration;

	this->_velocity.x = this->_velocity.x + this->_acceleration.x*time;
	this->_velocity.y = this->_velocity.y + (this->_acceleration.y + GRAVITY)*time;

	if(this->_velocity.y > 0.16)
		this->_velocity.y = 0.16;
	else if(this->_velocity.y < -1*0.16)
		this->_velocity.y = -1*0.16;

	if(this->_velocity.x > this->_maxVelocity)
		this->_velocity.x = this->_maxVelocity;
	else if(this->_velocity.x < -1*this->_maxVelocity)
		this->_velocity.x = -1*this->_maxVelocity;

	this->_position.x = this->_position.x + this->_velocity.x*(timeSinceLastUpdate % 40) + 0.5*this->_acceleration.x*pow(time, 2);
	this->_position.y = this->_position.y + this->_velocity.y*time + 0.5*(this->_acceleration.y + GRAVITY)*pow(time, 2);

	if(this->_position.x < 0)
		this->_position.x = 0;
	else if(this->_position.x > WINDOW_WIDTH)
		this->_position.x = WINDOW_WIDTH;

	if(this->_position.y < 0)
		this->_position.y = 0;
	else if(this->_position.y > WINDOW_HEIGHT)
		this->_position.y = WINDOW_HEIGHT;
}

const bool MoveableObject::getSignOfFloat(const float & val) {
	return (val > 0.0f);
}