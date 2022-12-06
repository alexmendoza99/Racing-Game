#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;


Boost::Boost()
{
    yLayer = 0;
    setSprite("Sprites/speedboost.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}


int Boost::collide(float gameTime, PlayerCar* player)
{
    player->upgradeSpeed();
    m_Alive = false;
    return 15;
}