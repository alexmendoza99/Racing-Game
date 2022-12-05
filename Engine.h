#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "PlayerCar.h"
#include "ObjectManager.h"
#include "RoadManager.h"
#include "MusicManager.h"
#include "Score.h"
#include "UI.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;
	RoadManager road;
	PlayerCar player;
	ObjectManager objectManager;
	RenderWindow m_Window;
	MusicManager musicManager;
	UI UI;
	Score score;
	Text infoText;

	View m_MainView;

	float totalGameTime = 0.0;

	// The game will always be in one of these states
	enum class State {MAIN_MENU, LEVEL_COUNTDOWN, PAUSED, PLAYING, PLAYER_DIED, LEVEL_WON, GAME_OVER, GAME_WON};
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