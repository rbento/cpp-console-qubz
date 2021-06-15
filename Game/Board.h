// Copyright (c) Rodrigo Bento

#pragma once

#include "EBoard.h"
#include "EColor.h"
#include "EPixel.h"
#include "EPiece.h"

#include "MathUtil.h"
#include "Piece.h"

class Board
{
private:

	void ResetGrid();

public:

	Board();

	~Board();

	void Reset();

	// Moves a piece in the given direction, if move is valid.
	void TryMovePiece(const int Direction);

	// Rotates a piece in the given direction, if move is valid. 
	void TryRotatePiece(const int Direction);

	// Places a piece on the board grid changing the state of the grid cells in terms
	// of pixels and color according to the piece attributes. 
	void PlacePiece();

	// Searches for filled board grid lines and remove them. 
	int ClearRows();

	// Given a row, move down all blocks above it. 
	void ClearRow(const int FromRow);

	bool IsCellFree(const int Row, const int Col) const;

	bool IsCellOccupied(const int Row, const int Col) const;

	// Tells whether the given row and column index falls outside the board grid bounds. 
	bool IsOutOfBounds(const int RowIndex, const int ColIndex) const;

	// Given a direction, predicts a move.
	// Checks for collision between the current piece cells and the board grid cells. 
	bool IsValidMove(const int Direction, const bool bRotate = false) const;

	bool IsTopReached() const;

	bool HasCurrentPiece() const;

	Piece* GetCurrentPiece() const;

	void SetCurrentPiece(Piece& Piece);

	Shape* GetGrid() const;

public:

	Shape* Grid;

	// The current piece in play.
	Piece* CurrentPiece;
};
