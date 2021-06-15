
#include "Piece.h"

Piece::Piece(const Piece& Piece) : Shape(Piece), Rotation(Piece.Rotation), Type(Piece.Type)
{
}

Piece::Piece(const int Y, const int X) : Shape(Y, X, EPiece::NumRows, EPiece::NumCols), Rotation(0), Type(0)
{
}

Piece::~Piece()
{
}

bool Piece::IsPixelEmpty(const int Row, const int Col)
{
	return Pixel[Row][Col] == EPixel::Empty;
}

bool Piece::IsPixelFilled(const int Row, const int Col)
{
	return Pixel[Row][Col] != EPixel::Empty;
}

void Piece::SetInitialPosition(Piece& Piece)
{
	Piece.X += Position[Piece.Type][Piece.Rotation][0];
	Piece.Y += Position[Piece.Type][Piece.Rotation][1];
}

void Piece::Rotate(int Direction)
{
	Rotation += (Direction == EDirection::Left) ? -1 : (Direction == EDirection::Right) ? 1 : 0;
	Rotation = MathUtil::Rotate(Rotation, 0, 3);

	Fill(*this);
}

void Piece::Move(int Direction)
{
	int VerticalDirection = (Direction == EDirection::Down) ? 1 : 0;
	int HorizontalDirection = (Direction == EDirection::Left) ? -1 : (Direction == EDirection::Right) ? 1 : 0;

	Y += VerticalDirection;
	X += HorizontalDirection;
}

Piece Piece::CreateRandom(int X, int Y)
{
	int Type = rand() % EPiece::NumTypes;
	int Rotation = rand() % EPiece::NumRotations;

	Piece Piece(X, Y);

	Piece.Type = Type;
	Piece.Rotation = Rotation;

	Piece.X = X;
	Piece.Y = Y;

	Fill(Piece);

	return Piece;
}

WORD Piece::GetColorByType(int Type)
{
	switch (Type)
	{
	case I: { return EForegroundColor::LightCyan;  }
	case L: { return EForegroundColor::LightRed; }
	case J: { return EForegroundColor::LightBlue; }
	case Z: { return EForegroundColor::Red; }
	case S: { return EForegroundColor::Green;  }
	case O: { return EForegroundColor::Yellow;     }
	case T: { return EForegroundColor::Magenta;   }
	}

	return EColor::Black;
}

void Piece::Fill(Piece& Piece)
{
	WORD Color = GetColorByType(Piece.Type);

	for (int Row = 0; Row < EPiece::NumRows; ++Row)
	{
		for (int Col = 0; Col < EPiece::NumCols; ++Col)
		{
			Piece.Color[Row][Col] = EColor::Black;
			Piece.Pixel[Row][Col] = EPixel::Empty;

			if (PixelData[Piece.Type][Piece.Rotation][Row][Col] != 0)
			{
				Piece.Color[Row][Col] = Color;
				Piece.Pixel[Row][Col] = EPixel::Block;
			}
		}
	}
}

const char Piece::PixelData[EPiece::NumTypes][EPiece::NumRotations][EPiece::NumRows][EPiece::NumCols] =
{
	// Type Level [7]
	// I
	{
		// Rotation Level [4]
		{
			// Piece Level [5][5]
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{1, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// L
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// J
	{
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// N
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// S
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// O
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// T
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	}
};

const int Piece::Position[EPiece::NumTypes][EPiece::NumRotations][EPiece::InitialPosition] =
{
	// I
	{
		{-2, -3},
		{-2, -5},
		{-2, -3},
		{-2, -4}
	},

	// L
	{
		{-2, -4},
		{-2, -4},
		{-2, -3},
		{-2, -4}
	},

	// J
	{
		{-2, -3},
		{-2, -4},
		{-2, -4},
		{-2, -4}
	},

	// Z
	{
		{-2, -4},
		{-2, -4},
		{-2, -4},
		{-2, -3}
	},

	// S
	{
		{-2, -4},
		{-2, -4},
		{-2, -4},
		{-2, -3}
	},

	// O
	{
		{-2, -4},
		{-2, -4},
		{-2, -4},
		{-2, -4}
	},

	// T
	{
		{-2, -4},
		{-2, -4},
		{-2, -4},
		{-2, -3}
	},
};

