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
	vector<RoadTile*> m_RoadTiles;
public:
	RoadManager();
	vector<Sprite> getSprites();
	void update(float dtAsSeconds, float playerSpeed);
	float getLeftBound();
	float getRightBound();
};