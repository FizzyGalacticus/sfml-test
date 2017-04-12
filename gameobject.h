#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

class GameObject
{
	public:
		// GameObject();
		// ~GameObject();
		virtual void update(RenderWindow & window, const uint64_t & microseconds) = 0;
		static void updateAll(RenderWindow & window, const uint64_t & microseconds);
		static void setDebugging(const bool debugging);
		static bool getDebugging();

	protected:
		void setLastUpdate(const uint64_t & lastUpdate);
		uint64_t getLastUpdate();
		uint64_t getTimeSinceLastUpdate(const uint64_t & microseconds);

	private:
		static vector<shared_ptr<GameObject>> _objects;
		// unsigned int _objIndex;
		static bool _debugging;
		uint64_t _lastUpdate;
};

#endif