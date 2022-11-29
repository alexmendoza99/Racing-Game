#include <SFML/Graphics.hpp>
#include "RoadManager.h"
#include "RoadTile.h"
#include "TextureHolder.h"
#include <iostream>

using namespace sf;
using namespace std;

RoadTile::RoadTile()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Levels\\roadtile.png"));
	m_Sprite.setScale(5, 5);
}


RoadTile::RoadTile(float leftBound, float rightBound)
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Levels\\roadtile.png"));
	m_Sprite.setScale(5, 5);
	m_LeftBound = leftBound;
	m_RightBound = rightBound;
}


Sprite RoadTile::getSprite()
{
	return m_Sprite;
}


Vector2f RoadTile::getPosition()
{
	return m_Position;
}


void RoadTile::setPosition(Vector2f position)
{
	m_Position = position;
	m_Sprite.setPosition(position);
}


float RoadTile::getLeftBound()
{
	return m_LeftBound;
}


float RoadTile::getRightBound()
{
	return m_RightBound;
}