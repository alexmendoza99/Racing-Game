#pragma once
#include "TextureHolder.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>


using namespace sf;
using namespace std;

class UI{
private:
    int score = 0;
    int fuel;
    float playerRatio;
    Font font;
    Font gameOverFont;
    Text displayFont;
    stringstream s;
    //1
    Sprite sideMap;
    Texture textureSideMap = TextureHolder::GetTexture("Sprites/road_sidemap.png");
    //2
    Sprite fuelLabel;
    Texture textureFuelLabel = TextureHolder::GetTexture("Sprites/fuel_label.png");
    //3
    Sprite scoreLabel;
    Texture texturescoreLabel = TextureHolder::GetTexture("Sprites/score_label.png");
    //4
    Sprite mapMarker;
    Texture textureMapMarker = TextureHolder::GetTexture("Sprites/sidemap_marker.png");
    //5
    Sprite rightSide;
    Texture textureRightSide = TextureHolder::GetTexture("Sprites/ui_right_backing.png");

public:
    UI();
    void drawSideMap(RenderWindow* window);
    void drawFuelLabel(RenderWindow* window);
    void drawScoreLabel(RenderWindow* window);
    void drawMapMarker(RenderWindow* window);
    void drawRightSide(RenderWindow* window);
    void drawGameOver(RenderWindow* window);
    void drawStartMenu(RenderWindow* window);

    
};