#include "gameobject.h"

vector<shared_ptr<GameObject>> GameObject::_objects = {};
bool GameObject::_debugging = true;

// GameObject::GameObject() :
// _lastUpdate(0)
// {
// 	GameObject::_objects.push_back(make_shared<GameObject>(*this));
// 	this->_objIndex = GameObject::_objects.size()-1;
// }

// GameObject::~GameObject() {
// 	GameObject::_objects.erase(GameObject::_objects.begin()+this->_objIndex);
// }

void GameObject::updateAll(RenderWindow & window, const uint64_t & microseconds) {
	for(auto obj : GameObject::_objects)
		obj->update(window, microseconds);
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

uint64_t GameObject::getTimeSinceLastUpdate(const uint64_t & microseconds) {
	return (microseconds - this->_lastUpdate);
}