#include "Engine.h"
#include <SFML/Audio.hpp>

// this file handles user input
void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        // General Input - input across entire game
        if (Keyboard::isKeyPressed(Keyboard::Escape)) { m_Window.close(); }
        if (event.type == Event::Closed) { m_Window.close(); }
        // State Specific Input
        switch (state)
        {
        case State::MAIN_MENU:
            if (Keyboard::isKeyPressed(Keyboard::Space)) { setState(State::LEVEL_COUNTDOWN); }
            break;
        case State::PLAYING:

            if (Keyboard::isKeyPressed(Keyboard::Left)) { player.moveLeft(); }
            else { player.stopLeft(); }

            if (Keyboard::isKeyPressed(Keyboard::Right)) { player.moveRight(); }
            else { player.stopRight(); }
            break;
        }
    }
}