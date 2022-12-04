#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

class SoundManager {
public:
    SoundManager();

    void Racing();
    void Explosion();

private:
    sf::SoundBuffer racingSB;
    sf::Sound racing;
    sf::SoundBuffer explosionSB;
    sf::Sound explosion;
};
