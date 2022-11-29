#include <SFML/Graphics.hpp>
#include "RoadManager.h"
#include "RoadTile.h"
#include "TextureHolder.h"
#include <iostream>

using namespace sf;
using namespace std;


RoadManager::RoadManager() {
	int heightCounter = 600;
	for (int i = 0; i < 100; i++)
	{
		m_RoadTiles.push_back(new RoadTile);
		m_RoadTiles[i]->setPosition(Vector2f(0, heightCounter));
		heightCounter -= 80 * 4.9;
	}
}


vector<Sprite> RoadManager::getSprites()
{
	vector<Sprite> sprites;
	for (RoadTile* tile : m_RoadTiles)
	{
		sprites.push_back(tile->getSprite());
	}
	return sprites;
}


void RoadManager::update(float timeElapsed, float playerSpeed)
{
	for (RoadTile* tile : m_RoadTiles)
	{	
		tile->setPosition(tile->getPosition() + Vector2f(0, playerSpeed * timeElapsed));
	}
}


float RoadManager::getLeftBound()
{
	return m_RoadTiles[0]->getLeftBound();
}


float RoadManager::getRightBound()
{
	return m_RoadTiles[0]->getRightBound();
}