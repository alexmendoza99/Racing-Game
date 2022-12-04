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
            break;

        case State::LEVEL_COUNTDOWN:
            m_Window.clear(Color(0, 100, 0, 255));
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            m_Window.draw(player.getSprite());
            objectManager.drawObjects(&m_Window);
            break;

        case State::PAUSED:
            break;

        case State::PLAYING:
            m_Window.clear(Color(0, 100, 0, 255));
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            objectManager.drawObjects(&m_Window);
            m_Window.draw(player.getSprite());
            break;

        case State::PLAYER_DIED:
            m_Window.clear(Color(0, 100, 0, 255));
            for (Sprite sprite : road.getSprites())
            {
                m_Window.draw(sprite);
            }
            objectManager.drawObjects(&m_Window);
            break;

        case State::LEVEL_WON:
            m_Window.clear(Color(0, 100, 0, 255));
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
            break;

    }

    m_Window.display();
}