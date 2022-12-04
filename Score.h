#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

class Score {
private:
    Font mainFont;
    Text infoText;
    int score;
public:
    Score();
    int getScore();
    void increaseScore();
    void decreaseScore();
    void displayScore(Text& text); //load text

};
