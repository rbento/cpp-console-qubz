// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <cmath>

class MathUtil
{
public:

	// Generates a random number between 0 and limit, inclusive. 
	static int NextInt(const int Limit)
	{
		return rand() / (Limit + 1); // srand is initialized at Core::Core
	}

	// Generates a random number between lower and upper, inclusive. 
	static int NextInt(const int Lower, const int Upper)
	{
		int Range = abs(Upper - Lower);
		return NextInt(Range) + Lower;
	}

	// Clamps a value between min and max. 
	static void Clamp(ULONGLONG& Value, const ULONGLONG Min, const ULONGLONG Max)
	{
		Value = Value < Min ? Min : (Value > Max ? Max : Value);
	}

	// Clamps a value between min and max. 
	static void Clamp(int& Value, const int Min, const int Max)
	{
		Value = Value < Min ? Min : (Value > Max ? Max : Value);
	}

	// Rotates a value between min and max. 
	static int Rotate(int& Value, const int Min, const int Max)
	{
		return Value < Min ? Max : (Value > Max ? Min : Value);
	}
};
