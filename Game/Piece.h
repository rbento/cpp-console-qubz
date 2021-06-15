// Copyright (c) Rodrigo Bento

#pragma once

#include <wtypes.h>

#include <sstream>
#include <string>

#include "EColor.h"
#include "EDirection.h"
#include "EPiece.h"
#include "EPixel.h"

#include "MathUtil.h"
#include "Shape.h"

enum EPieceType { I, L, J, Z, S, O, T };

class Piece : public Shape
{
private:

	static WORD GetColorByType(const int Type);

	static void Fill(Piece& Piece);

public:

	Piece(const int X = 0, const int Y = 0);
	Piece(const Piece& Other);

	~Piece();

	static Piece CreateRandom(const int X, const int Y);

	static void SetInitialPosition(Piece& Piece);

	bool IsPixelEmpty(const int Row, const int Col);
	bool IsPixelFilled(const int Row, const int Col);

	void Rotate(const int Direction);
	void Move(const int Direction);

private:

	// Stores the blocks (pixels) of all pieces according to their types and rotations. 
	static const char PixelData[EPiece::NumTypes][EPiece::NumRotations][EPiece::NumRows][EPiece::NumCols];


	// Stores initial positions of all pieces according to their types and rotations. 
	static const int Position[EPiece::NumTypes][EPiece::NumRotations][EPiece::InitialPosition];

public:

	unsigned char Type;

	int Rotation;
};
