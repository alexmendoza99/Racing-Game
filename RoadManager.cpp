#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "RoadManager.h"
#include "RoadTile.h"
#include "TextureHolder.h"
#include <iostream>

using namespace sf;
using namespace std;


RoadManager::RoadManager() 
{
	int heightCounter = 500;
	for (int i = 0; i < 4; i++)
	{
		m_RoadTiles.push_back(new RoadTile());
		m_RoadTiles[i]->setPosition(Vector2f(0, heightCounter));
		if (i == 0)
		{
			m_RoadTiles[i]->setType(RoadTile::START);
		}
		heightCounter -= 80 * 4.9; // Has to be 4.9 so the sprites slightly overlap. This prevent
	}
}


void RoadManager::reset() 
{
	for (RoadTile* tile : m_RoadTiles)
	{
		delete tile;
	}
	m_RoadTiles.clear();

	m_RoadFinished = false;
	
	int heightCounter = 500;
	for (int i = 0; i < 4; i++)
	{
		m_RoadTiles.push_back(new RoadTile());
		m_RoadTiles[i]->setPosition(Vector2f(0, heightCounter));
		if (i == 0)
		{
			m_RoadTiles[i]->setType(RoadTile::START);
		}
		heightCounter -= 80 * 4.9; // Has to be 4.9 so the sprites slightly overlap. This prevent
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


void RoadManager::update(float timeElapsed, float playerSpeed, float playerDistance)
{
	const int PIXEL_SIZE = 5;
	const int SCREEN_HEIGHT = 900;

	for (RoadTile* tile : m_RoadTiles)
	{
		if (m_RoadTiles[0]->getPosition().y >= SCREEN_HEIGHT && !m_RoadFinished)
		{
			delete m_RoadTiles[0];
			m_RoadTiles.erase(m_RoadTiles.begin());
			RoadTile* previousRoad = m_RoadTiles[m_RoadTiles.size() - 1];

			m_RoadTiles.push_back(new RoadTile);
			RoadTile* newRoad = m_RoadTiles[m_RoadTiles.size() - 1];
			newRoad->setType(RoadTile::STRAIGHT_1);

			if (playerDistance > m_RoadLength)
			{
				newRoad->setType(RoadTile::FINISH);
				m_RoadFinished = true;
			}

			float newTileY = previousRoad->getPosition().y - newRoad->getSprite().getLocalBounds().height * PIXEL_SIZE * 0.99;

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