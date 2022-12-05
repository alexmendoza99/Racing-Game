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
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            m_Window.draw(player.getSprite());
            objectManager.drawObjects(&m_Window);
            //UI.drawCountDown(&m_Window);
            break;
        case State::PAUSED:
            break;
        case State::PLAYING:
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            objectManager.drawObjects(&m_Window);
            m_Window.draw(player.getSprite());
            UI.drawInGameUI(&m_Window);
            break;
        case State::PLAYER_DIED:
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            objectManager.drawObjects(&m_Window);
            UI.drawGameOver(&m_Window);
            break;
        case State::LEVEL_WON:
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            objectManager.drawObjects(&m_Window);
            m_Window.draw(player.getSprite());
            break;
        case State::GAME_OVER:
            break;
        case State::GAME_WON:
            UI.drawGameWon(&m_Window);
            break;
    }

    m_Window.display();
}