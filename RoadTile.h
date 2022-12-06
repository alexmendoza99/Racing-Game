#pragma once
#include "TextureHolder.h"
#include <SFML/Graphics.hpp>
#include <vector>

// this file defines all the functions and variables used for building the sprites for road map
class RoadTile
{
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	float m_LeftBound = 81 * 4;
	float m_RightBound = 174 * 4;
public:
	enum TileType { 
		GRASS_START,
		GRASS_STRAIGHT, 
		GRASS_FINISH,
		DESERT_START,
		DESERT_STRAIGHT,
		DESERT_FINISH,
		OCEAN_START,
		OCEAN_STRAIGHT,
		OCEAN_FINISH
	};
	TileType m_Type = TileType::GRASS_STRAIGHT;
	RoadTile();
	RoadTile(float leftBound, float rightBound);
	Sprite getSprite();
	Vector2f getPosition();
	void setPosition(Vector2f position);
	void setType(TileType newType);
	float getLeftBound();
	float getRightBound();
};