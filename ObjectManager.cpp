#include<cstdlib>
#include "ObjectManager.h"
#include "GameObjects.h"
#include "Object.h"
#include <iostream>
#include <random>

using namespace std;


ObjectManager::ObjectManager()
{
	clearObjects();
}


void ObjectManager::setBounds(float leftBound, float rightBound)
{
	m_leftBound = leftBound;
	m_rightBound = rightBound;
}


void ObjectManager::updateObjects(float dtAsSeconds, PlayerCar* player)
{
	for (Object* object : m_Objects)
	{
		object->update(dtAsSeconds, player);
	}
}


void ObjectManager::drawObjects(RenderWindow* window)

{
	for (Object* object : m_Objects)
	{
		window->draw(object->getSprite());
	}
}


void ObjectManager::manageCollisions(PlayerCar* player)
{
	for (Object* object : m_Objects)
	{
		FloatRect objectBox = object->getPosition();
		FloatRect playerBox = player->getPosition();


		if ((playerBox.left + playerBox.width) > objectBox.left && playerBox.left < (objectBox.left + objectBox.width))
		{
			if ((playerBox.top + playerBox.height) > objectBox.top && playerBox.top < (objectBox.top + objectBox.height))
			{
				object->collide(player);
			}
		}
	}
}


void ObjectManager::spawnObject()
{
	// Get a random number
	int randomID = 0;
	float randomX = (float)(rand() % (int)(m_rightBound - m_leftBound)) + m_leftBound;

	if (randomID == CAR)
	{
		EnemyCar* newEnemyCar = new EnemyCar;
		m_Objects.push_back(newEnemyCar);
		newEnemyCar->spawn(randomX, SPAWN_HEIGHT, 400);
	}
	else if (randomID == TRUCK)
	{

	}
	else if (randomID == OIL)
	{

	}
	else if (randomID == ROCK)
	{

	}
	else if (randomID == FUEL)
	{

	}
	else if (randomID == BOOST)
	{

	}
}


void ObjectManager::clearObjects()
{
	if (m_Objects.size() > 0)
	{
		for (Object* object : m_Objects)
		{
			delete object;
		}
		m_Objects.clear();
	}
}