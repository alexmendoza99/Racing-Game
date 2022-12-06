#include "Object.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

// this file gets and sets objects
// this file handles the parent functions for  defined objects to morph
// create object
void Object::spawn(float startX, float startY, float startSpeed)
{
    m_Speed = startSpeed;

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
}


void Object::setSprite(String texturePath)
{
    m_Sprite = Sprite(TextureHolder::GetTexture(texturePath));
    // Set its origin to its center
    m_Sprite.setOrigin(0, 0);
    // Set its position
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale(4, 4);
}


FloatRect Object::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Sprite Object::getSprite()
{
    return m_Sprite;
}

int Object::getYLayer()
{
    return yLayer;
}

// virtual function
int Object::collide(float gameTime, PlayerCar* player)
{
    return 0;
}
// virtual function
void Object::update(float dtAsSeconds, PlayerCar* player)
{
    m_Position.y -= (m_Speed - player->getSpeed()) * dtAsSeconds;
    // Move the sprite
    m_Sprite.setPosition(m_Position);
}





