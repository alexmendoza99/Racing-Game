#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class PlayerCar
{
private:
      //we can adjust the starting base speed
    const float START_MAX_SPEED = 850;
    const float START_MAX_FUEL = 100;
    const float STEER_SPEED = 500;
    const float DEFAULT_Y_POS = 700;

    bool m_EngineOn = false;
    
    // Where is the player
    Vector2f m_Position;

    // Of course we will need a sprite
    Sprite m_Sprite;

    // What is the screen resolution
    Vector2f m_Resolution;

    // Which directions is the player currently moving in
    bool m_LeftPressed;
    bool m_RightPressed;

    float m_LeftBound = 0;
    float m_RightBound = 1280;

    // How much fuel has the player got?
    int m_Fuel;
    // What is the maximum fuel the player can have
    int m_MaxFuel;

    // When was the player last hit
    float m_LastHit;

    // Forward Speed used by other objects and road to move
    float m_Speed;
    float m_MaxSpeed;

    const float SLIP_TIME = 0.75;
    float slipTimer = 0.0;

    float m_TravelDistance = 0;

    bool m_Dead = false;

    SoundBuffer bumpSB;
    Sound bump;


// All our public functions will come next
public:

    PlayerCar();

    SoundBuffer explodeSB;
    Sound explode;

    SoundBuffer powerUpSB;
    Sound powerUp;

    
    void spawn(int start_pos);

    void reset();

    void engineOn();

    void setBounds(float leftBound, float rightBound);
    
    // Handle the player getting hit by a objects
    // Only activates slip no matter the conditions
    void slip(float timeHit);

    //Instantly Kills no matter the conditions
    void killHit();

    // Causes Slip and then Kill if Slipping
    void hit(float timeHit);

    // How long ago was the player last hit
    float getLastHitTime();

    // Where is the player
    FloatRect getPosition();

    // Where is the center of the player
    Vector2f getCenter();

    // Send a copy of the sprite to main
    Sprite getSprite();

    // Return the forward speed of the car
    float getSpeed();
    
    float getTravelDistance();

    // How much fuel has the player currently got
    int getFuel();

    // The next two functions move the player horizontally
    void moveLeft();

    void moveRight();

    // Stop the player moving in a specific direction
    void stopLeft();

    void stopRight();

    // We will call this function once every frame
    void update(float elapsedTime);

    // Give player a speed boost
    void upgradeSpeed();

    // Give the player some fuel
    void upgradeFuel();

    // Increase the maximum amount of Fuel the player can have
    void increaseFuelLevel(int amount);

    void setDeath(bool isDead);

    bool isDead();
    
    void playCrash();
    void playExplode();
};
