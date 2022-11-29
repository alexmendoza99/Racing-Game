#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "PlayerCar.h"
#include "Object.h"
#include "RoadManager.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	RoadManager road;

	PlayerCar player;

	Object evilCar;

	RenderWindow m_Window;

	View m_MainView;

	// The game will always be in one of these states
	enum class State {MAIN_MENU, LEVEL_COUNTDOWN, PAUSED, PLAYING, LEVEL_WON, GAME_OVER, GAME_WON};
	// Start with the MAIN_MENU state
	State state = State::MAIN_MENU;

	void setState(State newState);
	void input();
	void update(float dtAsSeconds);
	void draw();
public:
	Engine();
	void run();
};