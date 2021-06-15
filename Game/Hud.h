// Copyright (c) Rodrigo Bento

#pragma once

#include <string>

#include "EBackgroundColor.h"
#include "ECanvas.h"
#include "EChar.h"
#include "EForegroundColor.h"
#include "EPixel.h"

#include "Shape.h"

class Hud
{
public:

	Hud();

	void Initialize();
	void Cleanup();

	Shape* GetBoardFrame();

	Shape* GetLinesTitle();
	Shape* GetNextTitle();
	Shape* GetScoreTitle();
	Shape* GetSpeedTitle();
	Shape* GetTimeTitle();

	Shape* GetScoreValue(int Value);
	Shape* GetSpeedValue(int Value);
	Shape* GetTimeValue(int Value);
	Shape* GetLinesValue(int Value);
	Shape* GetMessageValue(const std::string& Value);

private:

	Shape BoardFrame;

	Shape LinesTitle;
	Shape NextTitle;
	Shape ScoreTitle;
	Shape SpeedTitle;
	Shape TimeTitle;

	Shape LinesValue;
	Shape ScoreValue;
	Shape SpeedValue;
	Shape TimeValue;
	Shape MessageValue;

	std::string Lines;
	std::string Score;
	std::string Speed;
	std::string Time;
};
