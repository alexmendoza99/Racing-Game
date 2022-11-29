#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayerCar
{
private:
      //we can adjust the starting base speed
    const float START_SPEED = 100;
    const float START_FUEL = 100;

    // Where is the player
    Vector2f m_Position;

    // Of course we will need a sprite
    Sprite m_Sprite;

    // And a texture
    // !!Watch this space!!
    Texture m_Texture;

    // What is the screen resolution
    Vector2f m_Resolution;

    // What size is the current road
    IntRect m_Road;

    // How big is each tile of the road
    int m_TileSize;

    // Which directions is the player currently moving in
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    // How much fuel has the player got?
    int m_Fuel;
    // What is the maximum fuel the player can have
    int m_MaxFuel;

    // When was the player last hit
    Time m_LastHit;

    // Speed in pixels per second
    float m_Speed;


// All our public functions will come next
public:

    PlayerCar();

    void spawn(IntRect road, Vector2f resolution, int tileSize);
    
    // Handle the player getting hit by a objects
    bool hit(Time timeHit);

    // How long ago was the player last hit
    Time getLastHitTime();

    // Where is the player
    FloatRect getPosition();

    // Where is the center of the player
    Vector2f getCenter();

    // Which angle is the player facing. we might not need
    float getRotation();

    // Send a copy of the sprite to main
    Sprite getSprite();

    // How much fuel has the player currently got?
    int getFuel();

    // The next four functions move the player
    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    // Stop the player moving in a specific direction
    void stopLeft();

    void stopRight();

    void stopUp();

    void stopDown();

    // We will call this function once every frame
    void update(float elapsedTime, Vector2i mousePosition);

    // Give player a speed boost
    void upgradeSpeed();

    // Give the player some fuel
    void upgradeFuel();

    // Increase the maximum amount of Fuel the player can have
    void increaseFuelLevel(int amount);

    
};
