#include "UI.h"

using namespace std;
using namespace sf;

// this file draws images in the game that get called in the update function
UI::UI(){
    sideMap = Sprite(TextureHolder::GetTexture("Sprites/road_sidemap.png"));
    fuelLabel = Sprite(TextureHolder::GetTexture("Sprites/fuel_label.png"));
    scoreLabel = Sprite(TextureHolder::GetTexture("Sprites/score_label.png"));
    mapMarker = Sprite(TextureHolder::GetTexture("Sprites/sidemap_marker.png"));
    rightSide = Sprite(TextureHolder::GetTexture("Sprites/ui_right_backing.png"));
    title = Sprite(TextureHolder::GetTexture("Sprites/main_menu.png"));

    fuel = 100;
    playerRatio = 0.0;
    if (!font.loadFromFile("font/ARCADECLASSIC.ttf")) {
        cout << "ERROR: font/ARCADECLASSIC.ttf didn't load" << endl;
    }
};


void UI::drawSideMap(RenderWindow* window)
{
    sideMap.setPosition(-10, 0);
    sideMap.setScale(4.f, 4.f);
    window->draw(sideMap);
}


void UI::drawRightSide(RenderWindow* window)
{
    rightSide.setPosition(810,0);
    rightSide.setScale(4.f,4.f);
    window->draw(rightSide);
}


void UI::drawInGameUI(RenderWindow* window, int score)
{
    drawSideMap(window);
    drawMapMarker(window);
    drawRightSide(window);
    drawScoreLabel(window, score);
    drawFuelLabel(window);
}


void UI::drawScoreLabel(RenderWindow* window, int score)
{
    scoreLabel.setPosition(850,300);
    scoreLabel.setScale(3.f,3.f);
    window->draw(scoreLabel);

    stringstream s;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(30);
    displayFont.setColor(Color::White);
    displayFont.setPosition(850, 350);
    s << setw(5) << setfill('0') << score << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);
}


void UI::drawMapMarker(RenderWindow* window)
{
    mapMarker.setScale(4.f,4.f);
    window->draw(mapMarker);
}


void UI::updateMapMarker(float ratio)
{
    float bottomScreen = 880;
    float topScreen = 16;
    playerRatio = ratio;
    float positionY = bottomScreen - ((bottomScreen - topScreen) * ratio);
    mapMarker.setPosition(74, positionY);
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
    s << setw(5) << "00000" << endl;
    displayFont.setString(s.str());
    window->draw(displayFont);

}


void UI::drawGameOver(RenderWindow* window, int score)
{
    stringstream s1, s2;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(150);
    displayFont.setColor(Color::Red);
    displayFont.setPosition(200,280);
    displayFont.setOutlineColor(Color::Black);
    displayFont.setOutlineThickness(4.0);
    s1 << "GAME OVER" << endl;
    displayFont.setString(s1.str());
    window->draw(displayFont);
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(50);
    displayFont.setColor(Color::Red);
    displayFont.setPosition(450, 500);
    displayFont.setOutlineColor(Color::Black);
    displayFont.setOutlineThickness(4.0);
    s2 << "Score" << endl;
    s2 << "      " << score << endl;
    displayFont.setString(s2.str());
    window->draw(displayFont);
}


void UI::drawGameWon(RenderWindow* window, int score)
{
    stringstream s1, s2;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(150);
    displayFont.setColor(Color::Blue);
    displayFont.setPosition(300,280);
    displayFont.setOutlineColor(Color::Black);
    displayFont.setOutlineThickness(4.0);
    s1 << "Winner" << endl;
    displayFont.setString(s1.str());
    window->draw(displayFont);
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(50);
    displayFont.setColor(Color::Blue);
    displayFont.setPosition(450, 500);
    displayFont.setOutlineColor(Color::Black);
    displayFont.setOutlineThickness(4.0);
    s2 << "Score" << endl;
    s2 << "      " << score << endl;
    displayFont.setString(s2.str());
    window->draw(displayFont);
}

void UI::drawStartMenu(RenderWindow* window)
{
    
    stringstream s;
   
    displayFont.setFont(font);
    displayFont.setCharacterSize(80);
    displayFont.setColor(Color::White);
    displayFont.setPosition(150,700);
    s << "press  space  to  start" << endl;
    displayFont.setString(s.str());
    
    title.setPosition(0,0);
    title.setScale(4.f,4.f);
    window->draw(title);
    window->draw(displayFont); 

}

void UI::drawCountDown(RenderWindow* window)
{
    Clock clock;
    stringstream s;
    
    displayFont.setFont(font);
    displayFont.setOutlineColor(Color::Black);
    displayFont.setOutlineThickness(4.0);
    displayFont.setCharacterSize(100);
    displayFont.setColor(Color::White);
    displayFont.setPosition(486,300);
    if (countdown < 3)
    {
        if (countdown > 2)
        {
            s << "3" << endl;
            displayFont.setColor(Color::Green);
            displayFont.setString(s.str());
            window->draw(displayFont);
            s.clear();
        }
        else if (countdown > 1)
        {
            s << "2" << endl;
            displayFont.setColor(Color::Yellow);
            displayFont.setString(s.str());
            window->draw(displayFont);
            s.clear();
        }
        else if (countdown > 0)
        {
            s << "1" << endl;
            displayFont.setColor(Color::Red);
            displayFont.setString(s.str());
            window->draw(displayFont);
            s.clear();
        }
    }
}

void UI::updateCountDown(float dtAsSeconds)
{
    countdown -= dtAsSeconds;
}

void UI::resetCountDown()
{
    countdown = 9.0;
}
