
#include "Shape.h"

Shape::Shape(const int Y, const int X, const int Height, const int Width)
	: Color(Height, std::vector<WORD>(Width, EColor::Black)),
	Pixel(Height, std::vector<std::string>(Width, EPixel::Empty)),
	Y(Y),
	X(X),
	Height(Height),
	Width(Width)
{
}

Shape::Shape(const Shape& Shape)
	: Color(Shape.Color),
	Pixel(Shape.Pixel),
	Y(Shape.Y),
	X(Shape.X),
	Height(Shape.Height),
	Width(Shape.Width)
{
}

Shape::Shape()
	: Color(1, std::vector<WORD>(1, EColor::Black)),
	Pixel(1, std::vector<std::string>(1, EPixel::Empty)),
	Y(0),
	X(0),
	Height(1),
	Width(1)
{
}

Shape::~Shape()
{
	Color.clear();
	Pixel.clear();
}

Shape& Shape::operator = (const Shape& Other)
{
	if (this != &Other)
	{
		this->Y = Other.Y;
		this->X = Other.X;
		this->Height = Other.Height;
		this->Width = Other.Width;
		this->Color = Other.Color;
		this->Pixel = Other.Pixel;
	}

	return *this;
}

void Shape::Fill(Shape& Shape, const std::string& String, WORD Color)
{
	for (int Row = 0; Row < Shape.Height; ++Row)
	{
		for (int Col = 0; Col < Shape.Width; ++Col)
		{
			Shape.Color[Row][Col] = Color;
			Shape.Pixel[Row][Col] = String;
		}
	}
}

Shape Shape::FromString(const std::string& String, WORD Color, const int X, const int Y)
{
	int Length = String.length();

	Shape Shape(Y, X, 1, Length);

	Fill(Shape, EPixel::Empty, Color);

	for (int Index = 0; Index < Length; ++Index)
	{
		Shape.Pixel[0][Index] = String[Index];
		Shape.Color[0][Index] = Color;
	}

	return Shape;
}
