#include "Engine.h"
#include <iostream>

using namespace std;


Engine::Engine()
{
	// Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = 1280;
    resolution.y = 900;

    m_Window.create(VideoMode(resolution.x, resolution.y), "RACING 400!!!", Style::Default);

    // Create a an SFML View for the main action
    m_MainView.setSize(resolution);
}


void Engine::setState(State newState)
{
    state = newState;

    switch (newState)
    {
    case State::PLAYING:
        player.spawn(m_Window.getSize().x / 2.0);
        evilCar.spawn(m_Window.getSize().x/2.0, m_Window.getSize().y/2.0, 400);
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