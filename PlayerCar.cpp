#include "PlayerCar.h"
PlayerCar::PlayerCar()
{
    m_Speed = START_SPEED;
    m_Fuel = START_FUEL;
    m_MaxFuel = START_FUEL;

    // Associate a texture with the sprite
    // !!Watch this space!!
    m_Texture.loadFromFile("graphics/playerCar.png");
    m_Sprite.setTexture(m_Texture);

    // Set the origin of the sprite to the center, 
    // for smooth rotation
    m_Sprite.setOrigin(25, 25);
}

void PlayerCar::spawn(IntRect road, Vector2f resolution, int tileSize)
{
    // Place the player in the middle of the road
    m_Position.x = road.width / 2;
    m_Position.y = road.height / 2;

    // Copy the details of the road to the player's m_Road
    m_Road.left = road.left;
    m_Road.width = road.width;
    m_Road.top = road.top;
    m_Road.height = road.height;

    // Remember how big the tiles are in this road
    m_TileSize = tileSize;

    // Store the resolution for future use
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;

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

float PlayerCar::getRotation()
{
    return m_Sprite.getRotation();
}

Sprite PlayerCar::getSprite()
{
    return m_Sprite;
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
/* might not need
void PlayerCar::moveUp()
{
    m_UpPressed = true;
}
void PlayerCar::moveDown()
{
    m_DownPressed = true;
}
*/
void PlayerCar::stopLeft()
{
    m_LeftPressed = false;
}

void PlayerCar::stopRight()
{
    m_RightPressed = false;
}
/*
void PlayerCar::stopUp()
{
    m_UpPressed = false;
}

void PlayerCar::stopDown()
{
    m_DownPressed = false;
}
*/
void PlayerCar::update(float elapsedTime, Vector2i mousePosition)
{
/* might not need
    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
*/
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    m_Sprite.setPosition(m_Position);



    // Keep the player car in the road
    if (m_Position.x > m_Road.width - m_TileSize)
    {
        m_Position.x = m_Road.width - m_TileSize;
    }

    if (m_Position.x < m_Road.left + m_TileSize)
    {
        m_Position.x = m_Road.left + m_TileSize;
    }

    if (m_Position.y > m_Road.height - m_TileSize)
    {
        m_Position.y = m_Road.height - m_TileSize;
    }

    if (m_Position.y < m_Road.top + m_TileSize)
    {
        m_Position.y = m_Road.top + m_TileSize;
    }
    // Calculate the angle the player is facing
    float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
        mousePosition.x - m_Resolution.x / 2)
        * 180) / 3.141;

    m_Sprite.setRotation(angle);
}

void PlayerCar::upgradeSpeed()
{
    // 20% speed upgrade
    m_Speed += (START_SPEED * .2);
}

void PlayerCar::upgradeFuel()
{
    // 20% max Fuel upgrade
    m_MaxFuel += (START_FUEL * .2);

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
