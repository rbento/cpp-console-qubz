// Copyright (c) Rodrigo Bento

#pragma once

#include <windows.h>

#include <cstdlib>
#include <iostream>

#include "EKeys.h"
#include "EGameState.h"
#include "ETimeStep.h"

#include "Board.h"
#include "Canvas.h"
#include "Console.h"
#include "Core.h"
#include "Hud.h"
#include "Piece.h"
#include "Screen.h"

class GameScreen : public Screen
{
public:

	~GameScreen();

	static Screen& Instance();

	void Initialize();
	void Cleanup();

	void Reset();

	void Input();
	void Update(ULONGLONG TimeDiff);
	void Paint();

	// Adds the next piece to the board. 
	void AddPieceToBoard();

	// Increases the overall game speed. 
	void IncreaseSpeed();

	// Moves a piece down, places a piece on the board and delete lines. 
	void UpdateBoard();

	// Calculates the score and updates the game speed when a line is deleted.
	void UpdateStatus();

private:

	GameScreen();

private:

	int NumLinesDeleted;
	int TotalLinesDeleted;
	int PlayerScore;
	int GameSpeed;
	int GameTime;

	bool bIsGameOver;
	bool bIsGameStarted;

	ULONGLONG GameStartTimeout;
	ULONGLONG NextTimeStep;
	ULONGLONG CurrentTimeStep;

	Piece CurrentPiece;
	Piece NextPiece;

	std::string GameStatusMessage;

	Hud* GameHud;
	Board* GameBoard;
};
