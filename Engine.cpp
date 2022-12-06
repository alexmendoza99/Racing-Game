#include "Engine.h"
#include "MusicManager.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

Engine::Engine()
{
    srand(time(NULL));
	// Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = 1024;
    resolution.y = 960;

    m_Window.create(VideoMode(resolution.x, resolution.y), "RACING 400!!!", Style::Default);

    // Create a an SFML View for the main action
    m_MainView.setSize(resolution);
}
// Handles game states and music
void Engine::setState(State newState)
{
    state = newState;

    switch (newState)
    {
    case State::MAIN_MENU:
        musicManager.stopRacing();
        road.reset();
        player.reset();
        score.reset();
        objectManager.clearObjects();
        UI.resetCountDown();
        break;
    case State::LEVEL_COUNTDOWN:
        player.spawn(m_Window.getSize().x / 2.0);
        musicManager.playRacingStart();
        musicManager.playCarEngine();
        break;
    case State::PLAYING:
        musicManager.playRacing();
        break;
    case State::PLAYER_DIED:
        musicManager.stopRacing();
        break;
    }
}
// Runs the time of the game
void Engine::run() 
{
    Clock clock;
    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}