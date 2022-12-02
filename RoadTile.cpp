#include <SFML/Graphics.hpp>
#include "RoadTile.h"
#include "TextureHolder.h"

using namespace sf;


RoadTile::RoadTile()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/roadtile.png"));
	m_Sprite.setScale(4, 4);
}


RoadTile::RoadTile(float leftBound, float rightBound)
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/roadtile.png"));
	m_Sprite.setScale(4, 4);
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


void RoadTile::setType(TileType newType)
{
	m_Type = newType;
	switch (m_Type)
	{
	case TileType::START:
		m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/startroadtile.png"));
		break;
	case TileType::FINISH:
		m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/finishroadtile.png"));
		break;
	case TileType::STRAIGHT_1:
		m_Sprite = Sprite(TextureHolder::GetTexture("Sprites/roadtile.png"));
		break;
	}
	m_Sprite.setScale(4, 4);
}


float RoadTile::getLeftBound()
{
	return m_LeftBound;
}


float RoadTile::getRightBound()
{
	return m_RightBound;
}