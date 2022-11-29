#include "Object.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

void Object::spawn(float startX, float startY, float startSpeed)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("Cars/enemyCar.png"));
    m_Speed = startSpeed;

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(0, 0);
    // Set its position
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale(5, 5);
}


FloatRect Object::getPosition()
{
    return m_Sprite.getGlobalBounds();
}


Sprite Object::getSprite()
{
    return m_Sprite;
}


void Object::update(float dtAsSeconds, float playerSpeed)
{
    m_Position.y -= (m_Speed - playerSpeed) * dtAsSeconds;

    // Move the sprite
    m_Sprite.setPosition(m_Position);
}



// This code should be specifically for AI Car's update, which will be an inherited class object
/*
void Object::update(float elapsedTime, Vector2f playerLocation)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    // Update the object's position variables
    if (playerX > m_Position.x)
    {
        m_Position.x = m_Position.x +
            m_Speed * elapsedTime;
    }
    if (playerY > m_Position.y)
    {
        m_Position.y = m_Position.y +
            m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x)
    {
        m_Position.x = m_Position.x -
            m_Speed * elapsedTime;
    }
    if (playerY < m_Position.y)
    {
        m_Position.y = m_Position.y -
            m_Speed * elapsedTime;
    }

    // Move the sprite
    m_Sprite.setPosition(m_Position);
}
*/

