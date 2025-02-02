#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

// Pipes used in the game
class Pipe {
public:
    // Constructor to initialize the pipe with position, texture, and orientation (bottom or top)
    Pipe(float x, float y, const sf::Texture& texture, bool isBottom)
        : sprite(texture) {
        // Initialize the sprite with the given texture and set the texture rectangle
        sf::FloatRect floatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(52.f, 320.f));
        sprite.setTextureRect(sf::IntRect(floatRect)); // Convert FloatRect to IntRect
        if (isBottom) {
            // Set the position for the bottom pipe
            sprite.setPosition({x, y});
        } else {
            // Adjust position for the top pipe
            sprite.setPosition({x, y - 30.f});
            // Rotate the top pipe by 180 degrees
            sprite.setRotation(sf::degrees(180));
        }
    }

    // Update the pipe's position based on the delta time (dt)
    void update(float dt) {
        // Move the pipe to the left at a constant speed
        sprite.move({-100.f * dt, 0.f});
    }

    // Draw the pipe on the window
    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

    // Get the current x-coordinate of the pipe
    float getX() const {
        return sprite.getPosition().x;
    }

    // Get the sprite of the pipe
    const sf::Sprite& getSprite() const {
        return sprite;
    }

    // Get the bounding box of the pipe for collision detection
    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

private:
    sf::Sprite sprite;  // Sprite representing the pipe
};

#endif // PIPE_H
