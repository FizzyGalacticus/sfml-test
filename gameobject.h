#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <vector>
using std::vector;

class GameObject
{
	public:
		GameObject();
		~GameObject();
		virtual void update(RenderWindow & window, const uint64_t & milliseconds);
		static void updateAll(RenderWindow & window, const uint64_t & milliseconds);
		static void setDebugging(const bool debugging);
		static bool getDebugging();

	protected:
		void setLastUpdate(const uint64_t & lastUpdate);
		uint64_t getLastUpdate();
		uint64_t getTimeSinceLastUpdate(const uint64_t & milliseconds);

	private:
		static vector<GameObject *> _objects;
		unsigned int _objIndex;
		static bool _debugging;
		uint64_t _lastUpdate;
};

#endif