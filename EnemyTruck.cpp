#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;


EnemyTruck::EnemyTruck()
{
    yLayer = 1;
    setSprite("Sprites/enemytruck.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
    int chance = rand() % 2;
    if (chance == 0) m_AICar = true;
    else m_AICar = false;
}


void EnemyTruck::collide(PlayerCar* player)
{
    cout << "COLLIDE WITH TRUCK" << endl;
}


void EnemyTruck::update(float dtAsSeconds, PlayerCar* playerCar)
{
    Object::update(dtAsSeconds, playerCar);
    float playerX = playerCar->getCenter().x;
    float playerY = playerCar->getCenter().y;
    // Update the object's position variables
    if ((playerY > m_Position.y) && (playerY - m_Position.y) < 400 && m_AICar)
    {
        if (playerX > m_Position.x)
        {
            m_Position.x = m_Position.x +
                steerSpeed * dtAsSeconds;
        }
        if (playerX < m_Position.x)
        {
            m_Position.x = m_Position.x -
                steerSpeed * dtAsSeconds;
        }
    }

    // Move the sprite
    m_Sprite.setPosition(m_Position);
}