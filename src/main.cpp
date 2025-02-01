#include <iostream>
#include <SFML/Graphics.hpp>

class FappyBird {
public:
    FappyBird(const std::string& textureFile) : sprite(texture) {
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Failed loading Fappy texture" << std::endl;
        }
        sprite.setTextureRect(sf::IntRect({0, 0}, {34, 24}));
        sprite.setScale({2.2, 2.2});
        sprite.setPosition({50, 50});
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
        sprite.setPosition({100, 200});
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

    FappyBird fappyBird("src/assets/FappyBird.png");
    Pipe pipe("src/assets/pipe-green.png", 200, 300);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        fappyBird.draw(window);
        pipe.draw(window);
        window.display();
    }
}
