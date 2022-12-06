#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;

// if the player comes in contact with the fuel sprite, player's fuel increases
Fuel::Fuel()
{
    yLayer = 0;
    setSprite("Sprites/fueltank.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}

// updates score and screen presence
int Fuel::collide(float gameTime, PlayerCar* player)
{
    if (m_Alive)
    {
        player->increaseFuelLevel(10);
        m_Alive = false;
        return 10;
    }
    else return 0;
}