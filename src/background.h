#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Class to manage the background of the game
class backGround {
public:
    // Constructor to load the texture and set up the sprite
    backGround() {
        // Load the texture from a file
        if (!texture.loadFromFile(imageFile)) {
            std::cerr << "Failed loading background texture" << std::endl;
        }
        sprite.setTexture(texture); // Set the texture for the sprite after loading it
        sprite.setTextureRect(sf::IntRect({0, 0}, {288, 512}));
        // Scale the sprite to fit the whole screen
        sprite.setScale({1.7, 1.8});

        rectangle.setSize(sf::Vector2f(500, 100));
        rectangle.setFillColor(sf::Color(222, 216, 149));
        rectangle.setPosition(sf::Vector2f(0, 715));
    }

    // Draw the sprite on the window
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
        window.draw(rectangle);
    }

private:
    std::string imageFile = "src/assets/background-night.png";
    // Texture to hold the background image
    sf::Texture texture;
    // Sprite to display the texture
    sf::Sprite sprite = sf::Sprite(texture); // Initialize sprite with texture
    sf::RectangleShape rectangle;
};

#endif // BACKGROUND_H
