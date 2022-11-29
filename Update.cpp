#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;


void Engine::update(float dtAsSeconds)
{
    // State Specific Updates
    switch (state)
    {
    case State::MAIN_MENU:
        break;
    case State::LEVEL_COUNTDOWN:
        break;
    case State::PAUSED:
        break;
    case State::PLAYING:
        road.update(dtAsSeconds, player.getSpeed());
        evilCar.update(dtAsSeconds, player.getSpeed());
        player.update(dtAsSeconds);
        player.setBounds(road.getLeftBound(), road.getRightBound());
        break;
    case State::LEVEL_WON:
        break;
    case State::GAME_OVER:
        break;
    case State::GAME_WON:
        break;
    }
}