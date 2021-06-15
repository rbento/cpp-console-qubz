// Copyright (c) Rodrigo Bento

#pragma once

namespace EBoard
{
	enum : int
	{
		Width = 14,
		Height = 15,
		PositionFree = 0,
		PositionFilled = 1,
		WaitForMove = 400, // Milliseconds

		X = 32,
		Y = 6,
		NumRows = 15,
		NumCols = 14,
		MaxNumRowsIndex = NumRows - 1,
		MaxNumColsIndex = NumCols - 1
	};
}
