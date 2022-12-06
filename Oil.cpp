#include "GameObjects.h"
#include "Object.h"
#include <iostream>

using namespace std;


Oil::Oil()
{
    yLayer = 0;
    int chance = rand() % 2;
    if (chance == 0) setSprite("Sprites/oilspill_1.png");
    else setSprite("Sprites/oilspill_2.png");
    m_Sprite.setOrigin(Vector2f(m_Sprite.getTexture()->getSize().x / 2.0, m_Sprite.getTexture()->getSize().y / 2.0));
}


int Oil::collide(float gameTime, PlayerCar* player)
{
    if (!m_PlayerCollided)
    {
        cout << "COLLIDE WITH OIL" << endl;
        m_PlayerCollided = true;
        player->slip(gameTime);
        return -5;
    }
}