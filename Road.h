#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCar.h"
#include "Objects.h"
using namespace sf;
int createBackground(VertexArray& rVA, IntRect road);
Object* collisions(int numObjects, IntRect road);
