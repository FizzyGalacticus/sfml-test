#ifndef __MOVEABLEOBJECT_H_
#define __MOVEABLEOBJECT_H_

#include "constants.h"
#include "gameobject.h"

#include <SFML/Graphics.hpp>
using sf::Vector2f;

class MoveableObject : public GameObject
{
	public:
		MoveableObject();

		const Vector2f & getVelocity() const;
		void setVelocity(const Vector2f & velocity);
		void setVelocity(const float & x, const float & y);
		const bool hasVelocity() const;
		void setMaxVelocity(const float & maxVelocity);
		const float & getMaxVelocity();

		const Vector2f & getAcceleration() const;
		void setAcceleration(const Vector2f & acceleration);
		void setAcceleration(const float & x, const float & y);
		const bool hasAcceleration() const;
		void setMaxAcceleration(const float & maxAcceleration);
		const float & getMaxAcceleration();

	protected:
		void move(const uint64_t & milliseconds);

		Vector2f _position;
		
	private:
		const bool getSignOfFloat(const float & val);

		Vector2f _velocity;
		Vector2f _acceleration;
		float _maxVelocity;
		float _maxAcceleration;
};

#endif