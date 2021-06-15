
#include "MenuScreen.h"

MenuScreen::MenuScreen() : CursorIndex(0)
{
	CursorPosition[0] = 12;
	CursorPosition[1] = 14;
	CursorPosition[2] = 16;
}

MenuScreen::~MenuScreen()
{}

Screen& MenuScreen::Instance()
{
	static MenuScreen Instance;
	return Instance;
}

void MenuScreen::Initialize()
{
	Reset();
}

void MenuScreen::Cleanup()
{}

void MenuScreen::Reset()
{
	std::string Text = "[ Q u b z ]";
	int CenterX = (ECanvas::NumCols - Text.length()) / 2;
	TitleText = Shape::FromString(Text, EForegroundColor::Yellow, CenterX, 7);

	Text = "play";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	OptionPlay = Shape::FromString(Text, EForegroundColor::LightRed, CenterX, 12);

	Text = "info";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	OptionInfo = Shape::FromString(Text, EForegroundColor::LightRed, CenterX, 14);

	Text = "exit";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	OptionExit = Shape::FromString(Text, EForegroundColor::LightRed, CenterX, 16);

	CenterX = (ECanvas::NumCols - (Text.length() * 2)) / 2;
	Cursor = Shape::FromString(EPixel::Block, EForegroundColor::DarkGray, CenterX, 10);

	CursorIndex = 0;
}

void MenuScreen::Input()
{
	if (_kbhit())
	{
		char Key = _getch();

		if (Key != EChar::Empty)
		{
			switch (Key)
			{
			case EKeys::Up:
			{
				CursorIndex = MathUtil::Rotate(--CursorIndex, 0, 2);
			}
			break;

			case EKeys::Down:
			{
				CursorIndex = MathUtil::Rotate(++CursorIndex, 0, 2);
			}
			break;

			case EKeys::Return:
			{
				SelectOption();
			}
			break;
			}
		}
	}
}

void MenuScreen::Update(ULONGLONG _timeDiff)
{
	Cursor.Y = CursorPosition[CursorIndex];
}

void MenuScreen::Paint()
{
	Clear();

	Merge(&TitleText);
	Merge(&OptionPlay);
	Merge(&OptionInfo);
	Merge(&OptionExit);
	Merge(&Cursor);

	Flush();
}

void MenuScreen::SelectOption()
{
	switch (CursorIndex)
	{
	case 0:
	{
		Core::Instance().ShowGame();
	} break;
	case 1:
	{
		Core::Instance().ShowInfo();
	} break;
	case 2:
	{
		Core::Instance().Exit();
	} break;
	}
}


