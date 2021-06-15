
#include "GameScreen.h"

GameScreen::GameScreen() :
	GameBoard(nullptr),
	GameHud(nullptr),
	TotalLinesDeleted(0),
	PlayerScore(0),
	GameSpeed(0),
	GameTime(0),
	bIsGameOver(0),
	bIsGameStarted(0),
	NumLinesDeleted(0),
	GameStartTimeout(0),
	NextTimeStep(0),
	CurrentTimeStep(0)
{
}

GameScreen::~GameScreen()
{
}

Screen& GameScreen::Instance()
{
	static GameScreen Instance;
	return Instance;
}

void GameScreen::Initialize()
{
	GameBoard = new Board();

	GameHud = new Hud();
	GameHud->Initialize();

	Reset();
}

void GameScreen::Cleanup()
{
	if (GameHud)
	{
		GameHud->Cleanup();
		delete GameHud;
	}

	if (GameBoard)
	{
		delete GameBoard;
	}
}

void GameScreen::Reset()
{
	TotalLinesDeleted = 0;
	PlayerScore = 0;
	GameSpeed = 1;
	GameTime = 0;

	GameStartTimeout = ETimeStep::StartTimeout;
	NextTimeStep = ETimeStep::Max;
	CurrentTimeStep = ETimeStep::Max;

	bIsGameStarted = false;
	bIsGameOver = false;

	GameBoard->Reset();
	NextPiece = Piece::CreateRandom(48, 6);
	Clear();
}

void GameScreen::Input()
{
	if (_kbhit())
	{
		char Key = _getch();

		if (Key != EChar::Empty)
		{
			switch (Key)
			{
			case EKeys::Backspace:
			{
				Reset();
			}
			break;

			case EKeys::Esc:
			{
				Core::Instance().ShowMenu();
			}
			break;

			case EKeys::Up:
			{
				GameBoard->TryRotatePiece(EDirection::Right);
			}
			break;

			case EKeys::Right:
			{
				GameBoard->TryMovePiece(EDirection::Right);
			}
			break;

			case EKeys::Down:
			{
				GameBoard->TryMovePiece(EDirection::Down);
			}
			break;

			case EKeys::Left:
			{
				GameBoard->TryMovePiece(EDirection::Left);
			}
			break;
			}
		}
	}
}

void GameScreen::Update(ULONGLONG TimeDiff)
{
	static ULONGLONG TotalTime = 0;
	static ULONGLONG ElapsedTime = 0;

	TotalTime += TimeDiff;
	ElapsedTime += TimeDiff;

	if (bIsGameOver)
	{
		return;
	}

	if (!bIsGameStarted)
	{
		if (GameStartTimeout == ETimeStep::StartTimeout)
		{
			ElapsedTime = 0;
			GameStatusMessage = "Get Ready!";
			GameStartTimeout += TimeDiff;
		}

		if (ElapsedTime > GameStartTimeout)
		{
			ElapsedTime = 0;
			GameStatusMessage = "Qubz ";
			bIsGameStarted = true;
		}

		return;
	}

	if (GameBoard->IsTopReached())
	{
		GameStatusMessage = "Game Over!";
		bIsGameOver = true;

		return;
	}

	/** Update NextStep when it is the first update after reset. */
	if (0 == NextTimeStep)
	{
		NextTimeStep = TimeDiff + CurrentTimeStep;
	}

	if (ElapsedTime >= 1000)
	{
		GameTime += 1;
		ElapsedTime = 0;
	}

	if (!GameBoard->HasCurrentPiece())
	{
		AddPieceToBoard();
	}

	if (TotalTime > NextTimeStep)
	{
		UpdateBoard();
		UpdateStatus();

		NextTimeStep = TotalTime + CurrentTimeStep;
	}
}

void GameScreen::Paint()
{
	Clear();

	Merge(GameBoard->GetGrid());

	Merge(GameHud->GetNextTitle());
	Merge(GameHud->GetLinesTitle());
	Merge(GameHud->GetTimeTitle());
	Merge(GameHud->GetSpeedTitle());
	Merge(GameHud->GetScoreTitle());

	Merge(GameHud->GetLinesValue(TotalLinesDeleted));
	Merge(GameHud->GetTimeValue(GameTime));
	Merge(GameHud->GetSpeedValue(GameSpeed));
	Merge(GameHud->GetScoreValue(PlayerScore));

	Merge(&NextPiece);
	Merge(GameBoard->GetCurrentPiece());

	Merge(GameHud->GetBoardFrame());
	Merge(GameHud->GetMessageValue(GameStatusMessage));

	Flush();
}

void GameScreen::AddPieceToBoard()
{
	CurrentPiece = NextPiece;

	CurrentPiece.Y = EBoard::Y;
	CurrentPiece.X = EBoard::X + 6;

	Piece::SetInitialPosition(CurrentPiece);

	GameBoard->SetCurrentPiece(CurrentPiece);

	NextPiece = Piece::CreateRandom(48, 6);
}

void GameScreen::UpdateBoard()
{
	if (!GameBoard->HasCurrentPiece())
	{
		return;
	}

	if (GameBoard->IsValidMove(EDirection::Down, false))
	{
		CurrentPiece.Move(EDirection::Down);
	}
	else
	{
		GameBoard->PlacePiece();
	}

	NumLinesDeleted += GameBoard->ClearRows();
}

void GameScreen::UpdateStatus()
{
	if (NumLinesDeleted > 0)
	{
		TotalLinesDeleted += NumLinesDeleted;

		if (PlayerScore < EGameState::MaxScore)
		{
			PlayerScore += 10 * NumLinesDeleted;

			if (PlayerScore >= GameSpeed * 80)
			{
				IncreaseSpeed();
			}
		}
		else
		{
			bIsGameOver = true;
		}

		NumLinesDeleted = 0;
	}
}

void GameScreen::IncreaseSpeed()
{
	GameSpeed += 1;
	CurrentTimeStep -= (GameSpeed * 20);
	MathUtil::Clamp(CurrentTimeStep, ETimeStep::Min, ETimeStep::Max);
}
