#ifndef PIPE_H
#define PIPE_H


#include <SFML/Graphics.hpp>

// pipes used in the game
class Pipe {
public:
    // Constructor to initialize the pipe with position, texture, and orientation (bottom or top)
    Pipe(float x, float y, const sf::Texture& texture, bool isBottom)
        : sprite(texture) {
        // Initialize the sprite with the given texture and set the texture rectangle
        sprite.setTextureRect(sf::IntRect({0, 0}, {52, 320}));
        if (isBottom) {
            // Set the position for the bottom pipe
            sprite.setPosition({x, y});
        } else {
            // Adjust position for the top pipe
            sprite.setPosition({x, y - 30});
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

private:
    sf::Sprite sprite;  // Sprite representing the pipe
};

#endif // PIPE_H
