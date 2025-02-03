// Created by antho on 2/2/2025.

#ifndef FAPPYBIRDGAME_H
#define FAPPYBIRDGAME_H

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

class FappyBirdGame {
public:
    // Constructor to initialize the game window and set up initial configurations
    FappyBirdGame() : window(sf::VideoMode({480, 800u}), "Fappy Bird") {
        window.setFramerateLimit(144);

        // Load pipe texture
        if (!pipeTexture.loadFromFile("src/assets/pipe-green.png")) {
            std::cerr << "Failed loading pipe texture" << std::endl;
            exit(-1);
        }
        pipeTexture.setSmooth(true);

        // Seed the random number generator
        std::srand(static_cast<unsigned>(std::time(nullptr)));

        // Basic game elements
        spawnTimer = 0.f;
        clock.restart();
    }

    // Method to run the game loop
    void run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window; // Game window
    sf::Texture pipeTexture; // Texture for the pipes
    icon icon; // Icon object
    backGround backGround; // Background object
    FappyBird fappyBird{20.f, 30.f}; // Bird object
    std::vector<Pipe> pipes; // Vector of pipes
    float spawnTimer; // Timer for pipe spawning
    const float spawnInterval = 1.7f; // Time interval between pipe spawns
    const float gapSize = 180.f; // Gap between the top and bottom pipes
    SoundEffects sound_effects; // Sound effects
    sf::Clock clock;

    // Method to handle window events
    void handleEvents() {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }

    // Method to update game state
    void update() {
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
            sound_effects.playDeath(); // Plays death sound
            sf::sleep(sf::milliseconds(2000)); // Wait for death sound to play
            window.close();
        }
    }

    // Method to render the game elements on the window
    void render() {
        window.clear();
        icon.draw(window);
        backGround.draw(window);
        fappyBird.draw(window);
        for (auto& pipe : pipes) {
            pipe.draw(window);
        }
        window.display();
    }
};

#endif //FAPPYBIRDGAME_H
