#ifndef __MOVEABLEOBJECT_H_
#define __MOVEABLEOBJECT_H_

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

		const Vector2f & getAcceleration() const;
		void setAcceleration(const Vector2f & acceleration);
		void setAcceleration(const float & x, const float & y);
		
	private:
		static const float _GRAVITY;
		Vector2f _velocity;
		Vector2f _acceleration;
};

#endif