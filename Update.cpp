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
    case State::MAIN_MENU:
        break;
    case State::LEVEL_COUNTDOWN:
        UI.updateMapMarker(player.getTravelDistance() / road.getLength());
        countdownTimer -= dtAsSeconds;
        if (countdownTimer <= 0)
        {
            setState(State::PLAYING);
            countdownTimer = 9.0;
            player.engineOn();
        }
        objectManager.setBounds(road.getLeftBound(), road.getRightBound());
        player.setBounds(road.getLeftBound(), road.getRightBound());
        road.update(dtAsSeconds, player.getSpeed(), player.getTravelDistance());
        player.update(dtAsSeconds);
        UI.updateCountDown(dtAsSeconds);
        break;
    case State::PAUSED:
        break;
    case State::PLAYING:
        objectManager.setBounds(road.getLeftBound(), road.getRightBound());
        player.setBounds(road.getLeftBound(), road.getRightBound());
        road.update(dtAsSeconds, player.getSpeed(), player.getTravelDistance());
        UI.updateMapMarker(player.getTravelDistance() / road.getLength());
        if (player.isDead())
        {
            setState(State::PLAYER_DIED);
        }
        player.update(dtAsSeconds);
        if (spawnTimer > 1.0)
        {
            objectManager.spawnObject();
            spawnTimer = 0;
        }
        objectManager.updateObjects(dtAsSeconds, &player);
        objectManager.manageCollisions(totalGameTime, &player, &score);
        if (player.getTravelDistance() > road.getLength() + 15)
        {
            cout << player.getTravelDistance() << endl;
            setState(State::LEVEL_WON);
        }
        spawnTimer += dtAsSeconds;
        break;
    case State::PLAYER_DIED:
        objectManager.setBounds(road.getLeftBound(), road.getRightBound());
        player.setBounds(road.getLeftBound(), road.getRightBound());
        road.update(dtAsSeconds, player.getSpeed(), player.getTravelDistance());
        if (spawnTimer > 1.0)
        {
            objectManager.spawnObject();
            spawnTimer = 0;
        }
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
        frameTimer++;
        if (frameTimer > 5000)
        {
            setState(State::MAIN_MENU);
            frameTimer = 0;
        }
        break;
    case State::GAME_OVER:
        break;
    case State::GAME_WON:
        break;
    }
}