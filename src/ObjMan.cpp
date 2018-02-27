#include "ObjMan.h"

ObjMan::ObjMan() {};

ObjMan::~ObjMan() {std::for_each(_gameObjects.begin(), _gameObjects.end(), ObjMan::GameObjDealloc());};

void ObjMan::add(std::string name, VisibleGameObject *gameObject) {
    _gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void ObjMan::remove(std::string name) {
    auto it = _gameObjects.find(name); // This is an iterator
    if(it!=_gameObjects.end()){
        delete it->second;
        _gameObjects.erase(it);
    }
}

VisibleGameObject *ObjMan::get(std::string name) const {
    auto it = _gameObjects.find(name);
    if(it!=_gameObjects.end()) return it->second;
    return nullptr;
}

int ObjMan::getObjCount() const {
    return _gameObjects.size();
}

void ObjMan::drawAll(sf::RenderWindow &renderWindow) {
    auto it = _gameObjects.begin();
    while(it!=_gameObjects.end()) {
        it->second->Draw(renderWindow);
        it++;
    }
};
void ObjMan::UpdateAll()
{
    std::map<std::string,VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
    float timeDelta = clock.restart().asSeconds();

    while(itr != _gameObjects.end())
    {
        itr->second->Update(timeDelta);
        itr++;
    }


}




