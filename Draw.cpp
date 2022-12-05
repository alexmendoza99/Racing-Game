#include "Engine.h"
#include <iostream>

using namespace std;


void Engine::draw()
{
    m_Window.clear(Color::Black);
    // State Specific Updates
    cout << (int)state << endl;
    switch (state)
    {
        case State::MAIN_MENU:
            UI.drawStartMenu(&m_Window);
            break;
        case State::LEVEL_COUNTDOWN:
            drawGameplay();
            UI.drawCountDown(&m_Window);
            break;
        case State::PLAYING:
            drawGameplay();
            UI.drawInGameUI(&m_Window);
            break;
        case State::PLAYER_DIED:
            drawGameplay();
            UI.drawGameOver(&m_Window);
            break;
        case State::LEVEL_WON:
            drawGameplay();
            break;
        case State::GAME_WON:
            UI.drawGameWon(&m_Window);
            break;
    }
    m_Window.display();
}

void Engine::drawGameplay()
{
    for (Sprite sprite : road.getSprites())
    {
        m_Window.draw(sprite);
    }
    objectManager.drawObjects(&m_Window);
    m_Window.draw(player.getSprite());
}