#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Audio.hpp>
#include <string>

class SoundEffects {
public:
  int jump() {
    sf::SoundBuffer jump;
    if (!jump.loadFromFile(jumpSound))
      return -1;
    sf::Sound sound(jump);
    sound.play();
    return 0;
  }

  int point() {
    sf::SoundBuffer point;
    if (!point.loadFromFile(pointSound))
      return -1;
    sf::Sound sound(point);
    sound.play();
    return 0;
  }

  int death() {
    sf::SoundBuffer death;
    if (!death.loadFromFile(deathSound))
      return -1;
    sf::Sound sound(death);
    sound.play();
    return 0;
  }

private:
  std::string jumpSound = "src/assets/jump.wav";
  std::string pointSound = "src/assets/point.wav";
  std::string deathSound = "src/assets/hit.wav";
};

#endif // SOUNDS_H
