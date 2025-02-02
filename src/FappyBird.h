#ifndef FAPPYBIRD_H
#define FAPPYBIRD_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "soundEffects.h"

constexpr float GRAVITY = 980.0f;  // Centralized constant for gravity
constexpr float FLY_FORCE = 400.0f; // Centralized constant for fly force

class FappyBird {
public:
    FappyBird(float x, float y) {
        if (!texture.loadFromFile(fileName)) {
            std::cerr << "Failed loading Fappy texture" << std::endl;
            exit(EXIT_FAILURE); // Exit if texture loading fails
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {34, 24}));
        sprite.setScale({2.2, 2.2});
        sprite.setPosition({x, y});
    }

    void handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            fly();
        }
    }

    void update(float dt) {
        // Apply gravity
        velocity.y += GRAVITY * dt;
        // Update position
        sprite.move(velocity * dt);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    void fly() {
        sound_effects.playJump();
        velocity.y = -FLY_FORCE;

    }

    std::string fileName = "src/assets/FappyBirdUp.png";
    sf::Texture texture;
    sf::Sprite sprite = sf::Sprite(texture);
    sf::Vector2f velocity;
    SoundEffects sound_effects;
};

#endif // FAPPYBIRD_H
