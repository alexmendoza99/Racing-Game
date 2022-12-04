#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include <vector>
#include "PlayerCar.h"
#include "Object.h"
#include "RoadTile.h"

using namespace sf;
using namespace std;

class RoadManager
{
private:
	const int PIXEL_SIZE = 4;
	const float SCREEN_HEIGHT = 960;
	vector<RoadTile*> m_RoadTiles;
	bool m_RoadFinished = false;
	float m_RoadLength = 2500;
public:
	RoadManager();
	void reset();
	vector<Sprite> getSprites();
	void update(float dtAsSeconds, float playerSpeed, float playerDistance);
	float getLeftBound();
	float getRightBound();
	float getLength();
};