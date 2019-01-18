#include "State.h"
#include <iostream>
#include <string>
using namespace std;



State::State()
{
	

	board[0][0] = new Piece(L"\u265C", 1, BT);
	board[0][1] = new Piece(L"\u265E", 1, Bk);
	board[0][2] = new Piece(L"\u265D", 1, BB);
	board[0][3] = new Piece(L"\u265B", 1, BQ);
	board[0][4] = new Piece(L"\u265A", 1, BK);
	board[0][5] = new Piece(L"\u265D", 1, BB);
	board[0][6] = new Piece(L"\u265E", 1, Bk);
	board[0][7] = new Piece(L"\u265C", 1, BT);

	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Piece(L"\u265F", 1, BS);
		board[6][i] = new Piece(L"\u2659", 0, WS);
	}

	board[7][0] = new Piece(L"\u2656", 0, WT);
	board[7][1] = new Piece(L"\u2658", 0, Wk);
	board[7][2] = new Piece(L"\u2657", 0, WB);
	board[7][3] = new Piece(L"\u2655", 0, WQ);
	board[7][4] = new Piece(L"\u2654", 0, WK);
	board[7][5] = new Piece(L"\u2657", 0, WB);
	board[7][6] = new Piece(L"\u2658", 0, Wk);
	board[7][7] = new Piece(L"\u2656", 0, WT);

	

}



State::~State()
{
}

Piece State::getBoard()
{
	return Piece();
}

void State::setBoard(Piece * board)
{
}

void State::setSquare(int x, int y, Piece* piece)
{
	board[x][y] = piece;
}

Piece State::getPiece(int x, int y)
{
	if (board[x][y] == NULL)
	{
		return NULL;
	}
	else;
	{
		return board[x][y];
	}
	
}

Piece*[] operator[](int number)
[
	return board[number];
]
