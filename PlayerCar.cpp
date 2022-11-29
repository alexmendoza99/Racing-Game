#include "PlayerCar.h"
#include "TextureHolder.h"
#include <cmath>

PlayerCar::PlayerCar()
{
    m_Speed = 0;
    m_MaxSpeed = START_MAX_SPEED;
    m_Fuel = START_MAX_FUEL;
    m_MaxFuel = START_MAX_FUEL;

    // Associate a texture with the sprite
    // !!Watch this space!!
    m_Sprite = Sprite(TextureHolder::GetTexture("Cars\\playerCar.png"));

    // Set the origin of the sprite to the center
    m_Sprite.setOrigin(7, 10);
    m_Sprite.setScale(5, 5);
}


void PlayerCar::spawn(int start_pos)
{
    // Place the player in the middle of the road
    m_Position.x = start_pos;
    m_Position.y = DEFAULT_Y_POS;

}


void PlayerCar::engineOn()
{
    m_EngineOn = true;
}


void PlayerCar::setBounds(float leftBound, float rightBound)
{
    m_LeftBound = leftBound;
    m_RightBound = rightBound;
}


Time PlayerCar::getLastHitTime()
{
    return m_LastHit;
}


bool PlayerCar::hit(Time timeHit)
{
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
    {
        m_LastHit = timeHit;
        m_Fuel -= 10;
        return true;
    }
    else
    {
        return false;
    }

}


FloatRect PlayerCar::getPosition()
{
    return m_Sprite.getGlobalBounds();
}


Vector2f PlayerCar::getCenter()
{
    return m_Position;
}


Sprite PlayerCar::getSprite()
{
    return m_Sprite;
}


float PlayerCar::getSpeed()
{
    return m_Speed;
}


float PlayerCar::getTravelDistance()
{
    return m_TravelDistance;
}


int PlayerCar::getFuel()
{
    return m_Fuel;
}


void PlayerCar::moveLeft()
{
    m_LeftPressed = true;
}


void PlayerCar::moveRight()
{
    m_RightPressed = true;
}


void PlayerCar::stopLeft()
{
    m_LeftPressed = false;
}


void PlayerCar::stopRight()
{
    m_RightPressed = false;
}


void PlayerCar::update(float elapsedTime)
{
    if (m_EngineOn)
    {
        if (m_Speed < m_MaxSpeed)
        {
            m_Speed += 1;
        }
    }

    if (m_RightPressed)
    {
        m_Position.x += STEER_SPEED * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= STEER_SPEED * elapsedTime;
    }

    m_TravelDistance += m_Speed;

    m_Sprite.setPosition(m_Position);


    if (m_Position.x < m_LeftBound)
    {
        m_Position.x = m_LeftBound;
    }

    if (m_Position.x > m_RightBound)
    {
        m_Position.x = m_RightBound;
    }
    
}


void PlayerCar::upgradeSpeed()
{
    // 20% speed upgrade
    m_MaxSpeed += (START_MAX_SPEED * .2);
}


void PlayerCar::upgradeFuel()
{
    // 20% max Fuel upgrade
    m_MaxFuel += (START_MAX_FUEL * .2);
}


void PlayerCar::increaseFuelLevel(int amount)
{
    m_Fuel += amount;

    // But not beyond the maximum
    if (m_Fuel > m_MaxFuel)
    {
        m_Fuel = m_MaxFuel;
    }
}
