#include "soundhandler.h"

#include <iostream>
using std::cout;
using std::endl;

SoundHandler::SoundHandler() :
_backgroundTracks{
	
},
_currentBackgroundTrack(0) {
	if(!this->_backgroundTracks.size()) {
		if(this->getDebugging())
			cout << "No audio tracks given for background music." << endl;
	}
	else if(!this->_backgroundMusic.openFromFile(this->_backgroundTracks[0])) {
		if(this->getDebugging())
			cout << "Could not open background track: " << this->_backgroundTracks[0] << endl;
	}
	else {
		this->_backgroundMusic.setVolume(50);
		this->_backgroundMusic.play();
	}
}

SoundHandler::~SoundHandler() {

}

void SoundHandler::update(RenderWindow * window, sf::Time clock) {

}