#include "Road.h"
#include "AiCar.h"

AiCar* createAiCar(int numAiCar, IntRect road)
{
//This section will also have to change. We might not want to use the variable name AiCar and instead change it to objects that way when we are spawning in different objects ie. cars, logs etc. it’s not as confusing
    AiCar* aiCars = new AiCar[numAiCars];
    int maxY = road.height - 20;
    int minY = road.top + 20;
    int maxX = road.width - 20;
    int minX = road.left + 20;
    for (int i = 0; i < numAiCars; i++)
    {

        // Which side should the AiCars spawn
        srand((int)time(0) * i);
        int side = (rand() % 4);
        float x, y;
        switch (side)
        {
//this code will have to change since all collisions and cars spawn from the stop
        case 0:
            // left
            x = minX;
            y = (rand() % maxY) + minY;
            break;
        case 1:
            // right
            x = maxX;
            y = (rand() % maxY) + minY;
            break;
        case 2:
            // top
            x = (rand() % maxX) + minX;
            y = minY;
            break;
        case 3:
            // bottom
            x = (rand() % maxX) + minX;
            y = maxY;
            break;
        }
        // AiCar, logs, oil, Rock
        srand((int)time(0) * i * 2);
        int type = (rand() % 3);
        // Spawn the new objects into the array
        aiCars[i].spawn(x, y, type, i);

    }
    return aiCars;
}

/*
We can use this file to spawn different types of objects onto the map and make it random. This code will change a lot too
*/
