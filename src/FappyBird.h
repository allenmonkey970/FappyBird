#ifndef FAPPYBIRD_H
#define FAPPYBIRD_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "soundEffects.h"

constexpr float GRAVITY = 980.0f; // Centralized constant for gravity
constexpr float FLY_FORCE = 400.0f; // Centralized constant for fly force

//class for fappy the knock of bird
class FappyBird {
public:
    FappyBird(float x, float y) {
        // Load the "up" texture for the bird
        if (!textureUp.loadFromFile(fileNameUp)) {
            std::cerr << "Failed loading Fappy texture (Up)" << std::endl;
            exit(EXIT_FAILURE); // Exit if texture loading fails
        }
        // Load the "down" texture for the bird
        if (!textureDown.loadFromFile(fileNameDown)) {
            std::cerr << "Failed loading Fappy texture (Down)" << std::endl;
            exit(EXIT_FAILURE); // Exit if texture loading fails
        }
        sprite.setTexture(textureUp); // Set initial texture
        // Define the texture rectangle using FloatRect and convert to IntRect
        sf::FloatRect floatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(34.f, 24.f));
        sprite.setTextureRect(sf::IntRect(floatRect));
        sprite.setScale({2.2f, 2.2f}); // Scale the sprite
        sprite.setPosition({x, y}); // Set initial position
    }

    void handleInput() {
        // Check for space key or left mouse button press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ||
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sprite.setTexture(textureDown); // Change to wing-down texture
            fly(); // Apply fly force
        } else {
            sprite.setTexture(textureUp); // Change back to wing-up texture
        }
    }

    void update(float dt) {
        // Apply gravity to the vertical velocity
        velocity.y += GRAVITY * dt;
        // Update the position of the sprite based on the velocity
        sprite.move(velocity * dt);
    }

    const sf::Sprite& getSprite() const {
        return sprite; // Return the sprite
    }

    void draw(sf::RenderWindow &window) const {
        window.draw(sprite); // Draw the sprite on the window
    }

    // Get the bounding box of the bird for collision detection
    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

private:
    void fly() {
        sound_effects.playJump(); // Play jump sound
        velocity.y = -FLY_FORCE; // Set vertical velocity to fly force
    }

    std::string fileNameUp = "src/assets/FappyBirdUp.png"; // Path to "up" texture file
    std::string fileNameDown = "src/assets/FappyBirdDown.png"; // Path to "down" texture file
    sf::Texture textureUp; // Texture for "up" position
    sf::Texture textureDown; // Texture for "down" position
    sf::Sprite sprite = sf::Sprite(textureUp); // Sprite representing the bird
    sf::Vector2f velocity; // Velocity vector for movement
    SoundEffects sound_effects; // Sound effects for the bird
};

#endif // FAPPYBIRD_H
