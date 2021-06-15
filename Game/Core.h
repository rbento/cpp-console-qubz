// Copyright (c) Rodrigo Bento

#pragma once

#include <ctime>

#include "GameScreen.h"
#include "InfoScreen.h"
#include "MenuScreen.h"

class Core
{
private:

	Core();

public:

	~Core();

	static Core& Instance();

	void Startup();
	void Shutdown();

	void Run();
	void Exit();

	void ChangeScreen(Screen& NewScreen);

	void ShowMenu();
	void ShowInfo();
	void ShowGame();

private:

	bool bIsRunning;

	Screen* CurrentScreen;
};
