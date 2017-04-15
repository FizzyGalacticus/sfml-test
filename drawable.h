#ifndef __MOVEABLEOBJECT_H_
#define __MOVEABLEOBJECT_H_

#include "constants.h"
#include "gameobject.h"

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

class Drawable : public GameObject {
	public:

	protected:
		void move(const uint64_t & milliseconds);
		
	private:
};

#endif