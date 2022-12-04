#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager {
public:
    SoundManager();

    void Racing();
    void CarEngine();
    void Crash();

private:
    SoundBuffer racingSB;
    Sound racing;

    SoundBuffer carEngineSB;
    Sound carEngine;

    SoundBuffer explodeSB;
    Sound explode;


};
