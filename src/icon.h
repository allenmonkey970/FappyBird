#ifndef ICON_H
#define ICON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class icon {
public:
    icon(const std::string& imageFile) {
        if (!image.loadFromFile(imageFile)) {
            std::cerr << "Failed loading icon" << std::endl;
        }
    }

    void draw(sf::RenderWindow& window) {
        window.setIcon(image);
    }

private:
    sf::Image image;
};

#endif // ICON_H
