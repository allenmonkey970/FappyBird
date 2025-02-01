#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "icon.h"
#include "background.h"
#include "FappyBird.h"
#include "Pipe.h"
#include "soundEffects.h"
#include <vector>

int main() {
    SoundEffects sound_effects;
    auto window = sf::RenderWindow(sf::VideoMode({480, 800u}), "Fappy Bird");
    window.setFramerateLimit(144);

    //basic
    icon icon("src/assets/icon.png");
    background background("src/assets/background-night.png");

    FappyBird fappyBird("src/assets/FappyBird.png", 20, 30);
    Pipe pipe("src/assets/pipe-green.png", 200, 300);

    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            float dt = clock.restart().asSeconds();

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            fappyBird.update(dt);
            sound_effects.jump();
        };

        window.clear();
        icon.draw(window);
        background.draw(window);
        fappyBird.draw(window);
        pipe.draw(window);
        window.display();
    }
}
