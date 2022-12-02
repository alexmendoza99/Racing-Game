#include "Object.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;


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


void Object::collide(PlayerCar* player)
{

}


void Object::update(float dtAsSeconds, PlayerCar* player)
{
    m_Position.y -= (m_Speed - player->getSpeed()) * dtAsSeconds;

    // Move the sprite
    m_Sprite.setPosition(m_Position);
}





