#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class SoundEffects {
public:
    SoundEffects() {
        if (!jumpBuffer.loadFromFile(jumpSoundPath) ||
            !pointBuffer.loadFromFile(pointSoundPath) ||
            !deathBuffer.loadFromFile(deathSoundPath)) {
            std::cerr << "Failed to load sound files." << std::endl;
            exit(EXIT_FAILURE); // Exit if sound loading fails
            }
        jumpSound.setBuffer(jumpBuffer);
        pointSound.setBuffer(pointBuffer);
        deathSound.setBuffer(deathBuffer);
    }

    void playJump() { playSound(jumpSound); }
    void playPoint() { playSound(pointSound); }
    void playDeath() { playSound(deathSound); }

private:
    void static playSound(sf::Sound& sound) {
        sound.setVolume(10.f);  // Set the volume to 10%
        sound.play();
    }

    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer pointBuffer;
    sf::SoundBuffer deathBuffer;

    const std::string jumpSoundPath = "src/assets/jump.wav";
    const std::string pointSoundPath = "src/assets/point.wav";
    const std::string deathSoundPath = "src/assets/hit.wav";

    sf::Sound jumpSound{ jumpBuffer }; // Initialized with buffer
    sf::Sound pointSound{ pointBuffer }; // Initialized with buffer
    sf::Sound deathSound{ deathBuffer }; // Initialized with buffer
};

#endif // SOUNDS_H
