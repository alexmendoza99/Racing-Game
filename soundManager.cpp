#include "soundManager.h"

using namespace std;
using namespace sf;

// Constructor
SoundManager::SoundManager() {
    if (!racingSB.loadFromFile("sound/test.wav")) {
        std::cout << "ERROR: sound/racing.wav didn't load" << endl;
    } else {
        racing.setBuffer(racingSB);
    }

    if (!explosionSB.loadFromFile("sound/test.wav")) {
        std::cout << "ERROR: sound/explosion.wav didn't load" << endl;
    } else {
        explosion.setBuffer(explosionSB);
    }
}

//Functions
void SoundManager::Racing() {
    racing.play();
}

void SoundManager::Explosion() {
    explosion.play();
}
