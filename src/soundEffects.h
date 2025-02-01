#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#ifndef SOUNDS_H
#define SOUNDS_H


class SoundEffects{
public:
  int jump(){
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(jumpSound))
      return -1;
  }

  int point(){
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(PointSound))
      return -1;
  }

  int death(){
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(deathSound))
      return -1;
  }

private:
  std::string jumpSound = "src/assets/jump.wav";
  std::string PointSound = "src/assets/point.wav";
  std::string deathSound = "src/assets/hit.wav";
};
#endif //SOUNDS_H
