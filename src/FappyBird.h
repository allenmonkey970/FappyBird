#ifndef FAPPYBIRD_H
#define FAPPYBIRD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "soundEffects.h"
class FappyBird {
public:
    FappyBird(float x, float y){
        if (!texture.loadFromFile(fileName)) {
            std::cerr << "Failed loading Fappy texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {34, 24}));
        sprite.setScale({2.2, 2.2});
        sprite.setPosition({x, y});
    }

    void update(float dt) {
        // Apply gravity
        velocity.y += gravity * dt;
        // Update position
        sprite.move(velocity * dt);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    std::string fileName = "src/assets/FappyBird.png";
    sf::Texture texture;
    sf::Sprite sprite = sf::Sprite(texture);
    sf::Vector2f velocity;
    static constexpr float gravity = 980.f; // Gravity constant in pixels/second^2
};

#endif // FAPPYBIRD_H
