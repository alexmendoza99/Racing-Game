#pragma once
#include "Object.h"


class EnemyCar : public Object
{
private:
	float steerSpeed = 200;
	bool m_AICar = false;
public:
	EnemyCar();
	void collide(float gameTime, PlayerCar* player);
	void update(float dtAsSeconds, PlayerCar* player);
};


class EnemyTruck : public Object
{
private:
	float steerSpeed = 100;
	bool m_AICar = false;
public:
	EnemyTruck();
	void collide(float gameTime, PlayerCar* player);
	void update(float dtAsSeconds, PlayerCar* player);
};


class Oil : public Object
{
public:
	Oil();
	void collide(float gameTime, PlayerCar* player);
	bool m_PlayerCollided = false;
};


class Rock : public Object
{
public:
	Rock();
	void collide(float gameTime, PlayerCar* player);
};


class Fuel : public Object
{
public:
	Fuel();
	void collide(float gameTime, PlayerCar* player);
};


class Boost : public Object
{
public:
	Boost();
	void collide(float gameTime, PlayerCar* player);
};