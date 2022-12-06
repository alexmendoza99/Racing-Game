#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;

// this file defines the functions and variables for music manager
class MusicManager {
public:
    MusicManager();

    void playRacingStart();
    void playRacing();
    void playCarEngine();
    void stopRacing();

private:
    SoundBuffer racingSB;
    SoundBuffer racingStartSB;
    Sound racing;
    Sound racingStart;

    SoundBuffer carEngineSB;
    Sound carEngine;
};
