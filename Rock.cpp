#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;


Rock::Rock()
{
    yLayer = 1;
    setSprite("Sprites/rock.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}


void Rock::collide(float gameTime, PlayerCar* player)
{
    m_Alive = false;
    player->killHit();
}