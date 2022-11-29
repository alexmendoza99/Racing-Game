#include "Engine.h"


void Engine::draw()
{

    m_Window.clear(Color::Black);

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
        break;
    case State::LEVEL_WON:
        break;
    case State::GAME_OVER:
        break;
    case State::GAME_WON:
        break;
    }

    m_Window.setView(m_HUDView);

    m_Window.display();
}