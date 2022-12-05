#include "MusicManager.h"

using namespace std;
using namespace sf;

// Constructor
MusicManager::MusicManager() {
    if (!racingStartSB.loadFromFile("sound/StartOfRace.wav")) {
        std::cout << "ERROR: sound/StartOfRace.wav didn't load" << endl;
    }
    else
    {
        racing.setBuffer(racingSB);
    }

    if (!racingSB.loadFromFile("sound/Racing.wav")) {
        std::cout << "ERROR: sound/Racing.wav didn't load" << endl;
    }
    else
    {
        racingStart.setBuffer(racingStartSB);
    }

    if (!carEngineSB.loadFromFile("sound/CarEngine.wav")) {
        std::cout << "ERROR: sound/CarEngine.wav didn't load" << endl;
    } else {
        carEngine.setBuffer(carEngineSB);   
    }
    carEngine.setLoop(true);

}

//Functions
void MusicManager::playRacing() {
    racing.setLoop(true);
    racing.setVolume(50);
    racing.play();
}

void MusicManager::stopRacing() {
    racing.stop();
    carEngine.stop();
}

void MusicManager::playRacingStart() {
    racingStart.setLoop(false);
    racingStart.setVolume(70);
    racingStart.play();
}

void MusicManager::playCarEngine() {
    carEngine.setVolume(20);
    carEngine.play();
}