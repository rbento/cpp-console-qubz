
#include "Canvas.h"

Canvas::Canvas() :
	Console(Console::Instance()),
	Pixels(ECanvas::NumRows, std::vector<std::string>(ECanvas::NumCols)),
	Colors(ECanvas::NumRows, std::vector<WORD>(ECanvas::NumCols))
{
	Console.Initialize();
}

Canvas::~Canvas()
{
	Pixels.clear();
	Colors.clear();
}

Canvas& Canvas::Instance()
{
	static Canvas Instance;
	return Instance;
}

void Canvas::Clear()
{
	for (int Row = 0; Row < ECanvas::NumRows; Row++)
	{
		for (int Col = 0; Col < ECanvas::NumCols; Col++)
		{
			Pixels[Row][Col] = EChar::Empty;
			Colors[Row][Col] = EColor::Black;
		}
	}
}

void Canvas::Flush()
{
	for (int Row = 0; Row < ECanvas::NumRows; Row++)
	{
		for (int Col = 0; Col < ECanvas::NumCols; Col++)
		{
			Console.Write(Pixels[Row][Col], Colors[Row][Col], Col, Row);
		}
	}
}

void Canvas::Merge(Shape* Shape)
{
	if (!Shape)
	{
		return;
	}

	int CanvasX = 0;
	int CanvasY = 0;

	for (int Row = 0; Row < Shape->Height; ++Row)
	{
		CanvasX = (Shape->Y > 0) ? (Shape->Y - 1) + Row : Shape->Y + Row;

		for (int Col = 0; Col < Shape->Width; ++Col)
		{
			CanvasY = (Shape->X > 0) ? (Shape->X - 1) + Col : Shape->X + Row;

			if (Shape->Pixel[Row][Col] != EPixel::Empty)
			{
				Colors[CanvasX][CanvasY] = Shape->Color[Row][Col];
				Pixels[CanvasX][CanvasY] = Shape->Pixel[Row][Col];
			}
		}
	}
}

std::vector<std::vector<std::string>>* Canvas::GetPixels()
{
	return &Pixels;
}

std::vector<std::vector<WORD>>* Canvas::GetColors()
{
	return &Colors;
}
