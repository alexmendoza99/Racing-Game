#include "Engine.h"
#include <iostream>

using namespace std;


void Engine::draw()
{

    m_Window.clear(Color::Black);

    // State Specific Updates
    switch (state)
    {
        case State::MAIN_MENU:
            cout << "MAIN MENU" << endl;
            break;

        case State::LEVEL_COUNTDOWN:
            cout << "LEVEL COUNTDOWN" << endl;
            break;

        case State::PAUSED:
            cout << "PAUSED" << endl;
            break;

        case State::PLAYING:
            cout << "PLAYING" << endl;
            m_Window.clear(Color(0, 100, 0, 255));
            break;

        case State::LEVEL_WON:
            cout << "LEVEL WON" << endl;
            break;

        case State::GAME_OVER:
            cout << "GAME OVER" << endl;
            break;

        case State::GAME_WON:
            cout << "GAME WON" << endl;
            break;

    }

    m_Window.display();
}