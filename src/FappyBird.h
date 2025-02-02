#ifndef FAPPYBIRD_H
#define FAPPYBIRD_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "soundEffects.h"

constexpr float GRAVITY = 980.0f; // Centralized constant for gravity
constexpr float FLY_FORCE = 400.0f; // Centralized constant for fly force

class FappyBird {
public:
    FappyBird(float x, float y) {
        if (!textureUp.loadFromFile(fileNameUp)) {
            std::cerr << "Failed loading Fappy texture (Up)" << std::endl;
            exit(EXIT_FAILURE); // Exit if texture loading fails
        }
        if (!textureDown.loadFromFile(fileNameDown)) {
            std::cerr << "Failed loading Fappy texture (Down)" << std::endl;
            exit(EXIT_FAILURE); // Exit if texture loading fails
        }
        sprite.setTexture(textureUp);
        sprite.setTextureRect(sf::IntRect({0, 0}, {34, 24}));
        sprite.setScale({2.2, 2.2});
        sprite.setPosition({x, y});
    }

    void handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ||
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sprite.setTexture(textureDown); // Change to wing-down texture
            fly();
        } else {
            sprite.setTexture(textureUp); // Change back to wing-up texture
        }
    }

    void update(float dt) {
        // Apply gravity
        velocity.y += GRAVITY * dt;
        // Update position
        sprite.move(velocity * dt);
    }

    const sf::Sprite& getSprite() const {
        return sprite;
    }


    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }

private:
    void fly() {
        sound_effects.playJump();
        velocity.y = -FLY_FORCE;
    }

    std::string fileNameUp = "src/assets/FappyBirdUp.png";
    std::string fileNameDown = "src/assets/FappyBirdDown.png";
    sf::Texture textureUp;
    sf::Texture textureDown;
    sf::Sprite sprite = sf::Sprite(textureUp);
    sf::Vector2f velocity;
    SoundEffects sound_effects;
};

#endif // FAPPYBIRD_H
