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


void Score::updateScore(int scoreChange)
{
    score += scoreChange;
}