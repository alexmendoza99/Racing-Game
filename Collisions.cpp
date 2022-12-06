#include "RoadManager.h"
#include "Object.h"
#include <SFML/Audio.hpp>

// This file controls the rand function that spawns objects in the game at the top of the map
Object* createAiCar(int numObjects, IntRect road)
{
    Object* collisions = new Object[numObjects];

// Sets the  boundries for objects to spawn on the map
    int maxY = road.height - 20;
    int minY = road.top + 20;
    int maxX = road.width - 20;
    int minX = road.left + 20;
    
// rand fir loop that controls object spawn location
    for (int i = 0; i < numObjects; i++)
    {  
        srand((int)time(0) * i);
        int side = (rand() % 4);
        float x, y;

        switch (side)
        {
        case 0: // left
            x = minX;
            y = (rand() % maxY) + minY;
            break;
        case 1: // right
            x = maxX;
            y = (rand() % maxY) + minY;
            break;
        case 2: // top
            x = (rand() % maxX) + minX;
            y = minY;
            break;
        case 3: // bottom
            x = (rand() % maxX) + minX;
            y = maxY;
            break;
        }
        // rand fucnction that chooses which object to spawn
        srand((int)time(0) * i * 2);
        int type = (rand() % 3);
    }
    return collisions;
}
