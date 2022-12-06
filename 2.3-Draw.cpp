#include "Engine.h"
#include <iostream>

using namespace std;

// This file draws all of the sprites by using draw functions from UI file and draws the window
void Engine::draw()
{
    m_Window.clear(Color::Black);
    // State Specific Updates and when to draw certain images
    switch (state)
    {
        case State::MAIN_MENU:
            UI.drawStartMenu(&m_Window);
            break;
        case State::LEVEL_COUNTDOWN:
            drawGameplay();
            UI.drawCountDown(&m_Window);
            UI.drawInGameUI(&m_Window, score.getScore(), player.getFuel());
            break;
        case State::PLAYING:
            drawGameplay();
            UI.drawInGameUI(&m_Window, score.getScore(), player.getFuel());
            break;
        case State::PLAYER_DIED:
            drawGameplay();
            UI.drawGameOver(&m_Window, score.getScore());
            break;
        case State::LEVEL_WON:
            drawGameplay();
            UI.drawInGameUI(&m_Window, score.getScore(), player.getFuel());
            UI.drawGameWon(&m_Window, score.getScore());
            break;
        case State::GAME_WON:
            UI.drawGameWon(&m_Window, score.getScore());
            break;
    }
    m_Window.display();
}
// draws road tiles and sprites
void Engine::drawGameplay()
{
    for (Sprite sprite : road.getSprites())
    {
        m_Window.draw(sprite);
    }
    objectManager.drawObjects(&m_Window);
    m_Window.draw(player.getSprite());
}