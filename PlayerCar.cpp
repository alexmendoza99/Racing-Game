#include "PlayerCar.h"
#include "TextureHolder.h"
#include <cmath>
#include <iostream>

using namespace std;
PlayerCar::PlayerCar()
{
   
    m_Speed = 0;
    m_MaxSpeed = START_MAX_SPEED;
    m_Fuel = START_MAX_FUEL;
    m_MaxFuel = START_MAX_FUEL;

    // Associate a texture with the sprite
    // !!Watch this space!!
    m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/playerCar.png"));

    // Set the origin of the sprite to the center
    m_Sprite.setOrigin(6, 10);
    m_Sprite.setScale(4, 4);

    if (!explodeSB.loadFromFile("sound/Explode.wav")) {
        cout << "ERROR: sound/Explode.wav didn't load" << endl;
    } else {
        explode.setBuffer(explodeSB);
    }

    if (!powerUpSB.loadFromFile("sound/Powerup.wav")) {
        cout << "ERROR: sound/Powerup.wav didn't load" << endl;
    } else {
        powerUp.setBuffer(powerUpSB);   
    }  

   if (!bumpSB.loadFromFile("sound/Bump.wav")) {
        cout << "ERROR: sound/Bump.wav didn't load" << endl;
    } else {
        bump.setBuffer(bumpSB);   
    }  
}


void PlayerCar::spawn(int start_pos)
{
    // Place the player in the middle of the road
    m_Position.x = start_pos;
    m_Position.y = DEFAULT_Y_POS;
    m_LeftPressed = false;
    m_RightPressed = false;
}

void PlayerCar::reset()
{
    m_Position.x = 0;
    m_Position.y = DEFAULT_Y_POS;
    m_TravelDistance = 0;
    m_EngineOn = false;
    m_Dead = false;

    m_Speed = 0;
    m_MaxSpeed = START_MAX_SPEED;
    m_Fuel = START_MAX_FUEL;
    m_MaxFuel = START_MAX_FUEL;
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


float PlayerCar::getLastHitTime()
{
    return m_LastHit;
}


void PlayerCar::slip(float timeHit)
{
    bump.setVolume(100);
    bump.play();
    m_Sprite.setRotation(45);
    m_LastHit = timeHit;
    slipTimer = 1.0;
    m_Fuel -= 10;
}


void PlayerCar::killHit()
{
    setDeath(true);
}


void PlayerCar::hit(float timeHit)
{
   

    if (timeHit - m_LastHit > 1.0)
    {
        slip(timeHit);
    }
    else
    {
        killHit();
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
    if (m_EngineOn)
    m_LeftPressed = true;
}


void PlayerCar::moveRight()
{
    if (m_EngineOn) 
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

    m_TravelDistance += (m_Speed * elapsedTime) / 4.0;

    m_Sprite.setPosition(m_Position);


    if (m_Position.x < m_LeftBound)
    {
        m_Position.x = m_LeftBound;
    }

    if (m_Position.x > m_RightBound)
    {
        m_Position.x = m_RightBound;
    }
    
    if (slipTimer > 0.0)
    {
        slipTimer -= elapsedTime;
    }
    else
    {
        m_Sprite.setRotation(0);
    }
}


void PlayerCar::upgradeSpeed()
{
    // 20% speed upgrade
    powerUp.stop();
    powerUp.setVolume(100);
    powerUp.play();
    m_MaxSpeed += (START_MAX_SPEED * .2);
}


void PlayerCar::upgradeFuel()
{
    // 20% max Fuel upgrade
    m_MaxFuel += (START_MAX_FUEL * .2);
}


void PlayerCar::increaseFuelLevel(int amount)
{
    powerUp.stop();
    powerUp.setVolume(100);
    powerUp.play();
    m_Fuel += amount;

    // But not beyond the maximum
    if (m_Fuel > m_MaxFuel)
    {
        m_Fuel = m_MaxFuel;
    }
}


void PlayerCar::setDeath(bool isDead)
{
    m_Dead = isDead;
    if (isDead)
    {
        explode.setVolume(100);
        explode.play();
        m_Speed = 0;
    }
}


bool PlayerCar::isDead()
{
    return m_Dead;
}