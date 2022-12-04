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
	for (int i = 0; i < m_Objects.size(); i++)
	{
		Object* object = m_Objects[i];
		object->update(dtAsSeconds, player);
		if (!object->m_Alive)
		{
			m_Objects.erase(m_Objects.begin() + i);
		}
	}
}


void ObjectManager::drawObjects(RenderWindow* window)
{
	for (Object* object : m_Objects)
	{
		if (object->getYLayer() == 0) window->draw(object->getSprite());
	}
	for (Object* object : m_Objects)
	{
		if (object->getYLayer() == 1) window->draw(object->getSprite());
	}
}


void ObjectManager::manageCollisions(float gameTimer, PlayerCar* player)
{
	for (Object* object : m_Objects)
	{
		FloatRect objectBox = object->getPosition();
		FloatRect playerBox = player->getPosition();


		if ((playerBox.left + playerBox.width) > objectBox.left && playerBox.left < (objectBox.left + objectBox.width))
		{
			if ((playerBox.top + playerBox.height) > objectBox.top && playerBox.top < (objectBox.top + objectBox.height))
			{
				object->collide(gameTimer, player);
			}
		}
	}
}


void ObjectManager::spawnObject()
{
	// Get a random number
	int randomID = rand() % 6;
	float randomX = (float)(rand() % (int)(m_rightBound - m_leftBound)) + m_leftBound;

	if (randomID == CAR)
	{
		EnemyCar* newEnemyCar = new EnemyCar;
		m_Objects.push_back(newEnemyCar);
		newEnemyCar->spawn(randomX, SPAWN_HEIGHT, 500);
	}
	else if (randomID == TRUCK)
	{
		EnemyTruck* newEnemyTruck = new EnemyTruck;
		m_Objects.push_back(newEnemyTruck);
		newEnemyTruck->spawn(randomX, SPAWN_HEIGHT, 485);
	}
	else if (randomID == OIL)
	{
		Oil* newOil = new Oil;
		m_Objects.push_back(newOil);
		newOil->spawn(randomX, SPAWN_HEIGHT, 0);
	}
	else if (randomID == ROCK)
	{
		Rock* newRock = new Rock;
		m_Objects.push_back(newRock);
		newRock->spawn(randomX, SPAWN_HEIGHT, 0);
	}
	else if (randomID == FUEL)
	{
		Fuel* newFuel = new Fuel;
		m_Objects.push_back(newFuel);
		newFuel->spawn(randomX, SPAWN_HEIGHT, 300);
	}
	else if (randomID == BOOST)
	{
		Boost* newBoost = new Boost;
		m_Objects.push_back(newBoost);
		newBoost->spawn(randomX, SPAWN_HEIGHT, 300);
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