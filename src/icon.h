#ifndef ICON_H
#define ICON_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Class to manage the icon for the exe
class icon {
public:
    // Constructor to load the icon
    icon() {
        // Load the image from the pathway
        if (!image.loadFromFile(imageFile)) {
            std::cerr << "Failed loading icon" << std::endl;
        }
    }

    // Method to set the window icon
    void draw(sf::RenderWindow& window) {
        window.setIcon(image);
    }

private:
    // Image to hold the icon
    sf::Image image;
    std::string imageFile = "src/assets/icon.png";
};

#endif // ICON_H
