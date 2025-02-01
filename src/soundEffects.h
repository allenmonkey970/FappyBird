#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

// Class to manage sound effects for the game
class SoundEffects {
public:
  // Constructor to load sound files
  SoundEffects() {
    if (!jumpBuffer.loadFromFile(jumpSound) ||
        !pointBuffer.loadFromFile(pointSound) ||
        !deathBuffer.loadFromFile(deathSound)) {
      std::cerr << "Failed to load sound files." << std::endl;
        }
  }

// function to play sound effects
  void playJump() { playSound(jumpBuffer); }

  void playPoint() { playSound(pointBuffer); }

  void playDeath() { playSound(deathBuffer); }

private:
  // Method to play a sound buffer
  void playSound(const sf::SoundBuffer& buffer) {
    sf::Sound sound(buffer);
    sound.setVolume(10.f);  // Set the volume to 10%
    sound.play();
    while (sound.getStatus() == sf::Sound::Status::Playing) {
      // Keep the application alive while the sound is playing
      sleep(sf::milliseconds(10));
    }
  }

  // Sound buffers for different sound effects
  sf::SoundBuffer jumpBuffer;
  sf::SoundBuffer pointBuffer;
  sf::SoundBuffer deathBuffer;

  // File paths for sound effects
  std::string jumpSound = "src/assets/jump.wav";
  std::string pointSound = "src/assets/point.wav";
  std::string deathSound = "src/assets/hit.wav";
};

#endif // SOUNDS_H
