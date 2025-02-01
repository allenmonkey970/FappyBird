#ifndef PIPE_H
#define PIPE_H
#include "soundEffects.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Pipe {
public:
    Pipe(const std::string& textureFile, float x, float y) : sprite(texture) {
        if (!texture.loadFromFile(textureFile)) {
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
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // PIPE_H
