#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

class Score {
private:
    int score = 100;
public:
    Score();
    void reset();
    int getScore();
    void updateScore(int scoreChange);
};
