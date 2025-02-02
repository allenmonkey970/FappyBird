#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "icon.h"
#include "background.h"
#include "FappyBird.h"
#include "Pipe.h"
#include "soundEffects.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({480, 800u}), "Fappy Bird");
    window.setFramerateLimit(144);

    // Load pipe texture
    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("src/assets/pipe-green.png")) {
        std::cerr << "Failed loading pipe texture" << std::endl;
        return -1;
    }
    pipeTexture.setSmooth(true);

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Basic game elements
    icon icon;
    backGround backGround;
    FappyBird fappyBird(20.f, 30.f);
    std::vector<Pipe> pipes;
    float spawnTimer = 0.f;
    const float spawnInterval = 1.5f; // Time interval between pipe spawns
    const float gapSize = 150.f; // Gap between the top and bottom pipes
    SoundEffects sound_effects;

    sf::Clock clock;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();
        fappyBird.handleInput();
        fappyBird.update(dt);

        // Pipe spawning logic
        spawnTimer += dt;
        if (spawnTimer >= spawnInterval) {
            float pipeY = static_cast<float>(std::rand() % 100 + 400); // Random vertical position
            pipes.emplace_back(480.f, pipeY, pipeTexture, true); // Bottom pipe
            pipes.emplace_back(480.f, pipeY - gapSize, pipeTexture, false); // Top pipe
            spawnTimer = 0.f;
        }

        // Update the position of each pipe
        for (auto& pipe : pipes) {
            pipe.update(dt);
        }

        // Check for collisions with pipes
        bool collisionDetected = false;
        for (const auto& pipe : pipes) {
            if (fappyBird.getBounds().findIntersection(pipe.getBounds())) {
                collisionDetected = true;
                break;
            }
        }

        // Check for collisions with the ground
        if (fappyBird.getBounds().findIntersection(backGround.getGroundBounds())) {
            collisionDetected = true;
        }

        // Remove pipes that have moved off-screen
        pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](const Pipe& pipe) {
            return pipe.getX() < -52.f;
        }), pipes.end());

        // If a collision is detected, exit the game loop
        if (collisionDetected) {
            std::cerr << "Collision detected! Game over." << std::endl;
            sound_effects.playDeath(); // plays death sound
            sf:_sleep(2000); //wait for death sound to play
            break;
        }

        window.clear();
        icon.draw(window);
        backGround.draw(window);
        fappyBird.draw(window);
        for (auto& pipe : pipes) {
            pipe.draw(window);
        }
        window.display();
    }

    return 0;
}
