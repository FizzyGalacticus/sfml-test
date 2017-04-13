#include "moveableobject.h"

const float MoveableObject::_GRAVITY = 9.81f;

MoveableObject::MoveableObject() :
_velocity(0.f, 0.f),
_acceleration(0.f,0.f)
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
