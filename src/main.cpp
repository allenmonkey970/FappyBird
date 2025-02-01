#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Fappy bird");
    window.setFramerateLimit(144);
    sf::Texture texture;
    if (!(texture.loadFromFile("C:\\Users\\antho\\CLionProjects\packman\\src\\FappyBird.png", false, sf::IntRect( {10, 10}, {100, 100})))){
        std::cerr << "Failed to load texture" << std::endl;
        return -1;
    }
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
