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
	RoadTile();
	RoadTile(float leftBound, float rightBound);
	Sprite getSprite();
	Vector2f getPosition();
	void setPosition(Vector2f position);
	float getLeftBound();
	float getRightBound();
};