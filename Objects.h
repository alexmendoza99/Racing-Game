#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Object
{
private:
    // How fast is each object type?
    const float AICAR_SPEED = 40;
    const float LOG_SPEED = 80;
    const float OIL_SPEED = 20;
    // How tough is each object type
    const float AICAR_FUEL = 5;
    const float LOG_FUEL = 1;
    const float OIL_FUEL = 3;
    // Make each object vary its speed slightly
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;
    // Where is this object?
    Vector2f m_Position;
    // A sprite for the object
    Sprite m_Sprite;
    // How fast can this one move?
    float m_Speed;
    // How much fuel has it got?
    float m_Fuel;
    // how hard was a collision if any?
    bool m_EngineOn;

    // Public prototypes go here    
public:

    // Handle when a bullet hits a zombie
    bool hit();
    
    bool isAlive();
    // Spawn a new object
    void spawn(float startX, float startY, int type, int seed);
    // Return a rectangle that is the position in the world
    FloatRect getPosition();
    // Get a copy of the sprite to draw
    Sprite getSprite();
    // Update the object each frame
    void update(float elapsedTime, Vector2f playerLocation);
};
