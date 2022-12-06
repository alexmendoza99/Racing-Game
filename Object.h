#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCar.h"
using namespace sf;

// this file defines all the functions and variables for getting and setting objects
class Object
{
protected:
    int yLayer = 0;         // Where is this object?
    Vector2f m_Position;    // A sprite for the object
    Sprite m_Sprite;        // The relative speed of the object
    float m_Speed = 0;      // object speed
  
public:
    bool m_Alive = true;
    void spawn(float startX, float startY, float startSpeed);
    void setSprite(String texturePath);
    FloatRect getPosition();
    Sprite getSprite();
    int getYLayer();
    virtual int collide(float gameTime, PlayerCar* player);
    virtual void update(float dtAsSeconds, PlayerCar* player);
};
