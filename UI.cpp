
#include "UI.h"
#include <cmath>
using namespace std;
using namespace sf;

UI::UI(){
    if (!font.loadFromFile("font/ARCADECLASSIC.ttf")) {
        cout << "ERROR: font/ARCADECLASSIC.ttf didn't load" << endl;
    }
    if (!textFont.loadFromFile("font/ARCADECLASSIC.ttf")) {
        cout << "ERROR: font/ARCADECLASSIC.ttf didn't load" << endl;
    }
};

void UI::drawSideMap(RenderWindow* window)
{
	sideMap.setTexture(textureSideMap);
    sideMap.setPosition(-10,0);
    sideMap.setScale(4.f,4.f);
    window->draw(sideMap);
}
void UI::drawRightSide(RenderWindow* window)
{
	rightSide.setTexture(textureRightSide);
    rightSide.setPosition(800,0);
    rightSide.setScale(4.f,4.f);
    window->draw(rightSide);
}
void UI::drawScoreLabel(RenderWindow* window)
{
	scoreLabel.setTexture(texturescoreLabel);
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
	mapMarker.setTexture(textureMapMarker);
    //mapMarker.setPosition(player->getPosition());
    mapMarker.setScale(2.f,2.f);
    window->draw(mapMarker);
}
void UI::drawFuelLabel(RenderWindow* window)
{
	fuelLabel.setTexture(textureFuelLabel);
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
    stringstream sA;
    stringstream sB;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(150);
    displayFont.setColor(Color::Red);
    displayFont.setPosition(200,280);
    sA << "GAME OVER" << endl;
    displayFont.setString(sA.str());
    window->draw(displayFont);


    displayTextFont.setFont(textFont);
    displayTextFont.setCharacterSize(70);
    displayTextFont.setColor(Color::Red);
    displayTextFont.setPosition(100,500);
    sB << "press space to play again" << endl;
    displayTextFont.setString(sB.str());
    window->draw(displayTextFont);
}
void UI::drawGameWon(RenderWindow* window)
{
    stringstream s1;
    stringstream s2;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(100);
    displayFont.setColor(Color::Blue);
    displayFont.setPosition(200,280);
    s1 << "WINNER" << endl;
    displayFont.setString(s1.str());
    window->draw(displayFont);

    //display players score here
}


void UI::drawStartMenu(RenderWindow* window)
{
     stringstream s1;
     stringstream s2;
    
    displayFont.setFont(font);
    displayFont.setCharacterSize(100);
    displayFont.setColor(Color::Green);
    displayFont.setPosition(200,280);
    s1 << "Racing 400!!!" << endl;
    displayFont.setString(s1.str());
    window->draw(displayFont);

    displayTextFont.setFont(textFont);
    displayTextFont.setCharacterSize(80);
    displayTextFont.setColor(Color::Green);
    displayTextFont.setPosition(150,500);
    s2 << "press space to start" << endl;
    displayTextFont.setString(s2.str());
    window->draw(displayTextFont);
}

void UI::drawCountDown(RenderWindow* window)
{
    /*
    Clock clock;
    int countdown = 3;

    //convert countdown to a string
    string countdownString;
    ostringstream convert;
    convert << countdown;
    countdownString = convert.str();

    //LOAD FONT AND TEXT
    sf::Text displayFont;
    displayFont.setFont(font);
    displayFont.setString(countdownString);
    displayFont.setPosition(10, 0);
    displayFont.setCharacterSize(40);

    int timer = clock.getElapsedTime().asSeconds();
    cout << timer << std::endl;
    if (timer > 0) 
    {
        countdown--;
                    
        displayTextFont.setString(to_string(countdown) );
                    clock.restart();
    }
    */
  
	displayFont.setFont(font);
	displayFont.setString("00");
	displayFont.setCharacterSize(300);
	displayFont.setFillColor(sf::Color::White);
  // Text Position //
	displayFont.setPosition(200,280);

	// Timer Variables //
	sf::Clock clock;
	float duration = 20.0f;
	float fSeconds;
	int intSeconds;

	sf::String stringSeconds;
	sf::String timerString;
    Time time = clock.restart();
		// Timer Countdown //
	while (duration > 0) {
			// Calculate countdown
			duration -= time.asSeconds();
		
			// Change float to int
			intSeconds = static_cast<int>(fSeconds);
		
			// Change int to string 
			
			stringSeconds =std::to_string(intSeconds);

           


			if (intSeconds <= 0) {
				stringSeconds = "00"; 
			}
			else if (intSeconds < 10) {
				stringSeconds = "0" + stringSeconds; 
			}

			timerString = stringSeconds;
			displayFont.setString(timerString); 
            window->draw(displayFont);
            duration--;
		}
   
}