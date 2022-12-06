#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

class Score {
private:
    int score;
public:
    Score();
    int setScore;
    void updateScore(int scoreChange);
};
