#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;


Fuel::Fuel()
{
    yLayer = 0;
    setSprite("Sprites/fueltank.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}


int Fuel::collide(float gameTime, PlayerCar* player)
{
    player->increaseFuelLevel(10);
    m_Alive = false;
    return 10;
}