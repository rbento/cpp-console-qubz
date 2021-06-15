
#include "Hud.h"

Hud::Hud()
{
}

void Hud::Initialize()
{
	BoardFrame = Shape(2, 31, 23, 16);
	Shape::Fill(BoardFrame, EPixel::Empty, EForegroundColor::White);

	// Outer black
	BoardFrame.Pixel[0][0] = EPixel::Block;
	BoardFrame.Pixel[0][1] = EPixel::Block;
	BoardFrame.Pixel[0][2] = EPixel::Block;
	BoardFrame.Pixel[0][3] = EPixel::Block;
	BoardFrame.Pixel[0][4] = EPixel::Block;
	BoardFrame.Pixel[0][5] = EPixel::Block;
	BoardFrame.Pixel[0][6] = EPixel::Block;
	BoardFrame.Pixel[0][7] = EPixel::Block;
	BoardFrame.Pixel[0][8] = EPixel::Block;
	BoardFrame.Pixel[0][9] = EPixel::Block;
	BoardFrame.Pixel[0][10] = EPixel::Block;
	BoardFrame.Pixel[0][11] = EPixel::Block;
	BoardFrame.Pixel[0][12] = EPixel::Block;
	BoardFrame.Pixel[0][13] = EPixel::Block;
	BoardFrame.Pixel[0][14] = EPixel::Block;
	BoardFrame.Pixel[0][15] = EPixel::Block;

	BoardFrame.Pixel[1][0] = EPixel::Block;
	BoardFrame.Pixel[1][1] = EPixel::Block;
	BoardFrame.Pixel[1][2] = EPixel::Block;
	BoardFrame.Pixel[1][3] = EPixel::Block;
	BoardFrame.Pixel[1][4] = EPixel::Block;
	BoardFrame.Pixel[1][5] = EPixel::Block;
	BoardFrame.Pixel[1][6] = EPixel::Block;
	BoardFrame.Pixel[1][7] = EPixel::Block;
	BoardFrame.Pixel[1][8] = EPixel::Block;
	BoardFrame.Pixel[1][9] = EPixel::Block;
	BoardFrame.Pixel[1][10] = EPixel::Block;
	BoardFrame.Pixel[1][11] = EPixel::Block;
	BoardFrame.Pixel[1][12] = EPixel::Block;
	BoardFrame.Pixel[1][13] = EPixel::Block;
	BoardFrame.Pixel[1][14] = EPixel::Block;
	BoardFrame.Pixel[1][15] = EPixel::Block;

	BoardFrame.Pixel[2][0] = EPixel::Block;
	BoardFrame.Pixel[2][1] = EPixel::Block;
	BoardFrame.Pixel[2][2] = EPixel::Block;
	BoardFrame.Pixel[2][3] = EPixel::Block;
	BoardFrame.Pixel[2][4] = EPixel::Block;
	BoardFrame.Pixel[2][5] = EPixel::Block;
	BoardFrame.Pixel[2][6] = EPixel::Block;
	BoardFrame.Pixel[2][7] = EPixel::Block;
	BoardFrame.Pixel[2][8] = EPixel::Block;
	BoardFrame.Pixel[2][9] = EPixel::Block;
	BoardFrame.Pixel[2][10] = EPixel::Block;
	BoardFrame.Pixel[2][11] = EPixel::Block;
	BoardFrame.Pixel[2][12] = EPixel::Block;
	BoardFrame.Pixel[2][13] = EPixel::Block;
	BoardFrame.Pixel[2][14] = EPixel::Block;
	BoardFrame.Pixel[2][15] = EPixel::Block;

	BoardFrame.Color[0][0] = EBackgroundColor::Black;
	BoardFrame.Color[0][1] = EBackgroundColor::Black;
	BoardFrame.Color[0][2] = EBackgroundColor::Black;
	BoardFrame.Color[0][3] = EBackgroundColor::Black;
	BoardFrame.Color[0][4] = EBackgroundColor::Black;
	BoardFrame.Color[0][5] = EBackgroundColor::Black;
	BoardFrame.Color[0][6] = EBackgroundColor::Black;
	BoardFrame.Color[0][7] = EBackgroundColor::Black;
	BoardFrame.Color[0][8] = EBackgroundColor::Black;
	BoardFrame.Color[0][9] = EBackgroundColor::Black;
	BoardFrame.Color[0][10] = EBackgroundColor::Black;
	BoardFrame.Color[0][11] = EBackgroundColor::Black;
	BoardFrame.Color[0][12] = EBackgroundColor::Black;
	BoardFrame.Color[0][13] = EBackgroundColor::Black;
	BoardFrame.Color[0][14] = EBackgroundColor::Black;
	BoardFrame.Color[0][15] = EBackgroundColor::Black;

	BoardFrame.Color[1][0] = EBackgroundColor::Black;
	BoardFrame.Color[1][1] = EBackgroundColor::Black;
	BoardFrame.Color[1][2] = EBackgroundColor::Black;
	BoardFrame.Color[1][3] = EBackgroundColor::Black;
	BoardFrame.Color[1][4] = EBackgroundColor::Black;
	BoardFrame.Color[1][5] = EBackgroundColor::Black;
	BoardFrame.Color[1][6] = EBackgroundColor::Black;
	BoardFrame.Color[1][7] = EBackgroundColor::Black;
	BoardFrame.Color[1][8] = EBackgroundColor::Black;
	BoardFrame.Color[1][9] = EBackgroundColor::Black;
	BoardFrame.Color[1][10] = EBackgroundColor::Black;
	BoardFrame.Color[1][11] = EBackgroundColor::Black;
	BoardFrame.Color[1][12] = EBackgroundColor::Black;
	BoardFrame.Color[1][13] = EBackgroundColor::Black;
	BoardFrame.Color[1][14] = EBackgroundColor::Black;
	BoardFrame.Color[1][15] = EBackgroundColor::Black;

	BoardFrame.Color[2][0] = EBackgroundColor::Black;
	BoardFrame.Color[2][1] = EBackgroundColor::Black;
	BoardFrame.Color[2][2] = EBackgroundColor::Black;
	BoardFrame.Color[2][3] = EBackgroundColor::Black;
	BoardFrame.Color[2][4] = EBackgroundColor::Black;
	BoardFrame.Color[2][5] = EBackgroundColor::Black;
	BoardFrame.Color[2][6] = EBackgroundColor::Black;
	BoardFrame.Color[2][7] = EBackgroundColor::Black;
	BoardFrame.Color[2][8] = EBackgroundColor::Black;
	BoardFrame.Color[2][9] = EBackgroundColor::Black;
	BoardFrame.Color[2][10] = EBackgroundColor::Black;
	BoardFrame.Color[2][11] = EBackgroundColor::Black;
	BoardFrame.Color[2][12] = EBackgroundColor::Black;
	BoardFrame.Color[2][13] = EBackgroundColor::Black;
	BoardFrame.Color[2][14] = EBackgroundColor::Black;
	BoardFrame.Color[2][15] = EBackgroundColor::Black;

	// Top wall
	BoardFrame.Pixel[3][1] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][2] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][3] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][4] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][5] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][6] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][7] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][8] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][9] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][10] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][11] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][12] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][13] = EChar::BarHorizontal;
	BoardFrame.Pixel[3][14] = EChar::BarHorizontal;

	// Left wall
	BoardFrame.Pixel[3][0] = EChar::BarCornerUpLt;
	BoardFrame.Pixel[4][0] = EChar::BarVertical;
	BoardFrame.Pixel[5][0] = EChar::BarVertical;
	BoardFrame.Pixel[6][0] = EChar::BarVertical;
	BoardFrame.Pixel[7][0] = EChar::BarVertical;
	BoardFrame.Pixel[8][0] = EChar::BarVertical;
	BoardFrame.Pixel[9][0] = EChar::BarVertical;
	BoardFrame.Pixel[10][0] = EChar::BarVertical;
	BoardFrame.Pixel[11][0] = EChar::BarVertical;
	BoardFrame.Pixel[12][0] = EChar::BarVertical;
	BoardFrame.Pixel[13][0] = EChar::BarVertical;
	BoardFrame.Pixel[14][0] = EChar::BarVertical;
	BoardFrame.Pixel[15][0] = EChar::BarVertical;
	BoardFrame.Pixel[16][0] = EChar::BarVertical;
	BoardFrame.Pixel[17][0] = EChar::BarVertical;
	BoardFrame.Pixel[18][0] = EChar::BarVertical;
	BoardFrame.Pixel[19][0] = EChar::BarCornerDwLt;

	// Bottom wall
	BoardFrame.Pixel[19][1] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][2] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][3] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][4] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][5] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][6] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][7] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][8] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][9] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][10] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][11] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][12] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][13] = EChar::BarHorizontal;
	BoardFrame.Pixel[19][14] = EChar::BarHorizontal;

	// Right wall
	BoardFrame.Pixel[3][15] = EChar::BarCornerUpRt;
	BoardFrame.Pixel[4][15] = EChar::BarVertical;
	BoardFrame.Pixel[5][15] = EChar::BarVertical;
	BoardFrame.Pixel[6][15] = EChar::BarVertical;
	BoardFrame.Pixel[7][15] = EChar::BarVertical;
	BoardFrame.Pixel[8][15] = EChar::BarVertical;
	BoardFrame.Pixel[9][15] = EChar::BarVertical;
	BoardFrame.Pixel[10][15] = EChar::BarVertical;
	BoardFrame.Pixel[11][15] = EChar::BarVertical;
	BoardFrame.Pixel[12][15] = EChar::BarVertical;
	BoardFrame.Pixel[13][15] = EChar::BarVertical;
	BoardFrame.Pixel[14][15] = EChar::BarVertical;
	BoardFrame.Pixel[15][15] = EChar::BarVertical;
	BoardFrame.Pixel[16][15] = EChar::BarVertical;
	BoardFrame.Pixel[17][15] = EChar::BarVertical;
	BoardFrame.Pixel[18][15] = EChar::BarVertical;
	BoardFrame.Pixel[19][15] = EChar::BarCornerDwRt;

	NextTitle = Shape::FromString("next", EForegroundColor::White, 48, 5);
	TimeTitle = Shape::FromString("time", EForegroundColor::White, 48, 13);
	SpeedTitle = Shape::FromString("speed", EForegroundColor::White, 48, 15);
	ScoreTitle = Shape::FromString("score", EForegroundColor::White, 48, 17);
	LinesTitle = Shape::FromString("lines", EForegroundColor::White, 48, 19);

	GetLinesValue(0);
	GetScoreValue(0);
	GetSpeedValue(0);
	GetTimeValue(0);
}

