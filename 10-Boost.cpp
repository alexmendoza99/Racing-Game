#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;

// If the player comes into contact with the boost sprite the speed of the game is increased
Boost::Boost()
{
    yLayer = 0;
    setSprite("Sprites/speedboost.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}

// updates score and screen presence
int Boost::collide(float gameTime, PlayerCar* player)
{
    player->upgradeSpeed();
    m_Alive = false;
    return 15;
}