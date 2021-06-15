// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <string>

#include "ECanvas.h"
#include "EForegroundColor.h"
#include "EKeys.h"

#include "Canvas.h"
#include "Core.h"
#include "MathUtil.h"
#include "Screen.h"
#include "Shape.h"

class MenuScreen : public Screen
{
private:

	MenuScreen();

public:

	~MenuScreen();

	static Screen& Instance();

	void Initialize();
	void Cleanup();

	void Reset();

	void Input();
	void Update(ULONGLONG TimeDiff);
	void Paint();

	void SelectOption();

private:

	Shape Cursor;

	int CursorIndex;
	int CursorPosition[3];

	Shape OptionInfo;
	Shape OptionExit;
	Shape OptionPlay;

	Shape TitleText;
};
