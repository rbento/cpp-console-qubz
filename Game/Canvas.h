// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <string>
#include <vector>

#include "ECanvas.h"
#include "EChar.h"
#include "EColor.h"
#include "EPixel.h"

#include "Console.h"
#include "Shape.h"

// Represents a buffer of pixels (characters) and colors (integers) to be
// written to the Windows Console. 
// 
// Bridges interactions with the Windows Console, accumulating state change and
// flushing state at once. This mitigates the flickering effect that otherwise
// would happen while writing individual characters to the console.
// 
// Receives pixels (characters) and colors from other game entities via the Merge method.
class Canvas
{
private:

	Canvas();

public:

	~Canvas();

	static Canvas& Instance();

	// Clears the canvas by filling Pixels with the empty char and Colors with black.
	void Clear();

	// Writes the current pixels to the Windows Console. 
	void Flush();

	// Copies the given shape's pixels onto the Canvas' pixels. 
	void Merge(Shape* Shape);

	std::vector<std::vector<std::string>>* GetPixels();
	std::vector<std::vector<WORD>>* GetColors();

private:

	std::vector<std::vector<std::string>> Pixels;
	std::vector<std::vector<WORD>> Colors;

	Console& Console;
};
