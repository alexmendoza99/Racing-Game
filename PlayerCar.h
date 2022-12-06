#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

// this file defines all functions and variables for the player
class PlayerCar
{
private:
    const float START_MAX_SPEED = 850;
    const float START_MAX_FUEL = 100;
    const float STEER_SPEED = 500;
    const float DEFAULT_Y_POS = 700;

    bool m_EngineOn = false;
    
    Vector2f m_Position;    // Where is the player
    Sprite m_Sprite;
    Vector2f m_Resolution;

    // Which directions is the player currently moving in
    bool m_LeftPressed;
    bool m_RightPressed;

    float m_LeftBound = 0;
    float m_RightBound = 1280;

    int m_Fuel;             // fuel amount
    int m_MaxFuel;
    float fuelCountDown = 100;
    float countdown = 30.0;

    float m_LastHit;

    // Forward Speed used by other objects and road to move
    float m_Speed;
    float m_MaxSpeed;

    //
    const float SLIP_TIME = 0.75;
    float slipTimer = 0.0;

    float m_TravelDistance = 0;

    bool m_Dead = false;

    SoundBuffer bumpSB;
    Sound bump;
public:
    PlayerCar();
    
    SoundBuffer explodeSB;      //sfx definitions
    Sound explode;

    SoundBuffer powerUpSB;
    Sound powerUp;
    
    void spawn(int start_pos);
    void reset();
    void engineOn();
    void setBounds(float leftBound, float rightBound);
    
    // Handle the player getting hit by a objects

    void slip(float timeHit);       // slip when in contact with enemy object
    void killHit();                 // instant kill
    void hit(float timeHit);        // slip and kill if slipping
    float getLastHitTime();         // time player last hit
    FloatRect getPosition();        // player position
    Vector2f getCenter();           // get player center
    Sprite getSprite();             // Send a copy of the sprite to main
    float getSpeed();               // Return the forward speed of the car
    float getTravelDistance();      // get player's distance traveled
                    // How much fuel player has

    // The next two functions move the player horizontally
    void moveLeft();
    void moveRight();

    // Stop the player moving in a specific direction
    void stopLeft();
    void stopRight();

    // We will call this function once every frame
    void update(float elapsedTime);

    void upgradeSpeed();                //speed boost
    void upgradeFuel();                 // fuel increase
    void increaseFuelLevel(int amount); //increase max fuel amount
    void updateFuel(int fuelChange, float dtAsSeconds);
    void fuelUpdateCountDown(float dtAsSeconds);
    void fuelResetCountDown();
    int getFuel(); 
    void fuelReset();

    void setDeath(bool isDead);
    bool isDead();
    
    void playCrash();
    void playExplode();
};
