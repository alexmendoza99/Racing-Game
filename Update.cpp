#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

int frameTimer = 0;


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
        road.update(dtAsSeconds, player.getSpeed(), player.getTravelDistance());
        evilCar.update(dtAsSeconds, player.getSpeed());
        player.update(dtAsSeconds);
        player.setBounds(road.getLeftBound(), road.getRightBound());
        if (player.getTravelDistance() > road.getLength() + 117.0)
        {
            setState(State::LEVEL_WON);
        }
        break;
    case State::LEVEL_WON:
        frameTimer++;
        if (frameTimer > 5000)
        {
            setState(State::MAIN_MENU);
            frameTimer = 0;
        }
        break;
    case State::GAME_OVER:
        break;
    case State::GAME_WON:
        break;
    }
}