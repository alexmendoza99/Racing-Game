#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;

// This file sets all the attributes and polymorphs the collide function for enemy cars
EnemyCar::EnemyCar()
{
    yLayer = 1;
	setSprite("Sprites/enemyCar.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
    int chance = rand() % 2;
    if (chance == 0) { m_AICar = true; }
    else { m_AICar = false; }
}

// polymorphs the collide function and returns score value for score.h
int EnemyCar::collide(float gameTime, PlayerCar* player)
{
    m_Alive = false;
    player->hit(gameTime);
    return -10;
}

//im not sure what this function does -alex check collision?
void EnemyCar::update(float dtAsSeconds, PlayerCar* playerCar)
{
    Object::update(dtAsSeconds, playerCar);
    float playerX = playerCar->getCenter().x;
    float playerY = playerCar->getCenter().y;
    // Update the object's position variables
    if ((playerY > m_Position.y) && (playerY - m_Position.y) < 400 && m_AICar)
    {
        if (playerX > m_Position.x)
        {
            m_Position.x = m_Position.x + steerSpeed * dtAsSeconds;
        }
        if (playerX < m_Position.x)
        {
            m_Position.x = m_Position.x - steerSpeed * dtAsSeconds;
        }
    }
    // Move the sprite
    m_Sprite.setPosition(m_Position);
}