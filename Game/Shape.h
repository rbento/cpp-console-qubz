// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <string>
#include <vector>

#include "EColor.h"
#include "EForegroundColor.h"
#include "EPixel.h"

class Shape
{
public:

	Shape(const int Y, const int X, const int Height, const int Width);
	Shape(const Shape& Other);
	Shape();

	virtual ~Shape();

	Shape& operator= (const Shape& Other);

	static void Fill(Shape& Shape, const std::string& String, WORD Color);
	static Shape FromString(const std::string& String, WORD Color = EForegroundColor::White, const int X = 0, const int Y = 0);

	int Top() { return Y; }
	int Right() { return (X + Width) - 1; }
	int Bottom() { return (Y + Height) - 1; }
	int Left() { return X; }

public:

	std::vector<std::vector<WORD>> Color;
	std::vector<std::vector<std::string>> Pixel;

	int Y;
	int X;
	int Height;
	int Width;
};
