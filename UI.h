#pragma once
#include "TextureHolder.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

// defines variables and functions used for display
using namespace sf;
using namespace std;

class UI{
private:
    int score = 100;
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
    void drawFuelLabel(RenderWindow* window, int m_Fuel);
    void drawScoreLabel(RenderWindow* window, int score);
    void drawMapMarker(RenderWindow* window);
    void updateMapMarker(float ratio);
    void drawRightSide(RenderWindow* window);
    void drawInGameUI(RenderWindow* window, int score, int m_Fuel);
    void drawGameOver(RenderWindow* window, int score);
    void drawStartMenu(RenderWindow* window);
    void drawGameWon(RenderWindow* window, int score);
    void drawCountDown(RenderWindow* window);
    
    void updateCountDown(float dtAsSeconds);
    void resetCountDown();
};