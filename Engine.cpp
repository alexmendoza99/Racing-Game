#include "Engine.h"
#include "SoundManager.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

Text infoText;

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


void Engine::setState(State newState)
{
    state = newState;

    switch (newState)
    {
    case State::MAIN_MENU:
        road.reset();
        player.reset();
        objectManager.clearObjects();
        break;
    case State::LEVEL_COUNTDOWN:
        player.spawn(m_Window.getSize().x / 2.0);
        //sound test
        soundManager.Racing();
        //soundManager.CarEngine();
        infoText.setString("Score: ");
        infoText.setCharacterSize(30);
        infoText.setColor(Color::White);
        infoText.setPosition(10,10);
        break;
    case State::PLAYER_DIED:
        soundManager.Crash();
        break;
    }
}


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