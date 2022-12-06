#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

// this file defines all functions used to update player score
class Score 
{
private:
    int score = 100;
public:
    Score();
    void reset();
    int getScore();
    void updateScore(int scoreChange);
};
