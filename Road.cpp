#include <SFML/Graphics.hpp>
#include "PlayerCar.h"

using namespace sf;

int old_main()
{
    // The game will always be in one of four states
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
      // we can use LEVELING_UP state for collisions, changing the speed of the player and use this to spin the player put when they drive over oil
    // Start with the GAME_OVER state
    State state = State::GAME_OVER;

    // Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), 
        "RACING 400!!!", Style::Default);

    // Create a an SFML View for the main action
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    // Here is our clock for timing everything
    Clock clock;
    // How long has the PLAYING state been active
    Time gameTimeTotal;

    // Where is the mouse in relation to world coordinates
    Vector2f mouseWorldPosition;
    // Where is the mouse in relation to screen coordinates
    Vector2i mouseScreenPosition;

    // Create an instance of the Player class
    PlayerCar playerCar;

    // The boundaries of the road
    IntRect road;

    // The main game loop
    while (window.isOpen())
    {
        /*
        ************
        Handle input
        ************
        */

        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {                                    
                // Pause a game while playing
                if (event.key.code == Keyboard::Return &&
                    state == State::PLAYING)
                {
                    state = State::PAUSED;
                }

                // Restart while paused
                else if (event.key.code == Keyboard::Return &&
                    state == State::PAUSED)
                {
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }

                // Start a new game while in GAME_OVER state
                else if (event.key.code == Keyboard::Return &&
                    state == State::GAME_OVER)
                {
                    state = State::LEVELING_UP;
                }

                if (state == State::PLAYING)
                {
                }

            }
        }// End event polling


        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // Handle controls while playing
        if (state == State::PLAYING)
        {
            // Handle the pressing and releasing of the arrow keys
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                playerCar.moveUp();
            }
            else
            {
                playerCar.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                playerCar.moveDown();
            }
            else
            {
                playerCar.stopDown();
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                playerCar.moveLeft();
            }
            else
            {
                playerCar.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                playerCar.moveRight();
            }
            else
            {
                playerCar.stopRight();
            }

        }// End WASD while playing

        // Handle the leveling up state
        if (state == State::LEVELING_UP)
        {
                // I think we can use these different leveling up states to check for collisions
            // Handle the player leveling up
            if (event.key.code == Keyboard::Num1)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num2)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num3)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num4)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num5)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num6)
            {
                state = State::PLAYING;
            }
            
            if (state == State::PLAYING)
            {            
                // Prepare the level
                // We will modify the next two lines later
                road.width = 500;
                road.height = 500;
                road.left = 0;
                road.top = 0;

                // We will modify this line of code later
                int tileSize = 50;

                // Spawn the player in the middle of the road
                playerCar.spawn(road, resolution, tileSize);
                
                // Reset the clock so there isn't a frame jump
                clock.restart();
            }
        }// End leveling up

        /*
        ****************
        UPDATE THE FRAME
        ****************
        */
        if (state == State::PLAYING)
        {
            // Update the delta time
            Time dt = clock.restart();
            // Update the total game time
            gameTimeTotal += dt;
            // Make a decimal fraction of 1 from the delta time
            float dtAsSeconds = dt.asSeconds();

            // Where is the mouse pointer
            mouseScreenPosition = Mouse::getPosition();

            // Convert mouse position to world coordinates of mainView
            mouseWorldPosition = window.mapPixelToCoords(
                Mouse::getPosition(), mainView);

            // Update the player
            playerCar.update(dtAsSeconds, Mouse::getPosition());

            // Make a note of the players new position
            Vector2f playerPosition(playerCar.getCenter());

            // Make the view center around the player                
            mainView.setCenter(playerCar.getCenter());
        }// End updating the scene

        /*
        **************
        Draw the scene
        **************
        */

        if (state == State::PLAYING)
        {
            window.clear();

            // set the mainView to be displayed in the window
            // And draw everything related to it
            window.setView(mainView);

            // Draw the player
            window.draw(playerCar.getSprite());
        }

        if (state == State::LEVELING_UP)
        {
        }

        if (state == State::PAUSED)
        {
        }

        if (state == State::GAME_OVER)
        {
        }

        window.display();

    }// End game loop

    return 0;
}



