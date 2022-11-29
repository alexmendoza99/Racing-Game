#include "Engine.h"
#include <iostream>

using namespace std;


Engine::Engine()
{
	// Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y), "RACING 400!!!", Style::Default);

    // Create a an SFML View for the main action
    m_MainView.setSize(resolution);
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