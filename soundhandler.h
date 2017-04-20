#ifndef __SOUNDHANDLER_H_
#define __SOUNDHANDLER_H_

#include "gameobject.h"

#include <SFML/Audio.hpp>
using sf::Music;

#include <vector>
using std::vector;

#include <string>
using std::string;

class SoundHandler : GameObject
{
	public:
		SoundHandler();
		~SoundHandler();
		void update(RenderWindow * window, sf::Time clock);
	
	private:
		Music _backgroundMusic;
		const vector<string> _backgroundTracks;
		unsigned int _currentBackgroundTrack;
};

#endif