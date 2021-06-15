
#include "Core.h"

Core::Core() :
	CurrentScreen(nullptr),
	bIsRunning(false)
{
	srand(static_cast<unsigned int>(time(0)));
}

Core::~Core()
{
}

Core& Core::Instance()
{
	static Core Instance;
	return Instance;
}

void Core::Startup()
{
	ShowMenu();
	bIsRunning = true;
}

void Core::Shutdown()
{
}

void Core::ChangeScreen(Screen& NewScreen)
{
	if (CurrentScreen)
	{
		CurrentScreen->Cleanup();
	}

	CurrentScreen = &NewScreen;

	CurrentScreen->Initialize();
}

void Core::Exit()
{
	bIsRunning = false;
}

void Core::Run()
{
	ULONGLONG FrameRate = 1000 / 60;
	ULONGLONG CurrentTick = GetTickCount64();
	ULONGLONG LastTick = GetTickCount64();
	ULONGLONG TickDiff = CurrentTick - LastTick;

	while (bIsRunning)
	{
		CurrentTick = GetTickCount64();

		TickDiff = CurrentTick - LastTick;

		if (CurrentTick - LastTick >= FrameRate)
		{
			if (CurrentScreen)
			{
				CurrentScreen->Input();
				CurrentScreen->Update(TickDiff);
				CurrentScreen->Paint();
			}

			LastTick = CurrentTick;
		}
	}
}

void Core::ShowMenu()
{
	ChangeScreen(MenuScreen::Instance());
}

void Core::ShowInfo()
{
	ChangeScreen(InfoScreen::Instance());
}

void Core::ShowGame()
{
	ChangeScreen(GameScreen::Instance());
}
