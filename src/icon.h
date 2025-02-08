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
        if (!image.loadFromFile(icon::imageFile)) {
            std::cerr << "Failed loading icon" << std::endl;
        }
    }

    // Method to set the window icon
    void draw(sf::RenderWindow& window) const{
        window.setIcon(image);
    }

    // Static function to set the image file path
    static void setImageFile(const std::string& filePath) {
        icon::imageFile = filePath;
    }

private:
    // Image to hold the icon
    sf::Image image;
    static std::string imageFile; // Static member variable
};

// Initialize the static member variable
std::string icon::imageFile = "src/assets/icon.png";

#endif // ICON_H
