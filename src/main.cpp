#include <iostream>
#include <SFML/Graphics.hpp>

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


class background {
public:
    background(const std::string& textureFile) : sprite(texture) {
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Failed loading pipe texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {288, 512}));
        sprite.setScale({1.7, 1.7});
        texture.setSmooth(true);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};


class FappyBird {
public:
    FappyBird(const std::string& textureFile, float x, float y) : sprite(texture) {
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Failed loading Fappy texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {34, 24}));
        sprite.setScale({2.2, 2.2});
        sprite.setPosition({x, y});
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

class Pipe {
public:
    Pipe(const std::string& textureFile, float x, float y) : sprite(texture) {
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Failed loading pipe texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {52, 320}));
        sprite.setPosition({x, y});
        texture.setSmooth(true);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({480, 800u}), "Fappy Bird");
    window.setFramerateLimit(144);

    //basic
    icon icon("src/assets/icon.png");
    background background("src/assets/background-night.png");

    FappyBird fappyBird("src/assets/FappyBird.png", 20, 30);
    Pipe pipe("src/assets/pipe-green.png", 200, 300);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        icon.draw(window);
        background.draw(window);
        fappyBird.draw(window);
        pipe.draw(window);
        window.display();
    }
}
