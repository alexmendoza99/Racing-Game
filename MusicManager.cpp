#include "MusicManager.h"

using namespace std;
using namespace sf;

// Constructor
MusicManager::MusicManager() {
    if (!racingSB.loadFromFile("sound/Racing.wav")) {
        std::cout << "ERROR: sound/racing.wav didn't load" << endl;
    } else {
        racing.setBuffer(racingSB);

    }
    racing.setLoop(true);
    if (!carEngineSB.loadFromFile("sound/CarEngine.wav")) {
        std::cout << "ERROR: sound/CarEngine.wav didn't load" << endl;
    } else {
        carEngine.setBuffer(carEngineSB);   
    }
    carEngine.setLoop(true);

}

//Functions
void MusicManager::playRacing() {
    racing.setVolume(0);
    racing.play();
}

void MusicManager::playCarEngine() {
    carEngine.setVolume(0);
    carEngine.play();
}