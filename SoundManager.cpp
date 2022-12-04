#include "SoundManager.h"

using namespace std;
using namespace sf;

// Constructor
SoundManager::SoundManager() {
    if (!racingSB.loadFromFile("sound/Racing.wav")) {
        std::cout << "ERROR: sound/racing.wav didn't load" << endl;
    } else {
        racing.setBuffer(racingSB);
    }

    if (!carEngineSB.loadFromFile("sound/CarEngine.wav")) {
        std::cout << "ERROR: sound/explosion.wav didn't load" << endl;
    } else {
        Sound carEngine;
        carEngine.setBuffer(carEngineSB);
    }
     if (!explodeSB.loadFromFile("sound/CarEngine.wav")) {
        std::cout << "ERROR: sound/explosion.wav didn't load" << endl;
    } else {
        Sound explode;
        explode.setBuffer(explodeSB);
    }
    

}

//Functions


void SoundManager::Racing() {
    racing.setVolume(70);
    racing.play();
}

void SoundManager::CarEngine() {
    carEngine.setVolume(50);
    carEngine.setLoop(true);
    carEngine.play();
}

void SoundManager::Crash() {
    explode.play();
}
