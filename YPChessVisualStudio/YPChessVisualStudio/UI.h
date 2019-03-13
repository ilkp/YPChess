#pragma once

#include "State.h"
#include "Piece.h"
#include "Move.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

class UI
{
private:
	HANDLE hConsole;

public:
	UI(State* state, HANDLE outputHandle);
	~UI();
	void drawBoard(State* state);
	Move* takePlayersMove();
};

