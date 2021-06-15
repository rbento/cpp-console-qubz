
#include "InfoScreen.h"

InfoScreen::InfoScreen()
{
}

InfoScreen::~InfoScreen()
{
}

Screen& InfoScreen::Instance()
{
	static InfoScreen Instance;
	return Instance;
}

void InfoScreen::Initialize()
{
	Reset();
}

void InfoScreen::Cleanup()
{
}

void InfoScreen::Reset()
{
	std::string Text = "[ Q u b z ]";
	int CenterX = (ECanvas::NumCols - Text.length()) / 2;
	TitleText = Shape::FromString(Text, EForegroundColor::Yellow, CenterX, 7);

	Text = "Press left, right and down to move around. Press up to rotate.";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	KeyActionText = Shape::FromString(Text, EForegroundColor::LightGray, CenterX, 11);

	Text = "Press backspace to reset.";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	KeyResetText = Shape::FromString(Text, EForegroundColor::LightGray, CenterX, 13);

	Text = "Press escape to go back to menu.";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	KeyExitText = Shape::FromString(Text, EForegroundColor::LightGray, CenterX, 15);

	Text = "Copyright (c) 2010, Rodrigo Bento";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	CopyrightText = Shape::FromString(Text, EForegroundColor::Yellow, CenterX, 19);

	Text = "Back";
	CenterX = (ECanvas::NumCols - Text.length()) / 2;
	OptionBackText = Shape::FromString(Text, EForegroundColor::LightRed, CenterX, 24);

	CenterX = (ECanvas::NumCols - (Text.length() * 2)) / 2;
	Cursor = Shape::FromString(EPixel::Block, EForegroundColor::DarkGray, CenterX, 24);
}

void InfoScreen::Input()
{
	if (_kbhit())
	{
		char Key = _getch();

		if (Key != EChar::Empty)
		{
			switch (Key)
			{
			case EKeys::Esc:
			case EKeys::Return:
			{
				Core::Instance().ShowMenu();
			}
			break;
			}
		}
	}
}

void InfoScreen::Update(ULONGLONG TimeDiff)
{
}

void InfoScreen::Paint()
{
	Clear();

	Merge(&TitleText);

	Merge(&KeyActionText);
	Merge(&KeyResetText);
	Merge(&KeyExitText);

	Merge(&CopyrightText);

	Merge(&OptionBackText);
	Merge(&Cursor);

	Flush();
}
