#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#ifndef SOUNDS_H
#define SOUNDS_H


class SoundEffects{
public:
  jump(){
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(jump))
      return -1;
  }

private:
  string jump = "src/assets/jump.wav";
};
#endif //SOUNDS_H
