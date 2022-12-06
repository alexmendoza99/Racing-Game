#pragma once

#include "TextureHolder.h"
#include "PlayerCar.h"
#include "Object.h"
#include "RoadTile.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

// this file defines all functions and variables for road management
//brayden
class RoadManager
{
private:
	const int PIXEL_SIZE = 4;
	const float SCREEN_HEIGHT = 960;
	vector<RoadTile*> m_RoadTiles;
	bool m_RoadFinished = false;
	float m_RoadLength = 20 * 96.0;
public:
	RoadManager();
	void reset();
	vector<Sprite> getSprites();
	void update(float dtAsSeconds, float playerSpeed, float playerDistance);
	float getLeftBound();
	float getRightBound();
	float getLength();
};