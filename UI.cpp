#include "UI.h"

using namespace std;
using namespace sf;


UI::UI(){
    sideMap = Sprite(TextureHolder::GetTexture("Sprites/road_sidemap.png"));
    fuelLabel = Sprite(TextureHolder::GetTexture("Sprites/fuel_label.png"));
    scoreLabel = Sprite(TextureHolder::GetTexture("Sprites/score_label.png"));
    mapMarker = Sprite(TextureHolder::GetTexture("Sprites/sidemap_marker.png"));
    rightSide = Sprite(TextureHolder::GetTexture("Sprites/ui_right_backing.png"));

    fuel = 100;
    playerRatio = 0.0;
    if (!font.loadFromFile("font/Lato-Black.ttf")) {
        cout << "ERROR: font/Lato-Black.ttf didn't load" << endl;
    }
    if (!gameOverFont.loadFromFile("font/StrangerNight.ttf"))
    {
        cout << "ERROR: font/StrangerNight.ttf didn't load" << endl;
    }
};


void UI::drawSideMap(RenderWindow* window)
{
    sideMap.setPosition(-10,0);
    sideMap.setScale(4.f,4.f);
    window->draw(sideMap);
}


void UI::drawRightSide(RenderWindow* window)
{
    rightSide.setPosition(800,0);
    rightSide.setScale(4.f,4.f);
    window->draw(rightSide);
}


void UI::drawInGameUI(RenderWindow* window)
{
    drawSideMap(window);
    drawMapMarker(window);
    drawRightSide(window);
    drawScoreLabel(window);
    drawFuelLabel(window);
}


void UI::drawScoreLabel(RenderWindow* window)
{
    scoreLabel.setPosition(850,300);
    scoreLabel.setScale(3.f,3.f);
    window->draw(scoreLabel);

    stringstream s;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::White);
    displayFont.setPosition(850, 350);
    s << "00000" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);

}


void UI::drawMapMarker(RenderWindow* window)
{
    //mapMarker.setPosition(player->getPosition());
    mapMarker.setScale(2.f,2.f);
    window->draw(mapMarker);
}


void UI::drawFuelLabel(RenderWindow* window)
{
    fuelLabel.setPosition(850,450);
    fuelLabel.setScale(3.f,3.f);
    window->draw(fuelLabel);

     stringstream s;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::White);
    displayFont.setPosition(850, 500);
    s << "00000" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);

}


void UI::drawGameOver(RenderWindow* window)
{
    stringstream s;
    
    displayFont.setFont(gameOverFont);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::Red);
    displayFont.setPosition(512,480);
    s << "GAME OVER" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);
}


void UI::drawGameWon(RenderWindow* window)
{
    stringstream s;
    
    displayFont.setFont(gameOverFont);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::Blue);
    displayFont.setPosition(512,480);
    s << "WINNER" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);
}


void UI::drawStartMenu(RenderWindow* window)
{
     stringstream s;
    
    displayFont.setFont(gameOverFont);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::Green);
    displayFont.setPosition(512,480);
    s << "Racing 400!!!" << endl;
    s << "press space to start" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);
}

