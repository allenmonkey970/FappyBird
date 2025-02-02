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
    icon icon;
    backGround backGround;

    FappyBird fappyBird(20, 30);
    Pipe pipe(200, 300);

    sf::Clock clock;
    sound_effects.playJump();
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            float dt = clock.restart().asSeconds();
            fappyBird.update(dt);

        };

        window.clear();
        icon.draw(window);
        backGround.draw(window);
        fappyBird.draw(window);
        pipe.draw(window);
        window.display();
    }
}
