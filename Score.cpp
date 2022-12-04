#include <SFML/Graphics.hpp>
#include "Score.h"
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;
using namespace sf;

Score::Score()
{
    score = 0;
}
//increases score when player hits fuel or speed boost
void Score::increaseScore(){
    //work on getting score to increase every secong
    score += 5;
}
//decrease score everytime player hits an object
void Score::decreaseScore(){
    score += 10;
}

int Score::getScore()
{
    return score;
}

void Score::displayScore(Text& text)
{
    mainFont.loadFromFile("font/Lato-Black.ttf");
    stringstream infoStream;
    infoStream << "Score:" << score << endl;
    text. setString(infoStream.str());

}