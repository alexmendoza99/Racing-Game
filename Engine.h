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

// this file defines the the classes, functions and states to build the game
class Engine
{
private:
	TextureHolder th;				// stores texture 
	RoadManager road;				// builds road map
	PlayerCar player;				// handles player input
	ObjectManager objectManager;	// handles object spawing and interaction
	RenderWindow m_Window;			// for winow manipulation
	MusicManager musicManager;		// handles audio for music
	UI UI;							// user interface and draws different states
	Score score;					// handles score

	View m_MainView;				// view class

	float totalGameTime = 0.0;		// length of gameplay

	// The game will always be in one of these states
	enum class State {MAIN_MENU, LEVEL_COUNTDOWN, PAUSED, PLAYING, PLAYER_DIED, LEVEL_WON, GAME_OVER, GAME_WON};
	// Start with the MAIN_MENU state
	State state = State::MAIN_MENU;

	void setState(State newState);
	void input();
	void update(float dtAsSeconds);
	void draw();
	void drawGameplay();

public:
	Engine();
	void run();
};