#include "gameobject.h"
#include <iostream>
using std::cout;
using std::endl;

vector<GameObject *> GameObject::_objects = {};
bool GameObject::_debugging = true;

GameObject::GameObject() :
_lastUpdate(0)
{
	GameObject::_objects.push_back(this);
	this->_objIndex = GameObject::_objects.size()-1;
}

GameObject::~GameObject() {
	GameObject::_objects.erase(GameObject::_objects.begin()+this->_objIndex);
}

void GameObject::update(RenderWindow * window, const uint64_t & milliseconds) {
	this->setLastUpdate(milliseconds);
	cout << "Calling the wrong update function... =(" << endl;
}

void GameObject::updateAll(RenderWindow * window, const uint64_t & milliseconds) {
	for(auto obj : GameObject::_objects)
		obj->update(window, milliseconds);
}

void GameObject::setDebugging(const bool debugging) {
	GameObject::_debugging = debugging;
}

bool GameObject::getDebugging() {
	return GameObject::_debugging;
}

void GameObject::setLastUpdate(const uint64_t & lastUpdate) {
	this->_lastUpdate = lastUpdate;
}

uint64_t GameObject::getLastUpdate() {
	return this->_lastUpdate;
}

uint64_t GameObject::getTimeSinceLastUpdate(const uint64_t & milliseconds) {
	return (milliseconds - this->_lastUpdate);
}