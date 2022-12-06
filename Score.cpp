#include <SFML/Graphics.hpp>
#include "Score.h"
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;
using namespace sf;


Score::Score()
{
    reset();
}


void Score::reset()
{
    score = 100;
}


int Score::getScore()
{
    return score;
}


void Score::updateScore(int scoreChange)
{
    score += scoreChange;
    if (score < 0)
    {
        score = 0;
    }
}