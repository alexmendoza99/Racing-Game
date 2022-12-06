#include "Score.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;
using namespace sf;

// this file handles players score
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

    if (score < 0) { score = 0; }
}