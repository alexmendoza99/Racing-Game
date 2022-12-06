#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <random>

using namespace sf;
using namespace std;

// this file updates the games different states
int frameTimer = 0;
double spawnTimer = 0.0;
double countdownTimer = 9.0;
double gameOverTimer = 5.0;


void Engine::update(float dtAsSeconds)
{
    totalGameTime += dtAsSeconds;
    // State Specific Updates
    switch (state)
    {
    case State::LEVEL_COUNTDOWN:
        updateGameplay(dtAsSeconds);
        UI.updateCountDown(dtAsSeconds);
        UI.updateMapMarker(player.getTravelDistance() / road.getLength());
        countdownTimer -= dtAsSeconds;
        if (countdownTimer <= 0)
        {
            setState(State::PLAYING);
            countdownTimer = 9.0;
            player.engineOn();
        }
        break;
    case State::PLAYING:
        updateGameplay(dtAsSeconds);
        player.updateFuel(dtAsSeconds);
        spawnTimer += dtAsSeconds;
        if (spawnTimer > 1.0)
        {
            objectManager.spawnObject();
            spawnTimer = 0;
        }
        break;
    case State::PLAYER_DIED:
        objectManager.updateObjects(dtAsSeconds, &player);
        objectManager.manageCollisions(totalGameTime, &player, &score);
        gameOverTimer -= dtAsSeconds;
        if (gameOverTimer <= 0.0)
        {
            setState(State::MAIN_MENU);
            gameOverTimer = 5.0;
        }
        break;
    case State::LEVEL_WON:
        gameOverTimer -= dtAsSeconds;
        if (gameOverTimer <= 0.0)
        {
            setState(State::MAIN_MENU);
            gameOverTimer = 5.0;
        }
        break;
    }
}


void Engine::updateGameplay(float dtAsSeconds)
{
    if (player.isDead())
    {
        setState(State::PLAYER_DIED);
    }
    if (player.getTravelDistance() > road.getLength() + 15)
    {
        cout << player.getTravelDistance() << endl;
        setState(State::LEVEL_WON);
    }

    objectManager.setBounds(road.getLeftBound(), road.getRightBound());
    player.setBounds(road.getLeftBound(), road.getRightBound());

    road.update(dtAsSeconds, player.getSpeed(), player.getTravelDistance());
    player.update(dtAsSeconds);
    objectManager.updateObjects(dtAsSeconds, &player);
    objectManager.manageCollisions(totalGameTime, &player, &score);
    UI.updateMapMarker(player.getTravelDistance() / road.getLength());
}