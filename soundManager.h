#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager {
public:
    SoundManager();

    void Racing();
    void CarEngine();
    void GameOver();

private:
    SoundBuffer racingSB;
    Sound explode;

    SoundBuffer carEngineSB;
    Sound carEngine;

    SoundBuffer explodeSB;
    Sound explode;


};
