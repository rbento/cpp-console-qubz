// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>
#include <conio.h>

#include <string>

#include "EColor.h"
#include "EChar.h"
#include "EConsole.h"

// Represent the Windows Console and provides operations to clear and write to it. 
class Console
{
private:

	Console();

public:

	static Console& Instance();

	void Initialize();

	// Clear the Windows Console buffer.
	void Clear(WORD ClearColor = EColor::Black);

	// Write text with the given color and x/y coordinate to the Windows Console. 
	void Write(const std::string& Text, const WORD TextColor = EColor::Black, int X = 0, int Y = 0);

public:

	// Windows handle to an Object.
	HANDLE Handle;

	bool bIsInitialized;
};
