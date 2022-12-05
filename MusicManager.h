#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;

class MusicManager {
public:
    MusicManager();

    void playRacing();
    void playCarEngine();

private:
    SoundBuffer racingSB;
    Sound racing;

    SoundBuffer carEngineSB;
    Sound carEngine;
};
