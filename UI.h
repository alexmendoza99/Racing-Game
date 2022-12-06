#pragma once
#include "TextureHolder.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>


using namespace sf;
using namespace std;

class UI{
private:
    int score = 0;
    int fuel = 100;
    float playerRatio = 0.0;

    float countdown = 9.0;

    Font font;

    Text displayFont;
    Text displayTextFont;

    stringstream s;

    Sprite sideMap;

    Sprite fuelLabel;

    Sprite scoreLabel;

    Sprite mapMarker;

    Sprite rightSide;

    Sprite title;

public:
    UI();
    void drawSideMap(RenderWindow* window);
    void drawFuelLabel(RenderWindow* window);
    void drawScoreLabel(RenderWindow* window);
    void drawMapMarker(RenderWindow* window);
    void updateMapMarker(float ratio);
    void drawRightSide(RenderWindow* window);

    void drawInGameUI(RenderWindow* window);
    void drawGameOver(RenderWindow* window);
    void drawStartMenu(RenderWindow* window);
    void drawGameWon(RenderWindow* window);
    void drawCountDown(RenderWindow* window);
    void updateCountDown(float dtAsSeconds);
    void resetCountDown();
};