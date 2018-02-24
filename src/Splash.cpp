#include <GameState.h>
#include "Splash.h"

void Splash::show(sf::RenderWindow &renderWindow){
    sf::Texture texture;
    if(!texture.loadFromFile("../res/img/splash.png")){ // Arg: const string: the path to the image file
        return; // Error handling here
    }

    sf::Sprite sprite(texture);
    sprite.setScale(GameState::_resX/sprite.getGlobalBounds().width, GameState::_resY/sprite.getGlobalBounds().height);
    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;

    while(true) { // Event loop
           while(renderWindow.pollEvent(event)){
                if(event.type == sf::Event::EventType::KeyPressed
                   || event.type == sf::Event::EventType::MouseButtonPressed
                   || event.type == sf::Event::EventType::Closed ) {
                    return;
                }
           }
    }

}; //show

