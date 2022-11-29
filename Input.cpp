#include "Engine.h"


void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        // General Input - input across entire game
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }

        // State Specific Input
        switch (state)
        {
        case State::MAIN_MENU:
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                setState(State::PLAYING);
            }
            break;
        case State::LEVEL_COUNTDOWN:
            break;
        case State::PAUSED:
            break;
        case State::PLAYING:
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                player.moveLeft();
            }
            else
            {
                player.stopLeft();
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                player.moveRight();
            }
            else
            {
                player.stopRight();
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                player.engineOn();
            }
            break;
        case State::LEVEL_WON:
            break;
        case State::GAME_OVER:
            break;
        case State::GAME_WON:
            break;
        }
    }
}