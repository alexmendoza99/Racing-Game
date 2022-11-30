#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include <vector>

class RoadTile
{
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	float m_LeftBound = 465;
	float m_RightBound = 810;
public:
	enum TileType { START, STRAIGHT_1, FINISH };
	TileType m_Type = TileType::STRAIGHT_1;
	RoadTile();
	RoadTile(float leftBound, float rightBound);
	Sprite getSprite();
	Vector2f getPosition();
	void setPosition(Vector2f position);
	void setType(TileType newType);
	float getLeftBound();
	float getRightBound();
};