void Hud::Cleanup()
{
}

Shape* Hud::GetBoardFrame()
{
	return &BoardFrame;
}

Shape* Hud::GetNextTitle()
{
	return &NextTitle;
}

Shape* Hud::GetTimeTitle()
{
	return &TimeTitle;
}

Shape* Hud::GetTimeValue(int Value)
{
	static int CurrentValue = -1;

	if (CurrentValue != Value)
	{
		CurrentValue = Value;
		Time = std::to_string((long long)Value);
		TimeValue = Shape::FromString(Time, EForegroundColor::Yellow, 48, 14);
	}

	return &TimeValue;
}

Shape* Hud::GetSpeedTitle()
{
	return &SpeedTitle;
}

Shape* Hud::GetSpeedValue(int Value)
{
	static int CurrentValue = -1;

	if (CurrentValue != Value)
	{
		CurrentValue = Value;
		Speed = std::to_string((long long)Value);
		SpeedValue = Shape::FromString(Speed, EForegroundColor::Yellow, 48, 16);
	}

	return &SpeedValue;
}

Shape* Hud::GetScoreTitle()
{
	return &ScoreTitle;
}

Shape* Hud::GetScoreValue(int Value)
{
	static int CurrentValue = -1;

	if (CurrentValue != Value)
	{

		CurrentValue = Value;
		Score = std::to_string((long long)Value);
		ScoreValue = Shape::FromString(Score, EForegroundColor::Yellow, 48, 18);
	}

	return &ScoreValue;
}

Shape* Hud::GetLinesTitle()
{
	return &LinesTitle;
}

Shape* Hud::GetLinesValue(int Value)
{
	static int CurrentValue = -1;

	if (CurrentValue != Value)
	{
		CurrentValue = Value;
		Lines = std::to_string((long long)Value);
		LinesValue = Shape::FromString(Lines, EForegroundColor::Yellow, 48, 20);
	}

	return &LinesValue;
}

Shape* Hud::GetMessageValue(const std::string& Value)
{
	static std::string CurrentValue;

	if (Value != CurrentValue)
	{
		CurrentValue = Value;
		int Length = CurrentValue.length();
		int X = (ECanvas::NumCols - Length) / 2;
		MessageValue = Shape::FromString(Value, EForegroundColor::Yellow, X, 4);
	}

	return &MessageValue;
}
