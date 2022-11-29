#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Object
{
protected:
    // Where is this object?
    Vector2f m_Position;
    // A sprite for the object
    Sprite m_Sprite;
    // The relative speed of the object
    float m_Speed = 0;
    // How tough the object is (also how much fuel the player looses when hitting)
    float m_Strength = 0;

    // Public prototypes go here    
public:
    // Handle when player hits the object
    bool hit();
    
    bool isAlive();
    // Spawn a new object
    void spawn(float startX, float startY, float startSpeed);
    // Return a rectangle that is the position in the world
    FloatRect getPosition();
    // Get a copy of the sprite to draw
    Sprite getSprite();
    // Update the object each frame
    void update(float dtAsSeconds, float playerSpeed);
};
