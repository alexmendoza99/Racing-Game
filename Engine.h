#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	RenderWindow m_Window;

	View m_MainWindow;
	View m_HUDView;
	View m_MenuView;

	// The game will always be in one of these states
	enum class State {MAIN_MENU, LEVEL_COUNTDOWN, PAUSED, PLAYING, LEVEL_WON, GAME_OVER, GAME_WON};
	// Start with the MAIN_MENU state
	State state = State::MAIN_MENU;

	void input();
	void update(float dtAsSeconds);
	void draw();
public:
	Engine();

	void run();
};