
#include "Board.h"

Board::Board() : Grid(nullptr), CurrentPiece(nullptr)
{
}

Board::~Board()
{
	delete Grid;
}

void Board::ResetGrid()
{
	if (Grid)
	{
		delete Grid;
	}

	Grid = new Shape(EBoard::Y, EBoard::X, EBoard::NumRows, EBoard::NumCols);
	Shape::Fill(*Grid, EPixel::Empty, EColor::Black);
}

void Board::Reset()
{
	ResetGrid();

	CurrentPiece = 0;
}

bool Board::IsCellFree(const int Row, const int Col) const
{
	return Grid->Pixel[Row][Col] == EPixel::Empty;
}

bool Board::IsCellOccupied(const int Row, const int Col) const
{
	if (IsOutOfBounds(Row, Col))
	{
		return false;
	}

	return Grid->Pixel[Row][Col] != EPixel::Empty;
}

bool Board::IsOutOfBounds(const int RowIndex, const int ColIndex) const
{
	return RowIndex < 0 || RowIndex > EBoard::MaxNumRowsIndex || ColIndex < 0 || ColIndex > EBoard::MaxNumColsIndex;
}

bool Board::HasCurrentPiece() const
{
	return 0 != CurrentPiece;
}

bool Board::IsValidMove(const int Direction, const bool bRotate) const
{
	if (!HasCurrentPiece())
	{
		return false;
	}

	Piece TestPiece = *CurrentPiece;

	if (bRotate)
	{
		TestPiece.Rotate(Direction);
	}
	else
	{
		TestPiece.Move(Direction);
	}

	int CursorRow = TestPiece.Y - EBoard::Y;
	int CursorCol = TestPiece.X - EBoard::X;

	// Predicts the next move by looking ahead with the help of the TestPiece.

	for (int BoardRow = CursorRow, PieceRow = 0; BoardRow < CursorRow + EPiece::NumRows; ++BoardRow, ++PieceRow)
	{
		for (int BoardCol = CursorCol, PieceCol = 0; BoardCol < CursorCol + EPiece::NumCols; ++BoardCol, ++PieceCol)
		{
			// Cannot play next move if, past the top row, a filled piece block would be out of the board bounds.

			if (BoardRow >= 0 && IsOutOfBounds(BoardRow, BoardCol) && TestPiece.IsPixelFilled(PieceRow, PieceCol))
			{
				return false;
			}

			// Cannot play next move if a filled piece block overlaps with a filled board position.

			if (IsCellOccupied(BoardRow, BoardCol) && TestPiece.IsPixelFilled(PieceRow, PieceCol))
			{
				return false;
			}
		}
	}

	return true;
}

void Board::PlacePiece()
{
	if (HasCurrentPiece())
	{
		int CursorRow = CurrentPiece->Y - EBoard::Y;
		int CursorCol = CurrentPiece->X - EBoard::X;

		for (int BoardRow = CursorRow, PieceRow = 0; BoardRow < CursorRow + EPiece::NumRows; ++BoardRow, ++PieceRow)
		{
			for (int BoardCol = CursorCol, PieceCol = 0; BoardCol < CursorCol + EPiece::NumCols; ++BoardCol, ++PieceCol)
			{
				if (!IsOutOfBounds(BoardRow, BoardCol) && CurrentPiece->IsPixelFilled(PieceRow, PieceCol))
				{
					Grid->Pixel[BoardRow][BoardCol] = EPixel::Block;
					Grid->Color[BoardRow][BoardCol] = CurrentPiece->Color[PieceRow][PieceCol];
				}
			}
		}

		CurrentPiece = 0;
	}
}

void Board::TryRotatePiece(int Direction)
{
	if (IsValidMove(Direction, true))
	{
		CurrentPiece->Rotate(Direction);
	}
}

void Board::TryMovePiece(int Direction)
{
	if (IsValidMove(Direction))
	{
		CurrentPiece->Move(Direction);
	}
}

bool Board::IsTopReached() const
{
	for (int Col = 0; Col < EBoard::NumCols; ++Col)
	{
		if (Grid->Pixel[0][Col] == EPixel::Block)
		{
			return true;
		}
	}

	return false;
}

int Board::ClearRows()
{
	int NumCleared = 0;

	for (int Row = 0; Row < EBoard::NumRows; ++Row)
	{
		int Col = 0;

		while (Col < EBoard::NumCols)
		{
			if (IsCellFree(Row, Col))
			{
				break;
			}

			Col++;
		}

		if (Col >= EBoard::NumCols)
		{
			ClearRow(Row);
			NumCleared++;
		}
	}

	return NumCleared;
}

void Board::ClearRow(const int FromRow)
{
	for (int Row = FromRow; Row > 0; --Row)
	{
		for (int Col = 0; Col < EBoard::NumCols; ++Col)
		{
			Grid->Pixel[Row][Col] = Grid->Pixel[Row - 1][Col];
			Grid->Color[Row][Col] = Grid->Color[Row - 1][Col];
		}
	}
}

Piece* Board::GetCurrentPiece() const
{
	return CurrentPiece;
}

void Board::SetCurrentPiece(Piece& Piece)
{
	CurrentPiece = &Piece;
}

Shape* Board::GetGrid() const
{
	return Grid;
}
