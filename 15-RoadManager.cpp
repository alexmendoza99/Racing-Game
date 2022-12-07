#include "Engine.h"
#include "RoadManager.h"
#include "RoadTile.h"
#include "TextureHolder.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


RoadManager::RoadManager() 
{
	reset();
}

// Reset all the functionality of the Road when entering the Title Menu
void RoadManager::reset()
{
	if (m_RoadTiles.size() > 0) biome = static_cast<BIOME_TYPE>(rand() % 3); // Ensures we always start with grass level
	for (RoadTile* tile : m_RoadTiles) { delete tile; }
	m_RoadTiles.clear();
	m_RoadFinished = false;
	float heightCounter = SCREEN_HEIGHT;

	for (int i = 0; i < 4; i++)
	{
		m_RoadTiles.push_back(new RoadTile());

		if (i == 0) { setRoadStart(m_RoadTiles[i]); }
		else { setRoadStraight(m_RoadTiles[i]);}

		float tileHeight = m_RoadTiles[i]->getSprite().getLocalBounds().height;
		heightCounter -= tileHeight * 3.9;
		m_RoadTiles[i]->setPosition(Vector2f(0, heightCounter));
	}
}

// Returns a list of the road tile sprites so they can be drawn
vector<Sprite> RoadManager::getSprites()
{
	vector<Sprite> sprites;
	for (RoadTile* tile : m_RoadTiles) { sprites.push_back(tile->getSprite()); }
	return sprites;
}

// Updates all the road tiles and moves them relative to the player speed. Also generates road based off player distance.
void RoadManager::update(float timeElapsed, float playerSpeed, float playerDistance)
{
	for (RoadTile* tile : m_RoadTiles)
	{
		if (m_RoadTiles[0]->getPosition().y >= SCREEN_HEIGHT && !m_RoadFinished)
		{
			delete m_RoadTiles[0];
			m_RoadTiles.erase(m_RoadTiles.begin());
			RoadTile* previousRoad = m_RoadTiles[m_RoadTiles.size() - 1];

			m_RoadTiles.push_back(new RoadTile);
			RoadTile* newRoad = m_RoadTiles[m_RoadTiles.size() - 1];
			setRoadStraight(newRoad);
			if (playerDistance > m_RoadLength - 224)
			{
				cout << playerDistance << endl;
				setRoadFinish(newRoad);
				m_RoadFinished = true;
			}
			float newTileY = previousRoad->getPosition().y - newRoad->getSprite().getLocalBounds().height * PIXEL_SIZE * 0.98;
			newRoad->setPosition(Vector2f(0, newTileY));
		}
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


float RoadManager::getLength()
{
	return m_RoadLength;
}

// Sets a road tile to straight of the current biome
void RoadManager::setRoadStraight(RoadTile* tile)
{
	switch (biome)
	{
	case BIOME_TYPE::GRASS:
		tile->setType(RoadTile::GRASS_STRAIGHT);
		break;
	case BIOME_TYPE::DESERT:
		tile->setType(RoadTile::DESERT_STRAIGHT);
		break;
	case BIOME_TYPE::OCEAN:
		tile->setType(RoadTile::OCEAN_STRAIGHT);
		break;
	}
}

// Sets a road tile to starting line of the current biome
void RoadManager::setRoadStart(RoadTile* tile)
{
	switch (biome)
	{
	case BIOME_TYPE::GRASS:
		tile->setType(RoadTile::GRASS_START);
		break;
	case BIOME_TYPE::DESERT:
		tile->setType(RoadTile::DESERT_START);
		break;
	case BIOME_TYPE::OCEAN:
		tile->setType(RoadTile::OCEAN_START);
		break;
	}
}

// Sets a road tile to finish line of the current biome
void RoadManager::setRoadFinish(RoadTile* tile)
{
	switch (biome)
	{
	case BIOME_TYPE::GRASS:
		tile->setType(RoadTile::GRASS_FINISH);
		break;
	case BIOME_TYPE::DESERT:
		tile->setType(RoadTile::DESERT_FINISH);
		break;
	case BIOME_TYPE::OCEAN:
		tile->setType(RoadTile::OCEAN_FINISH);
		break;
	}
}