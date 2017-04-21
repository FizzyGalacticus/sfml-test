#include "soundhandler.h"

#include <iostream>
using std::cout;
using std::endl;

SoundHandler::SoundHandler() :
_backgroundTracks{
	"audio/snd_background01.wav"
},
_currentBackgroundTrack(0) {
	if(!this->_backgroundTracks.size()) {
		if(this->getDebugging())
			cout << "No audio tracks given for background music." << endl;
	}
	else if(!this->_backgroundMusic.openFromFile(this->_backgroundTracks[this->_currentBackgroundTrack])) {
		if(this->getDebugging())
			cout << "Could not open background track: " << this->_backgroundTracks[this->_currentBackgroundTrack] << endl;
	}
	else {
		this->_backgroundMusic.setVolume(50);
		this->_backgroundMusic.play();
	}
}

SoundHandler::~SoundHandler() {

}

void SoundHandler::update(RenderWindow * window, sf::Time clock) {
	if(this->_backgroundMusic.getStatus() == sf::SoundStream::Stopped) {
		this->_currentBackgroundTrack = (this->_currentBackgroundTrack < this->_backgroundTracks.size()-1 ? this->_currentBackgroundTrack+1:0);
		this->_backgroundMusic.openFromFile(this->_backgroundTracks[this->_currentBackgroundTrack]);
		this->_backgroundMusic.play();
	}
}