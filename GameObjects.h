#pragma once
#include "Object.h"


class EnemyCar : public Object
{
private:
	float steerSpeed = 200;
	bool m_AICar = false;
public:
	EnemyCar();
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, PlayerCar* player);
};


class EnemyTruck : public Object
{
public:
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, float playerSpeed);
};


class Oil : public Object
{
public:
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, float playerSpeed);
};


class Rock : public Object
{
public:
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, float playerSpeed);
};


class Fuel : public Object
{
public:
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, float playerSpeed);
};


class Boost : public Object
{
public:
	void collide(PlayerCar* player);
	void update(float dtAsSeconds, float playerSpeed);
};