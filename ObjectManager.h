#pragma once
#include "Object.h"
#include "PlayerCar.h"
#include "Score.h"
#include <vector>

using namespace std;

// this file defines functions, variables and enum for setting different objects
class ObjectManager
{
private:
	const int SPAWN_HEIGHT = -200;
	vector<Object*> m_Objects;
	float m_leftBound;
	float m_rightBound;
	const int numOfTypes = 6;
	enum ObjectID
	{
		CAR,
		TRUCK,
		OIL,
		ROCK,
		FUEL,
		BOOST
	};
public:
	ObjectManager();
	void setBounds(float leftBound, float rightBound);
	void updateObjects(float dtAsSeconds, PlayerCar* player);
	void drawObjects(RenderWindow* window);
	void manageCollisions(float gameTimer, PlayerCar* player, Score* score);
	void spawnObject();
	void clearObjects();
};