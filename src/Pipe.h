#ifndef PIPE_H
#define PIPE_H
#include "soundEffects.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Pipe {
public:
    Pipe(float x, float y){
        if (!texture.loadFromFile(fileName)) {
            std::cerr << "Failed loading pipe texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {52, 320}));
        sprite.setPosition({x, y});
        texture.setSmooth(true);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    std::string fileName = "src/assets/pipe-green.png";
    sf::Texture texture;
    sf::Sprite sprite = sf::Sprite(texture);
};

#endif // PIPE_H
