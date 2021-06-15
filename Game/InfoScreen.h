// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <string>

#include "ECanvas.h"
#include "EChar.h"
#include "EForegroundColor.h"
#include "EKeys.h"

#include "Canvas.h"
#include "Core.h"
#include "MathUtil.h"
#include "Screen.h"
#include "Shape.h"

class InfoScreen : public Screen
{
private:

	InfoScreen();

public:

	~InfoScreen();

	static Screen& Instance();

	void Initialize();
	void Cleanup();

	void Reset();

	void Input();
	void Update(ULONGLONG TimeDiff);
	void Paint();

private:

	Shape Cursor;

	Shape CopyrightText;
	Shape KeyActionText;
	Shape KeyResetText;
	Shape KeyExitText;
	Shape OptionBackText;
	Shape TitleText;
};
