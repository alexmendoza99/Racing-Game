#include "Objects.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void Object::spawn(float startX, float startY, int type, int seed)
{

    switch (type)
    {
    case 0:
        // aiCar
        m_Sprite = Sprite(TextureHolder::GetTexture(
            "graphics/aiCar.png"));
        m_Speed = AICAR_SPEED;
        m_Fuel = AICAR_FUEL;
//we can use fuel levels of objects and use that value in a formula to determine the force of impacts and if the impact value is high the car explodes and if the impact value is low the car gets bumped
        break;
    case 1:
        // log
        m_Sprite = Sprite(TextureHolder::GetTexture(
            "graphics/log.png"));
        m_Speed = LOG_SPEED;
        m_Fuel = LOG_FUEL;
        break;
    case 2:
        // oil
        m_Sprite = Sprite(TextureHolder::GetTexture(
            "graphics/oil.png"));
        m_Speed = OIL_SPEED;
        m_Fuel = OIL_FUEL;
        break;
    }
    // Modify the speed to make the objects unique
    // Every object is unique. Create a speed modifier
    srand((int)time(0) * seed);
    // Somewhere between 80 and 100
    float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
    // Express this as a fraction of 1
    modifier /= 100; // Now equals between .7 and 1
    m_Speed *= modifier;

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(25, 25);
    // Set its position
    m_Sprite.setPosition(m_Position);
}

bool Object::hit()
{
//this is where we can calculate the players speed and the force when the player collides with an object
    m_Fuel--;
    if (m_Fuel < 0)
    {
        // game over
        m_EngineOn = false;
        m_Sprite.setTexture(TextureHolder::GetTexture(
            "graphics/.png"));
        return true;
    }
    // injured but not dead yet
    return false;
}

/*bool Object::engineOn()
{
    return m_EngineOn;
}
*/
FloatRect Object::getPosition()
{
    return m_Sprite.getGlobalBounds();
}
Sprite Object::getSprite()
{
    return m_Sprite;
}

void Object::update(float elapsedTime,
    Vector2f playerLocation)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    // Update the object's position variables
    if (playerX > m_Position.x)
    {
        m_Position.x = m_Position.x +
            m_Speed * elapsedTime;
    }
    if (playerY > m_Position.y)
    {
        m_Position.y = m_Position.y +
            m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x)
    {
        m_Position.x = m_Position.x -
            m_Speed * elapsedTime;
    }
    if (playerY < m_Position.y)
    {
        m_Position.y = m_Position.y -
            m_Speed * elapsedTime;
    }
    // Move the sprite
    m_Sprite.setPosition(m_Position);
    // Face the sprite in the correct direction
    /*float angle = (playerY - m_Position.y,
        playerX - m_Position.x)
        * 180 / 3.141;
    m_Sprite.setRotation(angle);
    */
}
