#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCar.h"
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

    // Public prototypes go here    
public:
    void spawn(float startX, float startY, float startSpeed);
    void setSprite(String texturePath);
    FloatRect getPosition();
    Sprite getSprite();
    virtual void collide(PlayerCar* player);
    virtual void update(float dtAsSeconds, PlayerCar* player);
};
